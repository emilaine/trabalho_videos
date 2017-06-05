#include<stdio.h>

main(){
	int hab;
	
	while(1){
		printf("\n\n Tempo de Caminhada\n\n\t");
		printf("\n 1-Tomar Decisao de Fazer Caminhada");
		printf("\n 2-Primeira Semana");
		printf("\n 3-Programacao");
		printf("\n 4-Segunda Semana");
		printf("\n 5-Terceira Semana");
		printf("\n 6-Objetivo final");
		printf("\n 0-Meus Parabens Voce Conseguio\n");
		scanf("%d",&hab);
		switch(hab){ 
		case 1:printf("15 dias");
		break;
		case 2:printf("10 Minutos Caminhada");
		break;
		case 3:printf("15 minutos Caminhada");
		break;
		case 4:printf("20 minutos Caminhada");
		break;
		case 5:printf("25 minutos Caminhada");
		break;
		case 6:printf("30 Minutos Caminhada");
		break;
		case 0:return;
		default:printf("digitou a opcao invalida");
		}//fim switch
	}// fim while
	return 0;
}//fim main
