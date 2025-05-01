#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>
#include "HeroFactory.h"
#include "Team.h"
#include "iomanip"
#include "string"

std::string toLower(const std::string& str) {
    std::string lower;
    for (char c : str) lower += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return lower;
}
void wall() {
    std::cout << "\033[1;36m" << std::setfill('=') << std::setw(70) << "\033[0m";
}
void wall2() {
    std::cout << "\033[1;32m" << std::setfill('*') << std::setw(70) << "\033[0m";
}
int main() {
    Team team;
    const auto& pool = HeroFactory::getHeroPool();

    std::vector<std::pair<std::string, std::string>> laneRoles = {
        {"Jungler", "Assassin"},
        {"Gold", "Marksman"},
        {"Mid", "Mage"},
        {"Roam", "Support"},
        {"EXP", "Fighter"}
    };
    wall();
    std::cout << "\n\033[1;36m"
                 << std::setfill('=') << std::setw(27) << "\033[0m"
                    <<"\033[1;36m MLBB Hero Drafting \033[0m" << "\033[1;36m" 
                 << std::setfill('=') << std::setw(28)  << "\033[0m\n";

    for (const auto& [position, defaultRole] : laneRoles) {
        std::string role;
        wall();
        while (true) {
            std::cout << "\nSelect role for \033[1;32m" << position << "\033[0m lane (default is " << defaultRole << "): ";
            std::getline(std::cin, role);
            if (role.empty()) role = defaultRole;
            std::string roleLower = toLower(role);
            auto it = std::find_if(pool.begin(), pool.end(), [&](const auto& p) {
                return toLower(p.first) == roleLower;
                });
            if (it != pool.end()) {
                role = it->first; // set to canonical role spelling
                break;
            }
            std::cout << "Invalid role. Please enter a valid role.\n";
        }
        wall2();
        std::cout << "\nAvailable " << role << " heroes for \033[1;32m" << position << "\033[0m lane:\n";
        for (const auto& hero : pool.at(role)) {
            
            std::cout << "- \033[34m" << hero << "\033[0m" << std::endl;
        }
        wall2();
        std::string name;
        Hero* hero = nullptr;
        while (!hero) {
            std::cout << "\nPick for \033[1;32m" << position << "\033[0m lane (" << role << ")\nEnter hero name from the list above: ";
            std::getline(std::cin, name);

            for (const std::string& candidate : pool.at(role)) {
                if (toLower(candidate) == toLower(name)) {
                    hero = HeroFactory::createHero(role, candidate);
                    break;
                }
            }

            if (!hero) std::cout << "Invalid hero name! Please enter a valid hero name from the list.\n";
        }

        team.assignHeroToPosition(position, hero);
    }

    team.displayTeam();

    return 0;
}
