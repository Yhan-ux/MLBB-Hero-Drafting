#ifndef HEROFACTORY_H
#define HEROFACTORY_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Hero.h"

class HeroFactory {
public:
    static Hero* createHero(const std::string& role, const std::string& name);
    static const std::unordered_map<std::string, std::vector<std::string>>& getHeroPool();
};

#endif
