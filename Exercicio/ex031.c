#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

float a = 20, b = 10;
void x1(float e) {
    float c, d;
    printf("Valor e: %f\n", e);
    c = e;
    printf("Valor c: %f\n", c);
    printf("Valor a: %f\n", a);
}

void x2(float f) {
    float h = 40;
    printf("Valor f: %f\n", f);
    h = a;
    printf("Valor h: %f\n", h);
    f = f + 100;
}
int main() {
    setlocale(LC_ALL, "Portuguese");
    float g, h;
    g = 10;
    h = 5;
    a = a + 100;
    x1(g);
    x1(a);
    x2(h);
    printf("Valor f: %f\n", h);
    x2(b);
    return 0;
}
