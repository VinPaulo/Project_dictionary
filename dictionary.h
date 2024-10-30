/* strcmp compara duas strings A e B e retorna um valor caso sejam diferentes ou iguais.
strtok recebe uma string e divide em substrings, retornando as partes da string que são separadas pelo delimitador especificado.
strdup faz a cópia da string, ou seja, aloca memória para uma nova string e copia o conteúdo da string original. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNo {
    char* palavra;
    char* trad;
    struct sNo* prox; // uma struct nó que aponta para o próximo.
    struct sNo* ant; // uma struct nó que aponta para o anterior da lista encadeada.
} No;

No* inicializa_disc() {
    No* novo = malloc(sizeof(No)); // inicializa um ponteiro para acessar o nó.
    if (novo != NULL) { // verifica se a alocação foi bem sucedida.
        novo->ant = NULL; // o ponteiro aponta para o anterior e inicializa como nulo.
        novo->prox = NULL; // o ponteiro aponta para o próximo e inicializa como nulo.
        novo->palavra = NULL; // inicializa o vetor de palavra como nulo.
        novo->trad = NULL; // inicializa o vetor de tradução dentro da struct Nó como nulo.
    }
    return novo;
}

int inserir_palavra(No* prim_ref, char palavra[100], char trad[100]) {
    No* novo = malloc(sizeof(No)); // aloca memória para o nó novo.
    if (novo == NULL) { // verifica se a alocação foi bem sucedida.
        return 1;
    }
    No* atual = prim_ref; // inicializa o nó atual recebendo a primeira referência (Primeiro Nó).
    novo->palavra = strdup(palavra); // ponteiro novo aponta para palavra que recebe a função strdup como parâmetro 'palavra'.
    novo->trad = strdup(trad); // ponteiro novo aponta para trad (tradução) e recebe como parâmetro o elemento de trad.

    while (atual->prox != NULL) { // laço para percorrer a lista e encontrar o último elemento. atual aponta para próximo.
        atual = atual->prox; // atual recebe atual apontando para próximo, ou seja, avança um nó.
    }
    atual->prox = novo; // atual apontando para próximo recebe novo, ou seja, o próximo do último nó aponta para novo.
    novo->ant = atual; // o anterior do novo nó aponta para o nó atual.
    novo->prox = NULL; // novo nó aponta para próximo que recebe nulo por ser o último da lista.
    return 0;
}

No* remover_palavra(No* prim_ref, char palavra[100]) { 
    No* aux = prim_ref; // ponteiro aux recebe a referência do primeiro nó.

    while (aux != NULL) {
        if (strcmp(aux->palavra, palavra) == 0) { // Verifica se a palavra do nó atual é a que deve ser removida
            No* retira = aux; // Salva o nó a ser removido
            if (retira->ant != NULL) { // Se não for a palavra desejada. 
                retira->ant->prox = retira->prox; // Atualiza o próximo do nó anterior
            } else {
                prim_ref = retira->prox; // Atualiza o início do dicionário se for a primeira palavra
            }
            if (retira->prox != NULL) { // Se não for o último nó
                retira->prox->ant = retira->ant; // Atualiza o anterior do próximo nó
            }
            free(retira); // Libera a memória do nó removido
            return prim_ref; // Retorna o novo início do dicionário
        } else {
            aux = aux->prox; // Avança para o próximo nó   
        }
    }
    return prim_ref; // Retorna o dicionário sem alterações se a palavra não for encontrada
}

No* buscar_palavra(No* prim_ref, char palavra[100]) {
    No* aux = prim_ref; // ponteiro auxiliar recebe o primeiro nó da lista.
    while (aux != NULL) { // percorre a lista enquanto aux for diferente de nulo.
        if (strcmp(aux->palavra, palavra) == 0) { // compara a palavra do nó com a palavra buscada.
            return aux; // retorna a palavra do nó aux.
        }
        aux = aux->prox; // auxiliar percorre a lista.
    }
    return NULL;
}

void imprimir_dicionario(No* prim_ref) {
    No* aux = prim_ref; // ponteiro aux recebe o elemento do primeiro nó da lista. 
    while (aux != NULL) { // verifica se aux é diferente de nulo.
        if (aux->palavra != NULL && aux->trad != NULL) { // se aux apontando pra palavra e pra tradução for diferente de nulo imprime as strings.
            printf("Idioma: %s / Traducao: %s\n", aux->palavra, aux->trad);
        }
        aux = aux->prox; // aux percorre a lista.
    }
}

void imprimir_texto(No* dicionario, char text[100]) {
    char* token = strtok(text, " "); // função que divide strings em substrings.
    while (token != NULL) { // verifica se token é nulo.
        No* resultado = buscar_palavra(dicionario, token); // ponteiro resultado que recebe buscar palavra como parâmetro sua palavra e sua tradução.
        if (resultado != NULL) { // verifica se o ponteiro resultado é nulo.
            printf("%s ", resultado->trad); // imprime o resultado apontando para a tradução.
        } else {
            printf("%s ", token); // imprime a substring, ou seja, a palavra original.
        }
        token = strtok(NULL, " "); // continua a divisão da string.
    }
}
