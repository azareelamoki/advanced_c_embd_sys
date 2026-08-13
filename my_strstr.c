#include <stdio.h>

size_t my_strlen(const char *s) //Approche A
{
    int i = 0;
    while (s[i] != '\0') {                     // Pacours de la chaine de carcatère à l'aide d'un indice I qui représentera exactement le nombre de caractère lu. 
        i++;
    }
    return i;                                  // Retour de cet indice car la fonction sers à connaitre le nombre d'élément contenus dans un tableau de caractère
}

char *my_strstr_b(const char *haystack, const char *needle) //Approche recommandée (car plus logique et plus efficace)
{
    const char *tmp;                                        // initialisation d'un premier pointeur temporaire pour la copie de l'adresse contenue dans haystack
    const char *tmp2;                                       // initialisation d'un deuxième pointeur temporaire pour la copie de l'adresse contenue dans needle

    if (my_strlen(needle) < 1) return (char *)haystack;     // Retour du pointeur initial: haystack qui pointe vers le debut de la chaine de caractère (car needle est vide donc aucune recherche ne doit etre effectuée)

    while (*haystack != '\0') {          // Première boucle fonctionnelle à condition que le caractère (pointé par haystack soit différent du caractère nul)
        tmp = haystack;
        tmp2 = needle;

        while (*tmp2 != '\0' && *tmp == *tmp2 && *tmp2 != '\0') {
            tmp++; tmp2++;
        }

        if (*tmp2 == '\0') return (char *)haystack;
        haystack++;
    }
    return NULL;
}


void main(void)
{
    char s[] ="Bonjojour";
    char * test = my_strstr_b(s, "");
    (test != NULL) ? printf("%s\n", test) : printf("String Not found !\n");
}