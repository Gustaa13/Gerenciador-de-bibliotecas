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

typedef struct Biblioteca
{
    Livro *livros;
    int tamanho;
} Biblioteca;

Biblioteca* iniciar_biblioteca();
Livro cadastrar_livro();
void liberar_livro(Livro* livro);
void salvar_livro(char* nome_arquivo, Livro livro);
void exibir_livro(Livro livro);
void exibir_biblioteca(Biblioteca biblioteca);