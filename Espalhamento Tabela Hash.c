#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição das estruturas de dados
typedef struct lista {
    int chave;  // Valor do elemento armazenado
    struct lista *prox; // Ponteiro para o próximo elemento da lista
} Tlista;

typedef struct cabeca {
    Tlista *prim;  // Ponteiro para o primeiro elemento da lista
    Tlista *ult;  // Ponteiro para o último elemento da lista
} Tcabeca;

// Declaração das funcões
unsigned long int calcula_tam_tabela(unsigned int num_elementos);
unsigned short int eh_primo(unsigned int num);
int gerarNumeroAleatorio();
void busca(Tcabeca *tabela_hash, int busca, unsigned tam_tabela);

int main(void) {
    unsigned int num_elementos;

    printf("Insira o numero de elementos: ");
    scanf("%d", &num_elementos);

    // Cálculo do tamanho adequado da tabela hash
    unsigned long int tam_tabela = calcula_tam_tabela(num_elementos), i;

    printf("Tamanho da Tabela: %ld Fator de carga: %.4f\n", tam_tabela, num_elementos / (float)tam_tabela);

    // Alocação dinâmica da tabela hash
    Tcabeca *tabela_hash = (Tcabeca *)malloc(sizeof(Tcabeca) * tam_tabela);

    // Inicialização da tabela hash
    for (i = 0; i < tam_tabela; i++) {
        (tabela_hash + i)->prim = NULL;
        (tabela_hash + i)->ult = NULL;
    }

    int chave = 0;

    // Geração dos números aleatórios e inserção na tabela hash
    for (i = 0; i < num_elementos; i++) {
        chave = gerarNumeroAleatorio();

        // Cáculo do índice da tabela hash
        unsigned int indice = chave % tam_tabela;

        if (!((tabela_hash + indice)->prim)) {
            // Se a lista estiver vazia, insere o primeiro elemento
            (tabela_hash + indice)->prim = (Tlista *)malloc(sizeof(Tlista));
            (tabela_hash + indice)->ult = (tabela_hash + indice)->prim;
            (tabela_hash + indice)->prim->chave = chave;
            (tabela_hash + indice)->prim->prox = NULL;
        } else {
            // Se a lista já contiver elementos, insere no final para um processo de inserção mais rápida em caso de colisões
            (tabela_hash + indice)->ult->prox = (Tlista *)malloc(sizeof(Tlista));
            (tabela_hash + indice)->ult = (tabela_hash + indice)->ult->prox;
            (tabela_hash + indice)->ult->chave = chave;
            (tabela_hash + indice)->ult->prox = NULL;
        }
    }

    int elemento_busca;

    printf("Insira o elemento que deseja buscar: ");
    scanf("%d", &elemento_busca);
    printf("\n");

    // Realiza a busca na tabela hash
    busca(tabela_hash, elemento_busca, tam_tabela);
}

// Função para calcular o tamanho adequado da tabela hash
unsigned long int calcula_tam_tabela(unsigned int num_elementos) {
    int i = 2 * num_elementos, j = i;

    while (1) {
        if (i >= 2) {
            if (eh_primo(i) == 1) {
                return i;
            }
        }

        if (j >= 2) {
            if (eh_primo(j) == 1) {
                return j;
            }
        }

        i--;
        j++;
    }
}

// Função para verificar se um número é primo
unsigned short int eh_primo(unsigned int num) {
    unsigned int i;

    for (i = 2; i * i <= num; i++) {
        if ((num % i) == 0) {
            return 0;
        }
    }

    return 1;
}

// Função para gerar um número aleatório
int gerarNumeroAleatorio() {
    srand(time(NULL));
    return rand();
}

// Função para realizar a busca de um elemento na tabela hash
void busca(Tcabeca *tabela_hash, int busca, unsigned tam_tabela) {
    Tlista *aux = (tabela_hash + (busca % tam_tabela))->prim;

    while (aux) {
        if (aux->chave == busca) {
            printf("Achou");
            return;
        }

        aux = aux->prox;
    }

    printf("Nao achou");
}

