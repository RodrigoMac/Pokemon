#pragma once

#include "Pokemon.h"
#include "Element.h"

class Squirtle : public Pokemon
{
    public:
        Squirtle(std::string name, int lvl) : Pokemon::Pokemon(name, lvl, Element::Water) {}
        ~Squirtle() = default;

        void EmitSound() const override{
            std::cout << "squiiiiirtleee" << std::endl;
        }
};

