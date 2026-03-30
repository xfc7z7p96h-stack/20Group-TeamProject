#include "Game.h"
#include "Logger.h"
#include "Intro.h"
#include "Battle.h"
#include "Inventory.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cctype>

Game::Game()
{
    inventoryOpen = false;

    CurrentPlace = "라쿤 시티의 한 건물 앞";
    CurrentFloor = 0;
    chaincutter = false;
    firstfloorclear = false;
    secretRoom = false;
    secretRoomQuest = false;
    secretRoomKey = false;
    corridorCount = 0;
    storageCount = 0;
    corridorEndCount = 0;

    CurrentRoom = ROOM_OUTSIDE;
    FirstFloorIntro = false;
    SecondFloorIntro = false;
    ThirdFloorIntro = false;

	archivePuzzle = false;
	isolationRoomitem = false;
	isolationRoomitem2 = false;
	archiveitem = false;
	sergeryRoomitem = false;
    sergeryRoomCount = 0;
    Opened = false;
    fuse = false;
}

void Game::ControlRoomPuzzle()
{
    if (Opened == true)
    {
        Logger::Log("이미 열려 있는 금고다.\n");
        Logger::Log("\n(아무 키나 누르세요)\n");
        return;
    }

    const int dialMin = 0;
    const int dialMax = 15;

    int cursor = 0;
    int stage = 1;
    char input;
    char lastMove = '\0';

    while (true)
    {
        system("cls");

        Logger::Log("감시실 깊숙한 구석에 작은 금고가 하나 놓여있다.\n");
        Logger::Log("[A] 왼쪽 이동   [D] 오른쪽 이동   [E] 확정   [Q] 나가기\n\n");

        std::cout << "----------------------------------------------------------------" << '\n';

        for (int i = dialMin; i <= dialMax; ++i)
        {
            if (i == cursor)
            {
                std::cout << " ▼ ";
            }
            else
            {
                std::cout << "    ";
            }
        }
        std::cout << '\n';

        for (int i = dialMin; i <= dialMax; ++i)
        {
            if (i < 10)
            {
                std::cout << " 0" << i << " ";
            }
            else
            {
                std::cout << " " << i << " ";
            }
        }
        std::cout << '\n';

        std::cout << "----------------------------------------------------------------" << '\n';

        input = _getch();

        if (input == 'q' || input == 'Q')
        {
            return;
        }
        else if (input == 'a' || input == 'A')
        {
            if (cursor == dialMin)
            {
                cursor = dialMax;
            }
            else
            {
                --cursor;
            }

            lastMove = 'A';
        }
        else if (input == 'd' || input == 'D')
        {
            if (cursor == dialMax)
            {
                cursor = dialMin;
            }
            else
            {
                ++cursor;
            }

            lastMove = 'D';
        }
        else if (input == 'e' || input == 'E')
        {
            if (stage == 1)
            {
                if (cursor == 7 && lastMove == 'A')
                {
                    lastMove = '\0';
                    stage = 2;
                }
                else
                {
                    Logger::Log("\n틀린 것 같다...\n");
                    Logger::Log("\n(아무 키나 누르세요)\n");
                    return;
                }
            }
            else if (stage == 2)
            {
                if (cursor == 12 && lastMove == 'D')
                {
                    lastMove = '\0';
                    stage = 3;
                }
                else
                {
                    Logger::Log("\n틀린 것 같다...\n");
                    Logger::Log("\n(아무 키나 누르세요)\n");
                    return;
                }
            }
            else if (stage == 3)
            {
                if (cursor == 3 && lastMove == 'A')
                {
                    Opened = true;
                    fuse = true;

                    Logger::Log("\n'철컥'\n");
                    Logger::Log("금고 안쪽에서 잠금장치가 풀리는 소리가 울린다.\n");
                    Logger::Log("[ 퓨즈 ] 획득\n");
                    Logger::Log("\n(아무 키나 누르세요)\n");
                    return;
                }
                else
                {
                    Logger::Log("\n틀린 것 같다...\n");
                    _getch();
                    return;
                }
            }
        }
    }
}

void Game::ArchivePuzzle()
{
    std::string inputCode = "";
    const std::string correctCode = "4132";

    while (true)
    {
        system("cls");

        Logger::Log("[ 환자 이송 우선순위 단말기 ]\n");
        Logger::Log("사망이 임박한 순서대로 대상 병상을 지정하시오.\n");
        Logger::Log("'폐쇄수술실'은 수용 인원이 제한적이라 정확한 우선순위 등록이 필요합니다.\n");
        Logger::Space();
        Logger::Log("4자리 번호를 입력하세요. 단말기 종료 [ Q ]\n");
        Logger::Log("입력 : " + inputCode + "\n");

        char key = _getch();
        key = std::tolower(static_cast<unsigned char>(key));

        if (key == 'q')
        {
            break;
        }

        if (key >= '0' && key <= '9')
        {
            if (inputCode.size() < 4)
            {
                inputCode += key;
            }
        }
        else if (key == 8)
        {
            if (!inputCode.empty())
            {
                inputCode.pop_back();
            }
        }

        if (inputCode.size() == 4)
        {
            system("cls");

            Logger::Log("[ 환자 이송 우선순위 단말기 ]\n");
            Logger::Log("입력값 : " + inputCode + "\n\n");

            if (inputCode == correctCode)
            {
                archivePuzzle = true;
                Logger::Log("철컥, 어딘가에서 문이 열리는 소리가 들린다.\n");
                _getch();
                
                return;
            }
            else
            {
                Logger::Log("우선순위가 일치하지 않습니다.\n");
                Logger::Log("다시 입력하십시오.\n");
                _getch();

                inputCode = "";
            }
        }
    }
}

void Game::ShowHelp()
{
    Logger::Log("새로운 방이나 다른 층 진입 시, 일정 확률로 살아있는 시체와 마주하게 됩니다.");
    Logger::Log("근접 공격은 횟수에 제한이 없지만, 당신은 반드시 반격을 당하게 됩니다.");
    Logger::Log("권총 또는 샷건으로 공격 시 총알을 소비하지만 반격은 당하지 않습니다.");
    Logger::Log("싸울지 도망칠지는 당신의 몫입니다.\n");
    Logger::Log("(아무 키나 누르세요.)");
    _getch();
}

void Game::ShowStatus()
{
    Logger::Line();
    std::cout << "현재 위치 : " << CurrentPlace << "\n";
    std::cout << "[W][S][A][D] 이동 [E] 방 조사 [I] 인벤토리 [H] 도움말\n";
    Logger::Line();
    Logger::Space();
}

void Game::Run()
{
    // PlayIntro();

    bool gameRunning = true;

    while (gameRunning)
    {
        //// 비밀방 퀘스트 완료 조건///////
        if (corridorCount == 8 && storageCount == 4 && corridorEndCount == 6)
        {
            secretRoom = true;
        }
        else
        {
			secretRoom = false;
        }

        ////////////////////////////////
        switch (CurrentRoom)
        {
        case ROOM_OUTSIDE:
            CurrentFloor = 0;
            CurrentPlace = "라쿤 시티의 한 건물 앞";
            break;

        case ROOM_FIRSTFLOOR_CORRIDOR:
            CurrentFloor = 1;
            CurrentPlace = "건물 1층 [ 복도 ]";
            break;

        case ROOM_FIRSTFLOOR_STORAGE:
            CurrentFloor = 1;
            CurrentPlace = "건물 1층 [ 창고 ]";
            break;

        case ROOM_FIRSTFLOOR_CORRIDOREND:
            CurrentFloor = 1;
            CurrentPlace = "건물 1층 [ 복도 끝 ]";
            break;

        case ROOM_SECONDFLOOR_LOBBY:
            CurrentFloor = 2;
            CurrentPlace = "건물 2층 [ 로비 ]";
            break;

        case ROOM_SECONDFLOOR_RESTROOM:
            CurrentFloor = 2;
            CurrentPlace = "건물 2층 [ 화장실 ]";
            break;

        case ROOM_SECONDFLOOR_MEETINGROOM:
            CurrentFloor = 2;
            CurrentPlace = "건물 2층 [ 미팅룸 ]";
            break;

        case ROOM_SECONDFLOOR_SECRETROOM:
            CurrentFloor = 2;
            CurrentPlace = "건물 2층 [ 비밀방 ]";
            break;

        case ROOM_THIRDFLOOR_MAINHALL:
            CurrentFloor = 3;
            CurrentPlace = "건물 3층 [ 메인 홀 ]";
            break;

        case ROOM_THIRDFLOOR_ISOLATIONROOM:
            CurrentFloor = 3;
            CurrentPlace = "건물 3층 [ 격리병실 ]";
            break;

        case ROOM_THIRDFLOOR_SURGERYROOM:
            CurrentFloor = 3;
            CurrentPlace = "건물 3층 [ 폐쇄수술실 ]";
            break;

        case ROOM_THIRDFLOOR_ARCHIVE:
            CurrentFloor = 3;
            CurrentPlace = "건물 3층 [ 기록실 ]";
            break;

        case ROOM_THIRDFLOOR_CONTROLROOM:
            CurrentFloor = 3;
            CurrentPlace = "건물 3층 [ 감시실 ]";
            break;

        case ROOM_THIRDFLOOR_GENERATORROOM:
            CurrentFloor = 3;
            CurrentPlace = "건물 3층 [ 비상발전실 ]";
            break;
        }

        system("cls");
        ShowStatus();

        switch (CurrentRoom)       ///////////////////////////////////// 지도
        {
        case ROOM_OUTSIDE:
            Logger::Log("나는 좀비를 피해 도망치기 시작했다.");
            Logger::Space();
            Logger::Log("숨이 차오르는 와중에 시야에 한 건물이 들어왔다.");
            Logger::Space();
            Logger::Log("'들어가야한다.'");
            Logger::Space();
            Logger::Log("내 본능이 그렇게 말하고 있었다.");
            Logger::Space();
            Logger::Log("( [W] 건물에 들어간다. )\n");
            break;

        case ROOM_FIRSTFLOOR_CORRIDOR:
            Logger::Log("          창 고     ");
            Logger::Log("            ↑      ");
            Logger::Log("            |      ");
            Logger::Log("입구  ←  ▶ 복도  →  복도끝");
            Logger::Log("                     |");
            Logger::Log("                     ↓");
            Logger::Log("                    2층");
            break;

        case ROOM_FIRSTFLOOR_STORAGE:
            Logger::Log("        ▶ 창 고     ");
            Logger::Log("            |      ");
            Logger::Log("            ↓      ");
            Logger::Log("입구  ←    복도  →  복도끝");
            Logger::Log("                     |");
            Logger::Log("                     ↓");
            Logger::Log("                    2층");
            break;

        case ROOM_FIRSTFLOOR_CORRIDOREND:
            Logger::Log("          창 고     ");
            Logger::Log("            ↑      ");
            Logger::Log("            |      ");
            Logger::Log("입구  ←    복도  ← ▶복도끝");
            Logger::Log("                     |");
            Logger::Log("                     ↓");
            Logger::Log("                    2층");
            break;

        case ROOM_SECONDFLOOR_LOBBY:
            if (secretRoom == false)
            {
                Logger::Log("            1층           ");
                Logger::Log("             ↑              ");
                Logger::Log("             |             ");
                Logger::Log(" 화장실  ← ▶로비  →  미팅룸    ");
                Logger::Log("             |              ");
                Logger::Log("             ↓");
                Logger::Log("            3층");
            }
            else
            {
                Logger::Log("            1층      비밀방    ");
                Logger::Log("             ↑         ↑      ");
                Logger::Log("             |         |      ");
                Logger::Log(" 화장실  ← ▶로비  →  미팅룸    ");
                Logger::Log("             |              ");
                Logger::Log("             ↓");
                Logger::Log("            3층");
            }
            break;

        case ROOM_SECONDFLOOR_RESTROOM:
            if (secretRoom == false)
            {
                Logger::Log("            1층           ");
                Logger::Log("             ↑              ");
                Logger::Log("             |             ");
                Logger::Log("▶화장실  →  로비  →  미팅룸    ");
                Logger::Log("             |              ");
                Logger::Log("             ↓");
                Logger::Log("            3층");
            }
            else
            {
                Logger::Log("            1층      비밀방    ");
                Logger::Log("             ↑         ↑      ");
                Logger::Log("             |         |      ");
                Logger::Log("▶화장실  →  로비  →  미팅룸    ");
                Logger::Log("             |              ");
                Logger::Log("             ↓");
                Logger::Log("            3층");
            }
            break;

        case ROOM_SECONDFLOOR_MEETINGROOM:
            if (secretRoom == false)
            {
                Logger::Log("            1층           ");
                Logger::Log("             ↑              ");
                Logger::Log("             |             ");
                Logger::Log(" 화장실  ←  로비  ← ▶미팅룸    ");
                Logger::Log("             |              ");
                Logger::Log("             ↓");
                Logger::Log("            3층");
            }
            else
            {
                Logger::Log("            1층      비밀방    ");
                Logger::Log("             ↑         ↑      ");
                Logger::Log("             |         |      ");
                Logger::Log(" 화장실  ←  로비  ← ▶미팅룸    ");
                Logger::Log("             |              ");
                Logger::Log("             ↓");
                Logger::Log("            3층");
            }
            break;

        case ROOM_SECONDFLOOR_SECRETROOM:
            Logger::Log("            1층     ▶비밀방    ");
            Logger::Log("             ↑         ↑      ");
            Logger::Log("             |         |      ");
            Logger::Log(" 화장실  ←  로비  ←  미팅룸    ");
            Logger::Log("             |              ");
            Logger::Log("             ↓");
            Logger::Log("            3층");
            break;

        case ROOM_THIRDFLOOR_MAINHALL:
            Logger::Log("                 2층       엘리베이터    ");
            Logger::Log("                  ↑            ↑       ");
            Logger::Log("                  |            |       ");
            Logger::Log(" 기록보관실  ← ▶메인홀  x  비상발전실    ");
            Logger::Log("     |            |                   ");
            Logger::Log("     ↓            ↓                    ");
            Logger::Log("   감시실   ←  격리병실");
            Logger::Log("                  |    ");
            Logger::Log("                  ↓    ");
            Logger::Log("              폐쇄수술실");
            break;

        case ROOM_THIRDFLOOR_SURGERYROOM:
            Logger::Log("                 2층       엘리베이터    ");
            Logger::Log("                  ↑            ↑       ");
            Logger::Log("                  |            |       ");
            Logger::Log(" 기록보관실  ←  메인홀  x  비상발전실    ");
            Logger::Log("     |            ↑                   ");
            Logger::Log("     ↓            |                    ");
            Logger::Log("   감시실   ←  격리병실");
            Logger::Log("                  ↑    ");
            Logger::Log("                  |    ");
            Logger::Log("             ▶폐쇄수술실");
            break;

        case ROOM_THIRDFLOOR_GENERATORROOM:
            Logger::Log("                 2층       엘리베이터    ");
            Logger::Log("                  ↑            ↑       ");
            Logger::Log("                  |            |       ");
            Logger::Log(" 기록보관실  ←  메인홀  x ▶비상발전실    ");
            Logger::Log("     |            |                   ");
            Logger::Log("     ↓            ↓                    ");
            Logger::Log("   감시실   ←  격리병실");
            Logger::Log("                  |    ");
            Logger::Log("                  ↓    ");
            Logger::Log("              폐쇄수술실");
            break;

        case ROOM_THIRDFLOOR_ARCHIVE:
            Logger::Log("                 2층       엘리베이터    ");
            Logger::Log("                  ↑            ↑       ");
            Logger::Log("                  |            |       ");
            Logger::Log("▶기록보관실  →  메인홀  x  비상발전실    ");
            Logger::Log("     |            |                   ");
            Logger::Log("     ↓            ↓                    ");
            Logger::Log("   감시실   ←  격리병실");
            Logger::Log("                  |    ");
            Logger::Log("                  ↓    ");
            Logger::Log("              폐쇄수술실");
            break;

        case ROOM_THIRDFLOOR_CONTROLROOM:
            Logger::Log("                 2층       엘리베이터    ");
            Logger::Log("                  ↑            ↑       ");
            Logger::Log("                  |            |       ");
            Logger::Log(" 기록보관실  ←  메인홀  x  비상발전실    ");
            Logger::Log("     ↑            |                   ");
            Logger::Log("     |            ↓                    ");
            Logger::Log("  ▶감시실   →  격리병실");
            Logger::Log("                  |    ");
            Logger::Log("                  ↓    ");
            Logger::Log("              폐쇄수술실");
            break;

        case ROOM_THIRDFLOOR_ISOLATIONROOM:
            Logger::Log("                 2층       엘리베이터    ");
            Logger::Log("                  ↑            ↑       ");
            Logger::Log("                  |            |       ");
            Logger::Log(" 기록보관실  ←  메인홀  x  비상발전실    ");
            Logger::Log("     |            ↑                   ");
            Logger::Log("     ↓            |                    ");
            Logger::Log("   감시실   ← ▶격리병실");
            Logger::Log("                  |    ");
            Logger::Log("                  ↓    ");
            Logger::Log("              폐쇄수술실");
            break;

        }
        if (secretRoomQuest)
        {
            Logger::Space();
            Logger::Log("창고 : " + std::to_string(storageCount));
            Logger::Log("복도 : " + std::to_string(corridorCount));
            Logger::Log("복도 끝 : " + std::to_string(corridorEndCount));
			Logger::Space();
        }

        if (inventoryOpen)
        {
            system("cls");
            inven.OpenInventory(player);
            inventoryOpen = false;
            continue;
        }

        char Input = _getch();
        Input = std::tolower(Input);

        system("cls");

        switch (CurrentRoom)  //////////////////////////////////////////////이동
        {
        case ROOM_OUTSIDE:
            switch (Input)
            {
            case 'w':
                if (FirstFloorIntro == false)
                {
                    Logger::Log("건물 안으로 겨우 들어왔다. 다리가 후들거리고 있었다.");
                    Logger::Space();
                    Logger::Log("\"씨발!\"");
                    Logger::Space();
                    Logger::Log("약간 긴장이 풀리자 이 어처구니 없는 상황에 욕짓거리가 튀어나왔다.");
                    Logger::Space();
                    Logger::Log("하지만, 이렇게 손놓고 있을 시간은 없다. 나는 주위를 둘러보았다.");
                    Logger::Space();
                    Logger::Log("긴 복도 천장에 일렬로 늘어져 있는 전등은 금방이라도 꺼질 듯 깜빡거렸다.");
                    Logger::Space();
                    Logger::Log("기분 탓인지는 모르겠지만 나 말고 다른 사람도 이 건물에 있는 것 같은 느낌이 들었다. 정말 '사람'인지는 모르겠지만...");
                    Logger::Space();
                    Logger::Log("끔찍한 생각을 떨쳐내고 주변을 둘러본다.");
                    Logger::Space();
                    Logger::Log("무언가가 눈에 들어왔다.");
                    Logger::Space();
                    Logger::Log("'지도...?'");
                    Logger::Space();
                    Logger::Log("나는 벽에 붙어있던 건물 지도를 챙겼다.");
                    Logger::Log("(아무 키나 누르세요.)");
                    _getch();
                    FirstFloorIntro = true;
                }

                CurrentFloor = 1;
                CurrentRoom = ROOM_FIRSTFLOOR_CORRIDOR;
                break;

            default:
                Logger::Log("사방에는 좀비 떼가 들끓고 있다. 여기서 건물 안으로 들어가는 것 외에는 다른 선택지가 없다...(아무 키나 누르세요)\n");
                _getch();
                break;
            }
            break;

        case ROOM_FIRSTFLOOR_CORRIDOR:
            switch (Input)
            {
            case 'i':
				inventoryOpen = true;
			    break;

            case 'h':
                ShowHelp();
                break;

            case 'e':
                if (secretRoomQuest == true)
                {
                    ++corridorCount;
                }
                Logger::Log("딱히 눈에 띄는 것은 없다.\n");
                Logger::Log("(아무 키나 누르세요.)");
                _getch();
                break;

            case 'w':
                CurrentRoom = ROOM_FIRSTFLOOR_STORAGE;
                break;

            case 's':
                Logger::Log("뒤에는 벽이 있다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
                break;

            case 'a':
                Logger::Log("문은 단단히 잠궈놨다. 외부로부터의 침입은 걱정하지 않아도 될 것 같다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
                break;

            case 'd':
                CurrentRoom = ROOM_FIRSTFLOOR_CORRIDOREND;
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;

        case ROOM_FIRSTFLOOR_STORAGE:
            switch (Input)
            {
            case 'i':
                inventoryOpen = true;
                break;

            case 'h':
                ShowHelp();
                break;

            case 'e':
                if (secretRoomQuest == true)
                {
                    ++storageCount;
                    Logger::Log("딱히 눈에 띄는 것은 없다.\n");
                }
                else if (chaincutter == false)
                {
                    Logger::Log("체인 커터를 발견했다. 녹이 좀 슬었지만 어딘가 쓸 곳이 있을 것 같다.\n");
                    chaincutter = true;
                }
                else if (secretRoomQuest == false)
                {
                    Logger::Log("딱히 눈에 띄는 것은 없다.\n");
                }

                Logger::Log("(아무 키나 누르세요.)");
                _getch();
                break;

            case 'w':
                Logger::Log("공구들이 아무렇게나 널부러져 있다. 대부분 못 쓸 것처럼 보인다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
                break;

            case 's':
                CurrentRoom = ROOM_FIRSTFLOOR_CORRIDOR;
                break;

            case 'a':
                Logger::Log("공구들이 아무렇게나 널부러져 있다. 대부분 못 쓸 것처럼 보인다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
                break;

            case 'd':
                Logger::Log("공구들이 아무렇게나 널부러져 있다. 대부분 못 쓸 것처럼 보인다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;

        case ROOM_FIRSTFLOOR_CORRIDOREND:
            switch (Input)
            {
            case 'i':
                inventoryOpen = true;
                break;

            case 'h':
                ShowHelp();
                break;

            case 'e':
                if (secretRoomQuest == true)
                {
                    ++corridorEndCount;
                }

                Logger::Log("딱히 눈에 띄는 것은 없다.\n");
                Logger::Log("(아무 키나 누르세요.)");
                _getch();
                break;

            case 'w':
                Logger::Log("벽에 검붉은 얼룩이 곳곳에 묻어있다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
                break;

            case 's':
                if (firstfloorclear == true)
                {
                    CurrentFloor = 2;
                    CurrentRoom = ROOM_SECONDFLOOR_LOBBY;
                }
                else if (chaincutter == true)
                {
                    firstfloorclear = true;
                    CurrentFloor = 2;

                    if (SecondFloorIntro == false)
                    {
                        Logger::Log("쇠사슬을 끊어낸 뒤, 무거운 철문을 천천히 밀어 열었다.");
                        Logger::Space();
                        Logger::Log("2층으로 올라서자마자 코를 찌르는 악취가 훨씬 짙어졌다.");
                        Logger::Space();
                        Logger::Log("썩은 살점과 소독약 냄새가 뒤섞여 숨이 턱 막혀온다.");
                        Logger::Space();
                        Logger::Log("어딘가에서 낮고 기이한 신음소리가 길게 울렸다.");
                        Logger::Space();
                        Logger::Log("\"크르르륵...\"");
                        Logger::Space();
                        Logger::Log("곧이어, 살점이 바닥을 질질 끄는 듯한 소리가 끝에서 들려왔다.");
                        Logger::Space();
                        Logger::Log("등골을 타고 식은땀이 천천히 흘러내렸다.");
                        Logger::Space();
                        Logger::Log("(아무 키나 누르세요)");
                        _getch();
                        SecondFloorIntro = true;
                    }

                    CurrentRoom = ROOM_SECONDFLOOR_LOBBY;
                }
                else
                {
                    Logger::Log("2층으로 가는 계단은 철문으로 막혀있다. 손잡이쪽의 쇠사슬을 끊으면 열 수 있을 것 같다.\n");
                    Logger::Log("(아무 키나 누르세요.)");
                    _getch();
                }
                break;

            case 'a':
                CurrentRoom = ROOM_FIRSTFLOOR_CORRIDOR;
                break;

            case 'd':
                Logger::Log("벽에 검붉은 얼룩이 곳곳에 묻어있다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;

        case ROOM_SECONDFLOOR_LOBBY:
            switch (Input)
            {
            case 'i':
                inventoryOpen = true;
                break;

            case 'h':
                ShowHelp();
                break;

            case 'e':
                Logger::Log("넓은 로비의 중앙에 큰 원기둥이 천장을 받히고 있다.\n");
                Logger::Log("'무한대를 일으켜'라는 문장과 함께 [ ∞ ] 모양의 기호가 그려져 있다.\n");
                Logger::Log("(아무 키나 누르세요.)");
                _getch();
                break;

            case 'w':
                CurrentFloor = 1;
                CurrentRoom = ROOM_FIRSTFLOOR_CORRIDOREND;
                break;

            case 's':
                if (secretRoomKey == false)
                {
                    Logger::Log("문이 있지만 당연하게도 잠겨있다..열쇠가 필요하다.\n");
                    Logger::Log("(아무 키나 누르세요)");
                    _getch();
                }
				else if (ThirdFloorIntro == false)
                {
                    
                    Logger::Log("열쇠로 문을 열었다.\n");
                    Logger::Log("3층으로 향하는 계단은 나선형으로 되어 있었다.\n");
                    Logger::Log("이대로 윗층으로 계속 가는 게 맞는 일인지 모르겠다.\n");
                    Logger::Log("그저...희망을 찾고 싶을 뿐일지도 모른다.\n");
                    Logger::Log("\n(아무 키나 누르세요)");
                    ThirdFloorIntro = true;
                    _getch();
                    CurrentRoom = ROOM_THIRDFLOOR_MAINHALL;
                }
                else
                {
                    CurrentFloor = 3;
                    CurrentRoom = ROOM_THIRDFLOOR_MAINHALL;
				}
                break;

            case 'a':
                CurrentRoom = ROOM_SECONDFLOOR_RESTROOM;
                break;

            case 'd':
                CurrentRoom = ROOM_SECONDFLOOR_MEETINGROOM;
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;

        case ROOM_SECONDFLOOR_RESTROOM:
            switch (Input)
            {
            case 'i':
                inventoryOpen = true;
                break;

            case 'h':
                ShowHelp();
                break;

            case 'e':    ///////////////////////화장실에서 빵 발견
                Logger::Log("쓰레기통에서 포장된 빵을 발견했다.\n");                  
                Logger::Log("찝찝하지만 먹을 수 있을 것 같다....\n");
                Logger::Log("(아무 키나 누르세요.)");
                _getch();
                break;

            case 'w':
                Logger::Log("먼지 쌓인 세면대와 거칠게 금이 간 거울이 보인다.\n");
                Logger::Log("깨진 거울 조각에 'int* Ptrtox;' 가 써져있다. \n");
                Logger::Log("세면대 한 쪽 구석에 '64'가 쓰여있다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
                break;

            case 's':
                Logger::Log("좌변기와 칸막이가 보인다. 문짝은 너덜너덜해진 채로 바닥에 넣부러져있다.\n");
                Logger::Log("칸막이 안으로 들어가 살펴본다.\n");
                Logger::Log("왼쪽 칸막이에 'int* arr[4];' 가 쓰여있다.\n");
                Logger::Log("맞은편 칸막이에 '64' 가 쓰여있다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
                break;

            case 'a':
                Logger::Log("벽에 '[S] / [W] = byte?' 라는 알 수 없는 문자가 써있다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
                break;

            case 'd':
                CurrentRoom = ROOM_SECONDFLOOR_LOBBY;
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;

        case ROOM_SECONDFLOOR_MEETINGROOM:
            switch (Input)
            {
            case 'i':
                inventoryOpen = true;
                break;

            case 'h':
                ShowHelp();
                break;

            case 'e':
                Logger::Log("이상하리만치 고요한 방이다.\n");
                Logger::Log("이 방 어딘가에서 이상한 소리가 들리는 것 같다.\n");
                Logger::Log("(아무 키나 누르세요.)");
                _getch();
                break;

            case 'w':
                if (secretRoom == false)
                {
                    storageCount = 0;
                    corridorCount = 0;
                    corridorEndCount = 0;

                    secretRoomQuest = true;
                    Logger::Log("벽에 몸을 바짝 붙이고 귀를 대본다.\n");
                    Logger::Log("벽 너머에서 이상한 소리가 들리는 것 같다.\n");
                    Logger::Space();
                    Logger::Log("벽에 붙어있는 종이에 뭔가가 쓰여있다.\n");
                    Logger::Space();
                    Logger::Log("'화장실만큼 창고를 살피고, 로비만큼 복도를 살피고, 미팅룸만큼 복도 끝을 살펴라'\n");
                    Logger::Log("'보이지 않던 길이 보일 것이다'");
                    Logger::Log("(이 글을 보면 초기화)");
                    Logger::Space();
                    Logger::Log("(아무 키나 누르세요)");
                    _getch();
                }
                else
                {
					secretRoomQuest = false;
                    CurrentRoom = ROOM_SECONDFLOOR_SECRETROOM;
                }
                break;

            case 's':
                Logger::Log("딱히 눈에 띄는 건 없다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
                break;

            case 'a':
                CurrentRoom = ROOM_SECONDFLOOR_LOBBY;
                break;

            case 'd':
                Logger::Log("달력을 보니 토요일에 빨간 동그라미가 쳐져있다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;

        case ROOM_SECONDFLOOR_SECRETROOM:
            switch (Input)
            {
            case 'i':
                inventoryOpen = true;
                break;

            case 'h':
                ShowHelp();
                break;

            case 'e':
                if (secretRoomKey == false)
                {
                    secretRoomKey = true;
                    Logger::Log("책상 서랍에서 열쇠를 얻었다.\n");
                }
                else
                {
                    Logger::Log("딱히 눈에 띄는 건 없다.\n");
                }
                _getch();
                break;

            case 's':
                CurrentRoom = ROOM_SECONDFLOOR_MEETINGROOM;
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다. 열쇠를 찾아야 한다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;

        case ROOM_THIRDFLOOR_MAINHALL:
            switch (Input)
            {
            case 'i':
                inventoryOpen = true;
                break;

            case 'h':
                ShowHelp();
                break;

            case 'e':
                Logger::Log("3층의 중앙에 위치한 넓은 홀.\n");
                Logger::Log("꺼져가는 조명과 낡은 벽면, 바닥에 흩어진 파편들이\n");
                Logger::Log("이곳의 음산한 분위기를 더욱 짙게 만든다.\n");
                Logger::Log("여러 구역으로 이어지는 통로가 연결되어 있다.\n");
                Logger::Log("(아무 키나 누르세요.)");
                _getch();
                break;

            case 'w':
                CurrentRoom = ROOM_SECONDFLOOR_LOBBY;
                break;

            case 's':
                CurrentRoom = ROOM_THIRDFLOOR_ISOLATIONROOM;
                break;

            case 'a':
                CurrentRoom = ROOM_THIRDFLOOR_ARCHIVE;
                break;

            case 'd':
                Logger::Log("무너진 잔해로 길이 막혀있다.");
                Logger::Log("(아무 키나 누르세요.)");
                _getch();
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;

        case ROOM_THIRDFLOOR_ISOLATIONROOM:
            switch (Input)
            {
            case 'i':
                inventoryOpen = true;
                break;

            case 'h':
                ShowHelp();
                break;

            case 'e':
                if(isolationRoomitem == false)
                {
                    isolationRoomitem = true;
                    Logger::Log("침대 옆 책상에서 눈에 띄는 종이를 발견했다.\n");
                    Logger::Space();
                    Logger::Log("[ 환자 기록지 ] 획득\n");
                    Logger::Log("(아무 키나 누르세요.)");
                }
                else
                {
                    Logger::Log("딱히 눈에 띄는 건 없다.\n");
                    Logger::Log("(아무 키나 누르세요.)");
                }
                _getch();
                break;

            case 'w':
                CurrentRoom = ROOM_THIRDFLOOR_MAINHALL;
                break;

            case 's':
                if (archivePuzzle == true)
                {
                    CurrentRoom = ROOM_THIRDFLOOR_SURGERYROOM;
                }
                else
                {
                    Logger::Log("[ 폐쇄 수술실 공지사항 ]\n");
                    Logger::Log("'비상 격리 절차에 따라 폐쇄 수술실은 사망이 임박한 환자부터 순차적으로 수용합니다.'\n");
                    Logger::Log("'우선순위가 지정되지 않은 상태에서는 수술실 출입이 제한됩니다.'\n");
                    Logger::Log("'담당 의료진은 기록실 단말기를 통해 환자 이송 우선순위를 제출해 주시기 바랍니다.'\n");
                    Logger::Space();
                    Logger::Log("(아무 키나 누르세요.)");
                _getch();
				}
                break;

            case 'a':
                CurrentRoom = ROOM_THIRDFLOOR_CONTROLROOM;
                break;

            case 'd':
                if (isolationRoomitem2 == false)
                {
                    isolationRoomitem2 = true;
                    Logger::Log("이름표와 번호가 꽂혀있는 병상이 줄지어 있다.\n");
                    Logger::Log("혹시 몰라 근처에 있던 펜으로 메모지에 기록했다.\n");
                    Logger::Space();
                    Logger::Log("'1번 강민석'  '2번 이준호'  '3번 박도윤'  '4번 최현우'\n");
                    Logger::Space();
                    Logger::Log("[ 병상 메모 ] 획득 \n");
                    Logger::Space();
                    Logger::Log("(아무 키나 누르세요.)");
                }
                else
                {
                    Logger::Log("딱히 눈에 띄는 건 없다.\n");
					Logger::Log("(아무 키나 누르세요.)");
                }
                _getch();
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;

        case ROOM_THIRDFLOOR_SURGERYROOM:
            switch (Input)
            {
            case 'i':
                inventoryOpen = true;
                break;

            case 'h':
                ShowHelp();
                break;

            case 'e':
                ++sergeryRoomCount;
                if(sergeryRoomCount == 1)
                {
                    Logger::Log("공기 전체에 오래된 혈취가 눌어붙어 있다.\n");
                    Logger::Log("수술대와 바닥은 훼손된 흔적으로 난잡하게 뒤엉켜 있다.\n");
                    Logger::Log("조금만 더 살펴보면, 숨겨진 무언가를 찾아낼 수 있을 것 같다.\n");
                }
                else if (sergeryRoomCount == 2)
                {
                    Logger::Log("구석에 방치된 시신 하나가 눈에 들어온다.\n");
                    Logger::Log("굳어버린 손끝 사이로 바지 주머니가 미세하게 불룩 솟아 있다.\n");
                    Logger::Log("주머니를 뒤지자, 차가운 쇠의 감촉이 손끝에 닿을락 말락 한다.\n\n");
                }
				else if (sergeryRoomCount == 3)
                {
                    Logger::Log("피로 얼룩진 천 아래에서 작은 금속 열쇠 하나가 모습을 드러낸다.\n\n");
                    Logger::Log("[ 비밀 통로 열쇠 ] 획득\n");
					secretPassage = true;
				}
                else if (sergeryRoomCount == 10)
                {
                    Logger::Log("계속 뒤적거리다보니 빵과 물을 발견했다.\n");
                    Logger::Log("[ 빵 ] 획득\n");
                    Logger::Log("[ 물 ] 획득\n");
				}
                else
                {
                    Logger::Log("딱히 눈에 띄는 건 없다.\n");
				}
                _getch();
                break;

            case 'w':
                CurrentRoom = ROOM_THIRDFLOOR_ISOLATIONROOM;
                break;

            case 's':
                Logger::Log("녹이 슨 수술 기구들과 얼룩진 벽이 눈에 띈다.\n");
                _getch();
                break;

            case 'a':
                Logger::Log("희미한 조명 아래, 수술대와 기구들은 오래전부터 방치된 듯 싸늘하게 가라앉아 있다.\n");
                _getch();
                break;

            case 'd':
                if (secretPassage == false)
                {
                    Logger::Log("열쇠 구멍이 있는 소각로가 보인다.\n");
                    Logger::Space();
                    Logger::Log("수술실에 소각로? 열쇠 구멍은 뭐지?\n");
                    Logger::Space();
                    Logger::Log("열쇠가 근처에 있을까?\n");
                    _getch();
                }
                else
                {
                    Logger::Log("소각로에 비밀 통로 열쇠를 사용했다.\n");
                    Logger::Log("소각로가 천천히 열리며 숨겨진 통로가 모습을 드러낸다.\n");
                    Logger::Log("(아무 키나 누르세요.)");
                    _getch();
					CurrentRoom = ROOM_THIRDFLOOR_GENERATORROOM;
                }
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;

        case ROOM_THIRDFLOOR_CONTROLROOM:
            switch (Input)
            {
            case 'i':
                inventoryOpen = true;
                break;

            case 'h':
                ShowHelp();
                break;

            case 'e':
                ControlRoomPuzzle();
                _getch();
                break;

            case 'w':
                CurrentRoom = ROOM_THIRDFLOOR_ARCHIVE;
                break;

            case 's':
                Logger::Log("작동하지 않는 CCTV화면이 잔뜩 있다.\n");
                _getch();
                break;

            case 'a':
                Logger::Log("딱히 눈에 띄는 건 없다.\n");
                _getch();
                break;

            case 'd':
                CurrentRoom = ROOM_THIRDFLOOR_ISOLATIONROOM;
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;

        case ROOM_THIRDFLOOR_ARCHIVE:
            switch (Input)
            {
            case 'i':
                inventoryOpen = true;
                break;

            case 'h':
                ShowHelp();
                break;

            case 'e':
                if (archiveitem == false)
                {
                    archiveitem = true;
                    Logger::Log("바닥에 파일이 떨어져있다.\n");
                    Logger::Space();
                    Logger::Log("[ 증상 단계 관찰일지 ] 획득\n");
                    Logger::Log("(아무 키나 누르세요.)");
                }
                else
                {
                    Logger::Log("바닥이 마구잡이로 어질러져 있다.\n");
					Logger::Log("(아무 키나 누르세요.)");
                }
                _getch();
                break;

            case 'w':
                if (archivePuzzle == false)
                {
                    Logger::Log("작은 고정형 단말기가 있다.\n");
                    Logger::Log("빛이 약해 흐릿하지만 알아볼 수는 있을 정도다.\n");
                    Logger::Space();
                    Logger::Log("(아무 키나 누르세요.)\n");
                    _getch();

                    ArchivePuzzle();
                }
                else
                {
                    Logger::Log("(단말기가 꺼져있다.)\n");
                    _getch();
                }

                break;

            case 's':
                CurrentRoom = ROOM_THIRDFLOOR_CONTROLROOM;
                break;

            case 'a':
                Logger::Log("책상위에 컴퓨터가 여러 대 있지만 어느 것 하나 작동하지 않는다.\n");
                _getch();
                break;

            case 'd':
                CurrentRoom = ROOM_THIRDFLOOR_MAINHALL;
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;

        case ROOM_THIRDFLOOR_GENERATORROOM:
            switch (Input)
            {
            case 'i':
                inventoryOpen = true;
                break;

            case 'h':
                ShowHelp();
                break;

            case 'e':
                Logger::Log("이 곳은 비상발전실\n");
                Logger::Log("(아무 키나 누르세요.)");
                _getch();
                break;

            case 'w':
                Logger::Log("옥상으로 향하는 엘리베이터다.\n");
                Logger::Log("퓨즈 박스가 비어있어 작동은 하지 않는다.");
                _getch();
                break;

            case 's':
                CurrentRoom = ROOM_THIRDFLOOR_SURGERYROOM;
                break;

            case 'a':
                Logger::Log("무너진 잔해가 길을 막고 있다..\n");
                _getch();
                break;

            case 'd':
                Logger::Log("벽을 기대고 쓰러진 시체의 손에 무언가 들려있다.\n\n");
                Logger::Log("[ 감시실 금고 메모 ] 획득\n");
                _getch();
                break;

            default:
                std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
                _getch();
                break;
            }
            break;
           
        }
    }
}
