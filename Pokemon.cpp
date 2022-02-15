#include "Pokemon.h"
#include "Element.h"

#include <iostream>
#include <string>
#include <map>
#include <iterator>

constexpr int hpbase = 20;
constexpr int hplvl = 3;
constexpr int xplvl = 10;

Pokemon::Pokemon(const std::string& name, int level, Element type)
    : m_name(name),
      m_lvl(level),
      m_type(type),
      m_xp(0),
      m_xpmax(m_lvl * xplvl),
      m_atk(m_lvl),
      m_hpmax(hpbase + m_lvl * hplvl),
      m_hp(m_hpmax)

{
}

void Pokemon::Name()
{
    std::cout << "O nome do Pokemon é: " << m_name << std::endl;
}

void Pokemon::Attack(Pokemon &enemy)
{
    const float multiplier = Weakness(enemy)*Strength(enemy);

    EmitSound();
    std::cout << m_name << " causou " << static_cast<int>(m_atk * multiplier) << " de dano em " << enemy.m_name << std::endl;
    enemy.HP(enemy.m_hp - static_cast<int>(m_atk * multiplier));
    Pokemon::Level(static_cast<int>(m_atk * multiplier));
    std::cout << std::endl;
}

void Pokemon::Cure(int life)
{
    std::cout << m_name << " recebeu " << life << " pontos de vida" << std::endl;
    m_hp += life;

    if (m_hp > m_hpmax)
    {
        m_hp = m_hpmax;
    }

    Pokemon::HP();
}

void Pokemon::Level(const int exp)
{
    m_xpmax = m_lvl * 10;
    m_xp += exp;

    if (m_xp >= m_xpmax)
    {
        ++m_lvl;
        std::cout << m_name << " subiu para nível " << m_lvl << std::endl;
        m_atk = m_lvl;
        m_hpmax = (20 + m_lvl * 3);
        Pokemon::HP(m_hpmax);
    }
}

void Pokemon::HP()
{
    std::cout << m_name << " está com " << m_hp << " pontos de vida" << std::endl;
}

void Pokemon::HP(int life)
{
    m_hp = life;

    if (m_hp < 0)
    {
        m_hp = 0;
    }

    std::cout << m_name << " está com " << m_hp << " pontos de vida" << std::endl;
}

int Pokemon::Strength(Pokemon &enemy)
{
    for (const auto &type : Weaknesses.at(enemy.m_type))
    {
        if (type == m_type)
        {
            std::cout << m_name << " é forte contra " << enemy.m_name << std::endl;
            return 2;
        }
    }

    return 1;
}

float Pokemon::Weakness(Pokemon &enemy)
{
    for (const auto &type : Strengths.at(enemy.m_type))
    {
        if (type == m_type)
        {
            std::cout << m_name << " é fraco contra " << enemy.m_name << std::endl;
            return 0.5;
        }
    }

    return 1;
}