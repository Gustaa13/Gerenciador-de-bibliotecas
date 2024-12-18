#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/util.h"

Livro cadastrar_livro(){
    Livro livro;
    char* entrada;

    printf("Digite o codigo do livro: ");
    livro.codigo = leitor_de_numeros();

    printf("Digite o titulo do livro: ");
    entrada = leitor_de_palavras();
    strcpy(livro.titulo, entrada);
    free(entrada);
    

    printf("Digite o autor do livro: ");
    entrada = leitor_de_palavras();
    strcpy(livro.autor, entrada);
    free(entrada);

    printf("Digite o genero do livro: ");
    entrada = leitor_de_palavras();
    strcpy(livro.genero, entrada);
    free(entrada);

    printf("Digite o ano do livro: ");
    livro.ano = leitor_de_ano();

    printf("Digite a editoria do livro: ");
    entrada = leitor_de_palavras();
    strcpy(livro.editora, entrada);
    free(entrada);

    printf("Digite o numero de paginas do livro: ");
    livro.paginas = leitor_de_numeros();

    
    return livro;
}

void salvar_livro(char* nome_arquivo, Livro livro){
    FILE *arquivo = fopen(nome_arquivo, "a");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    fprintf(arquivo, "%i,%s,%s,%s,%i,%s,%i\n",
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

void exibir_livro(Livro livro){
    printf("Livro \"%s\":\n", livro.titulo);
        printf("  Codigo: %d\n", livro.codigo);
        printf("  Autor: %s\n", livro.autor);
        printf("  Genero: %s\n", livro.genero);
        printf("  Ano: %d\n", livro.ano);
        printf("  Editora: %s\n", livro.editora);
        printf("  Paginas: %d\n\n", livro.paginas);
}