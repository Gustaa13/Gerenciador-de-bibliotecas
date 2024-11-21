#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/livro.h"
#include "../include/util.h"

Livro cadastrar_livro(){
    Livro livro;

    printf("Digite o codigo do livro: ");
    livro.codigo = leitor_de_numeros();

    printf("Digite o titulo do livro: ");
    strcpy(livro.titulo, leitor_de_palavras());

    printf("Digite o autor do livro: ");
    strcpy(livro.autor, leitor_de_palavras());

    printf("Digite o gênero do livro: ");
    strcpy(livro.genero, leitor_de_palavras());

    printf("Digite o ano do livro: ");
    livro.ano = leitor_de_ano();

    printf("Digite a editoria do livro: ");
    strcpy(livro.editora, leitor_de_palavras());

    printf("Digite o numero de paginas do livro: ");
    livro.paginas = leitor_de_numeros();

    return livro;
}

void liberar_livro(Livro* livro) {
    free(livro->titulo);
    free(livro->autor);
    free(livro->genero);
    free(livro->editora);
}

void salvar_livro(char* nome_arquivo, Livro livro){
    FILE *arquivo = fopen(nome_arquivo, "a");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    fprintf(arquivo, "%i, %s, %s, %s, %i, %s, %i\n",
        livro.codigo, 
        livro.titulo,
        livro.autor,
        livro.genero,
        livro.ano,
        livro.editora,
        livro.paginas
    );

    fclose(arquivo);
}