#include <stdio.h>

int my_strcmp(const char *a, const char *b) //approche A
{
    while(*a != '\0') {                             // Tant que le caractère actuel de la première chaine est différent du caractère nul la boucle continue son fonctionnement
        if (*a != *b)                               // Dès que les caractères actuels de la première et de la deuxième chaine sont identique, le programme exécutela fontion "break" synonyme d'arrêt
            break;
        a++; b++;                                   // Tant que les caractères actuels de la première et de la deuxième chaine ne sont pas identiques le programme passe au carctères suivants des chaines respective
    }
    return *a - *b;
}

int my_strcmp_b(const char *a, const char *b) //approche B
{
    while ((*a == *b) && *a != 0) { 
        a++; b++; 
    }
    return *a - *b;
}

void main(void)
{
    char a[] = "Bonj";
    char b[] = "Bonh";
    int diff = my_strcmp_b(a, b);               // Appel de la fonction
    printf("%d\n", diff);
}