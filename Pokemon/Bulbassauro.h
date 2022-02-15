#pragma once

#include "Pokemon.h"
#include "Element.h"

class Bulbassauro : public Pokemon
{
    public:
        Bulbassauro(std::string name, int lvl) : Pokemon::Pokemon(name, lvl, Element::Grass) {}
        ~Bulbassauro() = default;

        void EmitSound() const override{
            std::cout << "bulbassaaaaaur" << std::endl;
        }
};