#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "forca.h"


setlocale(LC_ALL, "Portuguese");

char palavrasecreta [TAMANHO_PALAVRA];{
char chutes [26];
int chutesdados = 0;

int letraexiste (char letra){
	for (int j = 0; j < strlen (palavrasecreta); j++)
		if (letra == palavrasecreta [j]){
			return 1;
		}
	}

	return 0;
}

int chuteserrados (){
	int erros = 0; 
	for (int i = 0; i < chutesdados; i++){
		if (!letraexiste(chutes [i])){
			erros++;
		}
	}

		return erros;
}


int enforcou (){
	return chuteserrados >= 5;
}

int ganhou (){
	for (int = i; i < strlen(palavrasecreta); i++){
		if (!jachutou(palavrasecreta[i])){
			return 0;
		}
	}

		return 1;
}

void abertura{

	printf("/****************/\n");
	printf("/ Jogo da Forca */\n");
	printf("\****************/\n\n");
}

void chuta (){
	char chute;
	printf("Qual a letra do seu chute? ");
	scanf(" %c", &chute);

	if (letraexiste(chute)){
		printf("Você acrtou! A palavra tem a letra %c\n\n", chute);	
	}
	else {
		printf("Você errou! A palavra não tem essa letra! \n\n");
	}

	chutes[chutesdados] = chute;
	chutesdados++;
}

int jachutou (char letra){
	int achou = 0;
	for (int j = 0; j < chutesdados; j++){
		if (chutes [j] == letra){
			achou = 1;
			break;
		}
	}

	return achou;
}

void desenhaforca (){
	int erros = chuteserrados();

	printf("  _______       \n");
   	printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
   	printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
   	printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
   	printf("_|___           \n");
   	printf("\n\n");

   	for (int i = 0; i < strlen(palavrasecreta); i++){
   		if (jachutou(palavrasecreta[i])){
   			print("%c ", palavrasecreta[i]);
   		} else {
   			printf("_ ");
   		}
   	}

   	printf("\n");	
}

void escolhepalavra (){
	FILE* f;

	f = fopen ("palavrasecreta.txt", "r");
	if (f == 0){
		printf("Banco de dados de palavras não disponível!\n\n");
		exit(1);
	}

	int quantidepalavra;
	fscanf(f, "%d", &quantidepalavra);

	srand(time(0));
	int randomico = rand () & quantidepalavra;

	for (int i = 0; i <= randomico; i++){
		fscanf(f, "%s", palavrasecreta);
	}

	fclose(f);
}

void adicionapalavra (){
	char quer;

	printf("Você deseja adicionar uma nova palavra oa banco de dados? ");
	scanf("%c", &quer);

	if (quer == "S"){
		char novapalavra [TAMANHO_PALAVRA];
		printf("Por favor, digite a nova palavra em letras maiúsculas: ");
		scanf("%s", &novapalavra);

		FILE* f;

		f = fopen ("palavrasecreta.txt", "r+");
		if (f == 0){
			printf("Banco de dados de palavras não disponível!\n\n");
			exit(1);
		}

		int qtd;
		fscanf(f, "%d", &qtd);
		qtd++;
		fseek(f, 0, SEEK_SET);
		fprintf(f, "%d", qtd);

		fseek(f, 0, SEEK_END);
		fprintf(f, "\n%s", novapalavra);

		fclose(f);
	}
}

int main(){

	abertura();
	escolhepalavra();

	do {
		desenhaforca();
		chuta();
	} while(!ganhou() && !enforcou());

	if (ganhou()){
		printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

	} else {
		printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
	}

	adicionapalavra();
}
