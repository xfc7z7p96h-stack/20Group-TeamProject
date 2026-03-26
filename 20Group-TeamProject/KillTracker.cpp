#include "KillTracker.h"
#include "Logger.h"

/*
    static 멤버 변수 정의.

*/
std::map<std::string, int> KillTracker::killCount;


/*
    KillTracker::AddKill
    --------------------------------------------------
    몬스터 처치 시 호출되는 함수.

    동작 과정:
    1. 해당 몬스터의 처치 횟수를 증가시킨다.
    2. Logger를 통해 처치 로그를 출력한다.
*/
void KillTracker::AddKill(const std::string& monsterName)
{
    // monsterName 키가 없으면 자동 생성 후 0으로 초기화
    // 이후 1 증가
    killCount[monsterName]++;

    // 처치 로그 출력
    Logger::Log("[KILL] " + monsterName + " 처치!");
}


/*
    KillTracker::PrintSummary
    --------------------------------------------------
    현재까지 기록된 모든 몬스터 처치 정보를
    보기 쉬운 형태로 콘솔에 출력한다.

    주 사용 시점:
    - 던전 종료
    - 전투 종료
    - 게임 결과 화면
*/
void KillTracker::PrintSummary()
{
    Logger::Line();
    Logger::Log("전투 결과 요약");

    for (const auto& pair : killCount)
    {
        /*
            pair.first  -> 몬스터 이름
            pair.second -> 처치 횟수
        */
        Logger::Log(pair.first + " : "
            + std::to_string(pair.second) + "마리 처치");
    }

    Logger::Line();
}