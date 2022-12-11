#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num;
    printf("What task you want to solve 1 or 2?");
    void(*function[2])(void) = { &task1, &task2 };
    scanf_s("%d", &num);
    function[num - 1]();
}