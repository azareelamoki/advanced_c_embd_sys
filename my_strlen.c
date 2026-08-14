#include <stdio.h>

size_t my_strlen(const char *s) //Approche A
{
    int i = 0;
    while (s[i] != '\0') {                     // Pacours de la chaine de carcatère à l'aide d'un indice I qui représentera exactement le nombre de caractère lu. 
        i++;
    }
    return i;                                  // Retour de cet indice car la fonction sers à connaitre le nombre d'élément contenus dans un tableau de caractère
}

size_t my_strlen_b(const char *s) // Approche B
{
    size_t n = 0;
    while (*s != '\0') {                       // Lecture avec pointeur, plus efficace et directement liée au fonctionnement de la mémoire 
        n++;                                   // incrémentation d'un indice n au fur et à mesure que le pointeur permet de parcourir les élément du tabeau de caractère en accédant à leur emplacement mémoire
        s++;                                   // incrémentation du pointeur 
    }
    return n;                                  // retour de l'indice n représentant exatement le nombre de caractère contenu dans le tabeau
}

size_t my_strlen_c(const char *s) // Approche C
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
    
    const char *start = s;                      //Conservation de l'adresse initiale de la chaine dans start
    
    while (*s++);                               // A la sortie de la boucle le pointeur s pointe sur le caractère nul, 
                                                // car durant la dernière itération dès que le caractère nul est lu il est pris en compte en tant que caractère avant que la boucle ne sarrête
    return s - start - 1;                       // retour de la différence entre l'adresse du dernier élément et celui du premier pour connaitre le nombre d'élément contenu dans la chaine - 1 (-1 en raison de la soustraction du carctère nul inclus dans le comptage.)
}

void main(void)
{
    const char *s = "a";
    char s1[] = "Bonjour";

    printf("%ld\n%ld\n", my_strlen_b(s), my_strlen_c(s1));  // Appel de la fonction dans printf
}