#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_DESCRICAO 100
#define MAX_CATEGORIA 50
#define MAX_VIDEOS 20

typedef struct {
    int id;
    char titulo[MAX_NOME];
    char descricao[MAX_DESCRICAO];
    char categoria[MAX_CATEGORIA];
    int duracao;
} VIDEO;

typedef struct {
    int id;
    char nome[MAX_NOME];
    int favoritos;
    int videosfavoritos[MAX_VIDEOS];
} CADASTROUSUARIO;

void salvar_arquivo(const char *filename, void *data, size_t size) {
    FILE *arquivo = fopen(filename, "ab");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo.");
        return;
    }
    fwrite(data, size, 1, arquivo);
    fclose(arquivo);
}
void listar_arquivo(const char *filename, size_t size, void (*print_func)(void *)) {
    FILE *arquivo = fopen(filename, "rb");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo.");
        return;
    }
    void *data = malloc(size);
    while (fread(data, size, 1, arquivo)) {
        print_func(data);
    }
    free(data);
    fclose(arquivo);
}
void print_video(void *data) {
    VIDEO *video = (VIDEO *)data;
    printf("ID: %d\nTítulo: %s\nDescrição: %s\nCategoria: %s\nDuração: %d minutos\n\n",
           video->id, video->titulo, video->descricao, video->categoria, video->duracao);
}
void print_usuario(void *data) {
    CADASTROUSUARIO *usuario = (CADASTROUSUARIO *)data;
    printf("ID: %d\nNome: %s\nNúmero de Favoritos: %d\nVídeos Favoritos: ", 
           usuario->id, usuario->nome, usuario->favoritos);
    for (int i = 0; i < usuario->favoritos; i++) {
        printf("%d ", usuario->videosfavoritos[i]);
    }
    printf("\n\n");
}
int main() {
    int opcao, id;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Cadastrar vídeo\n");
        printf("2. Cadastrar usuário\n");
        printf("3. Listar vídeos\n");
        printf("4. Listar usuários\n");
        printf("5. Remover usuário\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_video();
                break;
            case 2:
                cadastrar_usuario();
                break;
            case 3:
                listar_arquivo("videos.bin", sizeof(VIDEO), print_video);
                break;
            case 4:
                listar_arquivo("usuarios.bin", sizeof(CADASTROUSUARIO), print_usuario);
                break;
            case 5:
                printf("ID do usuário para remover: ");
                scanf("%d", &id);
                remover_usuario(id);
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