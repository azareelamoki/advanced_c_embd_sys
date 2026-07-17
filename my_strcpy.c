#include <stdio.h>

char *my_strcpy(char *dest, const char *src)
{
    char *start = dest;                 // copie de l'adresse de 'dest' dans 'start'
    while (*src != '\0') {              //boucle d'itération conditionnée par la condition d'arrêt de la boucle.
        *dest = *src;                   // Copie de chaque caractère de 'src' vers 'dest'
        src++; dest++;                  // itération des deux pointeur (passage au caractère suivant)
    }
    *dest = '\0';                       // ajout du caractère nul.
    return start;                       //pointeur sur le premier élément de la chaine copiée
}

char *my_strcpy_s(char *dest, const char *src)
{
    char *start = dest;                 // copie de l'adresse de 'dest' dans 'start'
    while (*src) {                      //boucle d'itération conditionnée par la condition d'arrêt de la boucle.
        *dest++ = *src++;               // Copie de chaque caractère de 'src' vers 'dest' et passage à l'élément suivant.
    }
    *dest = '\0';                       // ajout du caractère nul.
    return start;                       //pointeur sur le premier élément de la chaine copiée
}

char *my_strcpy_trd(char *dest, const char *src)
{
    char *start = dest;                 // copie de l'adresse de 'dest' dans 'start'

    while ((*dest++ = *src++));         // ou  while ((*dest++ = *src++) != '\0'); boucle d'itération conditionnée par la condition d'arrêt de la boucle; Copie de chaque caractère de 'src' vers 'dest' et passage à l'élément suivant.
    
    return start; //pointeur sur le premier élément de la chaine copiée
}

void main(void)
{
    char dest[10];
    char *new = my_strcpy_trd(dest, "Hello Boy!");
    printf("%s\n", new);
    // printf("%s\n", dest);
}