#include "Team.h"
#include <iostream>
#include <iomanip>  // for setw and setfill
#include <windows.h>
#include "ColorUtil.h"
#include <sstream>
void Team::assignHeroToPosition(const std::string& position, Hero* hero) {
    positionToHero[position] = hero;
}

void Team::getFormattedTeam(std::vector<std::string>& lines, const std::string& teamName) const {
    std::ostringstream oss;
    if (teamName == "BLUE TEAM") {
        oss << "\033[1;34m"; // Blue
    }
    else if (teamName == "RED TEAM") {
        oss << "\033[1;31m"; // Red
    }

    oss << std::left << std::setw(25) << teamName << "\033[0m";
    lines.push_back(oss.str());

    for (const auto& [position, hero] : positionToHero) {
        std::ostringstream line;
        line << std::left << std::setw(10) << position << ": "
            << std::setw(15) << hero->getName()
            << "[" << hero->getRole() << "]";
        lines.push_back(line.str());
    }
}

