# Tabela Hash com Busca

Este programa implementa uma tabela hash com busca de elementos. A tabela hash é uma estrutura de dados que permite armazenar e recuperar informações de maneira eficiente. Neste programa, você terá a oportunidade de criar uma tabela hash com um número específico de elementos, onde cada elemento é gerado aleatoriamente.

## Funcionalidades

- Solicita ao usuário o número de elementos desejados para a tabela hash.
- Calcula o tamanho adequado da tabela hash com base no número de elementos fornecido.
- Gera números aleatórios para preencher a tabela hash.
- Permite ao usuário realizar uma busca na tabela hash por um elemento específico.
- Exibe uma mensagem indicando se o elemento buscado foi encontrado ou não.

## Como executar

1. Compile o programa utilizando um compilador C.
2. Execute o programa no terminal ou prompt de comando.
3. Insira o número de elementos desejados para a tabela hash.
4. Aguarde a geração da tabela hash.
5. Insira o elemento que você deseja buscar na tabela hash.
6. Verifique o resultado da busca na saída do programa.

Observações:

A função calcula_tam_tabela é responsável por calcular o tamanho adequado da tabela hash com base no número de elementos fornecidos pelo usuário. Ela utiliza a função eh_primo para determinar se um número é primo.
A função gerarNumeroAleatorio é usada para gerar números aleatórios que serão inseridos na tabela hash.
A função busca realiza a busca de um elemento na tabela hash com base no valor fornecido pelo usuário.
A tabela hash é implementada usando listas encadeadas. Cada elemento da lista é representado pela estrutura Tlista e a cabeça da lista é representada pela estrutura Tcabeca.