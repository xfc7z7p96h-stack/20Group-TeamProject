#include "Intro.h"
#include "Logger.h"
#include <thread>
#include <chrono>

void Intro::Play()
{
    using namespace std;

    Logger::Line();
    Logger::Log("...");
    this_thread::sleep_for(chrono::seconds(1));

    Logger::Log("당신은 눈을 뜹니다.");
    this_thread::sleep_for(chrono::seconds(2));

    Logger::Log("여기는 라쿤 시티.");
    this_thread::sleep_for(chrono::seconds(2));

    Logger::Log("이미 죽은 도시입니다.");
    this_thread::sleep_for(chrono::seconds(2));

    Logger::Space();
    Logger::Log("사방에는 엄브렐라 사가 만들어낸 좀비들이 배회하고 있습니다.");
    this_thread::sleep_for(chrono::seconds(2));

    Logger::Log("비명, 총성, 그리고 무언가를 씹는 소리.");
    this_thread::sleep_for(chrono::seconds(2));

    Logger::Space();
    Logger::Log("그때.");
    this_thread::sleep_for(chrono::seconds(1));

    Logger::Log("저 멀리 건물 옥상 위로 헬리콥터 한 대가 착륙하는 것이 보입니다.");
    this_thread::sleep_for(chrono::seconds(2));

    Logger::Space();
    Logger::Log("헬리콥터.");
    this_thread::sleep_for(chrono::seconds(1));

    Logger::Log("당신이 이 도시에서 살아 나갈 수 있는 유일한 수단일지도 모릅니다.");
    this_thread::sleep_for(chrono::seconds(2));

    Logger::Space();
    Logger::Log("그런데, 헬리콥터 소리에 몰려든 좀비가 당신을 확인하고 달려들기 시작했습니다.");
    this_thread::sleep_for(chrono::seconds(2));

    Logger::Log("지체할 시간이 없습니다.");
    this_thread::sleep_for(chrono::seconds(1));

    Logger::Log("당신은 서둘러 움직여야 했습니다.");

    Logger::Line();
}