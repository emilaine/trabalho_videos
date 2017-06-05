#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

/*
Autores
Nome Emilaine RA 2216112399
Nome Mauricio RA 2216101424
Nome Welington RA 2216100696
*/

#define POMODORI 25
#define PAUSA 5
#define PAUSAMAIOR 20
#define TEMPO 10

int main(){
    int i, j, m=0, s=0, cont = 0, intervalo;
    char status[20] = "POMODORI";

    printf("\n\tTECNICA POMODORO\n\n");
    printf("-------------------------------- INSTRUCOES ----------------------------------------\n\n");
    printf("Quando voce apertar a tecla ENTER vai comecar a correr o tempo\n");
    printf("Voce tera 25min para se dedicar a uma tarefa isso e um POMODORI\n");
    printf("Passado esse tempo soara um alerta sonoro e comecara o tempo de PAUSA de 5min\n");
    printf("Nesse periodo de PAUSA procure relaxar e nao fazer nada o deixe cansado\n");
    printf("Apos a PAUSA terminar soara um alerta sonoro para mais 25min de tarefa POMODORI\n\n");
    printf("Toda vez que soar o alarme o timer ira parar para que ele comece a contar o tempo\n");
    printf("novamente e necessario que precione ENTER\n");
    printf("Apos 4 POMODORIS voce tera direito a uma PAUSA maior com o tempo de 20min\n");
    printf("------------------------------------------------------------------------------------\n\n");

    printf("aperte ENTER para comecar\n");
    getch();
    system("cls");
    system("color 0e");

    intervalo = POMODORI;
    while(1){
        /*CRONOMETRO POMODORI*/
        while(1){
            printf("Tempo %d %s: %02d:%02d",cont+1, status, m, s);
            Sleep(TEMPO);
            system("cls");
            s++;
            if(s==60){
                s = 0;
                m++;
            }
            if(m==intervalo){
                cont++;
                if(cont==4){
                    printf("\a \nENTER PARA INICIAR PAUSA DE 20min\n");
                    intervalo=PAUSAMAIOR;
                }else{
                    printf("\a \nENTER PARA INICIAR PAUSA\n");
                    intervalo=PAUSA;
                }
                getch();
                m=0;
                s=0;
                if(cont==4){
                    strcpy(status,"PAUSA 20min ");
                }else{
                    strcpy(status,"PAUSA");
                }
                break;
            }
        }//WHILE
        /*CRONOMETRO PAUSA*/
        while(1){
            if(cont==4){
                break;
            }
            printf("Tempo %s: %02d:%02d", status, m, s);
            Sleep(TEMPO);
            system("cls");
            s++;
            if(s==60){
                s = 0;
                m++;
            }
            if(m==intervalo){
                printf("\a \nENTER PARA INICIAR POMODORI\n");
                intervalo=POMODORI;
                getch();
                m=0;
                s=0;
                strcpy(status,"POMODORI");
                break;
            }
        }//WHILE
        /*PAUSA DE 20 MINUTOS*/
            while(cont==4){
                printf("Tempo %s: %02d:%02d", status, m, s);
                Sleep(TEMPO);
                system("cls");
                s++;
                if(s==60){
                    s = 0;
                    m++;
                }
                if(m==intervalo){
                    cont=0;
                    printf("\a \nENTER PARA INICIAR POMODORI\n");
                    intervalo=POMODORI;
                    getch();
                    m=0;
                    s=0;
                    strcpy(status,"POMODORI");
                    break;
                }
        }//WHILE
    }



    printf("\n\n");
    system("pause");
    return 0;
}
