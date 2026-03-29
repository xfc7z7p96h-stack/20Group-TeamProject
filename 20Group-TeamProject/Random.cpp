#include "Random.h"

std::mt19937 Random::gen(std::random_device{}());

int Random::Range(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

bool Random::Chance(int percent)
{
    if (percent <= 0)
    {
        return false;
    }

    if (percent >= 100)
    {
        return true;
    }

    std::uniform_int_distribution<int> dist(1, 100);
    return dist(gen) <= percent;
}