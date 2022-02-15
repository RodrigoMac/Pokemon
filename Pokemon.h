#pragma once

#include "Element.h"

#include <iostream>

class Pokemon
{

public:
    Pokemon(const std::string& name, int level, Element type);
    ~Pokemon() = default;

    void Name();
    virtual void EmitSound() const = 0;
    void Attack(Pokemon &enemy);
    void Cure(int life);
    void Level(const int exp);
    void HP();
    int Strength(Pokemon &enemy);
    float Weakness(Pokemon &enemy);

private:
    int m_lvl, m_xpmax, m_xp, m_hpmax, m_hp, m_atk;
    std::string m_name;
    Element m_type;

    void HP(int life);
};

