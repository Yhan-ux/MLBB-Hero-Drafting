#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <unordered_map>
#include "Hero.h"

class Team {
private:
    std::unordered_map<std::string, Hero*> positionToHero;

public:
    void assignHeroToPosition(const std::string& position, Hero* hero);
    void getFormattedTeam(std::vector<std::string>& lines, const std::string& teamName) const;

};

#endif // TEAM_H
