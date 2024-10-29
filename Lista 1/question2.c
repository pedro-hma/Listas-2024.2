# include <stdio.h>
# include <string.h>

# define MAX_PRODUTOS 40
typedef struct Produto{
    int codigo;
    char descricao[100];
    float valorUnidade;
    int qtdEstoque;
} Produto;
void cadastarProduto(Produto produtos[],int *numProdutos);
void exibirProduto(Produto produtos[],int numProdutos);
void alterarValorUnitario(Produto produtos[],int numProdutos, int codigo);
float informarValorUnitario(Produto produtos[],int numProdutos, int codigo);
int informarQuantidadeEstoque(Produto produtos[],int numProdutos, int codigo);
void venderProduto(Produto produtos[],int numProdutos, int codigo, int qtdDesejada);
void atualizarQtdEstoque(Produto produtos[],int numProdutos, int codigo, int novaQtd);
void exibirProdutosEstoqueZero(Produto produtos[],int numProdutos);
int main(){
    Produto produtos [MAX_PRODUTOS];
    int numProdutos = 0;
    cadastarProduto(produtos,&numProdutos);
    alterarValorUnitario(produtos,numProdutos,produtos[0].codigo);
    float valor = informarValorUnitario(produtos,numProdutos,produtos[0].codigo);
    if(valor != -1){
        printf("O valor unitario da produto é : %.2f\n",valor);
    } else{
        printf("Produto não encontrado.\n");
    }
    int qtd = informarQuantidadeEstoque(produtos,numProdutos,produtos[0].codigo);
    if ( qtd != -1){
        printf("A quantidade em estoque do produto é : %d\n",qtd);
    } else{
        printf("Produto não encontrado.\n");
    }
    venderProduto(produtos,numProdutos,produtos[0].codigo,5);
    atualizarQtdEstoque(produtos,numProdutos,produtos[0].codigo,100);
    exibirProduto(produtos,numProdutos);
    exibirProdutosEstoqueZero(produtos,numProdutos);
}

void cadastarProduto(Produto produtos[], int *numProdutos){
    if(*numProdutos >= MAX_PRODUTOS){
        printf("Limite de produtos atingidos.\n");
        return;
    }
    printf("Informe o código do produto : ");
    scanf("%d",&produtos[*numProdutos].codigo);
    printf("Informe a descrição do produto : ");
    scanf("%s",&produtos[*numProdutos].descricao);
    printf("Informe o valor unitario do produto : ");
    scanf("%f",&produtos[*numProdutos].valorUnidade);
    printf("Informe a quantidade em estoque : ");
    scanf("%d",&produtos[*numProdutos].qtdEstoque);
    (*numProdutos) ++;
}
void exibirProduto(Produto produtos[],int numProdutos){
    for(int i = 0; i < numProdutos){
        if(produtos[i].codigo == 0){
             printf("Informe o novo valor unitário do produto %s: ", produtos[i].descricao);
            scanf("%f", &produtos[i].valorUnitario);
            printf("Valor unitário atualizado com sucesso.\n");
        }
        return;
    }
}