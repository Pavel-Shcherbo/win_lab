#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

char* get_str(char* s, int k)
{
    int c, i = 0;
    while (--k > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;   //Enter or Ctrl + Z
    s[i] = '\0';
    return s;
}

int str_len(const char* s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

char* str_cat(char* s1, char* s2, int k)
{
    char* s;
    int i, len1 = str_len(s1), len2 = str_len(s2);

    if (k > len1) k = len1;
    if ((s = (char*)malloc(sizeof(char) * (len1 + len2))) == NULL)
        return s1;
    for (i = 0; i < k; i++)
        *(s + i) = *(s1 + i);
    for (i = 0; *(s2 + i) != '\0'; i++)
        *(s + k + i) = *(s2 + i);
    for (i = 0; *(s1 + k + i) != '\0'; i++)
        *(s + k + len2 + i) = *(s1 + k + i);
    *(s + k + len2 + i) = '\0';
    s1 = s;
    return s1;
}

void* choice(void) {
    int num;
    printf("What task you want to solve 1 or 2?");
    scanf_s("%d", &num);
    switch (num) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    }
    return choice;
}


void* task1(void)
{
    char shortest_str[100] ;
    int len, i, index = 0, min_wlen = 0, wlen = 0;
    int n = 100;
    char* str = (char*)calloc(1, 1);

    printf("Enter string\n");
    input_string(&str);

    len = str_len(str);
    for (i = 0; i <= len; i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            wlen++;
            continue;
        }
        if (min_wlen == 0 || wlen < min_wlen) {
            min_wlen = wlen;
            index = i - min_wlen;
        }
        wlen = 0;
    }
    for (i = 0; i < min_wlen; i++) {
        shortest_str[i] = str[index + i];
    }
    shortest_str[i] = '\0';
    printf("Shortest word: %s\n", shortest_str);
    free(str);
    return 0;
}
void* task2(void) {
    printf("hello");
}

void input_string(char** string)
{
    int char_;
    int i = 0;
    rewind(stdin);
    while ((char_ = getchar()) != EOF && char_ != '\n')
    {
        (*string)[i++] = char_;
        (*string) = (char*)realloc((*string), (i + 1) * sizeof(char));
    }
    (*string)[i] = '\0';
}