#pragma once
#include <random>

class Random
{
private:
    static std::mt19937 gen;

public:
/// min ~ max 범위의 랜덤 정수값을 반환하는 함수 
/// 사용 예시
/// Random::Range(1, 10); // 1 ~ 10 사이의 랜덤값 반환
    static int Range(int min, int max);
    
/// percent(%)의 확률로 true를 반환하는 함수
/// 사용 예시
/// Random::Chance(30); // 30% 확률로 true 반환, 70% 확률로 false 반환
    static bool Chance(int percent);
};
