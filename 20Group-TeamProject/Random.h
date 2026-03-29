#pragma once
#include <random>

class Random
{
private:
    static std::mt19937 gen;

public:
    static int Range(int min, int max);
    static bool Chance(int percent);
};
