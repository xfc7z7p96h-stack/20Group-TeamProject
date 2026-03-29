#include "Random.h"

std::mt19937 Random::gen(std::random_device{}());

/// min ~ max 범위의 랜덤 정수값을 반환하는 함수 
/// 사용 예시
/// Random::Range(1, 10); // 1 ~ 10 사이의 랜덤값 반환
int Random::Range(int min, int max) 
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}



/// percent % 의 확률로 true를 반환하는 함수
/// 사용 예시
/// Random::Chance(30); // 30% 확률로 true 반환, 70% 확률로 false 반환
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