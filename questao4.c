#include <stdio.h>
#include <stdlib.h>

struct Caixa {
    int valor;
    struct Caixa* prox;
};

int contem(struct Caixa* L, int valor) {  // verifica se o valor está contido na lista que tem um ponteiro L para o primeiro elemento
    struct Caixa* p = L;
    while (p != NULL) {
        if (p->valor == valor)  // se p^.E = valor
            return 1; // valor encontrado
        p= p->prox;
    }
    return 0; // valor não encontrado
}
