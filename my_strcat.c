#include <stdio.h>

char *my_strcpy_c(char *dest, const char *src)
{
    char *start = dest;                 // copie de l'adresse de 'dest' dans 'start'

    while ((*dest++ = *src++));         // ou  while ((*dest++ = *src++) != '\0'); boucle d'itération conditionnée par la condition d'arrêt de la boucle; Copie de chaque caractère de 'src' vers 'dest' et passage à l'élément suivant.
    
    return start;                       //pointeur sur le premier élément de la chaine copiée
}

char *my_strcat(char *dest, const char *src)
{
    char *start = dest;                 // conservation de l'adresse du premier élément de dest dans start

    while (*dest != '\0')               // lecture de chaque caractère de la chaine dest jusqu'au terminateur afin d'avoir l'emplacement à partir duquel effectuer la concaténation
        dest++;

    dest = my_strcpy_c(dest, src);      //concaténation proprement dite à partir de l'adresse contenue dans dest (en utilisant la fonction strcpy)

    return start;                       //retour d l'adresse initiale de la fonction
}

char *my_strcat_b(char *dest, const char *src)
{
    char *start = dest;                  // conservation de l'adresse du premier élément de dest dans start
    
    while (*dest != '\0')                // lecture de chaque caractère de la chaine dest jusqu'au terminateur afin d'avoir l'emplacement à partir duquel effectuer la concaténation
        dest++;

    while ((*dest++ = *src++) != '\0')   //concaténation proprement dite à partir de l'adresse contenue dans dest 
        ;

    return start;                        //retour d l'adresse initiale de la fonction
}

void main(void)
{
    // printf("%s\n", my_strcat("Bon", "Jour")); impossible de faire ceci car génère des erreur du fait que les chaines directement 
    //passées en paramètre soit des chaine littérales et non modifiables, donc sont considéré par le programme comme des const

    char s1[20] = "Bon";
    char s2[] = "jour";
    printf("%s\n", my_strcat_b(s1, s2));

}