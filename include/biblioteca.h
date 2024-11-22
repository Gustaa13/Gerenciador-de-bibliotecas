#include "livro.h"

typedef struct Biblioteca
{
    Livro *livros;
    int tamanho;
} Biblioteca;

Biblioteca* iniciar_biblioteca();
void liberar_biblioteca(Biblioteca* biblioteca);
void exibir_biblioteca(Biblioteca biblioteca);
int aumentar_biblioteca(Biblioteca* biblioteca);