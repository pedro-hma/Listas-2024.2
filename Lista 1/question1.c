# include <stdio.h>
# define QTD_ESTADOS 26

typedef struct Estados{
    char nome [50];
    int numVeiculos;
    int numAcidentes;
};
void dados(struct Estados estados[]);
void acidentes(struct Estados estados[], int *maxAcidentes,int *minAcidentes);
float percental(struct Estados estados[]);
float mediaAcidentes(struct Estados estados[]);
void acimaDaMedia(struct Estados estados[],float media);

int main(){
    struct Estados estados[QTD_ESTADOS];
    dados(estados);

    int maxacidentes, minacidentes;
    acidentes(estados,maxacidentes,minacidentes);

    float media = mediaAcidentes(estados);
    acimaDaMedia(estados,media);

    for(int i = 0; i < QTD_ESTADOS; ++i){
         printf("Percentual de acidentes no estado %s: %.2f%%\n", estados[i].nome, percentualAcidentes(estados[i]));
    }
    printf("Estado com mais acidentes: %s com %d acidentes\n", estados[maxacidentes].nome, estados[maxacidentes].numAcidentes);
    printf("Estado com menos acidentes: %s com %d acidentes\n", estados[minacidentes].nome, estados[minacidentes].numAcidentes);
    printf("Média de acidentes no país: %.2f\n", media);

    return 0;
}
void dados(struct Estados estados[]){
    for(int i = 0; i < QTD_ESTADOS; ++i){
        printf("Informe o nome do estado: ");
        scanf("%s",estados[i].nome);
        printf("Informe o numero de veiculos do estado: ");
        scanf("%s",estados[i].numVeiculos);
        printf("Informe o numero de acidentes do estado: ");
        scanf("%s",estados[i].numVeiculos);
    }
}
void acidentes(struct Estados estados[], int *maxAcidentes,int *minAcidentes){
    *maxAcidentes = 0;
    *minAcidentes = 0;
    for(int i = 1; i < QTD_ESTADOS;++i){
        if(estados[i].numAcidentes > estados[*maxAcidentes].numAcidentes){
            *maxAcidentes = i;
        }
        if(estados[i].numAcidentes > estados[*maxAcidentes].numAcidentes){
            *minAcidentes = i;
        }
    }
}
float percental(struct Estados estados[]){
    return ((float)estados->numAcidentes / estados->numVeiculos);
}
float mediaAcidentes(struct Estados estados[]){
    int soma = 0;
    for(int i = 0; i < QTD_ESTADOS;++i){
        soma += estados[i].numAcidentes;
    }
    return (float) soma / QTD_ESTADOS;
}
void acimaDaMedia(struct Estados estados[],float media){
    printf("Estados acima da média :\n");
    for(int i = 0; i < QTD_ESTADOS; ++i){
        if(estados[i].numAcidentes > media){
            printf("%s\n",estados[i].nome);
        }
    }
}