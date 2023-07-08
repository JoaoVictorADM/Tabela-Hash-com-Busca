#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defini��o das estruturas de dados
typedef struct lista {
    int chave;  // Valor do elemento armazenado
    struct lista *prox; // Ponteiro para o pr�ximo elemento da lista
} Tlista;

typedef struct cabeca {
    Tlista *prim;  // Ponteiro para o primeiro elemento da lista
    Tlista *ult;  // Ponteiro para o �ltimo elemento da lista
} Tcabeca;

// Declara��o das func�es
unsigned long int calcula_tam_tabela(unsigned int num_elementos);
unsigned short int eh_primo(unsigned int num);
int gerarNumeroAleatorio();
void busca(Tcabeca *tabela_hash, int busca, unsigned tam_tabela);

int main(void) {
    unsigned int num_elementos;

    printf("Insira o numero de elementos: ");
    scanf("%d", &num_elementos);

    // C�lculo do tamanho adequado da tabela hash
    unsigned long int tam_tabela = calcula_tam_tabela(num_elementos), i;

    printf("Tamanho da Tabela: %ld Fator de carga: %.4f\n", tam_tabela, num_elementos / (float)tam_tabela);

    // Aloca��o din�mica da tabela hash
    Tcabeca *tabela_hash = (Tcabeca *)malloc(sizeof(Tcabeca) * tam_tabela);

    // Inicializa��o da tabela hash
    for (i = 0; i < tam_tabela; i++) {
        (tabela_hash + i)->prim = NULL;
        (tabela_hash + i)->ult = NULL;
    }

    int chave = 0;

    // Gera��o dos n�meros aleat�rios e inser��o na tabela hash
    for (i = 0; i < num_elementos; i++) {
        chave = gerarNumeroAleatorio();

        // C�culo do �ndice da tabela hash
        unsigned int indice = chave % tam_tabela;

        if (!((tabela_hash + indice)->prim)) {
            // Se a lista estiver vazia, insere o primeiro elemento
            (tabela_hash + indice)->prim = (Tlista *)malloc(sizeof(Tlista));
            (tabela_hash + indice)->ult = (tabela_hash + indice)->prim;
            (tabela_hash + indice)->prim->chave = chave;
            (tabela_hash + indice)->prim->prox = NULL;
        } else {
            // Se a lista j� contiver elementos, insere no final para um processo de inser��o mais r�pida em caso de colis�es
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

// Fun��o para calcular o tamanho adequado da tabela hash
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

// Fun��o para verificar se um n�mero � primo
unsigned short int eh_primo(unsigned int num) {
    unsigned int i;

    for (i = 2; i * i <= num; i++) {
        if ((num % i) == 0) {
            return 0;
        }
    }

    return 1;
}

// Fun��o para gerar um n�mero aleat�rio
int gerarNumeroAleatorio() {
    srand(time(NULL));
    return rand();
}

// Fun��o para realizar a busca de um elemento na tabela hash
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

