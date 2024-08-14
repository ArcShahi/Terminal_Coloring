#ifndef TERLOR_HPP
#define TERLOR_HPP

#include <iostream>

#ifdef _WIN32
#include <windows.h>

enum class Color : WORD
{
     // Text Colors
     BLACK = 0,
     DEFAULT = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
     DARKBLUE = FOREGROUND_BLUE,
     DARKGREEN = FOREGROUND_GREEN,
     DARKCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE,
     DARKRED = FOREGROUND_RED,
     DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
     DARKYELLOW = FOREGROUND_RED | FOREGROUND_GREEN,
     DARKGRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
     GRAY = FOREGROUND_INTENSITY,
     BLUE = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
     GREEN = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
     CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
     RED = FOREGROUND_INTENSITY | FOREGROUND_RED,
     MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
     YELLOW = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
     WHITE = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,

     // Background Colors
     BG_BLACK = 0,
     BG_DARKBLUE = BACKGROUND_BLUE,
     BG_DARKGREEN = BACKGROUND_GREEN,
     BG_DARKCYAN = BACKGROUND_GREEN | BACKGROUND_BLUE,
     BG_DARKRED = BACKGROUND_RED,
     BG_DARKMAGENTA = BACKGROUND_RED | BACKGROUND_BLUE,
     BG_DARKYELLOW = BACKGROUND_RED | BACKGROUND_GREEN,
     BG_DARKGRAY = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
     BG_GRAY = BACKGROUND_INTENSITY,
     BG_BLUE = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
     BG_GREEN = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
     BG_CYAN = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
     BG_RED = BACKGROUND_INTENSITY | BACKGROUND_RED,
     BG_MAGENTA = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
     BG_YELLOW = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
     BG_WHITE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
};

namespace arc
{
     inline void setTextColor(Color color)
     {  
          // Windows Handler 
          HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
          if (hConsole != INVALID_HANDLE_VALUE) {
               SetConsoleTextAttribute(hConsole, static_cast<WORD>(color));
          }
     }

     inline void resetColor()
     {
          setTextColor(Color::DEFAULT);
     }

     inline void clearConsole()
     {
          HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
          if (hConsole == INVALID_HANDLE_VALUE) {
               return;
          }

          CONSOLE_SCREEN_BUFFER_INFO csbi;
          if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
               return;
          }

          DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
          DWORD count;
          COORD homeCoords = { 0, 0 };

          // Fill the entire screen with spaces
          if (!FillConsoleOutputCharacter(hConsole, ' ', cellCount, homeCoords, &count)) {
               return;
     }

          // Fill the entire screen with the current colors and attributes
          if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, homeCoords, &count)) {
               return;
          }

          // Move the cursor back to the top left corner
          SetConsoleCursorPosition(hConsole, homeCoords);
     }
     
}

#elif defined(__linux__) || defined(__APPLE__)

namespace arc
{
     constexpr const char* BLACK = "\033[30m";
     constexpr const char* DARKBLUE = "\033[34m";
     constexpr const char* DARKGREEN = "\033[32m";
     constexpr const char* DARKCYAN = "\033[36m";
     constexpr const char* DARKRED = "\033[31m";
     constexpr const char* DARKMAGENTA = "\033[35m";
     constexpr const char* DARKYELLOW = "\033[33m";
     constexpr const char* DARKGRAY = "\033[90m";
     constexpr const char* GRAY = "\033[37m";
     constexpr const char* BLUE = "\033[94m";
     constexpr const char* GREEN = "\033[92m";
     constexpr const char* CYAN = "\033[96m";
     constexpr const char* RED = "\033[91m";
     constexpr const char* MAGENTA = "\033[95m";
     constexpr const char* YELLOW = "\033[93m";
     constexpr const char* WHITE = "\033[97m";

     // Background Colors
     constexpr const char* BG_BLACK = "\033[40m";
     constexpr const char* BG_DARKBLUE = "\033[44m";
     constexpr const char* BG_DARKGREEN = "\033[42m";
     constexpr const char* BG_DARKCYAN = "\033[46m";
     constexpr const char* BG_DARKRED = "\033[41m";
     constexpr const char* BG_DARKMAGENTA = "\033[45m";
     constexpr const char* BG_DARKYELLOW = "\033[43m";
     constexpr const char* BG_DARKGRAY = "\033[100m";
     constexpr const char* BG_GRAY = "\033[47m";
     constexpr const char* BG_BLUE = "\033[104m";
     constexpr const char* BG_GREEN = "\033[102m";
     constexpr const char* BG_CYAN = "\033[106m";
     constexpr const char* BG_RED = "\033[101m";
     constexpr const char* BG_MAGENTA = "\033[105m";
     constexpr const char* BG_YELLOW = "\033[103m";
     constexpr const char* BG_WHITE = "\033[107m";

     constexpr const char* NoClr = "\033[0m";

     inline void setTextColor(const char* fColor, const char* bColor = "\033[49m")
     {
          std::cout << fColor << bColor;
     }

     inline void resetColor()
     {
          std::cout << NoClr;
     }

     inline void clearConsole()
     {
          std::cout << "\033[2J\033[H";
     }
}

#else
#error "Unsupported platform"
#endif

#endif // !TERLOR_HPP
