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

    while (*haystack != '\0') {                             // Première boucle; fonctionnelle à condition que: le caractère (pointé par haystack soit différent du caractère nul)
        tmp = haystack;                                     // copie de l'adresse du caractère pointé par haystack dans tmp
        tmp2 = needle;                                      // copie de l'adresse du caractère pointé par needle dans tmp2

        while (*tmp2 != '\0' && *tmp == *tmp2) {            // Deuxième Boucle ; fonctionnelle à condition que : la valeur (le caractère plus précisément) pointée par tmp2 soit différent du carctère nul et que la valeur pointée par tmp soit équivalente celle pointée par tmp2 
            tmp++; tmp2++;                                  // passage des adresses actuelles aux addresses suivantes (autrement dit passage du caractère atuel au carctère qui suit)
        }

        if (*tmp2 == '\0') return (char *)haystack;         // dès que la valeur pointée par tmp2 à la sortie de la deuxième boucle 
                                                            // vérifie cette condition (C'est à dire que cette valeur n'est autre que le terminateur nul qui veut dire que tout les caractères de pointés par tmp2 ont trouvé d'quivalence), 
                                                            // le programme retourne le pointeur haystack qui représente le pointeur initial et l'adresse de repère.
        haystack++;                                         // Dans le cas ou la condition n'est pas vérifiée, le pointeur haystack pointe vers le caractère suivant afin de reprendre le processus ci dessus
    }
    return NULL;                                            // À la sortie de la première boucle (ce qui veut dire que tout la chaine initial a été belle et bien traitée sans obtenir une correspondance en son sein) le programme retourne un pointeur null.
}


void main(void)
{
    char s[] ="Bonjojour";
    char * test = my_strstr_b(s, "");
    (test != NULL) ? printf("%s\n", test) : printf("String Not found !\n");
}