#include <stdio.h>

size_t my_strlen(const char *s)
{
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

size_t my_strlen_s(const char *s)
{
    size_t n = 0;
    while (*s != '\0') {
        n++;
        s++;
    }
    return n;
}

size_t my_strlen_trd(const char *s)
{
    // size_t n = 0;
    // while (*s) {
    //     n++;
    //     s++;
    // }
    
    // return n;

    //ou encore
    /* 
    size_t n = 0;
    while (*s++) {
        n++;
    }
    return n;
    */

    //ou encore
    
    const char *start = s;
    
    while (*s++)
    
    return s - start;
}

void main(void)
{
    const char *s = "a";
    char s1[] = "Bonjour";

    printf("%ld\n%ld\n", my_strlen_s(s), my_strlen_s(s1));
}