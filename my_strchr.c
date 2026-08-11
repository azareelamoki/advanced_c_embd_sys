#include <stdio.h>

char *my_strchr(const char *s, int c)   // Approche A
{
    char *ptr = (char *)s;              // caster le pointeur s en un type char * et copier l'adresse qu'elle contient dans ptr pour correspondre au type de retour de la fonction
    while (*ptr != '\0' && *ptr != c)   // La boucle s'arrête à condition que le caractère soit retrouvé dans la chaine de caractère (on utilise ptr car il detient déjà l'adresse du premier emplacement de la chaine)
        ptr++;                          // incrémentation du pointeur: passage de l'adresse actuelle à la suivante (on parle d'adresse mémoire)
   
    if (*ptr == c)                      // À la sortie de la boucle si la valeur pointée est réellement identique au caractere recherché,
        return ptr;                     // On retourne le pointeur (Autrement dit l'adresse de l'emplacement auquel a été indentifié le caractère)
    
    return NULL;                        // Dans le cas où le caractère n'a pas été retrouvé le programme retourne une adresse nul.
}

char *my_strchr_b(const char *s, int c)   // Approche B
{
    char *ptr = (char *)s;              // caster le pointeur s en un type char * et copier l'adresse qu'elle contient dans ptr pour correspondre au type de retour de la fonction
    while (*ptr != '\0' && *ptr != c)   // La boucle s'arrête à condition que le caractère soit retrouvé dans la chaine de caractère (on utilise ptr car il detient déjà l'adresse du premier emplacement de la chaine)
        ptr++;                          // incrémentation du pointeur: passage de l'adresse actuelle à la suivante (on parle d'adresse mémoire)
   
    if (*ptr != c)                      // À la sortie de la boucle si la valeur pointée est réellement différente du caractere recherché,
        return NULL;                    // cela veut dire que le caractère n'a pas été retrouvé, le programme retourne une adresse nul. 
    
    return ptr;                         // Dans le cas où le caractère est identique, On retourne le pointeur (Autrement dit l'adresse de l'emplacement à laquelle a été indentifié le caractère)
}

void main(void)
{
    char s[] ="Bonjour";
    char * test = my_strchr(s, 'e');
    (test != NULL) ? printf("%s\n", test) : printf("Character Not found !\n");
}