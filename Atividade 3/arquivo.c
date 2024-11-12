# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_NOME 50
# define MAX_DESCRIÇÃO 100
# define MAX_CATEGORIA 50
# define MAX_VIDEOS 20

struct VIDEO{
    int id;
    char titulo [MAX_NOME];
    char descricao [MAX_DESCRIÇÃO];
    char categoria [MAX_CATEGORIA];
    int duracao;
} VIDEO;
struct CADASTROUSUARIO{
    int id;
    char nome[MAX_NOME];
    int favoritos;
    int videosfavaritos;
} CADASTROUSUARIO;
void cadastrarvideo();
void listarvideo();
void cadastrarusuario();
void listarusuario();
void removerusuario();