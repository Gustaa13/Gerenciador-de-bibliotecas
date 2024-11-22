#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/util.h"

char* leitor_de_palavras(){
    char* palavra = (char*)malloc(50 * sizeof(char));

    if (palavra == NULL){
        printf("Erro: Memoria insuficiente.\n");
        return NULL;
    }

    if(fgets(palavra, 50, stdin) != NULL){
        palavra[strcspn(palavra, "\n")] = '\0';
        
        if(strlen(palavra) == 49) {
            limpador_de_buffer();
        }

        return palavra;
    }
    else{
        printf("Erro ao ler o nome!\nDigite novamente: ");
        free(palavra);
        return leitor_de_palavras();
    }
}

int leitor_de_numeros(){
    int numero;
    int resultado;

    resultado = scanf("%d", &numero);

    if(resultado != 1 || numero <= 0 || numero >= 100000){
        printf("Numero invalido!\nDigite o numero novamente: ");
        limpador_de_buffer();
        return leitor_de_numeros();
    }

    limpador_de_buffer();
    return numero;
}

int leitor_de_ano(){
    int numero;
    int resultado;

    resultado = scanf("%d", &numero);

    if(resultado != 1 || numero <= 0 || numero > 2024){
        printf("Ano invalido!\nDigite o ano novamente: ");
        limpador_de_buffer();
        return leitor_de_numeros();
    }

    limpador_de_buffer();
    return numero;
}

void limpador_de_buffer(){
    while (getchar() != '\n');
}

void reiniciar_arquivo(char* nome_arquivo){
    FILE* arquivo = fopen(nome_arquivo, "w");
    fclose(arquivo);
}

char toupper_personalizado(char* letra) {
    if (strcmp(letra, "á") == 0) {
        strcpy(letra, "Á");
    } else if (strcmp(letra, "é") == 0) {
        strcpy(letra, "É");
    } else if (strcmp(letra, "í") == 0) {
        strcpy(letra, "Í");
    } else if (strcmp(letra, "ó") == 0) {
        strcpy(letra, "Ó");
    } else if (strcmp(letra, "ú") == 0) {
        strcpy(letra, "Ú");
    } else if (strcmp(letra, "ç") == 0) {
        strcpy(letra, "Ç");
    } else if (strcmp(letra, "ã") == 0) {
        strcpy(letra, "Ã");
    } else if (strcmp(letra, "õ") == 0) {
        strcpy(letra, "Õ");
    } else {
        letra[0] = toupper(letra[0]);
        letra[1] = '\0';
    }
    
    return *letra;
}

void para_maisculo(char* palavra){
    if (palavra == NULL) return;

    for(int i = 0; palavra[i] != '\0'; i++){
        palavra[i] = toupper_personalizado(&palavra[i]);
    }
}

int comparador_de_palavras(char* palavra1, char* palavra2){
    char temp1[strlen(palavra1) + 1]; 
    char temp2[strlen(palavra2) + 1]; 

    strcpy(temp1, palavra1);
    strcpy(temp2, palavra2);

    para_maisculo(temp1);
    para_maisculo(temp2);

    return strcmp(temp1, temp2);
}

void menu(){
    printf("\n======== MENU PRINCIPAL ========\n\n");

    printf("Selecione uma das operacoes abaixo:\n");

    printf("1 - Cadastrar um novo livro\n");
    printf("2 - Consultar livros por genero\n");
    printf("3 - Exibir todos os livros na biblioteca\n");
    printf("4 - Finalizar o programa\n");

    printf("\nDigite o numero da operacao desejada: ");
}

void menuOperacoes(int input, char* nome_arquivo, No* raiz){
    Livro livro;
    Biblioteca* biblioteca;

    switch (input)
    {
    case 1:
        livro = cadastrar_livro();
        inserir_livro(&raiz, livro);
        reiniciar_arquivo(nome_arquivo);
        salvar_arvore(nome_arquivo, raiz);
        break;
    case 2:
        biblioteca = iniciar_biblioteca();

        printf("Digite o genero que deseja procurar: ");
        char *genero = leitor_de_palavras();

        buscar_por_genero(raiz, genero, biblioteca);
        printf("\n--- Livros do genero %s ---\n\n", genero);
        exibir_biblioteca(*biblioteca);
        liberar_biblioteca(biblioteca);
        free(genero);
        break;
    case 3:
        printf("\n---- Livros carregados ---- \n\n");
        exibir_arvore(raiz);
        break;
    case 4:
        printf("\nObrigado por usar os nossos servicos!\n\n");
        break;
    default:
        printf("Opcao invalida\n");
        break;
    }
}