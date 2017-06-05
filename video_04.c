#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Autores
Nome Emilaine RA 2216112399
Nome Mauricio RA 2216101424
Nome Welington RA 2216100696
*/

#define MAX 10

int t_horas(int h, int m){
    m += h*60;
    m = m-((m*20)/100);
    h = m/60;
    return h;
}

int t_minutos(int h, int m){
    int horas;

    m += h*60;
    m = m-((m*20)/100);
    horas = m/60;
    m = (m-horas*60)%60;
    return m;
}
int tempo_total_otimizado(int h, int m){
    m += (h*60);
    m = m-((m*20)/100);
    return m;
}
int tempo_total(int h, int m){
    m += (h*60);
    return m;
}
int tempo_livre(int h, int m){
    m += (h*60);
    m = (m*20)/100;
    return m;
}

int main(){
    int i, j, cont, total, h, m;
    int tempo1=0, hora1=0, minuto1=0, tempo2=0, hora2=0, minuto2=0, tempoHoras=0, tempoMinutos=0, tempo3=0, hora3=0, minuto3=0;
    int aux1, aux2, aux3;
    char captura[50], aux4[50], data[20], nomearq[20] = "Cronograma_", dat[20];
    struct ficha {
        char tarefa[50];
        int horas;
        int minutos;
        int prioridade;
    };
    struct ficha cronograma[MAX];
    FILE *file;

    printf("VAMOS FAZER O CRONOGRAMA DIARIO DAS TAREFAS\n");
    printf("Digite a data de hoje [dd-mm-aaaa]: ");
    gets(data);

    strcpy(dat, data);//RECUPERA A DATA PARA TITULO DO ARQUIVO
    /*GERAR NOME DO ARQUIVO*/
    strcat(nomearq,data);
    strcat(nomearq,".txt");


    cont = 0; /*ZERA A VARIAVEL CONTADORA*/
    while(1){
        printf("\n\nDigite o nome da Tarefa ou [. para finalizar]: ");
        fflush(stdin);
        gets(captura);
        if(strcmp(captura,".")==0){
            break;
        }
        strcpy(cronograma[cont].tarefa, captura);
        do{
            if(cronograma[cont].horas < 0 || cronograma[cont].minutos < 0){
                printf("A data nao pode ser negativa\n");
            }
            printf("Quanto tempo leva pra fazer essa tarefa em horas? [hh:mm]: ");
            scanf("%d:%d", &cronograma[cont].horas, &cronograma[cont].minutos);
        }while(cronograma[cont].horas < 0 || cronograma[cont].minutos < 0);
        do{
            printf("Digite um numero de 1 a 10");
            printf("Classifique essa tarefa com uma prioridade de [1 - 10]: ");
            scanf("%d", &cronograma[cont].prioridade);
        }while(cronograma[cont].prioridade < 1 || cronograma[cont].prioridade > 10);

        cont++;
    }//WHILE
    total = cont; //RECEBE A QUANTIDADE TOTAL DE TAREFAS LIDAS

    for(j=0;j<total;j++){
        for(i=0;i<total-j-1;i++){
            if(cronograma[i].prioridade < cronograma[i+1].prioridade){
                /*PRIORIDADE*/
                aux1 = cronograma[i].prioridade;
                cronograma[i].prioridade = cronograma[i+1].prioridade;
                cronograma[i+1].prioridade = aux1;
                /*MINUTOS*/
                aux2 = cronograma[i].minutos;
                cronograma[i].minutos = cronograma[i+1].minutos;
                cronograma[i+1].minutos = aux2;
                /*HORAS*/
                aux3 = cronograma[i].horas;
                cronograma[i].horas = cronograma[i+1].horas;
                cronograma[i+1].horas = aux3;
                /*TAREFA*/
                strcpy(aux4,cronograma[i].tarefa);
                strcpy(cronograma[i].tarefa, cronograma[i+1].tarefa);
                strcpy(cronograma[i+1].tarefa, aux4);
            }
        }
    }
    file = fopen(nomearq,"w"); //ABRE O ARQUIVO

    printf("\n\n---- TENTE EXECUTAR A TAREFA NESSA ORDEM ----\n\n");

    for(i=0;i<total;i++){
        printf("\n---------------------------------------------------\n");
        printf("Tarefa %d: %s\n", i+1, cronograma[i].tarefa);
        printf("Tempo estimado: %d:%02d hrs\n", cronograma[i].horas, cronograma[i].minutos);
        tempoHoras += cronograma[i].horas;
        tempoMinutos += cronograma[i].minutos;
        printf("Tente executar a tarefa em %d:%02d hrs\n", t_horas(cronograma[i].horas, cronograma[i].minutos), t_minutos(cronograma[i].horas, cronograma[i].minutos));
    }

    /*CALCULA O TEMPO TOTAL DE TODAS AS TAREFAS*/
    tempo1 = tempo_total(tempoHoras, tempoMinutos); //CHAMA A FUNÇÃO DE CALCULO TOTAL DO TEMPO
    hora1 = tempo1/60; //CALCULA HORA TOTAL
    minuto1 = (tempo1-hora1*60)%60; //CALCULA MINUTOS TOTAL
    /*CALCULA O TEMPO OTIMIZADO DAS TAREFAS*/
    tempo2 = tempo_total_otimizado(tempoHoras, tempoMinutos); //CHAMA A FUNÇÃO DE CALCULO TOTAL DO TEMPO OTIMIZADO
    hora2 = tempo2/60; //CALCULA HORA OTMIZADA
    minuto2 = (tempo2-hora2*60)%60;//CALCULA MINUTOS OTIMIZADOS
    /*CALCULA O TEMPO LIVRE GANHO NO DIA*/
    tempo3 = tempo_livre(tempoHoras, tempoMinutos); //CHAMA A FUNÇÃO DE CALCULO TOTAL DO TEMPO OTIMIZADO
    hora3 = tempo3/60; //CALCULA HORA OTMIZADA
    minuto3 = (tempo3-hora3*60)%60;//CALCULA MINUTOS OTIMIZADOS

    /*IMPRESSAO DO TEMPO TOTAL E LIVRE DE TODAS AS TAREFAS*/
    printf("\n---------------------------------------------------\n");
    printf("               TEMPO TOTAL DAS TAREFAS");
    printf("\n---------------------------------------------------\n\n");
    printf("TEMPO TOTAL ESTIMADO DAS TAREFAS: %d:%02d hrs\n", hora1, minuto1);
    printf("TEMPO TOTAL OTIMIZADO DAS TAREFAS: %d:%02d hrs\n", hora2, minuto2);
    printf("RECOMPENSA TEMPO LIVRE: %d:%02d hrs\n", hora3, minuto3);


    /*GRAVAR NO ARQUIVO DE TEXTO O CRONOGRAMA*/
        fprintf(file, "CRONOGRAMA DO DIA: ");
        fputs(dat, file);
        fprintf(file, "\n");
        fprintf(file,"(Obs: Va marcando as tarefas para que voce tenha maior controle)\n");

    for(i=0;i<total;i++){
        fprintf(file, "\n---------------------------------------------------\n");
        fprintf(file, "Tarefa %d: %s\n", i+1, cronograma[i].tarefa);
        fprintf(file, "Tempo estimado: %d:%02d hrs\n", cronograma[i].horas, cronograma[i].minutos);
        fprintf(file, "Tente executar a tarefa em %d:%02d hrs\n", t_horas(cronograma[i].horas, cronograma[i].minutos), t_minutos(cronograma[i].horas, cronograma[i].minutos));
        fprintf(file, "\nTAREFA CONCLUIDA [ ]\n");
    }//FOR

    fprintf(file, "\n---------------------------------------------------\n");
    fprintf(file, "               TEMPO TOTAL DAS TAREFAS");
    fprintf(file, "\n---------------------------------------------------\n\n");
    fprintf(file, "TEMPO TOTAL ESTIMADO DAS TAREFAS: %d:%02d hrs\n", hora1, minuto1);
    fprintf(file, "TEMPO TOTAL OTIMIZADO DAS TAREFAS: %d:%02d hrs\n", hora2, minuto2);
    fprintf(file, "RECOMPENSA TEMPO LIVRE: %d:%02d hrs\n", hora3, minuto3);

    fclose(file); //FECHA O ARQUIVO

    printf("\npressione ENTER para prosseguir");
    getch();
    system("cls");

    printf("Cronograma gerado com sucesso\n");
    printf("Nome do arquivo %s\n", nomearq);
    printf("\n----------------------------------- INSTRUCOES ---------------------------------\n\n");
    printf("\tImprima o cronograma que se encontra no mesmo diretorio do programa\n");
    printf("\te tente cumprir as tarefas na ordem estipulada, tente sempre fazer\n");
    printf("\tno menor tempo possivel, assim a recompensa sera maior,\n");
    printf("\t e vai te sobrar mais tempo para o lazer.\n");
    printf("\n--------------------------------------------------------------------------------\n\n");

    getch();
    return 0;
}
