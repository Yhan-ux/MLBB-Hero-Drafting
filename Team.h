#ifndef TEAM_H
#define TEAM_H

#include <map>
#include "Hero.h"

class Team {
private:
    std::map<std::string, Hero*> positions;

public:
    void assignHeroToPosition(const std::string& position, Hero* hero);
    void displayTeam() const;
};

#endif
