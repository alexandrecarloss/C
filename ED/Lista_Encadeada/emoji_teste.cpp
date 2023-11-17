#include <iostream>
#include <Windows.h>

// U+1F47B
int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "\xF0\x9F\x92\x8C"
                " emoji "
                "\xF0\x9F\x92\x8D"
                " 📩 "
                << std::endl;
    printf("%c", 201);
    return 0;
}
