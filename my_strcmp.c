#include <stdio.h>

int my_strcmp(const char *a, const char *b) //approche A
{
    while(*a) {
        if (*a != *b)
            break;
        a++; b++;
    }
    return *a - *b;
}

int my_strcmp_two(const char *a, const char *b) //approche B
{
    while ((*a == *b) && *a != 0) { 
        a++; b++; 
    }
    return *a - *b;
}

void main(void)
{
    char a[] = "Chat";
    char b[] = "Chat";
    int diff = my_strcmp_two(a, b);
    // int diff = 'a' - 'b';
    printf("%d\n", diff);
}