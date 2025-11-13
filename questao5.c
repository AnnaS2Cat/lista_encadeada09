#include <stdio.h>
#include <stdlib.h>

struct Caixa {
    int valor;
    struct Caixa* prox;
};

struct Caixa* remove (struct Caixa* L, int valor) {
    if (L == NULL) {
        return NULL; // lista vazia, nada a fazer
    }

    if (L->valor == valor) { // se o valor está no primeiro nó (L^.E = valor)
        struct Caixa* aux = L;
        L = L->prox;  // atualiza onde a lista começa
        free(aux);           // libera a memória do nó removido
        return L;         // retorna o novo ponteiro para o primeiro nó
    }

    struct Caixa* p = L; // percorre a lista para encontrar o valor
    while (p->prox != NULL) {
        if (p->prox->valor == valor) {    //p^.Prox^.E = valor
            struct Caixa* aux = p->prox; // aux<- p^.Prox
            p->prox = p->prox->prox;    // p^.Prox<-p^.Prox^.Prox  (remove o nó da lista ao pular o nó com o valor que eu quero remover)
            free(aux);                 // libera a memória do nó removido
            return L;                 // retorna a lista modificada
        }
        p = p->prox; 
    }
    return L;  // se não encontrar o valor retorna a lista como tava
}
