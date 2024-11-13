# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_NOME 50
# define MAX_DESCRIÇÃO 100
# define MAX_CATEGORIA 50
# define MAX_VIDEOS 20

 typedef struct VIDEO{
    int id;
    char titulo [MAX_NOME];
    char descricao [MAX_DESCRIÇÃO];
    char categoria [MAX_CATEGORIA];
    int duracao;
} VIDEO;

typedef struct CADASTROUSUARIO{
    int id;
    char nome[MAX_NOME];
    int favoritos;
    int videosfavaritos;
} CADASTROUSUARIO;

void cadastrarvideo(){
    FILE *arquivo = fopen("videos.bin", "ab");
    if(!arquivo){
        perror("Erro ao abrir arquivo de vídeos.");
        return;
    }
    VIDEO video;
    printf("ID do vídeo: ");
    scanf("%d", &video.id);
    printf("Título do vídeo: ");
    scanf(" %[^\n]", video.titulo);
    printf("Descrição do vídeo: ");
    scanf(" %[^\n]", video.descricao);
    printf("Categoria do vídeo: ");
    scanf(" %[^\n]", video.categoria);
    printf("Duração do vídeo (em minutos): ");
    scanf("%d", &video.duracao);
}

void listarvideo();
void cadastrarusuario();
void listarusuario();
void removerusuario();

int main(){
    int opcao,id;

    while(1){
        printf("\nMenu:\n");
        printf("1. Cadastrar vídeo\n");
        printf("2. Cadastrar usuário\n");
        printf("3. Listar vídeo\n");
        printf("4. Listar usuário\n");
        printf("5. Remover usuário\n");
        printf("6. Sair\n");
        printf("Escolha uma opção \n");
        scanf("%d",&opcao);

        switch (opcao){
            case 1:
                cadastrarvideo();
                break;
            case 2:
                cadastrarusuario();
                break;
            case 3:
                listarvideo();
                break;
            case 4:
                listarvideo();
                break;
            case 5:
                printf("ID do usuário para remover: ");
                scanf("%d", &id);
                removerusuario(id);
                break;
            case 6:
                printf("Saindo do programa.\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }
    return 0;
}