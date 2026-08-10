#include <stdio.h>

size_t my_strlen(const char *s)
{
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

size_t my_strlen_b(const char *s)
{
    size_t n = 0;
    while (*s != '\0') {
        n++;
        s++;
    }
    return n;
}

size_t my_strlen_c(const char *s)
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
    
    const char *start = s;
    
    while (*s++); // A la sortie de la boucle le pointeur s pointe sur le caractère nul, 
                  // car durant la dernière itération dès que le caractère nul est lu il est pris en compte en tant que caractère avant que la boucle ne sarrête
    return s - start - 1; // raison pour laquelle il faut soutraire le carctère nul du comptage.
}

void main(void)
{
    const char *s = "a";
    char s1[] = "Bonjour";

    printf("%ld\n%ld\n", my_strlen_b(s), my_strlen_c(s1));
}