#include "arvore.h"


char* leitor_de_palavras();
int leitor_de_numeros();
int leitor_de_ano();
void limpador_de_buffer();
void reiniciar_arquivo(char* nome_arquivo);
int comparador_de_palavras(char* palavra1, char* palavra2);
char toupper_personalizado(char* letra);
void para_maisculo(char *palavra);
void menu();
void menuOperacoes(int input, char* nome_arquivo, No* raiz);