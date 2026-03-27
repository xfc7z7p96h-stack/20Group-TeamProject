#include "Game.h"
#include "Logger.h"
#include "Intro.h"
#include "Battle.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cctype>


Game::Game()
{
	CurrentPlace = "라쿤 시티의 한 건물 앞";
	CurrentFloor = 0; // 층 정보 초기화
    bchaincutter = false;
	firstfloorclear = false;
    secretRoom = false;
	secretRoomQuest = false;
	secretRoomKey = false;
    corridorCount=0;
    storageCount=0;
    corridorEndCount=0;
}

void Game::ShowHelp()
{
    Logger::Log("새로운 방이나 다른 층 진입 시, 일정 확률로 살아있는 시체와 마주하게 됩니다.");
    Logger::Log("근접 공격은 횟수에 제한이 없지만, 당신은 반드시 반격을 당하게 됩니다.");
    Logger::Log("권총 또는 샷건으로 공격 시, 총알을 소비하지만 반격은 당하지 않습니다.");
    Logger::Log("싸울지 도망칠지는 당신의 몫입니다.\n");
    Logger::Log("[ 단축키 ]");
    Logger::Log("[I] 인벤토리");
    Logger::Log("(아무 키나 누르세요.)");
    _getch();
}

void Game::ShowStatus()
{
    Logger::Line();
    std::cout << "현재 위치 : " << CurrentPlace << "\n";
    std::cout << "[W] ↑  [S] ↓  [A] ←  [D] →  [E] 방 조사  [H] 도움말\n";
    Logger::Line();
    Logger::Space();
}

void Game::Run()
{
    //PlayIntro();

    while (CurrentFloor == 0)
    {
       system("cls");
        ShowStatus();
        Logger::Log("나는 좀비를 피해 도망치기 시작했다.");
        Logger::Space();
        Logger::Log("숨이 차오르는 와중에 시야에 한 건물이 들어왔다.");
        Logger::Space();
        Logger::Log("'들어가야한다.'");
        Logger::Space();
        Logger::Log("내 본능이 그렇게 말하고 있었다.");
        Logger::Space();
        Logger::Log("( [W] 건물에 들어간다. )\n");

        char Input = _getch();
        Input = std::tolower(Input);

       system("cls");

        switch (Input)
        {
        case 'w':
            CurrentFloor = 1;
            break;
    
        default:
            Logger::Log("사방에는 좀비 떼가 들끓고 있다. 여기서 건물 안으로 들어가는 것 외에는 다른 선택지가 없다...(아무 키나 누르세요)\n");
            _getch();
            break;
        }
    }

    FirstFloor();
}




void Game::FirstFloor()
{ 
// 1층1층1층1층1층1층1층1층1층1층1층1층
// 1층1층1층1층1층1층1층1층1층1층1층1층
// 1층1층1층1층1층1층1층1층1층1층1층1층
// 1층1층1층1층1층1층1층1층1층1층1층1층
// 1층1층1층1층1층1층1층1층1층1층1층1층
// 1층1층1층1층1층1층1층1층1층1층1층1층
// 1층1층1층1층1층1층1층1층1층1층1층1층
    
    
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
       
FirstFloor_Corridor();

}

void Game::FirstFloor_Corridor()
{
    // 1층복도1층복도1층복도1층복도1층복도1층복도
    // 1층복도1층복도1층복도1층복도1층복도1층복도
    // 1층복도1층복도1층복도1층복도1층복도1층복도
    // 1층복도1층복도1층복도1층복도1층복도1층복도
    // 1층복도1층복도1층복도1층복도1층복도1층복도
    // 1층복도1층복도1층복도1층복도1층복도1층복도
    // 1층복도1층복도1층복도1층복도1층복도1층복도

    CurrentPlace = "건물 1층 [ 복도 ]";

    while (CurrentFloor == 1)
    {
        system("cls");

        ShowStatus();

        Logger::Log("          창 고     ");
        Logger::Log("            ↑      ");
        Logger::Log("            |      ");
        Logger::Log("입구  ←  ▶ 복도  →  복도끝");
        Logger::Log("                     |");
        Logger::Log("                     ↓");
        Logger::Log("                    2층");

        char Input = _getch();
        Input = std::tolower(Input);

        system("cls");


        switch (Input)
        {
        case 'h':
            ShowHelp();
            break;

        case 'e':
            if(secretRoomQuest==true)
            {
                ++corridorCount;
                Logger::Log("딱히 눈에 띄는 것은 없다.\n");
                Logger::Log("(아무 키나 누르세요.)");
                _getch();
                
            }
			else
            {
                Logger::Log("딱히 눈에 띄는 것은 없다.\n");
                Logger::Log("(아무 키나 누르세요.)");
                _getch();
            }
            
            break;

        case 'w':
            FirstFloor_storage();
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
            FirstFloor_CorridorEnd();
            break;

        default:
            std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
            _getch();
            break;
        }
    }
}

void Game::FirstFloor_storage()
{
    //1층창고1층창고1층창고1층창고1층창고1층창고1층창고
    //1층창고1층창고1층창고1층창고1층창고1층창고1층창고 
    //1층창고1층창고1층창고1층창고1층창고1층창고1층창고 
    //1층창고1층창고1층창고1층창고1층창고1층창고1층창고 
    //1층창고1층창고1층창고1층창고1층창고1층창고1층창고 
    //1층창고1층창고1층창고1층창고1층창고1층창고1층창고 
    //1층창고1층창고1층창고1층창고1층창고1층창고1층창고          
                      
	
    CurrentPlace = "건물 1층 [ 창고 ]";

    while (CurrentFloor == 1)
    {
        system("cls");

        ShowStatus();

        Logger::Log("        ▶ 창 고     ");
        Logger::Log("            |      ");
        Logger::Log("            ↓      ");
        Logger::Log("입구  ←    복도  →  복도끝");
        Logger::Log("                     |");
        Logger::Log("                     ↓");
        Logger::Log("                    2층");

        char Input = _getch();
        Input = std::tolower(Input);

        system("cls");


        switch (Input)
        {
        case 'h':
            ShowHelp();
            break;

        case 'e':

            if(secretRoomQuest==true)
            {
                ++storageCount;
                Logger::Log("딱히 눈에 띄는 것은 없다.\n");
			}
            else if (bchaincutter == false)
            {
                Logger::Log("체인 커터를 발견했다. 녹이 좀 슬었지만 어딘가 쓸 곳이 있을 것 같다.\n");
                bchaincutter = true;
            }
			else if (secretRoomQuest == true)
            {
                Logger::Log("딱히 눈에 띄는 것은 없다.\n");
            }
          
           
            Logger::Log("(아무 키나 누르세요.)");
            _getch();
            break;

        case 'w':
            Logger::Log("공구들이 아무렇게가 널부러져 있다. 대부분 못 쓸 것처럼 보인다.\n");
            Logger::Log("(아무 키나 누르세요)");
            _getch();
            break;

        case 's':
            CurrentPlace = "건물 1층 [ 복도 ]";
            return;

        case 'a':
            Logger::Log("공구들이 아무렇게가 널부러져 있다. 대부분 못 쓸 것처럼 보인다.\n");
            Logger::Log("(아무 키나 누르세요)");
            _getch();
            break;

        case 'd':
            Logger::Log("공구들이 아무렇게가 널부러져 있다. 대부분 못 쓸 것처럼 보인다.\n");
            Logger::Log("(아무 키나 누르세요)");
            _getch();
            break;

        default:
            std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
            _getch();
            break;
        }
    }

}

void Game::FirstFloor_CorridorEnd()
{
    CurrentPlace = "건물 1층 [ 복도 끝 ]";

    while (CurrentFloor == 1)
    {
        system("cls");

        ShowStatus();

        Logger::Log("          창 고     ");
        Logger::Log("            ↑      ");
        Logger::Log("            |      ");
        Logger::Log("입구  ←    복도  ← ▶복도끝");
        Logger::Log("                     |");
        Logger::Log("                     ↓");
        Logger::Log("                    2층");

        char Input = _getch();
        Input = std::tolower(Input);

        system("cls");


        switch (Input)
        {
        case 'h':
            ShowHelp();
            break;

        case 'e':

            if (secretRoomQuest == true)
            {
                ++corridorEndCount;

                Logger::Log("딱히 눈에 띄는 것은 없다.\n");
                Logger::Log("(아무 키나 누르세요.)");
                _getch();

            }
            else
            {
                Logger::Log("딱히 눈에 띄는 것은 없다.\n");
                Logger::Log("(아무 키나 누르세요.)");
                _getch();
            }
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
                SecondFloor_Lobby();
                return;
            }
            else if (bchaincutter == true)
            {
                firstfloorclear = true;
                CurrentFloor = 2;
                SecondFloor();
                
            }
            else 
            {
                Logger::Log("2층으로 가는 계단은 철문으로 막혀있다. 손잡이쪽의 쇠사슬을 끊으면 열 수 있을 것 같다.\n");
            }
            Logger::Log("(아무 키나 누르세요.)");
            _getch();
            break;

        case 'a':
            FirstFloor_Corridor();
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
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////



//2층




/////////////////////////////////////////////////////////////////////////////////////////////////////
void Game::SecondFloor()
{
    Logger::Log("쇠사슬을 끊어서 철문을 열었다.");
    Logger::Space();
    Logger::Log("2층으로 올라오니 케케묵은 냄새가 더 심해졌다.");
    Logger::Space();
    Logger::Log("아라라랄라라라");
    Logger::Space();
    Logger::Log("크크루삥빵뽕");
    Logger::Space();
    Logger::Log("끼얏후");
    Logger::Log("(아무 키나 누르세요)");

    _getch();

    SecondFloor_Lobby();
}

void Game::SecondFloor_Lobby()
{

    if (corridorCount >= 8 && storageCount >= 4 && corridorEndCount >= 6)
    {
        secretRoom = true;
    }

    CurrentPlace = "건물 2층 [ 로비 ]";

    while (CurrentFloor == 2)
    {

        system("cls");

        ShowStatus();

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

        char Input = _getch();
        Input = std::tolower(Input);

        system("cls");

        switch (Input)
        {
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
            FirstFloor_CorridorEnd();
            return;

        case 's':
            if (secretRoomKey == false)
            {
                Logger::Log("문이 있지만 당연하게도 잠겨있다..열쇠가 필요하다.\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
            }
            else
            {
                Logger::Log("열쇠로 문을 열었다.\n");
                Logger::Log("3층 가보자이\n");
                _getch();
            }
            break;

        case 'a':
            SecondFloor_Restroom();
            break;

        case 'd':
            SecondFloor_Meetingroom();
            break;

        default:
            std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
            _getch();
            break;
        }
    }
}

void Game::SecondFloor_Restroom()
{
    CurrentPlace = "건물 2층 [ 화장실 ]";

    while (CurrentFloor == 2)
    {
        system("cls");

        ShowStatus();

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

        char Input = _getch();
        Input = std::tolower(Input);

        system("cls");

        switch (Input)
        {
        case 'h':
            ShowHelp();
            break;

        case 'e':
            Logger::Log("개똥을 발견했다.\n");
            Logger::Log("먹을 수 있을 것 같다.\n");
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
            CurrentPlace = "건물 2층 [ 로비 ]";
            return;

        default:
            std::cout << "딴 짓하고 있을 때가 아니다.(아무 키나 누르세요)\n";
            _getch();
            break;
        }
    }
}

void Game::SecondFloor_Meetingroom()
{
    CurrentPlace = "건물 2층 [ 미팅룸 ]";

    while (CurrentFloor == 2)
    {
        system("cls");

        ShowStatus();

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

        char Input = _getch();
        Input = std::tolower(Input);

        system("cls");

        switch (Input)
        {
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
                secretRoomQuest = true;
                Logger::Log("벽에 몸을 바짝 붙이고 귀를 대본다.\n");
                Logger::Log("벽 너머에서 이상한 소리가 들리는 것 같다.\n");
                Logger::Space();
                Logger::Log("벽에 붙어있는 종이에 뭔가가 쓰여있다.\n");
                Logger::Log("'화장실만큼 창고를 살피고, 로비만큼 복도를 살피고, 미팅룸만큼 복도 끝을 살펴라'\n");
                Logger::Log("(아무 키나 누르세요)");
                _getch();
            }
            else
            {
                SecondFloor_Secretroom();
            }
           
            break;

        case 's':
            Logger::Log("딱히 눈에 띄는 건 없다.\n");
            Logger::Log("(아무 키나 누르세요)");
            _getch();
            break;

        case 'a':
            CurrentPlace = "건물 2층 [ 로비 ]";
            return;

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
    }
}

void Game::SecondFloor_Secretroom()
{
    CurrentPlace = "건물 2층 [ 비밀방 ]";

    while (CurrentFloor == 2)
    {
        system("cls");

        ShowStatus();

            Logger::Log("            1층     ▶비밀방    ");
            Logger::Log("             ↑         ↑      ");
            Logger::Log("             |         |      ");
            Logger::Log(" 화장실  ←  로비  ←  미팅룸    ");
            Logger::Log("             |              ");
            Logger::Log("             ↓");
            Logger::Log("            3층");

        char Input = _getch();
        Input = std::tolower(Input);

        system("cls");

        switch (Input)
        {
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
            CurrentPlace = "건물 2층 [ 미팅룸 ]";
            return;

        default:
            std::cout << "딴 짓하고 있을 때가 아니다. 열쇠를 찾아야 한다.(아무 키나 누르세요)\n";
            _getch();
            break;
        }
    }
}