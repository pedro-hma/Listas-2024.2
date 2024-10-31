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