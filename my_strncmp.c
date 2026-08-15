#include <stdio.h>

int my_strncmp(const char *a, const char *b, size_t n)
{
    size_t i = 1;                                           //initialisation d'un index (i) du même type que n (size_t) pour parcourir la boucle 
    
    if (n == 0) return 0;                                   // Lorsque n = 0, aucune comparaison n'est effectué alors la fonction retourne directement 0
   
    while (i <= n && ((*a == *b) && *a != '\0')) {          // Cette ligne represente le mécanisme principale de la fonction: 
      if (i <= n - 1) {                                     // tant que i est inférieur ou égale à n et que les caractères comparés sont identiques, sans atteindre le caractère nul, la boucle s'effectue toujours.
            a++;                                            // Condition pour limiter l'incrémentation des pointeurs: car l'incrémentation des pointeurs est indépendante de l'indexe i
            b++;                                            //dernier cas  de test: quand i = 2 sans cette condition, *a = 'C' et *b = 'D'(Alors que *a et *b devaient être B et B valeur correspondant au deuxiemme caractère de chaque chaine)
       }
        i++;
    }
   
    return *a - *b;
}

int my_strncmp_b(const char *a, const char *b, size_t n)    // Approche B
{
    size_t i = 0;                                           // initialisation d'un index (i) du même type que n (size_t) pour parcourir la boucle

    while (i < n && *a == *b && *a != '\0') {               // La boucle ne s'arrête pas tant que i est inférieur à n et que les caractère de a et b sont identiques avec a != du caractère nul.
        a++;                                                // passage du caractère actuel au caractère suivant en incrémentant a(en memoire il y a passage d'une adresse à une autre)
        b++;                                                // passage du caractère actuel au caractère suivant en incrémentant b
        i++;                                                // incrémentation de l'index i permettant respecter la marge de caractère à comparer.
    }

    if (i == n)                                             // à la sortie de la boucle si i est egale à n alors 
        return 0;

    return *a - *b;
}

void main(void)
{
    int diff = 0; 
    diff = my_strncmp("ABC", "AB", 3); 
    printf("%d\n", diff);
    diff = my_strncmp("AB", "ABC", 3);
    printf("%d\n", diff);
    diff = my_strncmp("", "", 3);
    printf("%d\n", diff);
    diff = my_strncmp("", "ABC", 0);
    printf("%d\n", diff);
    diff = my_strncmp("Chaton",  "Chat",   10);
    printf("%d\n", diff);
    diff = my_strncmp("ABC",     "XYZ",     0);
    printf("%d\n", diff);
    diff = my_strncmp("ABC",        "ABD",     2);  //dernier cas de test.
    printf("%d\n", diff);
    
}