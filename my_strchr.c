#include <stdio.h>
// #include <stddef.h>

char *my_strchr(const char *s, int c)
{
    char *ptr = (char *)s;              // caster le pointeur s en un type char * pour correpondre au type de retour de la fonction
    while (*ptr != '\0' && *ptr != c)
        ptr++;
   
    if (*ptr == c)
        return ptr;
    
    return NULL;
}

void main(void)
{
    char s[] ="Bonjour";
    char * test = my_strchr(s, 'e');
    (test != NULL) ? printf("%s\n", test) : printf("Character Not found !\n");
}