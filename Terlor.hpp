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

     

};

enum class BG : WORD
{
     // Background Colors
     BLACK = 0,
     DARKBLUE = BACKGROUND_BLUE,
     DARKGREEN = BACKGROUND_GREEN,
     DARKCYAN = BACKGROUND_GREEN | BACKGROUND_BLUE,
     DARKRED = BACKGROUND_RED,
     DARKMAGENTA = BACKGROUND_RED | BACKGROUND_BLUE,
     DARKYELLOW = BACKGROUND_RED | BACKGROUND_GREEN,
     DARKGRAY = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
     GRAY = BACKGROUND_INTENSITY,
     BLUE = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
     GREEN = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
     CYAN = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
     RED = BACKGROUND_INTENSITY | BACKGROUND_RED,
     MAGENTA = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
     YELLOW = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
     WHITE = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,


};
namespace arc

{
     inline void setTextColor(BG color)
     {
          // Windows Handler
          HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
          if (hConsole != INVALID_HANDLE_VALUE) {
               SetConsoleTextAttribute(hConsole, static_cast<WORD>(color));
          }
     }

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


namespace Color
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
}

namespace BG
{
     // Background Colors
     constexpr const char* BLACK = "\033[40m";
     constexpr const char* DARKBLUE = "\033[44m";
     constexpr const char* DARKGREEN = "\033[42m";
     constexpr const char* DARKCYAN = "\033[46m";
     constexpr const char* DARKRED = "\033[41m";
     constexpr const char* DARKMAGENTA = "\033[45m";
     constexpr const char* DARKYELLOW = "\033[43m";
     constexpr const char* DARKGRAY = "\033[100m";
     constexpr const char* GRAY = "\033[47m";
     constexpr const char* BLUE = "\033[104m";
     constexpr const char* GREEN = "\033[102m";
     constexpr const char* CYAN = "\033[106m";
     constexpr const char* RED = "\033[101m";
     constexpr const char* MAGENTA = "\033[105m";
     constexpr const char* YELLOW = "\033[103m";
     constexpr const char* WHITE = "\033[107m";
}



namespace arc
{
    


     constexpr const char* NoClr = "\033[0m";

     inline void setTextColor(const char* color)
     {
          std::cout << color;

     

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
