# include <stdio.h>
# include <string.h>

# define MAX_CONTA 100

typedef struct Conta{
    int numeroConta;
    char nomeCliente[100];
    char cpf [12];
    char telefone[15];
    float saldo;    
} Conta;
int buscarConta(Conta contas[],int numContas,int numeroConta);
void cadastrarConta(Conta contas[], int *numConta);
void consultarSaldo(Conta contas[],int nConta,int numConta);
void fazerDeposito(Conta contas[],int numConta, int nConta);
void fazerSaque(Conta contas[],int conta, int conta1);
void exibirConta(Conta contas[], int conta);

int main(){
    Conta contas [MAX_CONTA];
    int numContas = 0;
    int numConta = 0;
    int conta = 0;
    int contas = 0;

    int aux = buscarConta(contas,numContas,12345);
    printf("Resultado da busca %d\n",aux);

    cadastrarConta(contas,&numContas);
    consultarSaldo(contas,numContas,contas[0].numeroConta);
    fazerDeposito(contas,numContas,contas[0].numeroConta);
    fazerSaque(contas,conta,contas[0].numeroConta);
    exibirConta(contas,contas);

    return 0;
}

int buscarConta(Conta contas[], int numContas, int numeroConta){
    if(numContas == 0){
        return -1;
    }for(int i = 0; i < numContas; ++i){
        if(contas[i].numeroConta == numeroConta){
            return i;
        }
    }
    return -2;
}

void cadastrarConta(Conta contas[], int *numConta){
    if(*numConta >= MAX_CONTA){
        printf("Limite de contas cadastradas atingindas.\n");
        return;
    }
    int numeroConta;
    printf("Informe o número da nova conta: \n");
    scanf("%d",&numeroConta);

    if(buscarConta(contas,*numConta,numeroConta)>= 0){
        printf("Número de conta já cadastrada.\n");
        return;
    }
    contas[*numConta].numeroConta = numeroConta;
    printf("Informe o nome do cliente: ");
    scanf("%s", contas[*numConta].nomeCliente);
    printf("Informe o CPF do cliente: ");
    scanf("%s", contas[*numConta].cpf);
    printf("Informe o telefone do cliente: ");
    scanf("%s", contas[*numConta].telefone);
    contas[*numConta].saldo = 0.0;
    (*numConta)++;
    printf("Conta cadastrada com sucesso.\n");
}
void consultarSaldo(Conta contas[],int nConta,int numConta){
    int aux = buscarConta(contas,nConta,numConta);
    if(aux >= 0){
        printf("Saldo da conta %d: %.2f\n", numConta, contas[aux].saldo);
    } else if(aux == -1){
        printf("Cadastro de contas está vazio.\n");
    }else{
        printf("Conta não encontrada.\n");
    }
}
void fazerDeposito(Conta contas[], int numconta,int nconta){
    int aux = buscarConta(contas,numconta,nconta);
    if(aux >= 0){
       float valor;
        printf("Informe o valor do depósito: ");
        scanf("%f", &valor);
        contas[aux].saldo += valor;
        printf("Depósito realizado. Novo saldo: %.2f\n", contas[aux].saldo);
    } else if(aux == -1){
        printf("Cadastro de contas está vazio.\n");
    }else{
        printf("Conta não encontrada.\n");
    }    
}
void fazerSaque(Conta contas[], int conta,int conta1){
    int aux = buscarConta(contas,conta,conta1);
    if (aux >= 0) {
        float valor;
        printf("Informe o valor do saque: ");
        scanf("%f", &valor);
        if (contas[aux].saldo >= valor) {
            contas[aux].saldo -= valor;
            printf("Saque realizado. Novo saldo: %.2f\n", contas[aux].saldo);
        } else {
            printf("Saldo insuficiente.\n");
        }
    } else if (aux == -1) {
        printf("Cadastro de contas está vazio.\n");
    } else {
        printf("Conta não encontrada.\n");
    }
}
void exibirConta(Conta contas [], int contaS){
    for(int i = 0 ; i < contaS;i++){
        printf("Número da conta: %d, Nome do titular: %s, Telefone: %s\n", contas[i].numeroConta, contas[i].nomeCliente, contas[i].telefone);
    }
}
