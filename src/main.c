#include <stdio.h>
#include "../include/arvore.h"
#include "../include/util.h"

int main(){
    No* raiz = inicializar_arvore();

    raiz = carregar_livros("data/livros.csv", raiz);

    printf("Livros carregados: \n");

    exibir_arvore(raiz);

    return 0;
}

// Para compilar: gcc main.c src/arvore.c src/livro.c src/util.c -o biblioteca -g -W 
// Para executar: ./biblioteca