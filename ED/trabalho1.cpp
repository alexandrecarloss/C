#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    char a[10] = "dadfadfa";
    char *b;
    b = &a[0];
    a[0] = 'c';
    cout << b;
    cout << "\n" << a;
    return 0;
}
