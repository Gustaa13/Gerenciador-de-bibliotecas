#include <stdio.h>
#include "../include/arvore.h"

int main(){
    char* nome_arquivo = "data/livros.csv";
    No* raiz = inicializar_arvore();

    raiz = carregar_livros(nome_arquivo, raiz);

    Livro livro = cadastrar_livro();
    inserir_livro(&raiz, livro);
    liberar_livro(&livro);
    reiniciar_arquivo(nome_arquivo);
    salvar_arvore(nome_arquivo, raiz);

    printf("\n---- Livros carregados ---- \n\n");

    exibir_arvore(raiz);

    liberar_arvore(raiz);

    return 0;
}

// Para compilar: gcc src/main.c src/arvore.c src/livro.c src/util.c -o biblioteca -g -W 
// Para executar: ./biblioteca