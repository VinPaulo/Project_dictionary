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
    No* novo = (No*)malloc(sizeof(No)); // inicializa um ponteiro para acessar o nó.
    if (novo != NULL) { // verifica se a alocação foi bem sucedida.
        novo->ant = NULL; // o ponteiro aponta para o anterior e inicializa como nulo.
        novo->prox = NULL; // o ponteiro aponta para o próximo e inicializa como nulo.
        novo->palavra = NULL; // inicializa o vetor de palavra como nulo.
        novo->trad = NULL; // inicializa o vetor de tradução dentro da struct Nó como nulo.
    }
    return novo;
}

No* inserir_palavra(No* prim_ref, char palavra[100], char trad[100]) {
    No* novo = (No*)malloc(sizeof(No)); // aloca memória para o novo nó
    if (novo == NULL) { // verifica falha na alocação
        return NULL; // retorna NULL se falhar
    }

    novo->palavra = (char*)malloc(strlen(palavra) + 1); // aloca memória para 'palavra'
    if (novo->palavra == NULL) { // verifica falha na alocação de 'palavra'
        free(novo); // libera memória do nó
        return NULL;
    }
    strcpy(novo->palavra, palavra); // copia 'palavra' para o novo nó

    novo->trad = (char*)malloc(strlen(trad) + 1); // aloca memória para 'trad'
    if (novo->trad == NULL) { // verifica falha na alocação de 'trad'
        free(novo->palavra); // libera memória de 'palavra'
        free(novo); // libera memória do nó
        return NULL;
    }
    strcpy(novo->trad, trad); // copia 'trad' para o novo nó

    novo->prox = NULL; // inicializa o próximo como NULL
    novo->ant = NULL;  // inicializa o anterior como NULL

    if (prim_ref == NULL) { // se a lista estiver vazia
        return novo; // retorna o novo nó como primeiro
    }

    No* atual = prim_ref; // define o nó atual como o primeiro
    while (atual->prox != NULL) { // percorre até o último nó
        atual = atual->prox;
    }

    atual->prox = novo; // o próximo do último nó aponta para o novo
    novo->ant = atual;  // o anterior do novo aponta para o último
    return prim_ref; // retorna a cabeça da lista
}


No* remover_palavra(No* prim_ref, char palavra[100]){
    No* aux = prim_ref;

    while (aux != NULL) {
        if (strcmp(aux->palavra, palavra) == 0) { // Verifica se a palavra do nó atual é a que deve ser removida
            No* retira = aux;
            aux = aux->prox; // Salva o nó a ser removido
            if (retira->ant != NULL) { // Se não for o primeiro nó
                retira->ant->prox = retira->prox; // Atualiza o próximo do nó anterior
            } else {
                prim_ref = retira->prox; // Atualiza o início do dicionário se for a primeira palavra
            }
            if (retira->prox != NULL) { // Se não for o último nó
                retira->prox->ant = retira->ant; // Atualiza o anterior do próximo nó
            }
            free(retira);
            break; // Libera a memória do nó removido
        }
    return prim_ref; // Retorna o dicionário sem alterações se a palavra não for encontrada
    }
}

No* buscar_palavra(No* prim_ref, char palavra[100]){
    No* aux = prim_ref; // ponteiro auxiliar recebe o primeiro nó da lista.
    while (aux != NULL) { // percorre a lista enquanto aux for diferente de nulo.
        if (strcmp(aux->palavra, palavra) == 0) { // compara a palavra do nó com a palavra buscada.
            return aux; // retorna a palavra do nó aux.
        }
        aux = aux->prox; // auxiliar percorre a lista.
    }
    return NULL;
}

void imprimir_dicionario(No* prim_ref){

    if (prim_ref == NULL) { // verifica se a lista está vazia
        printf("Dicionario vazio.\n"); // imprime mensagem se não houver palavras
        return; // encerra a função se a lista estiver vazia
    }

    No* aux = prim_ref; // ponteiro auxiliar recebe o primeiro nó
    while (aux != NULL) { // percorre a lista enquanto o ponteiro não for nulo
        if (aux->palavra != NULL && aux->trad != NULL) { // verifica se há palavra e tradução
            printf("Idioma: %s / Traducao: %s\n", aux->palavra, aux->trad); // imprime palavra e tradução
        }
        aux = aux->prox; // avança para o próximo nó da lista
    }
}

void imprimir_texto(No* dicionario, char text[100]){
    if (dicionario == NULL || text == NULL) { // verifica se o dicionário ou o texto está vazio
        printf("Dicionario ou texto vazio.\n"); // imprime mensagem se não houver dicionário ou texto
        return; // encerra a função se o dicionário ou texto estiver vazio
    }

    char* copia_texto = strdup(text); // faz uma cópia do texto original para evitar modificações
    char* token = strtok(copia_texto, " "); // divide a cópia do texto em palavras (tokens)

    while (token != NULL) { // percorre cada palavra da cópia do texto
        No* resultado = buscar_palavra(dicionario, token); // busca a palavra no dicionário
        if (resultado != NULL) { // verifica se a palavra foi encontrada no dicionário
            printf("%s ", resultado->trad); // imprime a tradução se a palavra for encontrada
        } else {
            printf("%s ", token); // imprime a palavra original se não houver tradução
        }
        token = strtok(NULL, " "); // avança para a próxima palavra (token) do texto
    }
    printf("\n"); // pula linha após a impressão do texto

    free(copia_texto); // libera a memória alocada para a cópia do texto
}
