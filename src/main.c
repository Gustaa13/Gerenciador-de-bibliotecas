#include <stdio.h>
#include "../include/util.h"

int main(){
    char* nome_arquivo = "data/livros.csv";
    char* genero = "Romance";
    No* raiz = inicializar_arvore();
    Biblioteca* biblioteca = iniciar_biblioteca();

    raiz = carregar_livros(nome_arquivo, raiz);

    // inserção de livro pelo usuário
    Livro livro = cadastrar_livro();
    inserir_livro(&raiz, livro);
    liberar_livro(&livro);
    reiniciar_arquivo(nome_arquivo);
    salvar_arvore(nome_arquivo, raiz); // Essas 5 funções precisam estar juntas

    // Busca por gênero
    buscar_por_genero(raiz, genero, biblioteca);
    printf("\n--- Livros do genero %s ---\n\n", genero);
    exibir_biblioteca(*biblioteca); // Essas 3 precisam estar juntas

    printf("\n---- Livros carregados ---- \n\n");

    exibir_arvore(raiz);

    liberar_arvore(raiz);

    return 0;
}


// Para compilar: gcc src/main.c src/arvore.c src/livro.c src/util.c -o biblioteca -g -W 
// Para executar: ./biblioteca