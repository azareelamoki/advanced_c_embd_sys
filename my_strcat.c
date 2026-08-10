#include <stdio.h>

char *my_strcpy_c(char *dest, const char *src)
{
    char *start = dest;                 // copie de l'adresse de 'dest' dans 'start'

    while ((*dest++ = *src++));         // ou  while ((*dest++ = *src++) != '\0'); boucle d'itération conditionnée par la condition d'arrêt de la boucle; Copie de chaque caractère de 'src' vers 'dest' et passage à l'élément suivant.
    
    return start; //pointeur sur le premier élément de la chaine copiée
}

char *my_strcat(char *dest, const char *src)
{
    char *start = dest;

    while (*dest != '\0')
        dest++;
    dest = my_strcpy_c(dest, src);

    return start;
}

char *my_strcat_b(char *dest, const char *src)
{
    char *start = dest;
    
    while (*dest != '\0')
        dest++;
    while ((*dest++ = *src++) != '\0')
        ;

    return start;
}

void main(void)
{
    // printf("%s\n", my_strcat("Bon", "Jour"));

    char s1[20] = "Bon";
    char s2[] = "jour";
    printf("%s\n", my_strcat_b(s1, s2));

}