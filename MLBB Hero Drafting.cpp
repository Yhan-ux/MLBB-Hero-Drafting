    #include <iostream>
    #include <unordered_map>
    #include <unordered_set>
    #include <set>
    #include <vector>
    #include <string>
    #include <algorithm>
    #include <thread>
    #include <future>
    #include <random>
    #include <cctype>
    #include <windows.h>
    #include <atomic>
    #include <mutex>
    #include "ColorUtil.h"

    #include "Hero.h"
    #include "HeroFactory.h"
    #include "Team.h"
    #include <iomanip>
    #include <algorithm>
    //void cyanwall() {
    //    std::cout << "\033[1;36m" << std::setfill('*') << std::setw(85) << "\033[0m\n";
    //}
    //void redwall() {
    //    std::cout << "\033[41m" << "\033[1;31m" << std::setfill('=') << std::setw(85)<< "\033[0m\n";
    //}
    //void greenwall2() {
    //    std::cout << "\033[1;32m" << std::setfill('*') << std::setw(85) << "\033[0m\n";
    //}

    std::string toLower(const std::string& str) {
        std::string lower = str;
        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        return lower;
    }

    Hero* autoPickHero(const std::string& role, const std::set<std::string>& picked) {
        const auto& pool = HeroFactory::getHeroPool();
        std::vector<std::string> available;
        for (const auto& h : pool.at(role)) {
            if (!picked.count(h)) available.push_back(h);
        }
        if (available.empty()) return nullptr;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, available.size() - 1);
        return HeroFactory::createHero(role, available[dis(gen)]);
    }

    int main() {
        Team blueTeam, redTeam;
        std::set<std::string> pickedHeroes;

        std::unordered_map<std::string, std::string> defaultLaneRoles = {
            {"EXP", "Fighter"},
            {"Jungle", "Assassin"},
            {"Mid", "Mage"},
            {"Gold", "Marksman"},
            {"Roam", "Tank"}
        };
        std::cout << "\033[1;36m" << std::setfill('*') << std::setw(85) << "\033[0m\n";
        std::cout << "\n\033[1;36m"
            << std::setfill('=') << std::setw(35) << "\033[0m"
            << "\033[1;36m MLBB Hero Drafting \033[0m" << "\033[1;36m"
            << std::setfill('=') << std::setw(35) << "\033[0m\n\n";
        std::cout << "\033[1;36m" << std::setfill('*') << std::setw(85) << "\033[0m\n";
        const auto& pool = HeroFactory::getHeroPool();

        for (const auto& [position, defaultRole] : defaultLaneRoles) {
            std::cout << "\033[1;32m" << std::setfill('*') << std::setw(85) << "\033[0m\n";;
            std::string roleInput;
            std::string chosenRole = defaultRole;
            std::atomic<bool> roleReceived{ false };
            std::mutex roleMutex;

            std::cout << "\033[1;92m" << position << " lane \033[0m - Pick a role \033[1;92m (Tank, Mage, Marksman, Assassin, Fighter) [default: " << defaultRole << "]: \033[0m \n";
            std::cout << "\033[1;33mYou have 15 seconds to pick your role.\033[0m\n";

            std::thread roleThread([&]() {
                std::string temp;
                std::getline(std::cin, temp);
                std::lock_guard<std::mutex> lock(roleMutex);
                roleInput = temp;
                roleReceived = true;
                });

            for (int i = 15; i >= 0; --i) {
                {
                    std::lock_guard<std::mutex> lock(roleMutex);
                    std::string inputLower = toLower(roleInput);
                    for (const auto& [r, _] : pool) {
                        if (toLower(r) == inputLower) {
                            chosenRole = r;
                            break;
                        }
                    }
                }
                setColor(12);
                std::cout << "\rTime left: " << i << " seconds " << std::flush;
                setColor(7);
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
            std::cout << '\n';
            roleReceived = true;
            if (roleThread.joinable()) roleThread.detach();

            std::cout << "Selected role for \033[1;32m" << position << "\033[0m lane: \033[1;36m" << chosenRole << "\033[0m\n";

            Hero* hero = nullptr;

            std::cout << "\033[1;32m Available heroes for " << chosenRole << ":\n";
            for (const std::string& h : pool.at(chosenRole)) {
                if (!pickedHeroes.count(h)) std::cout << "- " << h << '\n';
            }

            std::cout << "\033[1;33mYou have 30 seconds to pick your hero.\033[0m\n";

            std::string inputName;
            std::atomic<bool> inputReceived{ false };
            std::mutex inputMutex;

            std::thread inputThread([&]() {
                while (!inputReceived) {
                    std::string temp;
                    std::getline(std::cin, temp);
                    std::lock_guard<std::mutex> lock(inputMutex);
                    inputName = temp;
                }
                });

            bool pickedInTime = false;
            for (int i = 30; i >= 0; --i) {
                {
                    std::lock_guard<std::mutex> lock(inputMutex);
                    for (const std::string& candidate : pool.at(chosenRole)) {
                        if (toLower(candidate) == toLower(inputName) && !pickedHeroes.count(candidate)) {
                            hero = HeroFactory::createHero(chosenRole, candidate);
                            pickedInTime = true;
                            inputReceived = true;
                            break;
                        }
                    }
                    if (!hero && !inputName.empty()) {
                        std::cout << "\nInvalid hero. Try again: ";
                        inputName.clear();
                    }
                }
                setColor(12);
                std::cout << "\rTime left: " << i << " seconds " << std::flush;
                setColor(7);
                if (pickedInTime) break;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }

            std::cout << '\n';
            inputReceived = true;
            if (inputThread.joinable()) inputThread.detach();

            if (!pickedInTime) {
                std::cout << "\nAuto-picking hero...\n";
                hero = autoPickHero(chosenRole, pickedHeroes);
            }
            std::cout << "\033[44m" << "\033[1;34m" << std::setfill(' ') << std::setw(85) << "\033[0m\n";
            if (hero) {
                setColor(9); // Blue

                pickedHeroes.insert(hero->getName());
                blueTeam.assignHeroToPosition(position, hero);
                setColor(9); 
                std::cout << "Blue Team picked: [" << position << "]\n";
                setColor(9); 
                hero->displayInfo();

                setColor(7); // Reset

            }
            std::cout << "\033[44m" << "\033[1;34m" << std::setfill(' ') << std::setw(85) << "\033[0m\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(800));
            std::cout << "\033[41m" << "\033[1;31m" << std::setfill(' ') << std::setw(85) << "\033[0m\n";
            Hero* redPick = autoPickHero(chosenRole, pickedHeroes);
            if (redPick) {
                setColor(12); // Red
                pickedHeroes.insert(redPick->getName());
                redTeam.assignHeroToPosition(position, redPick);
                setColor(12); 
                std::cout << "Red Team picked: ";
                redPick->displayInfo();
                setColor(7); // Reset

            }
            std::cout << "\033[41m" << "\033[1;31m" << std::setfill(' ') << std::setw(85) << "\033[0m\n";
        }

        std::vector<std::string> blueLines, redLines;
        blueTeam.getFormattedTeam(blueLines, "BLUE TEAM");
        redTeam.getFormattedTeam(redLines, "RED TEAM");

        std::cout << "\n\n\033[1;33m" << std::setfill('=') << std::setw(85) << "\033[0m\n";
        std::cout << std::setw(40) << std::left << "\033[1;34m BLUE TEAM \033[0m" << " | " << "\033[1;31m RED TEAM \033[0m\n";
        std::cout << std::setfill('-') << std::setw(85) << "-" << std::setfill(' ') << "\n";

        size_t maxLines = max(blueLines.size(), redLines.size());
        for (size_t i = 0; i < maxLines; ++i) {
            std::string blueEntry = i < blueLines.size() ? blueLines[i] : "";
            std::string redEntry = i < redLines.size() ? redLines[i] : "";
            std::cout << std::setw(40) << std::left << blueEntry << " # " << redEntry << "\n";
        }

        std::cout << "\033[1;33m" << std::setfill('=') << std::setw(85) << "\033[0m\n";


        return 0;
    }
