#include <stddef.h>
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


void *my_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d = dest;                 // On convertit dest en unsigned char * afin de pouvoir manipuler les données octet par octet.
    const unsigned char *s = src;            // On convertit src en const unsigned char * pour accéder aux octets source sans les modifier.
    ptrdiff_t diff = 0;                       // Cette variable servira à stocker la différence entre les deux pointeurs.

    if (n == 0 || dest == src) return dest;  // Si aucun octet ne doit être copié ou si la source et la destination sont identiques, on retourne directement dest.

    diff = d - s;                             // On calcule la différence entre les pointeurs afin de déterminer la position relative de la destination par rapport à la source.
                                               // Attention : cette soustraction n'est définie que si les pointeurs appartiennent au même tableau (ou désignent sa position juste après le dernier élément).

    if (diff > 0 && diff < (ptrdiff_t)n) {    // Si la destination commence après la source et que les zones se chevauchent, une copie vers l'avant risquerait d'écraser des octets source avant leur lecture.
        for (size_t i = n; i > 0; i--) {     // On parcourt les n octets de la fin vers le début afin de préserver les données source qui n'ont pas encore été copiées.
            d[i - 1] = s[i - 1];             // On copie l'octet d'indice i - 1 de la source vers la destination.
        }
        return dest;                          // On retourne l'adresse initiale de la destination une fois la copie terminée.
    }

    return my_memcpy(dest, src, n);           // Dans les autres cas, on utilise my_memcpy pour effectuer la copie de gauche à droite.
}

// L'implémentation de my_memmove a une limite: Celle de la portabilité ou de l'universalité ? En effet cette version 
// fonctionne correctement suivant le role principale de la fonction.La particularité est que la différences (d - s) effectuée
//  entre pointeurs ne constitue pas une méthode universelle (C'est à dire qui doit fonctionner peut importe l'environnement, 
// les compilateurs, architecture et d'autres facteurs), car le language C ne garantie pas son comportement dans tous les cas
