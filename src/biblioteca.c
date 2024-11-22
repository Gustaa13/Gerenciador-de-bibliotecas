#include <stdio.h>
#include <stdlib.h>
#include "../include/util.h"

Biblioteca* iniciar_biblioteca(){
    Biblioteca* biblioteca = (Biblioteca*)malloc(sizeof(Biblioteca));
    if (biblioteca == NULL){
        printf("Erro ao iniciar biblioteca!\n");
        return NULL;
    }
    biblioteca->livros = (Livro*)malloc(sizeof(Livro));
    biblioteca->tamanho = 0;
    return biblioteca;
}

void liberar_biblioteca(Biblioteca* biblioteca) {
    free(biblioteca->livros);
    free(biblioteca);
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

void exibir_biblioteca(Biblioteca biblioteca){
    for(int i = 0; i < biblioteca.tamanho; i++){
        exibir_livro(biblioteca.livros[i]);
    }
}