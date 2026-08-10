#include <stdio.h>

int my_strncmp(const char *a, const char *b, size_t n)
{
    size_t i = 1;
    if (n == 0) return 0;
    while (i <= n && ((*a == *b) && *a != '\0')) {
        if (i <= n - 1) {a++; b++;}
        i++;
    }
    return *a - *b;
}

void main(void)
{
    //  char a[] = "Chat";
    // char b[] = "Ahaton";
    int diff = 0; 
    diff = my_strncmp("ABC", "AB", 3);
    printf("%d\n", diff);
    diff = my_strncmp("AB", "ABC", 3);
    printf("%d\n", diff);
    diff = my_strncmp("", "", 3);
    printf("%d\n", diff);
    diff = my_strncmp("", "ABC", 0);
    printf("%d\n", diff);
    // diff = my_strncmp("Chaton",  "Chat",   10);
    // printf("%d\n", diff);
    // diff = my_strncmp("ABC",     "XYZ",     0);
    // printf("%d\n", diff);
    // diff = my_strncmp("ABC",        "ABD",     2);
    // printf("%d\n", diff);
    
}