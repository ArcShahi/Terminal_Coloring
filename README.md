# Terminal_Coloring
A Header only Lib to change the  text Foreground and Background. Made using Windows API for Windows OS and ANSI Escape Codes for Linux OS.

It's for C++ only. You can easily modify it use it for C.


## How to Use ?

1. Download this `Terlor.hpp` file and add it to your working directory.
2.  `#include "Terlor.hpp"` into a translation unit.

Like this :

```cpp

#include <iostream>
#include "Terlor.hpp"

int main()
{

	arc::setTextColor(Color::GREEN);
	std::cout << "Colored text\n";
	arc::resetColor();

}

```

There's so much Color to Select From. See after using  the Scope resolution operator `Color::` or Look Directly in the Header File.

## Tested on IDEs: 🧑🏻‍💻

- VS code ✅
- Visual Studio ✅
- Dev C++   ✅
- Sublime Test  ✅
-JetBrains ✅

   Works here fine so should work with almost every IDEs 🔥



> [!WARNING]
> Follow the Instruction Closely.



## Few Examples :



![Loading_Bar](https://github.com/ArcShahi/arc_color/assets/90377780/4fb847dc-c8f0-48f6-9dde-da5185c1f9cd)


![tree](https://github.com/ArcShahi/arc_color/assets/90377780/b37e0791-fd21-49ca-bf45-87e94eb68675)


![image](https://github.com/user-attachments/assets/1f9c0903-1a1e-4519-8b8b-1134b8e85788)





---

## CHANGES 

- Added Linux and Mac OS Support
- NOW Working on GCC x86
- Optimizations


## Please provide any feedback/issues you've. 
### If you can help improvve the Code please Do so. 😺

## Hritik Shahi  ( ICFAI UNIVERSITY )

