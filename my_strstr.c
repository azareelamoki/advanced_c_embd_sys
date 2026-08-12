#include <stdio.h>

size_t my_strlen(const char *s) //Approche A
{
    int i = 0;
    while (s[i] != '\0') {                     // Pacours de la chaine de carcatère à l'aide d'un indice I qui représentera exactement le nombre de caractère lu. 
        i++;
    }
    return i;                                  // Retour de cet indice car la fonction sers à connaitre le nombre d'élément contenus dans un tableau de caractère
}

char *my_strstr(const char *haystack, const char *needle) //Approche A
{
    const char *tmp;
    const char *tmp2 = needle;

    if (my_strlen(needle) < 1) return (char *)haystack;
    
    while (*haystack != '\0') {

        if (*haystack == *tmp2) {

            tmp = haystack;
            needle = tmp2;
            
            while (*needle != '\0' && *haystack == *needle) {
                haystack++;
                needle++;
            }
            
            if (*needle == '\0') 
                return (char *)tmp;
        }
        haystack++;
    }
    return NULL;
}

char *my_strstr_b(const char *haystack, const char *needle) //Approche B (recommandée) car plus logique et plus efficace
{
    const char *tmp;
    const char *tmp2;

    while (*haystack != '\0' && *needle != '\0') {
        tmp = haystack;
        tmp2 = needle;

        while (*tmp2 != '\0' && *tmp == *tmp2) {
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
    char * test = my_strstr_b(s, "jour");
    (test != NULL) ? printf("%s\n", test) : printf("String Not found !\n");
}