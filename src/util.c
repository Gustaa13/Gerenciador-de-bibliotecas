#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/util.h"

char* leitor_de_palavras(){
    char* palavra = (char*)malloc(50 * sizeof(char));

    if (palavra == NULL){
        printf("Erro: Memória insuficiente.\n");
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
        printf("Número inválido!\nDigite o número novamente: ");
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
        printf("Ano inválido!\nDigite o ano novamente: ");
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
    fprintf(arquivo, "");
    fclose(arquivo);
}