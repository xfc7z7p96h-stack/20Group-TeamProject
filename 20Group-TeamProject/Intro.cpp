#include "Intro.h"
#include "Logger.h"
#include <iostream>
#include <thread>
#include <chrono>


//////////////////////////////////////////////////
// 인트로
//////////////////////////////////////////////////
void PlayIntro()
{
    Logger::Line();
    Logger::TypeLine("           BIOHAZARD : RACCOON CITY", 20);
    Logger::Line();
    Logger::Space();

    Logger::TypeLine("[1998년 9월 29일]", 25);
    Logger::TypeLine("미국 중서부, 라쿤 시티.", 25);
    Logger::Space();

    Logger::TypeLine("평범한 하루였어야 했다.");
    Logger::TypeLine("야근을 마치고 집으로 돌아가");
    Logger::TypeLine("TV를 켜고 잠들었어야 할 그런 밤.");
    Logger::Space();

    Logger::TypeLine("하지만 거리에는 이미 사람들이 없었다.");
    Logger::TypeLine("버려진 경찰차, 깨진 유리창.");
    Logger::TypeLine("어딘가에서 들려오는 비명...");
    Logger::Space();

    std::this_thread::sleep_for(std::chrono::milliseconds(600));

    Logger::TypeLine("뉴스는 폭동이라고 말했다.");
    Logger::TypeLine("전염병이라고도 했다.");
    Logger::TypeLine("...하지만 그건 아니었다.");
    Logger::Space();

    Logger::TypeLine("총에 맞고도 다시 일어나는 사람.");
    Logger::TypeLine("사람을 물어뜯는 사람.");
    Logger::Space();

    std::this_thread::sleep_for(std::chrono::milliseconds(800));

    Logger::TypeLine("도시는 이미 끝나가고 있었다.");
    Logger::Space();

    Logger::TypeLine("밖에서 문을 두드리는 소리가 들린다.");
    Logger::TypeLine("천천히.");
    Logger::TypeLine("끈질기게.");
    Logger::Space();

    Logger::TypeLine("...살아남아야 한다.", 40);
    Logger::Space();

    Logger::Line();
    Logger::Log(">>      ENTER 키를 눌러 게임을 시작하세요.");
    Logger::Line();

    std::cin.get();
}