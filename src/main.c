#include <stdio.h>
#include <locale.h>
#include "../include/util.h"

int main(){
    char* nome_arquivo = "data/livros.csv";
    No* raiz = inicializar_arvore();
    raiz = carregar_livros(nome_arquivo, raiz);

    int input;

    do
    {
        menu();
        input = leitor_de_numeros();
        

        menuOperacoes(input, nome_arquivo, raiz);

    } while (input != 4);

    liberar_arvore(raiz);
    return 0;
}
