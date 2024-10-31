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
int buscarConta(Conta contas[],int numConta,int numeroConta);
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