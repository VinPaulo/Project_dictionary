#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNo {
    char* palavra;
    char* trad;
    struct sNo* prox;
    struct sNo* ant;
} No;

No* inicializa_disc() {
    No* novo = malloc(sizeof(No));
    if (novo != NULL) {
        novo->ant = NULL;
        novo->prox = NULL;
        novo->palavra = NULL;
        novo->trad = NULL;
    }
    return novo;
}

int inserir_palavra(No* prim_ref, char palavra[100], char trad[100]) {
    No* novo = malloc(sizeof(No));
    if (novo == NULL) {
        return 1;
    }
    No* atual = prim_ref;
    novo->palavra = strdup(palavra);
    novo->trad = strdup(trad);

    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo;
    novo->ant = atual;
    novo->prox = NULL;
    return 0;
}

No* remover_palavra(No* prim_ref, char palavra[100]) {
    No* aux = prim_ref;
    while (aux != NULL && strcmp(aux->palavra, palavra) != 0) {
        aux = aux->prox;
    }
    if (aux == NULL) return prim_ref;

    if (aux->ant != NULL) aux->ant->prox = aux->prox;
    if (aux->prox != NULL) aux->prox->ant = aux->ant;

    free(aux->palavra);
    free(aux->trad);
    free(aux);

    return prim_ref;
}

No* buscar_palavra(No* prim_ref, char palavra[100]) {
    No* aux = prim_ref;
    while (aux != NULL) {
        if (strcmp(aux->palavra, palavra) == 0) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void imprimir_dicionario(No* n) {
    No* aux = n;
    while (aux != NULL) {
        if (aux->palavra != NULL && aux->trad != NULL) {
            printf("Idioma: %s / Traducao: %s\n", aux->palavra, aux->trad);
        }
        aux = aux->prox;
    }
}

void imprimir_texto(No* dicionario, char text[100]) {
    char* token = strtok(text, " ");
    while (token != NULL) {
        No* resultado = buscar_palavra(dicionario, token);
        if (resultado != NULL) {
            printf("%s ", resultado->trad);
        } else {
            printf("%s ", token);
        }
        token = strtok(NULL, " ");
    }
}