#pragma once
#include "Character.h"

class Zombie : public Character
{
public:
    Zombie(std::string name, int hp, int attack)
        : Character(name, hp, attack)
    {
    }
};

class NormalZombie : public Zombie
{
public:
    NormalZombie()
        : Zombie("좀비", 50, 50)
    {
    }
};

class ArmoredZombie : public Zombie
{
public:
    ArmoredZombie()
        : Zombie("갑옷 좀비", 100, 30)
    {
    }
};

class FastZombie : public Zombie
{
public:
    FastZombie()
        : Zombie("재빠른 좀비", 35, 50)
    {
    }
};