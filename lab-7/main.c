#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("What task you want to solve 1 or 2?");
    void(*function[2])(void) = { task1, task2 };
    int num = 0, choice = 0;
    scanf_s("%d", &num);
    choice = num - 1;
    function[choice - 1]();
}

