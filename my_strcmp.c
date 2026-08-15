#include <stdio.h>

int my_strcmp(const char *a, const char *b) //approche A
{
    while(*a != '\0') {                             // Tant que le caractère actuel de la première chaine est différent du caractère nul la boucle continue son fonctionnement
        if (*a != *b)                               // Dès que les caractères actuels de la première et de la deuxième chaine ne sont pas identiques, le programme exécute la fontion "break" synonyme d'arrêt
            break;
        a++; b++;                                   // Tant que les caractères actuels de la première et de la deuxième chaine sont identiques le programme passe au caractères suivants des chaines respectives
    }
    return *a - *b;                                 // Le programme retourne la différence existant entre les caractères des deux chaines
}

int my_strcmp_b(const char *a, const char *b) //approche B
{
    while ((*a == *b) && *a != 0) {                 // Tant que les caractères des deux chaines sont identiques la boucle cntinue son fonctionnement dans le cas contraire elle s'arrête.
        a++; b++;                                   // Tant que les caractères actuels de la première et de la deuxième chaine sont identiques le programme passe au caractères suivants des chaines respectives
    }
    return *a - *b;                                 // Le programme retourne la différence existant entre les caractères des deux chaines
}

void main(void)
{
    char a[] = "Bonj";
    char b[] = "Bonh";
    int diff = my_strcmp_b(a, b);               // Appel de la fonction
    printf("%d\n", diff);
}