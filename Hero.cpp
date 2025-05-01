// ================= Hero.cpp =================
#include "Hero.h"

void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


Hero::Hero(const std::string& name, const std::string& role, const std::string& ability)
    : name(name), role(role), ability(ability) {}

std::string Hero::getRole() const { return role; }
std::string Hero::getName() const { return name; }

Tank::Tank(const std::string& name) : Hero(name, "Tank", "Absorb damage and protect teammates.") {}
void Tank::displayInfo() const {
    setConsoleColor(6); std::cout << name; setConsoleColor(7); std::cout << ": " << ability << std::endl;
}

Mage::Mage(const std::string& name) : Hero(name, "Mage", "Cast spells to damage and crowd-control enemies.") {}
void Mage::displayInfo() const {
    setConsoleColor(11); std::cout << name; setConsoleColor(7); std::cout << ": " << ability << std::endl;
}

Marksman::Marksman(const std::string& name) : Hero(name, "Marksman", "Deal sustained damage from a distance.") {}
void Marksman::displayInfo() const {
    setConsoleColor(9); std::cout << name; setConsoleColor(7); std::cout << ": " << ability << std::endl;
}

Assassin::Assassin(const std::string& name) : Hero(name, "Assassin", "Quickly eliminate key enemy targets.") {}
void Assassin::displayInfo() const {
    setConsoleColor(13); std::cout << name; setConsoleColor(7); std::cout << ": " << ability << std::endl;
}

Support::Support(const std::string& name) : Hero(name, "Support", "Assist allies by healing or providing utility.") {}
void Support::displayInfo() const {
    setConsoleColor(10); std::cout << name; setConsoleColor(7); std::cout << ": " << ability << std::endl;
}

Fighter::Fighter(const std::string& name) : Hero(name, "Fighter", "Balanced offense and defense for sustained fights.") {}
void Fighter::displayInfo() const {
    setConsoleColor(12); std::cout << name; setConsoleColor(7); std::cout << ": " << ability << std::endl;
}