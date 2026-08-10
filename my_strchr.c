#include <stdio.h>
// #include <stddef.h>

char *my_strchr(const char *s, int c)
{
    char *ptr = (char *)s;
    while (*ptr != '\0' && *ptr != c)
        ptr++;
   
    if (*ptr != c) 
        return NULL;
    
    return ptr;
}

void main(void)
{
    char s[] ="Bonjour";
    // char * test = my_strchr(s, 'i');
    char * test = my_strchr(s, 'o');
    printf("%s\n", test);
}