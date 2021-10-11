//Nome Completo: Maria Clara Rodrigues Silva    
//Curso: Engenharia de Software

#include <stdio.h> //biblioteca para uso de printf e scanf
#include <locale.h> //biblioteca que permite a acentuação dentro do printf
#include <string.h> //biblioteca para (strlen-Determina o tamanho de uma string) 
#include <stdlib.h> //biblioteca responsável pelo comando system();
#include <ctype.h> //biblioteca para o uso do toupper
#include "conio.h" //biblioteca para uso das cores na fonte

int main(){
	setlocale(LC_ALL, "Portuguese");
	int valor, valorMenor[200], id, num, i, j, assentos, idade[200], numPessoas, reservado[200], confirmado[200], cancelado[200];
	float  somaValorMenor, somaValorNormal, somaValor, somaReservas, somaReservados, somaConfirmados, somaDisponiveis, somaCancelado;
	char  nomeDestino[100];
	
	//contextualização para o usuario
	printf("\n---> Seja Bem-vindo(a) a venda de passagens aéreas da empresa SALUMAR LINHAS AÉREAS!\n");
	printf("\n");
	printf("---> INFORME!\n");
	printf("\n");
		//ENTRADA E PROCESSAMENTO
		do{
			printf("  Qual o nome do destino que será visitado? ");
			fgets(nomeDestino, 100, stdin);
				if(strlen(nomeDestino) < 2)
					printf("    --> ERRO! O destino não pode ser vazio!            \n");
			} while(strlen(nomeDestino) < 2); //repetição quando o nome do destino estiver vazio
		
			do{
				printf("\n |ATENÇÃO| O NÚMERO DE ASSENTOS PRECISA SER DIVISÍVEL POR 10!"); //adicionei essa condição para facilitar alguns cálculos
				printf("\n  Quantos assentos estão disponíveis nesse avião? ");
				scanf("%d", &assentos);
					if(assentos < 90 || assentos > 200)
						printf("    ---> ERRO! O número de assentos dessa empresa é igual ou maior que 90 e menor do que 200!\n");
			}while(assentos < 90 || assentos > 200 || (assentos % 10 != 0) );
			printf("\n  Qual o valor da passagem (em reais) para esse destino? ");
			scanf("%d", &valor);
	
	system("cls");
	printf("\n");
	textcolor(15); printf("---> (MENU) INFORME A OPÇÃO DESEJADA!"); //adicionei a cor branca para que o texto não mude de cor após a opção 1 e 5
	printf("\n");
	//inicializações em 0 para não interferir na soma
	somaConfirmados = 0;
	somaCancelado = 0;
	somaReservas = 0;
	somaValor = 0;
	somaValorMenor = 0;
	somaDisponiveis = 0;
	//contextualização do menu e escolha da opção
	do{
		printf("\n");
		textcolor(15);	printf("--> |1| Visualizar ocupação do vôo \n--> |2| Efetuar reserva \n--> |3| Confirmar uma reserva \n--> |4| Cancelar uma reserva \n--> |5| relatório \n--> |0| fechar o sistema");
		printf("\n");
		printf("\nEscolha a opção: ");
		scanf("%d", &num);
		fflush(stdin);
		//entradas e processamento do menu
		switch(num){
		case 1:	
			system("cls");
			printf("\n                  --> O MAPA DE ASSENTOS DO VÔO\n");
			printf("\n");
				
			for(i = 0; i < assentos / 10; i++){
				for(j = 0; j < 10; j++){
					textcolor(2); printf("D[%d][%d]\t", i, j);	//apenas para efeito de visualização do mapa	
					// As cores solicitados foram usados no relatorio							
				}
				printf("\n");
			}			
		
			break;
		case 2:
			system("cls");
			printf("\n---> FAÇA A RESERVA DE UM ASSENTO! CASO TENHA DÚVIDAS CONFIRA O MAPA DE ASSENTOS!(1)");
			printf("\n---> INSTRUÇÕES: \n"); //contextualização
			printf("\n*** Cada pessoa possui um id de identificação!\n*** Para realizar reservar, cancelar, ou confirmar o assento informe esse id!\n");
			printf("*** Caso você informe outro número o sistema irá entender que você não deseja prosseguir naquela operação!\n");
			do{
				printf("\n  Quantas pessoas farão reserva? ");
				scanf("%d", &numPessoas);
				if(numPessoas > assentos){
					printf("  --> NÚMERO SUPERIOR AO NÚMERO DE ASSENTOS [%d] DISPONÍVEIS\n", assentos);
				}
			}while(numPessoas > assentos);
			
			
			for(id = 1; id <= numPessoas; id++){				
					printf("\n  Qual a idade da pessoa de id[%d]? ", id);
					scanf("%d", &idade[id]);
					fflush(stdin);
						if(idade[id] <= 5){ //possibilita que as passagens de meia sejam contadas
							valorMenor[id] = valor / 2; //salva os valores das idades <= 5 para uso posterior
						}
											
					printf("  Para realizar a reserva informe o id[%d] ", id);
					scanf("%d", &reservado[id]);
					fflush(stdin);
						if(reservado[id] == id && idade[id] <= 5){
							printf("=====================================\n");
							printf("  RESERVA REALIZADA!\n");
							printf("  O valor dessa passagem será: R$ %d\n", valorMenor[id]); //informado o valor da passagem conforme solicitado
							printf("=====================================\n");
							somaReservas = reservado[id];
						}
							else if(reservado[id] == id ){
								printf("=====================================\n");
								printf("  RESERVA REALIZADA!\n");
								printf("  O valor dessa passagem será: R$ %d\n", valor); //informado o valor da passagem conforme solicitado
								printf("=====================================\n");
								somaReservas = reservado[id];
							}
								else{
									printf("  OK, NÃO FAREMOS A RESERVA!\n");
								} 				
			}
			break;
		case 3:
			//Essa parte realiza a confirmação dos assentos, e garante que para que haja a confirmação exista uma reserva
			printf("\n   --> AS RESERVAS FORAM FEITAS!");
			printf("\n");
			
			for(id = 1; id <= numPessoas; id++){
				printf("\n    --> PARA CONFIRMAR A RESERVA DO INTERESSADO INFORME O SEU ID [%d]: ", id);
				scanf("%d", &confirmado[id]);
				if(confirmado[id] != reservado[id] && confirmado[id] == id){ //confere se o id pertence a reservas
					printf("   --> ESSE ASSENTO NÃO FOI RESERVADO!\n");
				}
					else if(confirmado[id] == reservado[id] && confirmado[id] == id && idade[id] <= 5){ //condição para possibilitar o calculo dos valores de idade <= 5
						printf("==========================\n");
						printf("    ASSENTO CONFIRMADO!\n");
						printf("==========================\n");
						somaConfirmados = confirmado[id]; 
						somaValorMenor = somaValorMenor + valorMenor[id]; //calculo dos valores de passagens de interessados com idade <= 5	
					}	
						else if(confirmado[id] == reservado[id] && confirmado[id] == id && idade[id] > 5){ //calculo dos valores de passagens de interessados de outras idades
							printf("==========================\n");
							printf("    ASSENTO CONFIRMADO!\n");
							printf("==========================\n");
							somaConfirmados = confirmado[id];
							somaValorNormal = (valor * somaConfirmados) / 2;	
						}
							else{
								printf("==========================\n");				
								printf("    OK, O ASSENTO CONTINUARÁ RESERVADO!\n");
								printf("==========================\n");
							}	
				somaValor = somaValorMenor + somaValorNormal; // soma do valor total das passagens para mostrar no relatorio
			 }
			
			break;			
		case 4:	
			//Essa parte realiza a cancelamento dos assentos, e garante que para que haja a cancelamento exista uma reserva
			//Caso o assento já tenha sido confirmado não é permitido cancelar
			for(id = 1; id <= numPessoas; id++){
				printf("------> PARA REALIZAR O CANCELAMENTO DA RESERVA INFORME O SEU ID(%d): ",id);
				scanf("%d", &cancelado[id]);
					if(cancelado[id] != reservado[id] && cancelado[id] == id){
						printf("   --> ESSE ASSENTO NÃO FOI RESERVADO!\n");
					}
						else if(cancelado[id] == reservado[id] && cancelado[id] == id && cancelado[id] == confirmado[id]){
							printf("ESSE ASSENTO JÁ TEVE A RESERVA CONFIRMADA, IMPOSSIVEL CANCELAR!\n");
						}
							else if(cancelado[id] == reservado[id] && cancelado[id] == id && cancelado[id] != confirmado[id]){
								printf("  RESERVA DE ASSENTO CANCELADA!\n");
								if(cancelado[id] >= 1){
									somaCancelado = cancelado[id] - somaConfirmados;
								}
								else somaCancelado = cancelado[id];
								 							
							}
								else{
									printf("  OK, O ASSENTO CONTINUARÁ RESERVADO!\n");
								}			 					
			}
			break;
			
		case 5:
			somaReservados = somaReservas - somaConfirmados - somaCancelado; //soma de reservas para mostrar no relatorio
			somaDisponiveis = assentos - somaConfirmados; //soma de disponiveis para mostrar no relatorio
			//Relatorio com os dados solicitados no problema
			printf("\n");
			printf("   ============================\n");
			printf("            RELATÓRIO:\n");
			printf("   ============================\n");		
			printf("   ---> DADOS DOS ASSENTOS!\n");	
			printf("   ============================\n");		
			textcolor(2); printf("   %.2f estão |D- disponíveis|\n", somaDisponiveis);
			textcolor(4); printf("   %.2f estão |R - reservados|\n", somaReservados);
			textcolor(1); printf("   %.2f estão |C - confirmados|\n", somaConfirmados);
			textcolor(15); printf("   ============================\n");	
			printf("   ---> DADOS DAS VENDAS!\n");
			printf("   ============================\n");		
			printf("   O vôo com destino para %s", nomeDestino);
			printf("   ============================\n");		
			printf("   [Rendeu R$ %.2f em vendas]\n", somaValor);
			printf("   ============================\n");				
		}	
			
	}while(num != 0);

	
	return 0;
}
