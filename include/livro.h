typedef struct Livro 
{
    int codigo;
    char titulo[50];
    char autor[50];
    char genero[50];
    int ano;
    char editora[50];
    int paginas;
}Livro;

Livro cadastrar_livro();
void salvar_livro(char* nome_arquivo, Livro livro);
void exibir_livro(Livro livro);