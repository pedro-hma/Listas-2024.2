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