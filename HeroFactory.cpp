#include "HeroFactory.h"

static std::unordered_map<std::string, std::vector<std::string>> heroPool = {
    {"Assassin", {"Lancelot", "Hayabusa", "Natalia", "Gusion", "Helcurt"}},
    {"Marksman", {"Lesley", "Brody", "Beatrix", "Miya", "Granger"}},
    {"Mage", {"Lylia", "Lunox", "Valir", "Eudora", "Kagura"}},
    {"Support", {"Angela", "Rafaela", "Estes", "Floryn", "Faramis"}},
    {"Tank", {"Tigreal", "Khufra", "Franco", "Belerick", "Atlas"}},
    {"Fighter", {"Aldous", "Zilong", "Freya", "Martis", "Leomord"}}
};

Hero* HeroFactory::createHero(const std::string& role, const std::string& name) {
    if (role == "Tank") return new Tank(name);
    if (role == "Mage") return new Mage(name);
    if (role == "Marksman") return new Marksman(name);
    if (role == "Assassin") return new Assassin(name);
    if (role == "Support") return new Support(name);
    if (role == "Fighter") return new Fighter(name);
    return nullptr;
}

const std::unordered_map<std::string, std::vector<std::string>>& HeroFactory::getHeroPool() {
    return heroPool;
}
