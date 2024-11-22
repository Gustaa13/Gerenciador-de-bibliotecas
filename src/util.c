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
        printf("Numero invalido!\nDigite o número novamente: ");
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

void para_maisculo(char* palavra){
    if (palavra == NULL) return;

    for(int i = 0; palavra[i] != '\0'; i++){
        palavra[i] = toupper(palavra[i]);
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

int aumentar_biblioteca(Biblioteca* biblioteca){
    Livro* temporario = realloc(biblioteca->livros, (biblioteca->tamanho + 1) * sizeof(Livro));

    if (temporario == NULL) {
        printf("Erro ao realocar memoria!\n");
        return 0;
    }

    biblioteca->livros = temporario;
    biblioteca->tamanho++;
    return 1;
}

void menu(){
    printf("======== MENU PRINCIPAL ========\n");

    printf("Selecione uma das operações abaixo:\n");

    printf("1 - Cadastrar um novo livro\n");
    printf("2 - Consultar livros por gênero\n");
    printf("3 - Exibir todos os livros na biblioteca\n");
    printf("4 - Finalizar o programa\n");

    printf("Digite o número da operação desejada: ");
}

void menuOperacoes(int input, char* nome_arquivo, No* raiz){

    switch (input)
    {
    case 1:
        // inserção de livro pelo usuário
        Livro livro = cadastrar_livro();
        inserir_livro(&raiz, livro);
        salvar_arvore(nome_arquivo, raiz);
        break;
    case 2:
        // Busca por gênero
        Biblioteca *biblioteca = iniciar_biblioteca();

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
        printf("Obrigado por usar os nossos serviços!\n");
        break;
    default:
        printf("Opcão inválida\n");
        break;
    }
}