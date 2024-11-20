#include <stdio.h>
#include "../include/arvore.h"
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 100  // Número máximo de linhas no arquivo
#define TAM_LINHA 1024  // Tamanho máximo de cada linha

No* inicializar_arvore(){
    No* no = NULL;
    return no;
}

void inserir_livro(No** raiz, Livro livro) {
    if (*raiz == NULL) {
        // Criar um novo nó e atribuí-lo ao ponteiro raiz
        *raiz = (No*)malloc(sizeof(No));
        if (*raiz == NULL) {
            perror("Erro ao alocar memória para o nó");
            exit(1);
        }
        (*raiz)->livro = livro;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
        return;
    }

    if (livro.codigo < (*raiz)->livro.codigo) {
        inserir_livro(&(*raiz)->esquerda, livro); // Inserir à esquerda
    } else if (livro.codigo > (*raiz)->livro.codigo) {
        inserir_livro(&(*raiz)->direita, livro); // Inserir à direita
    }
}


// void buscar_por_genero(No* raiz, char genero[]){

// }

No* carregar_livros(char* nome_arquivo, No* raiz){
    
    FILE *file = fopen(nome_arquivo, "r");


    if (file == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    char line[TAM_LINHA];

    while (fgets(line, sizeof(line), file)){
       
        Livro *livro = malloc(sizeof(Livro));

        if (!livro){
            perror("Erro ao alocar memória para Livro");
            fclose(file);
            return NULL;
        }

        line[strcspn(line, "\n")] = 0;


        char *token = strtok(line, ",");
        int coluna = 0;

        while (token != NULL){
            coluna++;
            switch (coluna)
            {
            case 1: livro->codigo = atoi(token); break;
            case 2: strncpy(livro->titulo, token, sizeof(livro->titulo) - 1); break;
            case 3: strncpy(livro->autor, token, sizeof(livro->autor) - 1); break;
            case 4: strncpy(livro->genero, token, sizeof(livro->genero) - 1); break;
            case 5: livro->ano = atoi(token); break;
            case 6: strncpy(livro->editora, token, sizeof(livro->editora) - 1); break;
            case 7: livro->paginas = atoi(token); break;
            }
            
            token = strtok(NULL, ",");
        }
        inserir_livro(&raiz, *livro);

        free(livro);
    }

    fclose(file);

    return raiz;
    
}

void exibir_arvore(No* raiz){
    if (raiz != NULL) {
        exibir_arvore(raiz->esquerda);
        printf("Livro:\n");
        printf("  Código: %d\n", raiz->livro.codigo);
        printf("  Título: %s\n", raiz->livro.titulo);
        printf("  Autor: %s\n", raiz->livro.autor);
        printf("  Gênero: %s\n", raiz->livro.genero);
        printf("  Ano: %d\n", raiz->livro.ano);
        printf("  Editora: %s\n", raiz->livro.editora);
        printf("  Páginas: %d\n\n", raiz->livro.paginas);
        exibir_arvore(raiz->direita);
    }
}

// void liberar_arvore(No* raiz){

// }


