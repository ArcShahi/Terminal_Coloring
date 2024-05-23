# Terminal_Coloring
A Header only Lib to change the  text Foreground and Background. Made using Windows API for Windows OS and ANSI Escape Codes for Linux OS.

It's for C++ only. You can easily modify it use it for C.


## How to Use ?

1. Download this `terlor.hpp` file and add it to your working directory.
2.  `#include "terlor.hpp"` into a translation unit.

Like this :

```cpp

#include <iostream>
#include "terlor.hpp"

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
- Compiler Explorer ( Godbolt )  ✅
  
![image](https://github.com/ArcShahi/arc_color/assets/90377780/666947ce-f5f4-4520-a60f-f5c8257b8645)

   Works here fine so should work with almost every IDEs 🔥



> [!WARNING]
> Follow the Instruction Closely.



## Few Examples :



![Loading_Bar](https://github.com/ArcShahi/arc_color/assets/90377780/4fb847dc-c8f0-48f6-9dde-da5185c1f9cd)


![tree](https://github.com/ArcShahi/arc_color/assets/90377780/b37e0791-fd21-49ca-bf45-87e94eb68675)


![image](https://github.com/ArcShahi/arc_color/assets/90377780/ad8e9475-2da3-4ea5-8380-bba47c1ee2e5)




---


## Please provide any feedback/issues you've. 
### If you can help improvve the Code please Do so. 😺

## Hritik Shahi  ( ICFAI UNIVERSITY )

