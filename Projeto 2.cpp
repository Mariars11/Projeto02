//Nome Completo: Maria Clara Rodrigues Silva  
//Matr�cula: UC21100014  
//Curso: Engenharia de Software

#include <stdio.h> //biblioteca para uso de printf e scanf
#include <locale.h> //biblioteca que permite a acentua��o dentro do printf
#include <string.h> //biblioteca para (strlen-Determina o tamanho de uma string) 
#include <stdlib.h> //biblioteca respons�vel pelo comando system();
#include <ctype.h> //biblioteca para o uso do toupper
#include "conio.h" //biblioteca para uso das cores na fonte

int main(){
	setlocale(LC_ALL, "Portuguese");
	int valor, valorMenor[200], id, num, i, j, assentos, idade[200], numPessoas, reservado[200], confirmado[200], cancelado[200];
	float  somaValorMenor, somaValorNormal, somaValor, somaReservas, somaReservados, somaConfirmados, somaDisponiveis, somaCancelado;
	char  nomeDestino[100];
	
	//contextualiza��o para o usuario
	printf("\n---> Seja Bem-vindo(a) a venda de passagens a�reas da empresa SALUMAR LINHAS A�REAS!\n");
	printf("\n");
	printf("---> INFORME!\n");
	printf("\n");
		//ENTRADA E PROCESSAMENTO
		do{
			printf("  Qual o nome do destino que ser� visitado? ");
			fgets(nomeDestino, 100, stdin);
				if(strlen(nomeDestino) < 2)
					printf("    --> ERRO! O destino n�o pode ser vazio!            \n");
			} while(strlen(nomeDestino) < 2); //repeti��o quando o nome do destino estiver vazio
		
			do{
				printf("\n |ATEN��O| O N�MERO DE ASSENTOS PRECISA SER DIVIS�VEL POR 10!"); //adicionei essa condi��o para facilitar alguns c�lculos
				printf("\n  Quantos assentos est�o dispon�veis nesse avi�o? ");
				scanf("%d", &assentos);
					if(assentos < 90 || assentos > 200)
						printf("    ---> ERRO! O n�mero de assentos dessa empresa � igual ou maior que 90 e menor do que 200!\n");
			}while(assentos < 90 || assentos > 200 || (assentos % 10 != 0) );
			printf("\n  Qual o valor da passagem (em reais) para esse destino? ");
			scanf("%d", &valor);
	
	system("cls");
	printf("\n");
	textcolor(15); printf("---> (MENU) INFORME A OP��O DESEJADA!"); //adicionei a cor branca para que o texto n�o mude de cor ap�s a op��o 1 e 5
	printf("\n");
	//inicializa��es em 0 para n�o interferir na soma
	somaConfirmados = 0;
	somaCancelado = 0;
	somaReservas = 0;
	somaValor = 0;
	somaValorMenor = 0;
	somaDisponiveis = 0;
	//contextualiza��o do menu e escolha da op��o
	do{
		printf("\n");
		textcolor(15);	printf("--> |1| Visualizar ocupa��o do v�o \n--> |2| Efetuar reserva \n--> |3| Confirmar uma reserva \n--> |4| Cancelar uma reserva \n--> |5| relat�rio \n--> |0| fechar o sistema");
		printf("\n");
		printf("\nEscolha a op��o: ");
		scanf("%d", &num);
		fflush(stdin);
		//entradas e processamento do menu
		switch(num){
		case 1:	
			system("cls");
			printf("\n                  --> O MAPA DE ASSENTOS DO V�O\n");
			printf("\n");
				
			for(i = 0; i < assentos / 10; i++){
				for(j = 0; j < 10; j++){
					textcolor(2); printf("D[%d][%d]\t", i, j);	//apenas para efeito de visualiza��o do mapa	
					// As cores solicitados foram usados no relatorio							
				}
				printf("\n");
			}			
		
			break;
		case 2:
			system("cls");
			printf("\n---> FA�A A RESERVA DE UM ASSENTO! CASO TENHA D�VIDAS CONFIRA O MAPA DE ASSENTOS!(1)");
			printf("\n---> INSTRU��ES: \n"); //contextualiza��o
			printf("\n*** Cada pessoa possui um id de identifica��o!\n*** Para realizar reservar, cancelar, ou confirmar o assento informe esse id!\n");
			printf("*** Caso voc� informe outro n�mero o sistema ir� entender que voc� n�o deseja prosseguir naquela opera��o!\n");
			do{
				printf("\n  Quantas pessoas far�o reserva? ");
				scanf("%d", &numPessoas);
				if(numPessoas > assentos){
					printf("  --> N�MERO SUPERIOR AO N�MERO DE ASSENTOS [%d] DISPON�VEIS\n", assentos);
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
							printf("  O valor dessa passagem ser�: R$ %d\n", valorMenor[id]); //informado o valor da passagem conforme solicitado
							printf("=====================================\n");
							somaReservas = reservado[id];
						}
							else if(reservado[id] == id ){
								printf("=====================================\n");
								printf("  RESERVA REALIZADA!\n");
								printf("  O valor dessa passagem ser�: R$ %d\n", valor); //informado o valor da passagem conforme solicitado
								printf("=====================================\n");
								somaReservas = reservado[id];
							}
								else{
									printf("  OK, N�O FAREMOS A RESERVA!\n");
								} 				
			}
			break;
		case 3:
			//Essa parte realiza a confirma��o dos assentos, e garante que para que haja a confirma��o exista uma reserva
			printf("\n   --> AS RESERVAS FORAM FEITAS!");
			printf("\n");
			
			for(id = 1; id <= numPessoas; id++){
				printf("\n    --> PARA CONFIRMAR A RESERVA DO INTERESSADO INFORME O SEU ID [%d]: ", id);
				scanf("%d", &confirmado[id]);
				if(confirmado[id] != reservado[id] && confirmado[id] == id){ //confere se o id pertence a reservas
					printf("   --> ESSE ASSENTO N�O FOI RESERVADO!\n");
				}
					else if(confirmado[id] == reservado[id] && confirmado[id] == id && idade[id] <= 5){ //condi��o para possibilitar o calculo dos valores de idade <= 5
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
								printf("    OK, O ASSENTO CONTINUAR� RESERVADO!\n");
								printf("==========================\n");
							}	
				somaValor = somaValorMenor + somaValorNormal; // soma do valor total das passagens para mostrar no relatorio
			 }
			
			break;			
		case 4:	
			//Essa parte realiza a cancelamento dos assentos, e garante que para que haja a cancelamento exista uma reserva
			//Caso o assento j� tenha sido confirmado n�o � permitido cancelar
			for(id = 1; id <= numPessoas; id++){
				printf("------> PARA REALIZAR O CANCELAMENTO DA RESERVA INFORME O SEU ID(%d): ",id);
				scanf("%d", &cancelado[id]);
					if(cancelado[id] != reservado[id] && cancelado[id] == id){
						printf("   --> ESSE ASSENTO N�O FOI RESERVADO!\n");
					}
						else if(cancelado[id] == reservado[id] && cancelado[id] == id && cancelado[id] == confirmado[id]){
							printf("ESSE ASSENTO J� TEVE A RESERVA CONFIRMADA, IMPOSSIVEL CANCELAR!\n");
						}
							else if(cancelado[id] == reservado[id] && cancelado[id] == id && cancelado[id] != confirmado[id]){
								printf("  RESERVA DE ASSENTO CANCELADA!\n");
								if(cancelado[id] >= 1){
									somaCancelado = cancelado[id] - somaConfirmados;
								}
								else somaCancelado = cancelado[id];
								 							
							}
								else{
									printf("  OK, O ASSENTO CONTINUAR� RESERVADO!\n");
								}			 					
			}
			break;
			
		case 5:
			somaReservados = somaReservas - somaConfirmados - somaCancelado; //soma de reservas para mostrar no relatorio
			somaDisponiveis = assentos - somaConfirmados; //soma de disponiveis para mostrar no relatorio
			//Relatorio com os dados solicitados no problema
			printf("\n");
			printf("   ============================\n");
			printf("            RELAT�RIO:\n");
			printf("   ============================\n");		
			printf("   ---> DADOS DOS ASSENTOS!\n");	
			printf("   ============================\n");		
			textcolor(2); printf("   %.2f est�o |D- dispon�veis|\n", somaDisponiveis);
			textcolor(4); printf("   %.2f est�o |R - reservados|\n", somaReservados);
			textcolor(1); printf("   %.2f est�o |C - confirmados|\n", somaConfirmados);
			textcolor(15); printf("   ============================\n");	
			printf("   ---> DADOS DAS VENDAS!\n");
			printf("   ============================\n");		
			printf("   O v�o com destino para %s", nomeDestino);
			printf("   ============================\n");		
			printf("   [Rendeu R$ %.2f em vendas]\n", somaValor);
			printf("   ============================\n");				
		}	
			
	}while(num != 0);

	
	return 0;
}
