#include <stdio.h>

char *my_strchr(const char *s, int c)   // Approche A
{
    const char *ptr = s;              // copie de l'adresse contenue dans s, dans ptr.
    while (*ptr != '\0' && *ptr != c)   // La boucle s'arrête à condition que le caractère soit retrouvé dans la chaine de caractère (on utilise ptr car il detient déjà l'adresse du premier emplacement de la chaine)
        ptr++;                          // incrémentation du pointeur: passage de l'adresse actuelle à la suivante (on parle d'adresse mémoire)
   
    if (*ptr == c)                      // À la sortie de la boucle si la valeur pointée est réellement identique au caractere recherché,
        return (char *)ptr;             // On retourne le pointeur casté en char * pour correspondre au type de retour de la fonction (Autrement dit l'adresse de l'emplacement à laquelle a été indentifié le caractère)
    
    return NULL;                        // Dans le cas où le caractère n'a pas été retrouvé le programme retourne une adresse nul.
}

char *my_strchr_b(const char *s, int c)   // Approche B
{
    const char *ptr = s;                // copie de l'adresse contenue dans s, dans ptr.
    while (*ptr != '\0' && *ptr != c)   // La boucle s'arrête à condition que le caractère soit retrouvé dans la chaine de caractère (on utilise ptr car il detient déjà l'adresse du premier emplacement de la chaine)
        ptr++;                          // incrémentation du pointeur: passage de l'adresse actuelle à la suivante (on parle d'adresse mémoire)
   
    if (*ptr != c)                      // À la sortie de la boucle si la valeur pointée est réellement différente du caractere recherché,
        return NULL;                    // cela veut dire que le caractère n'a pas été retrouvé, le programme retourne une adresse nul. 
    
    return ((char *)ptr);               // Dans le cas où le caractère est identique, On retourne le pointeur casté en char * pour correspondre au type de retour de la fonction (Autrement dit l'adresse de l'emplacement à laquelle a été indentifié le caractère)
}

const char *my_strchr_c(const char *s, int c)   // Approche C
{
    const char *ptr = s;                // copie de l'adresse contenue dans s, dans ptr.
    while (*ptr != '\0' && *ptr != c)   // La boucle s'arrête à condition que le caractère soit retrouvé dans la chaine de caractère (on utilise ptr car il detient déjà l'adresse du premier emplacement de la chaine)
        ptr++;                          // incrémentation du pointeur: passage de l'adresse actuelle à la suivante (on parle d'adresse mémoire)
   
    if (*ptr == c)                      // À la sortie de la boucle si la valeur pointée est réellement identique au caractere recherché,
        return ptr;                     // On retourne le pointeur (Autrement dit l'adresse de l'emplacement auquel a été indentifié le caractère)
    
    return NULL;                        // Dans le cas où le caractère n'a pas été retrouvé le programme retourne une adresse nul.
}

void main(void)
{
    char s[] ="Bonjour";
    const char * test = my_strchr_c(s, 'e');
    (test != NULL) ? printf("%s\n", test) : printf("Character Not found !\n");
}