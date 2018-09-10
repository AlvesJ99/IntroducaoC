#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void menu();
void fatorial();
void primo();
void primo2();
void nprimos();
void potenciacao();
void radiciacao();
void anob();
void notas();
void notasp();
void matriculah();

int main()
{
	menu();
	printf("Fim do programa.");
}
void fatorial(){
	int n, x;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);
    //Solicita o numero ao usuario e guarda em n.
    
    if (n > 0){
        x = n;
    }
    else
        printf("Numero invalido!\n");
    //Verifica se o numero digitado e maior que 0, caso nao seja retorna erro.
    
    for (x; n > 1 ; n--){ //Atribui x como variavel de inicializacao, verifica se o numero armazenado ainda e maior que 1, se for, e executa o comando e decrementara 1.
	    x*= (n-1); 
		/*Ira multiplicar o numero armazenado por ele mesmo menos 1 e guardara o resultado na variavel x, será decrementado 1 do contador auxiliar.
		Por exemplo: se o usuario digitar 5, sera feita a operacao 5x4, o resultado (20) sera guardado na variavel x e o contador decrementa 1 (ficando 4).
		No proximo loop ele pega os 20 armazenados em x e multiplica pelo numero guardado no contador (4) menos 1, ficando 3, o resultado da operacao e 60,
		decrementa 1 do contador novamente, ficando 3. Fara a mesma operacao ate que o contador nao seja maior que 2, pois nesse caso o numero final (120),
		sera multiplicado por 1.*/
    }
    printf("Resultado: %d \n", x);
    return;
}
void menu(){
	int n = 1;
	printf("Bem vindo, digite o numero da operacao desejada: \n ");
    while(n!=0) {
        printf("\n 1 para fatorial... \n 2 para numeros primos... \n 3 para n numeros primos...");
        printf("\n 4 para potenciacao... \n 5 para radiciacao... \n 6 para ano bissexto...");
        printf("\n 7 para media de notas... \n 8 para media ponderada de notas...");
        printf("\n 9 para matricula hexadecimal... \n 0 para sair...: ");
        scanf("%d", &n);
        printf(" Numero digitado: %d \n \n", n);
        switch(n) {
            case 0:
                goto fim;
            case 1:
                fatorial();
                break;
            case 2:
                primo();
                break;
            case 3:
            	nprimos();
            	break;
            case 4: 
            	potenciacao();
            	break;
            case 5:
            	radiciacao();
            	break;
            case 6:
            	anob();
            	break;
            case 7:
            	notas();
            	break;
            case 8:
            	notasp();
            	break;
            case 9:
            	matriculah();
            	break;
            default:
                printf("Opcao invalida.\n");
        }
    }
    fim:
    return;
}
void primo(){
	/* Algoritmo 2: o primeiro algoritmo utiliza muito processamento em caso de numeros grandes, tendo que dividir um numero nao primo ate sua metade,
	onde encontrara 0 como resto. Por exemplo: o usuario inseriu o numero 50000, para fazer a verificacao o algoritmo precisaria realizar 24999
	operacoes ate chegar nos 25000 e finalmente ter resto 0. A proposta desse algoritmo e diminuir o processamento nesse tipo de situacao, realizando
	divisoes sucessivas por numeros maiores que 1 e ao mesmo tempo menores que o numero inserido pelo usuario.*/
	
	int n, x, resto=1;
    printf("Digite um numero: ");
    scanf("%d", &n);
    
    for (x = 2; x < n && resto != 0; x++){ /* Armazena em x todos os numeros abaixo do numero inserido pelo usuario a partir de 2, a primeira condicao
	do loop e que o divisor (n) seja maior que o dividendo (x), ja que se fossem iguais o resto da divisao seria 0 e todos os numeros seriam considerados
	nao primos. A segunda condicao e que o resto seja diferente de 0, so que dessa vez um numero nao primo muito grande sera dividido de cara por 2 ou algum
	outro numero pequeno, economizando milhares de operacoes.*/
    	
		resto = n % x; // Resto recebe a divisao entre o numero estatico inserido pelo usuario e os numeros abaixo dele (em ordem crescente) guardados no contador (x).
    	
		//printf("%d \n", resto);
	}
    if (resto == 0){
    	printf("O numero inserido nao e primo. \n");
	}
	else
		printf("O numero inserido e primo. \n");
    return;
}
void nprimos(){
	int loop=1, n, x, resto=1;
	while (loop !=0){
		printf("Digite um numero (0 para sair): ");
		scanf("%d", &loop);
		n = loop;
		
		if (loop == 0){
			break;
		}
		for (x = 2; x < n && resto !=0; x++){
			resto = n % x;
		}
    	if (resto == 0){
    		printf("O numero inserido nao e primo. \n");
    		resto=1; /*Necessario para quando o primeiro numero nao primo for inserido, pois uma vez que resto e igual a 0, o loop FOR nunca sera iniciado novamente,
			ja que nao se encaixa em uma das condicoes AND, e como nao temos RETURN no while, a variavel resto seria 0 ate que o loop fosse encerrado.*/
		}
		else
			printf("O numero inserido e primo. \n");
	}
}
void potenciacao(){
	float base, res;
	int exp;
	
	printf("Digite a base da potencia: ");
	scanf("%f", &base);
	printf("Digite o expoente da potencia: ");
	scanf("%d", &exp);
	
	res = pow(base, exp);
	
	printf("O resulado de %.1f elevado a %d e: %.2f\n", base, exp, res);
	printf("Resultado em forma cientifica: %E \n", res);
	
	return;
}
void radiciacao(){
	float radical, res;
	int radicando;
	
	printf("Digite o radicando da raiz: ");
	scanf("%d", &radicando);
	printf("Digite o radical da raiz: ");
	scanf("%f", &radical);
	
	res = pow(radicando, 1.0/radical);
	
	printf("Raiz de %d com indice %.f.\nResultado: %.2f\n", radicando, radical, res);
	printf("Resultado em forma cientifica: %E \n", res);
	
	return;
}
void anob(){
	int ano=1;
	int resto = 1;
	
	printf("Digite o numero de um ano: ");
	scanf("%d", &ano);
	
	if(ano <= 0){
		printf("Ano inexistente!\n");
		goto fim;
	}
	resto = ano % 4;
	
	if(resto==0){
		printf("O ano %d e bissexto.\n", ano);
	}
	else 
		printf("O ano %d nao e bissexto.\n", ano);
		
	fim:
	return;
}
void notas(){
	float n1=0.0,n2=0.0,media=1.0;
	
	printf("Insira duas notas separadas por virgula: ");
	scanf("%f, %f", &n1, &n2);
	
	media = (n1 + n2)/2;
	
	if ((n1 >=0.0 && n1<=10.0) && (n2>=0.0 && n2<=10.0)){
		printf("Nota 1: %.1f\nNota 2: %.1f\n", n1,n2);
		printf("Sua media e: %.2f\n", media);
	}
	else
		printf("Uma ou mais notas invalidas!\n");
	return;
}
void notasp(){
	int n1=0,n2=0,n3=0,media=1;
	
	printf("Insira tres notas separadas por virgula: ");
	scanf("%d, %d, %d", &n1, &n2, &n3);
	
	if ((n1 >=0 && n1<=100) && (n2>=0 && n2<=100) && (n3>=0 && n3<=100)){
		printf("Nota 1: %d\nNota 2: %d\nNota 3: %d\n", n1,n2,n3);
	}
	else
		printf("Uma ou mais notas invalidas!\n");
		
	media = ((n1 + n2)+(n3*2))/4;
	
	if(media >=60){
		printf("Aprovado, pontuacao: %d.\n", media);
	}
	else
		printf("Reprovado, pontuacao: %d.\n", media);
}
void matriculah(){
	int mat=1810023274;
	char *nome = "Rildo Alves Pereira Filho";
	
	printf("Meu nome: %s, minha matricula: %d.\n", nome, mat);
	printf("Minha matricula em hexadecimal: %X\n", mat);
	
	return;
}


