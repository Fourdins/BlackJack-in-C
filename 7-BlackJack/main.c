#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define BJ 21
#define MIN 1
#define MAX 10

int main()
{
    srand(time(NULL));

    int score_utente_1 = 0, score_utente_2 = 0;
    int card_1 = 0, card_2 = 0;
    char y_n;
    char ace;
    int counter_1 = 0, counter_2 = 0;

    card_1 = MIN + rand() % (MAX - MIN + 1);
    counter_1++;
    score_utente_1 += card_1;

    //ciclo if nel caso in cui l'utente peschi l'asso e richiesta per assegnare il valore che scegli l'utente
    if (card_1 == 1)
    {
        printf("Utente 1 ha pescato l'asso, scegli se farlo valere (n) 1 oppure (y) 11: \n");
        scanf(" %c", &ace);

        if (ace == 'n')
            score_utente_1 = 1;
        if (ace == 'y')
            score_utente_1 = 11;

    }

    printf("Utente 1 inizia con: %d\n", score_utente_1);

    while (score_utente_1 <= BJ)
    {
        puts("Vuoi un' altra carta? (y/n)");
        scanf(" %c", &y_n);
        y_n = tolower(y_n);

        if (y_n == 'y')
        {
            card_1 = MIN + rand() % (MAX - MIN + 1);
            score_utente_1 += card_1;
            printf("Utente 1 pesca %d. Totale: %d\n", card_1, score_utente_1);
            counter_1++;
                 if (score_utente_1 == BJ && counter_1 == 2){
                    printf("Utente 1 ha pescato %d e ha ottenuto il BlackJack. Totale: %d", card_1, score_utente_1);
                    break;
                 }
        }
        else if (y_n == 'n')
        {
            printf("Utente 1 ha scelto di giocare con: %d\n", score_utente_1);
            break;
        }
        else
        {
            puts("Input non valido! Inserisci 'y' o 'n'.");
        }

        if (score_utente_1 > BJ)
        {
            puts("Utente 1 ha perso.");
            break;
        }
    }

    if (score_utente_1 <= 21 )
    {
        card_2 = MIN + rand() % (MAX - MIN + 1);
        score_utente_2 += card_2;
        counter_2++;

        //ciclo if nel caso in cui l'utente peschi l'asso e richiesta per assegnare il valore che scegli l'utente
        if (card_2 == 1)
        {
            printf("Utente 2 ha pescato l'asso, scegli se farlo valere (n) 1 oppure (y) 11: \n");
            scanf(" %c", &ace);

            if (ace == 'n')
                score_utente_2 = 1;
            if (ace == 'y')
                score_utente_2 = 11;
        }

        printf("Utente 2 inizia con: %d\n", score_utente_2);

        while (score_utente_2 <= BJ)
        {
            puts("Vuoi un' altra carta? (y/n)");
            scanf(" %c", &y_n);
            y_n = tolower(y_n);

            if (y_n == 'y')
            {
                card_2 = MIN + rand() % (MAX - MIN + 1);
                counter_2++;
                score_utente_2 += card_2;
                printf("Utente 2 pesca %d. Totale: %d\n", card_2, score_utente_2);

                if (score_utente_2 == BJ && counter_2 == 2)
                {
                    printf("Utente 2 ha pescato %d e ha ottenuto il BlackJack. Totale: %d", card_2, score_utente_2);
                    break;
                }
            }
            else if (y_n == 'n')
            {
                printf("Utente 2 ha scelto di giocare con: %d\n", score_utente_2);
                break;
            }
            else
            {
                puts("Input non valido! Inserisci 'y' o 'n'.");
            }
        }
    }

    if (score_utente_1 <= BJ && score_utente_2 <= BJ){
        if (score_utente_1 > score_utente_2)
        {
            printf("Utente 1 vince con %d, mentre utente 2 perde con %d.\n", score_utente_1, score_utente_2);
        }else if (score_utente_2 > score_utente_1)
        {
            printf("Utente 2 vince con %d, mentre utente 1 perde con %d.\n", score_utente_2, score_utente_1);
        }else if (score_utente_1 == score_utente_2)
        {
            printf("Pareggio.");
        }
    }else if (score_utente_1 > BJ)
    {
        printf("Utente 1 ha sballato con %d, quindi vince utente 2 con %d", score_utente_1, score_utente_2);
    }else if (score_utente_2 > BJ)
    {
        printf("Utente 2 ha sballato con %d, quindi vince utente 1 con %d.", score_utente_2, score_utente_1);
    }
    return 0;
}