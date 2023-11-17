#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float a, b; // variável global
void x1(float e) {
    float c, d;
    printf("Valor e: %f\n", e);
    c = e;
    printf("Valor c: %f\n", c);
}
void x2(float f) {
    float h;
    printf("Valor f = %f\n", f);
    h = a;
    printf("Valor h = %f\n", h);
}
void main(){
    float g, h;
    g = 10;
    h = 5;
    a = 20;
    b = 10;
    x1(g);
    x1(a);
    x2(h);
    x2(b);
    return 0;

}
