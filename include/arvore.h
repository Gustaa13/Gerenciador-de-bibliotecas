#include "livro.h"

typedef struct No 
{
    Livro livro;
    struct No *esquerda;
    struct No *direita;
}No;

No* inicializar_arvore();
void inserir_livro(No** raiz, Livro livro);
void buscar_por_genero(No* raiz, char* genero, Biblioteca* biblioteca);
No* carregar_livros(char* nome_arquivo, No* raiz);
void exibir_arvore(No* raiz);
int arvore_vazia(No *raiz);
void liberar_arvore(No* raiz);
void salvar_arvore(char* nome_arquivo, No* raiz);



