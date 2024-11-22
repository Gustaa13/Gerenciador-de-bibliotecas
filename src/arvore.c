#include <stdio.h>
#include "../include/util.h"
#include <stdlib.h>
#include <string.h>

#define MAX_LINHAS 100  
#define TAM_LINHA 1024  

No* inicializar_arvore(){
    No* no = NULL;
    return no;
}

void inserir_livro(No** raiz, Livro livro) {
    if (*raiz == NULL) {
        *raiz = (No*)malloc(sizeof(No));
        if (*raiz == NULL) {
            perror("Erro ao alocar memoria para o no");
            exit(1);
        }
        (*raiz)->livro = livro;
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
        return;
    }

    if (livro.codigo < (*raiz)->livro.codigo) {
        inserir_livro(&(*raiz)->esquerda, livro); 
    } else if (livro.codigo > (*raiz)->livro.codigo) {
        inserir_livro(&(*raiz)->direita, livro); 
    } else {
        printf("\nEsse codigo ja esta sendo usado! Tente outro!\n");
    }
}


void buscar_por_genero(No* raiz, char* genero, Biblioteca* biblioteca){
    if(!arvore_vazia(raiz)){
        if(!(comparador_de_palavras(raiz->livro.genero, genero))){
            if(aumentar_biblioteca(biblioteca)){
                biblioteca->livros[biblioteca->tamanho - 1] = raiz->livro;
            }else{
                return;
            }
        }
        buscar_por_genero(raiz->esquerda, genero, biblioteca);
        buscar_por_genero(raiz->direita, genero, biblioteca);
    }
}

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
            perror("Erro ao alocar memoria para Livro");
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
        exibir_livro(raiz->livro);
        exibir_arvore(raiz->direita);
    }
}

int arvore_vazia(No *raiz){
    return raiz == NULL;
}

void liberar_arvore(No* raiz){
    if(!arvore_vazia(raiz)){
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
    return;
}

void salvar_arvore(char* nome_arquivo, No* raiz){
    if(!arvore_vazia(raiz)){
        salvar_livro(nome_arquivo, raiz->livro);
        salvar_arvore(nome_arquivo, raiz->esquerda);
        salvar_arvore(nome_arquivo, raiz->direita);
    }
}

