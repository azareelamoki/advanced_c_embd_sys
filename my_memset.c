#include <stdio.h>
#include <stddef.h>

void * my_memset(void *s, int c, size_t n) // Cette fonction à pour but d'écrire un certain nombre de fois (n) une valeur (c) dans un espace mémoire donné(s). il faut savoir qu'ici int c ne fait pas directemment référence qux int mais plutôt à l'octet poids faible (exemple: 0x12345678 = 78)
{
    unsigned char *ptr = s;                // Permet de stocker l'adresse de départ de l'espace mémoire. unsigned char comme type permet de garantire une accession à une représentation des objets brute en mémoire
    
    while (n > 0) {
        *ptr++ = (unsigned char) c;        // Cette ligne permet de reécrir la même valeur à chaque itération de la boucle(Tant que le nombre n n'a pas été encore atteint)
        n--;                               // Cette ligne est une sorte de validation d'itération: la décrémentation de n permet à sa valeur d'être réduite jusqu'à 0 afin que la boucle atteigne sa condition de fin.
    }

    return s;
}
