#include <stdio.h>

void *my_memcpy(void *dest, const void *src, size_t n) // Le rôle de la fonction memcpy est de pouvoir copier exactement n octets de la zone mémoire src vers la zone mémoire dest
{
    unsigned char *d = dest;                           // Pour pouvoir copier octet par octet, on peut transformer les deux adresses en unsigned char *
    const unsigned char *s = src;                      // Ce qui permettra dans la suite de la fonction de pourvoir effectuer une copie de données sans grabuge

    while (n > 0)
    {
        *d = *s;                                       // Cette ligne permet d'effectuer une copie de donnée à chaque itération de la boucle(Tant que le nombre n d'itération n'a pas été encore atteint)
        d++;
        s++;
        n--;                                           // Cette ligne est une sorte de validation d'itération: la décrémentation de n permet à sa valeur d'être réduite jusqu'à 0 afin que la boucle atteigne sa condition de fin.
    }
    return dest;                                       // Le retour de dest signifie qu'on reourne l'adresse initiale de la destination de la copie, afin que les données à cette adresse puisse être récupérées si besoin.
}
