Este projeto implementa um dicionário bilíngue simples em C, utilizando uma lista duplamente encadeada para armazenar pares de palavras e suas respectivas traduções. Ele permite adicionar, buscar, remover e traduzir palavras, com um exemplo de uso no programa principal.

Estrutura do Projeto
dictionary.h: Definição da estrutura e funções do dicionário.
main.c: Exemplo de uso do dicionário.
Funcionalidades
Inicialização do Dicionário

inicializa_disc(): Cria e retorna um ponteiro para um nó inicial do dicionário.
Inserção de Palavras

inserir_palavra(): Insere uma nova palavra e sua tradução ao final da lista.
Remoção de Palavras

remover_palavra(): Encontra e remove uma palavra do dicionário, ajustando os ponteiros dos nós adjacentes.
Busca de Palavras

buscar_palavra(): Retorna o nó correspondente à palavra especificada, se existir no dicionário.
Impressão do Dicionário

imprimir_dicionario(): Exibe todas as palavras e suas traduções presentes no dicionário.
Tradução de Texto

imprimir_texto(): Traduz palavras de uma string de texto usando o dicionário. As palavras não encontradas são exibidas sem tradução.
