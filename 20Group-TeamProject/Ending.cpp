#include "Ending.h"
#include "Logger.h"
#include <conio.h>
#include <cstdlib>

namespace Ending
{
    // =========================
    // BAD ENDING
    // =========================
    void StarvationEnding()
    {
        system("cls");

        Logger::TypeLine("옥상 문을 밀어 올렸다.", 30);
        Logger::TypeLine("녹슨 철문이 끼익 소리를 내며 열린다.", 35);
        Logger::TypeLine("차가운 밤공기가 폐 깊숙이 파고든다.", 35);

        Logger::TypeLine("", 15);

        Logger::TypeLine("라쿤 시티.", 40);
        Logger::TypeLine("불빛은 거의 꺼졌고, 거리에는 아무도 없다.", 35);
        Logger::TypeLine("살아있는 것은… 울부짖는 소리뿐이다.", 40);

        Logger::TypeLine("", 20);

        Logger::TypeLine("구조 헬기가 온다고 방송은 말했다.", 35);
        Logger::TypeLine("옥상에서 기다리라고.", 35);

        Logger::TypeLine("", 25);

        Logger::TypeLine("나는 기다렸다.", 45);
        Logger::TypeLine("한 시간.", 45);
        Logger::TypeLine("두 시간.", 45);
        Logger::TypeLine("그리고 그보다 훨씬 더.", 45);

        Logger::TypeLine("", 20);

        Logger::TypeLine("가방을 뒤졌다.", 35);
        Logger::TypeLine("부스러기 하나 남지 않은 빵 봉지.", 35);
        Logger::TypeLine("텅 빈 물통.", 35);

        Logger::TypeLine("", 20);

        Logger::TypeLine("배고픔은 고통이었다.", 35);
        Logger::TypeLine("하지만 시간이 지나자…", 40);
        Logger::TypeLine("그저 아무 감각도 남지 않았다.", 45);

        Logger::TypeLine("", 20);

        Logger::TypeLine("몸이 점점 무거워진다.", 40);
        Logger::TypeLine("일어나야 한다는 걸 알면서도 움직일 수 없다.", 45);

        Logger::TypeLine("", 20);

        Logger::TypeLine("하늘을 바라본다.", 40);
        Logger::TypeLine("별이 이렇게 많았던가.", 45);

        Logger::TypeLine("", 20);

        Logger::TypeLine("멀리서 헬기 소리 같은 것이 들린다.", 40);
        Logger::TypeLine("…아니, 착각이었을지도 모른다.", 45);

        Logger::TypeLine("", 30);

        Logger::TypeLine("눈을 감는다.", 50);
        Logger::TypeLine("이제 괜찮다.", 55);
        Logger::TypeLine("더 이상 배고프지 않다.", 60);

        Logger::TypeLine("", 30);

        Logger::TypeLine("라쿤 시티의 마지막 밤이 조용히 지나간다.", 40);

        Logger::TypeLine("", 40);
        Logger::TypeLine("[ BAD ENDING - 구조는 오지 않았다 ]", 20);

        _getch();
        exit(0);
    }

    // =========================
    // TRUE ENDING
    // =========================
    void RescueEnding()
    {
        system("cls");

        Logger::TypeLine("옥상에 올라섰다.", 30);
        Logger::TypeLine("문을 닫고 기대자 다리가 풀린다.", 35);
        Logger::TypeLine("여기까지… 살아왔다.", 45);

        Logger::TypeLine("", 20);

        Logger::TypeLine("도시는 불타고 있었다.", 35);
        Logger::TypeLine("어둠 속에서 간헐적으로 터지는 폭발.", 35);
        Logger::TypeLine("라쿤 시티는 이미 끝나가고 있었다.", 40);

        Logger::TypeLine("", 25);

        Logger::TypeLine("가방을 열었다.", 30);
        Logger::TypeLine("남아있는 빵.", 30);
        Logger::TypeLine("그리고 물.", 30);

        Logger::TypeLine("", 15);

        Logger::TypeLine("충분하다.", 45);
        Logger::TypeLine("조금만 더 버티면 된다.", 40);

        Logger::TypeLine("", 25);

        Logger::TypeLine("시간이 흐른다.", 40);
        Logger::TypeLine("좀비들의 울음소리도 점점 멀어진다.", 40);

        Logger::TypeLine("", 20);

        Logger::TypeLine("그리고.", 50);

        Logger::TypeLine("", 20);

        Logger::TypeLine("두두두두두두...", 20);
        Logger::TypeLine("공기가 진동한다.", 30);

        Logger::TypeLine("", 15);

        Logger::TypeLine("고개를 들었다.", 35);
        Logger::TypeLine("하늘 위, 탐조등.", 30);

        Logger::TypeLine("", 20);

        Logger::TypeLine("헬기다.", 20);

        Logger::TypeLine("", 25);

        Logger::TypeLine("빛이 나를 비춘다.", 35);
        Logger::TypeLine("누군가 손을 흔든다.", 35);

        Logger::TypeLine("", 20);

        Logger::TypeLine("살아남았다.", 55);

        Logger::TypeLine("", 25);

        Logger::TypeLine("사다리가 내려온다.", 35);
        Logger::TypeLine("손을 뻗는다.", 40);
        Logger::TypeLine("이번에는 놓치지 않는다.", 45);

        Logger::TypeLine("", 30);

        Logger::TypeLine("헬기가 떠오른다.", 35);
        Logger::TypeLine("점점 멀어지는 라쿤 시티가 보였다.", 35);

        Logger::TypeLine("", 20);

        Logger::TypeLine("지옥에서 빠져나왔다.", 45);

        Logger::TypeLine("", 40);
        Logger::TypeLine("[ TRUE ENDING - 라쿤 시티 탈출 ]", 20);

        _getch();
        exit(0);
    }
}