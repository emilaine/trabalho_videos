#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Autores
Nome Emilaine RA 2216112399
Nome Mauricio RA 2216101424
Nome Welington RA 2216100696
*/
int main(){
    char assunto[100];
    int quant_topicos = 0, i, j = 0, l, sort = 0, cont = 0, jaestudado[100], saiu=0;
    char nomearq[50] = "Conteudo_", folhaestudo[50] = "Resumo_";
    struct note {
        char topico[100];
        char resumo[2000];
    };
    struct note anotacoes[10];

    FILE *file;

    printf("\tAplicando a tecnica FEYNMAN\n");
    printf("\t\tQual o assunto que deseja estudar hoje?\n");
    fflush(stdin);
    gets(assunto);
    strupr(assunto);
    printf("\n");
    printf("\tConsegue dividir o assunto %s em quantos topicos?\n", assunto);
    scanf("%d", &quant_topicos);

    for(i=0;i<quant_topicos;i++){
        printf("\n\tQual e o nome do topico %d\n", i+1);
        fflush(stdin);
        gets(anotacoes[i].topico);
        strupr(anotacoes[i].topico);
    }

    printf("\n\tEstude um pouco a respeito desses topicos, quando estiver estudado tecle ENTER\n\n");
    getch();
    system("cls");
    srand(time(NULL));

    while(cont < quant_topicos){
        do{
            saiu = 0;
            sort = rand()%quant_topicos;
            for(i=0;i<=quant_topicos;i++){
                if(sort == jaestudado[i]){
                    saiu = 1;
                }
            }// FOR
        }while(saiu == 1);
        jaestudado[j]=sort;
        j++;

        printf("\tExplique com suas palavras sobre %s\n", anotacoes[sort].topico);
        printf("--------------------------------------------------------------\n");
        printf("\n");
        fflush(stdin);
        gets(anotacoes[sort].resumo);
        cont++;
        printf("\n\n");
    }//WHILE

    /*GERAR NOME DO ARQUIVO*/
    strcat(nomearq, assunto);
    strcat(nomearq, ".txt");

    file = fopen(nomearq,"w");//CRIA O ARQUIVO
    fprintf(file, "---------------------------------------------------------\n\t");
    fputs(assunto, file);
    fprintf(file, "\n---------------------------------------------------------\n\n");
    for(i=0;i<quant_topicos;i++){
        fputs(anotacoes[i].topico, file);
        fprintf(file, "\n---------------------------------------------------------\n");
        fputs(anotacoes[i].resumo, file);
        fprintf(file, "\n\n\n");
    }

    fclose(file);

    /*GERAR NOME DO ARQUIVO*/
    strcat(folhaestudo, assunto);
    strcat(folhaestudo, ".txt");

    file = fopen(folhaestudo,"w");//CRIA O ARQUIVO
    fprintf(file, "---------------------------------------------------------\n\t");
    fputs(assunto, file);
    fprintf(file, "\n---------------------------------------------------------\n\n");
    fputs("=> Procure explicar agora o conteudo de forma que fique o mais simples e objetivo possivel\n\n", file);
    for(i=0;i<quant_topicos;i++){
        fputs(anotacoes[i].topico, file);
        fprintf(file, "\n---------------------------------------------------------\n");
        fprintf(file, "\n\n\n\n\n\n\n\n\n\n\n\n\n");
    }

    printf("\n\tFORAM GERADOS 2(DOIS) ARQUIVOS\n\n");
    printf("-> O arquivo %s resumo que você escreveu\n", nomearq);
    printf("-> O arquivo %s contem somente os topicos procure rescrever sua explicacao do topico\n", folhaestudo);
    printf("de forma que fique mais simples e objetiva possivel, imprima e escreva a mao o novo resumo\n");
    printf("para que possa absorver o conteudo de forma mais eficiente\n\n");

    fclose(file);//FECHA O ARQUIVO

    system("pause");
    return 0;
}
