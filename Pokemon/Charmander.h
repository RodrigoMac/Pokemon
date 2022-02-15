#pragma once

#include "Pokemon.h"
#include "Element.h"

class Charmander : public Pokemon
{
    public:
        Charmander(std::string name, int lvl) : Pokemon::Pokemon(name, lvl, Element::Fire) {}
        ~Charmander() = default;

        void EmitSound() const override{
            std::cout << "char" << std::endl;
        }
};