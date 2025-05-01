#ifndef HERO_H
#define HERO_H

#include <string>
#include <iostream>
#include <windows.h>

class Hero {
protected:
    std::string name;
    std::string role;
    std::string ability;

public:
    Hero(const std::string& name, const std::string& role, const std::string& ability);
    virtual void displayInfo() const = 0;
    std::string getRole() const;
    std::string getName() const;
    virtual ~Hero() {}
};

class Tank : public Hero {
public:
    Tank(const std::string& name);
    void displayInfo() const override;
};

class Mage : public Hero {
public:
    Mage(const std::string& name);
    void displayInfo() const override;
};

class Marksman : public Hero {
public:
    Marksman(const std::string& name);
    void displayInfo() const override;
};

class Assassin : public Hero {
public:
    Assassin(const std::string& name);
    void displayInfo() const override;
};

class Support : public Hero {
public:
    Support(const std::string& name);
    void displayInfo() const override;
};

class Fighter : public Hero {
public:
    Fighter(const std::string& name);
    void displayInfo() const override;
};

#endif