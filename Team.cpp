#include "Team.h"

void Team::assignHeroToPosition(const std::string& position, Hero* hero) {
    if (hero) positions[position] = hero;
}

void Team::displayTeam() const {
    std::cout << "\nTeam Drafting Composition:\n";
    for (const auto& [position, hero] : positions) {
        std::cout << position << " Lane - ";
        hero->displayInfo();
    }
}
