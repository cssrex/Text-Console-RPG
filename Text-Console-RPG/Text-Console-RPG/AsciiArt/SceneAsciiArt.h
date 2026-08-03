#pragma once

#include <windows.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

static const char* TownAscii = R"Town(
.======================================================================================================================.
|                .-~~~~-.                                  .-~~~~-.                                                    |
|            .-''        ''-.                          .-''        ''-.                                                |
|       |==                          [_].:                []                    [_].      [_]:.                        |
|       |     [].                     _________         /\                    _______    __________              *     |
|     __|__      /\                  /_________\       //\\                  /_______\  /__________\           /|\     |
|    /_____\    //\\                /___________\     ///\\\                /_________\/____________\        /*|*\     |
|    |=====|   ///\\\       /**\   /_____________\  ==========  (*)  _____  =========================== /*\/__|__\     |
|    |[#] :|============   /****\ =================  | : [#]|   '|' /__|__\  | [#] : |  | [#] : [#]|/***\=========     |
|    |: [#]| | [#]  : |    \****/  | [#] [#]  :  |   | |#| .|    |    |:|    | : [#] |  |[INN] : |#|.| \***/|[#]:|     |
|    |[#] :| |.: |#| .|      ||    |.[SHOP].|#|..|   | |#|..|    |   [___]   |  |#| .|  |.:   :  |#| |    | |:():|     |
|    |_[_]_| |___|_|__|      ||    |___:____|_|__|   |_|_|__|    |   |:::|   |::|_|::|  |________|_|_|  ||:.[_].:|     |
|   ____..______.._____..______.._______..______.._____..______.._______..______.._____..______.._______..______..     |
|     .:'   ::.    .:.   '::   .:.    .:'   ::.    .:.   '::   .:.    .:'   ::.    .:.   '::   .:.    .:'   ::..:.     |
|        ::.    .:.    '::    .:.        ::.    .:.    '::    .:.        ::.    .:.    '::    .:.        ::.   .:.     |
|                                                                                                                      |
)Town";

static const char* ShopMainAscii = R"SHOP(
.======================================================================================================================.
|     [] [] []   ||      .----------------.             .----------------.   Shop  ||   [] [] []   ||   .-----.        |
|     || || ||   ||      |  | | | | | |   |    .-.      |   | | | | |  | |         ||   || || ||   ||   | o o |        |
|     || || ||   ||      |  | | | | | |   |   (- -)     |   | | | | |  | |         ||   || || ||   ||   '-----'        |
|     || || ||   ||      |  | | | | | |   |  .-'-'-.    |   | | | | |  | |         ||   || || ||   ||                  |
|     || || ||   ||      '----------------'  |  ___ |   '----------------'         ||   || || ||   ||   .---.          |
|     || || ||   ||          ___             | |   ||        ___                   ||   || || ||   ||  (  *  )         |
|     || || ||   ||         /___\            | |___||       /___\                  ||   || || ||   ||   '---'          |
|     || || ||   ||        |_____|           |------|      |_____|                 ||   || || ||   ||                  |
|     || || ||   ||________________________________________________________________||   || || ||   ||                  |
|     || || ||  /___________________________________________________________________\\  || || ||  /||                  |
|   ____________/_____________________________________________________________________\\____________/____________      |
|      ~~~~~~~        ~~~~~~~        ~~~~~~~        ~~~~~~~     ~~~~~~      ~~~~~~~        ~~~~~~~      ~~~~~~~        |
|                                                                                                                      |
|                                                                                                                      |
)SHOP";

static const char* PotionShopAscii =
R"POTION(.======================================================================================================================.
|     .-------------------.                 .----------------------.                   .-------------------.Potion     |
|     | o  o  o  o  o  o  |                 |  [] [] [] [] [] []   |                   | o  o  o  o  o  o  |           |
|     | |  |  |  |  |  |  |        .-.      |  || || || || || ||   |         .-.       | |  |  |  |  |  |  |           |
|     '-------------------'       (   )     '----------------------'        (   )      '-------------------'           |
|             _|_                 '-.-'              .-======-.             '-.-'                _|_                   |
|            /___\              .-`   `-.            |        |           .-`   `-.             /___\                  |
|      .----|___|----.         /  .---.  \           '--------'          /  .---.  \       .----|___|----.             |
|      |  *  *  *   |         |  |    |  |       .-.-.     .-.-.        |  |     |  |      |   +  +  +   |             |
|   ___|_____________|________|__|____|__|______|     |___|    |_______|__|_____|__|______|_____________|_________     |
|                                                                                                                      |
|                                                                                                                      |
|                                                                                                                      |
|                                                                                                                      |
|                                                                                                                      |
)POTION";

static const char* EquipmentShopAscii =
R"EquipmentShop(.======================================================================================================================.
|      [o] [o] [o] [o] [o]       /|\     /|\     /|\     /|\       [o] [o] [o] [o] [o]            EquipmentShop        |
|      | | | | | | | | | |       |||     |||     |||     |||       | | | | | | | | | |                                 |
|      [o] [o] [o] [o] [o]       |||     |||     |||     |||       [o] [o] [o] [o] [o]                                 |
|      .------------------.      / \     / \     / \     / \      .------------------.                                 |
|      | o  o  o  o  o  o |                    .---------.         | o  o  o  o  o  o |                                |
|      '------------------'                  .-'  (o  o)  '-.      '------------------'                                |
|                                             /      ^      |                                                          |
|                   .------------------------|   /////////// |------------------------.                                |
|                  /                         |  ///////////  |                         \                               |
|                 /      .-----.              /////_____//////             .-----.      \                              |
|   _____________/______/_______\_____________///////////////______________/_______\______\___                 _       |
|   _____________________________________________________________________________________________________________      |
|                                                                                                                      |
|                                                                                                                      |
)EquipmentShop";

static const char* EnhanceAscii = R"Enhance(
.======================================================================================================================.
|      [o] [o] [o] [o] [o]       /|\     /|\     /|\     /|\       [o] [o] [o] [o] [o]            EquipmentShop        |
|      | | | | | | | | | |       |||     |||     |||     |||       | | | | | | | | | |                                 |
|      [o] [o] [o] [o] [o]       |||     |||     |||     |||       [o] [o] [o] [o] [o]                                 |
|                   .        '      ,                                                                                  |
|                 '    .  *      .     ,                                                                               |
|               .    ,  '    .:*:.   '   .                                                                             |
|       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      .---------.                                                      |
|       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%     .-'  (o  o)  '-.            .================..                   |
|       ########################################      /      ^      |            |                 |                   |
|       %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%----|   /////////// |----------  |                 |                   |
|       #############################               |  ///////////  |          --- '================                   |
|                   ############                     /////_____//////            ----     | |                          |
|               #####################___              ///////////////___         ------   | |                          |
|           ################################                                          ----| |                          |
)Enhance";

static const char* DungeonEnteranceAscii = R"Dungeon(
.======================================================================================================================.
|         ||                    ||                     ||                    ||                    ||                  |
|      ___||___              ___||___               ___||___              ___||___              ___||___               |
|     /        \            /        \             /        \            /        \            /        \              |
|    |   .--.   |          |    /\    |           |   .--.   |          |    /\    |          |  .--.   |              |
|    |  / /\ \  |          | .-'  '-. |           |  / /\ \  |          | .-' '-. |          |  / /\ \  |              |
|    | | |  | | |     .----|/  .-.   \|----.      | | |  | | |     .----|   | |   |----.     | | |  | | |              |
|    | | |/\| | |    /     /  / | \   \     \     | | |/\| | |    /     |   | |   |     \    | | |/\| | |              |
|    | |  ||  | |   /_____/__/__|__\___\_____\    | |  ||  | |   /______|___|_|___|______\   | |  ||  | |              |
|    |  \_||_/  |         \      |      /         |  \_||_/  |         /     |     \         |  \_||_/  |              |
|    |____||____|__________\_____|_____/__________|____||____|________/______|______\________|____||____|_______       |
|                    \_______________________  고대의 봉인된 던전  ___________________/                                |
|                                                                                                                      |
|                                                                                                                      |
|                                                                                                                      |
)Dungeon";

static const char* DungeonCaveAscii = R"Cave(
.======================================================================================================================.
|                        .--------------------------------------------------------------------.                        |
|                       '            .--------------------------------------------.           '                        |
|                       |           '                                             '           |                        |
|                       |           |            .--------------------.           |           |        _.-''-._        |
|                  _.-' |           |           '                     '           |           |    .-'        '-._     |
|           _.-'        |           |           |                     |           |           |                        |
|                       |           |           |       *-*           |           |           |           _.-''-._     |
|            _.-''-._   |           |           .        -            .           |           |     -'         '-.     |
|      _.-'         '-. |           |            '--------------------'           |           |                        |
|    .-'                |           .                 -  - - -                    .           |                        |
|   '.__            __. .            '--------------------------------------------'           . -.__            __     |
|   '---.._______..-'    '--------------------------------------------------------------------'    '-.._______..--     |
|                                                                                                                      |
|                                                                                                                      |
)Cave";

static const char* DungeonClearAscii = R"Clear(
.======================================================================================================================.
|                        .--------------------------------------------------------------------.                        |
|                       '            .-----------.------------------.-------------.           '                        |
|                       |           '     /                                \      '           |                        |
|                       |           |/       *        *        *        *       \ |           |        _.-''-._        |
|                  _.-' |         /                                                \          |    .-'        '-._     |
|           _.-'        |       /                  던 전   클 리 어                       \        |                   |
|                       |         \                                                /          |           _.-''-._     |
|            _.-''-._   |           |\              * * * * * * *               / |           |     -'         '-.     |
|      _.-'         '-. |           |     \                                /      |           |                        |
|    .-'                |           .            '------------------'             .           |                        |
|   '.__            __. .            '--------------------------------------------'           . -.__            __     |
|   '---.._______..-'    '--------------------------------------------------------------------'    '-.._______..--     |
|                                                                                                                      |
|                                                                                                                      |
)Clear";

static const char* PlayerDeathAscii = R"Death(
.======================================================================================================================.
|                                                                                                                      |
|      \  |  /                                             |                                                           |
|       \ | /                                              |                                                           |
|      --*--                                             --+--                                                         |
|    /    \                                                |                                                           |
|   /     |     \                                          |                                                           |
|         |        .--.                                   .-+-.                   .--.                                 |
|         |        (    )         .--.                  /       \                 (    )        .--.                   |
|         |        |    |         (    )                |  R.I.P |                |    |        (    )                 |
|   ~~~~~~~~~~~~~~~'----'~~~~~~~~~|    |~~~~~~~~~~~~~~~~'---------'~~~~~~~~~~~~~~~'----'~~~~~~~~|    |~~~~~~~~~~~~     |
|   ..............................'----'........................................................'----'............     |
|                                           "죽어버리다니... 한심하구나.."                                             |
|                                                                                                                      |
|                                                                                                                      |
)Death";

static const char* HouseAscii = R"House(
.======================================================================================================================.
|     *                                                  / \                                                           |
|                  .--.                                 / . \                              *                 *         |
|          *      (    )  *                            / . : \                                                         |
|                 '--'                                / . : . \                                        *               |
|                                                    / . : . : \                                                       |
|      *                                            / . : . : . \                                                      |
|                                                  / . : . : . : \                                            *        |
|                                                 / . : . : . : . \                                                    |
|                                                / . : . : . : . : \                                                   |
|                                       /...\   / . : . : . : . : . \   /...\                                          |
|                                      /.....\ / . : . : . : . : . : \ /.....\                                         |
|                                             / . : . : . : . : . : . \                                                |
|                                            / . : . : . : . : . : . : \                                               |
|                                           / . : . : . : . : . : . : . \                                              |
|                                          '-----------------------------'                                             |
|    *                            |>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>|                                    |
|                                 |<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<|                             *      |
|   *                             |:::::::::::::::::::::::::::::::::::::::::::::::|                                    |
|                                 |                                               |                              *     |
|     *                           |   .---.         .----.  .----.       .---.    |                                    |
|                                 |   |:.:|         |::::|  |::::|       |:.:|    |                            *       |
|                                 |   '---'         |::::|  |::::|       '---'    |                                    |
|                                 |                 |____|__|____|                |                                    |
|                                 '-----------------------------------------------'                                    |
.======================================================================================================================.

)House";

static const char* TimeoutEndingAscii = R"TimeoutEnding(
.======================================================================================================================.
|     ~~~~~~~~                           ~~~~~                                  _.--''.--''\         ~~~~~             |
|                    ~~~~~~~~~~                                            .-------.   / \                ~~~~~~~~~    |
|   ~~~~~                                               ~~~~~~           /       /      |                              |
|                              ~~~~~~~~~~~~                             /         \     |                              |
|     ~~~~~~~~~~                                                        |         |     |                              |
|                                             ~~~~~~~                   |         |     |                              |
|                                                                      /           \    |                              |
|                                                                     /             \   |                              |
|                                                                    /               \  |                              |
|'| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '/                || || '| '| '| '| '| '| '| '| '| '|
|'| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| /                 || || '| '| '| '| '| '| '| '| '| '|
|'| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '| '|/                  || || '| '| '| '| '| '| '| '| '| '|
|'|~'| '| '|.'|~'| '| '|~'|.'| '| '|~'| '| '|.'|~'| '| '|~'|.'| '/                   || '|~'|.'| '| '|~'| '| '|.'|~'| '|
|'|~'| '| '|.'|~'| '| '|~'|.'| '| '|~'| '| '|.'|~'| '| '|~'|.'|'---------------------'| '|~'|.'| '| '|~'| '| '|.'|~'| '|
|                                       "시간 안에 던전을 클리어하지 못했다..."                                        |
)TimeoutEnding";

static const char* GameClearEndingAscii = R"GameClearEnding(
.======================================================================================================================.
|                             *     *     *     *     *     |     *     *     *     *     *                            |
|                                       *    *    *    *    |    *    *    *    *                                      |
|                                                        '''#''.                                                       |
|                                                     . .'' | ''' '                                                    |
|                                                .''  . '.  |  .' .  .'.                                               |
|                                             '. ' . ' '.   |   .' ' . ' .'                                            |
|                                          .'' .  '  '.'  ==+== '.'  '  . ''.                                          |
|                                       '. .   ' . . .'    / \    '. . . '   . .'                                      |
|                                    .   '    .   ' '     |   |     ' '   .    '   .                                   |
|                                 '    .    '    . .     |     |     . .    '    .    '                                |
|                            ' .  . '    ' .   .'       |       |       '.   . '    ' .  . '                           |
|                         . .   '             '        |         |        '             '   . .                        |
|                      ' '                              |  | |  |                              ' '                     |
|                    .                                 |  /   \  |                                 .                   |
|                 '                           `.`.`.`.`.`.`.`.`.`.`.`.`.`.`                           '                |
|                                                    "게임 클리어!"                                                    |
)GameClearEnding";

inline void PrintTownAsciiArt(short startX = 0, short startY = 0) {
    const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screenInfo;
    GetConsoleScreenBufferInfo(console, &screenInfo);
    const size_t visibleWidth =
        static_cast<size_t>(screenInfo.srWindow.Right - screenInfo.srWindow.Left + 1);

    istringstream input(TownAscii);
    string line;
    short row = 0;

    while (getline(input, line)) {
        if (line.empty() && row == 0) {
            continue;
        }
        SetConsoleCursorPosition(console, { startX, static_cast<short>(startY + row) });
        cout << line.substr(0, visibleWidth);
        ++row;
    }
}

inline void SetTownTheme(bool isNight) {
    const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    const WORD color = isNight
        ? FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
        : FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE |
        FOREGROUND_INTENSITY;

    CONSOLE_SCREEN_BUFFER_INFO screenInfo;
    GetConsoleScreenBufferInfo(console, &screenInfo);

    const COORD home = { 0, 0 };
    const DWORD cellCount = screenInfo.dwSize.X * screenInfo.dwSize.Y;
    DWORD written = 0;

    FillConsoleOutputCharacter(console, ' ', cellCount, home, &written);
    FillConsoleOutputAttribute(console, color, cellCount, home, &written);
    SetConsoleTextAttribute(console, color);
    SetConsoleCursorPosition(console, home);
}

inline void PrintTownSky(bool isNight) {
    const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    // 해랑 달 위치
    const short startX = 100;
    const short startY = 1;

    const char* skyObject = isNight
        ? "   _..._\n .-'     '-.\n/   .-.   \\\n|  (   )  |\n\\   `-'   /\n '-._____.-'"
        : "   \\ | /\n --  O  --\n   / | \\\n";

    istringstream input(skyObject);
    string line;
    short row = 0;
    while (getline(input, line)) {
        SetConsoleCursorPosition(
            console, { startX, static_cast<short>(startY + row) });
        cout << line;
        ++row;
    }
}

//메인메뉴 - 배경아트 PrintTownScene(false) 낮, (true) 밤 으로 호출
inline void PrintTownScene(bool isNight = false) {
    SetConsoleOutputCP(CP_UTF8);
    SetTownTheme(isNight);
    PrintTownAsciiArt(0, 0);
    PrintTownSky(isNight);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 15 });
    SetConsoleTextAttribute(
        GetStdHandle(STD_OUTPUT_HANDLE),
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE |
        FOREGROUND_INTENSITY);
}

//메인메뉴 - 상점
inline void PrintShopMainAsciiArt(short startX = 0, short startY = 0) {
    const HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    istringstream input(ShopMainAscii);
    string line;
    short row = 0;

    while (getline(input, line)) {
        if (line.empty() && row == 0) {
            continue;
        }
        SetConsoleCursorPosition(console, { startX, static_cast<short>(startY + row) });
        cout << line;
        ++row;
    }
}

//메인메뉴 - 상점 -  포션상점
inline void PrintPotionShopAsciiArt(short startX = 0, short startY = 0) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    istringstream input(PotionShopAscii);
    string line;
    short row = 0;

    while (getline(input, line)) {
        if (line.empty() && row == 0) {
            continue;
        }
        SetConsoleCursorPosition(console, { startX, static_cast<short>(startY + row) });
        cout << line;
        ++row;
    }
}

//메인메뉴 - 상점 - 장비상점
inline void PrintEquipmentShopAsciiArt(short startX = 0, short startY = 0) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    istringstream input(EquipmentShopAscii);
    string line;
    short row = 0;

    while (getline(input, line)) {
        if (line.empty() && row == 0) {
            continue;
        }
        SetConsoleCursorPosition(console, { startX, static_cast<short>(startY + row) });
        cout << line;
        ++row;
    }
}

//메인메뉴 - 상점 - 장비상점 - 강화
inline void PrintEnhanceAsciiArt(short startX = 0, short startY = 0) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    istringstream input(EnhanceAscii);
    string line;
    short row = 0;

    while (getline(input, line)) {
        if (line.empty() && row == 0) {
            continue;
        }
        SetConsoleCursorPosition(console, { startX, static_cast<short>(startY + row) });
        cout << line;
        ++row;
    }
}

//메인메뉴 - 던전
inline void PrintDungeonEntranceAsciiArt(short startX = 0, short startY = 0) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    istringstream input(DungeonEnteranceAscii);
    string line;
    short row = 0;

    while (getline(input, line)) {
        if (line.empty() && row == 0) {
            continue;
        }

        SetConsoleCursorPosition(
            console, { startX, static_cast<short>(startY + row) });

        cout << line;
        ++row;
    }
}

//메인메뉴 - 던전 - 스테이지 이동(클리어)
inline void PrintDungeonCaveAsciiArt(short startX = 0, short startY = 0) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    istringstream input(DungeonCaveAscii);
    string line;
    short row = 0;

    while (getline(input, line)) {
        if (line.empty() && row == 0) {
            continue;
        }

        SetConsoleCursorPosition(
            console, { startX, static_cast<short>(startY + row) });

        cout << line;
        ++row;
    }
}

//메인메뉴 - 던전 - 클리어
inline void PrintDungeonClearAsciiArt(short startX = 0, short startY = 0) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    istringstream input(DungeonClearAscii);
    string line;
    short row = 0;

    while (getline(input, line)) {
        if (line.empty() && row == 0) {
            continue;
        }

        SetConsoleCursorPosition(
            console, { startX, static_cast<short>(startY + row) });

        cout << line;
        ++row;
    }
}

//플레이어 사망
inline void PrintPlayerDeathAsciiArt(short startX = 0, short startY = 0) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    istringstream input(PlayerDeathAscii);
    string line;
    short row = 0;

    while (getline(input, line)) {
        if (line.empty() && row == 0) {
            continue;
        }

        SetConsoleCursorPosition(
            console, { startX, static_cast<short>(startY + row) });

        cout << line;
        ++row;
    }
}

//메인메뉴 - 여관(플레이어 부활 위치)
inline void PrintHouseAsciiArt(short startX = 0, short startY = 0) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    istringstream input(HouseAscii);
    string line;
    short row = 0;

    while (getline(input, line)) {
        if (line.empty() && row == 0) {
            continue;
        }

        SetConsoleCursorPosition(
            console, { startX, static_cast<short>(startY + row) });

        cout << line;
        ++row;
    }
}

//게임엔딩 - 시간초과
inline void PrintTimeoutEndingAsciiArt(short startX = 0, short startY = 0) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    istringstream input(TimeoutEndingAscii);
    string line;
    short row = 0;

    while (getline(input, line)) {
        if (line.empty() && row == 0) {
            continue;
        }

        SetConsoleCursorPosition(
            console, { startX, static_cast<short>(startY + row) });

        cout << line;
        ++row;
    }
}

//게임클리어
inline void PrintGameClearEndingAsciiArt(short startX = 0, short startY = 0) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    istringstream input(GameClearEndingAscii);
    string line;
    short row = 0;

    while (getline(input, line)) {
        if (line.empty() && row == 0) {
            continue;
        }

        SetConsoleCursorPosition(
            console, { startX, static_cast<short>(startY + row) });

        cout << line;
        ++row;
    }
}