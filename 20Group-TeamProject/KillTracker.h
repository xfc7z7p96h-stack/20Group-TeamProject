#pragma once
#include <string>
#include <map>

/*
    KillTracker
    --------------------------------------------------
    몬스터 처치 기록을 관리하는 클래스.

    역할:
    - 몬스터가 죽을 때마다 처치 횟수를 저장
    - 전투 종료 시 어떤 몬스터를 얼마나 잡았는지
      한 눈에 확인 가능한 요약 로그 출력

    Logger는 "출력"만 담당하고,
    KillTracker는 "기록"을 담당한다.
*/
class KillTracker
{
public:

    /*
        AddKill
        --------------------------------------------------
        몬스터 처치 시 호출되는 함수.

        매개변수:
            monsterName - 처치한 몬스터 이름

        기능:
        - 해당 몬스터의 처치 횟수를 +1 증가
        - 처치 로그를 콘솔에 출력
    */
    static void AddKill(const std::string& monsterName);

    /*
        PrintSummary
        --------------------------------------------------
        현재까지 기록된 몬스터 처치 결과를
        콘솔에 요약 형태로 출력한다.

        던전 종료 또는 전투 종료 시 호출한다.
    */
    static void PrintSummary();

private:

    /*
        killCount
        --------------------------------------------------
        몬스터 이름과 처치 횟수를 저장하는 컨테이너.

        key   : 몬스터 이름 (string)
        value : 처치 횟수 (int)

        예:
            "Goblin" -> 3
            "Slime"  -> 5
    */
    static std::map<std::string, int> killCount;
};