#include <stdio.h>

struct Caixa {
    int valor;
    struct Caixa* prox;
};

void exibe(struct Caixa* caixa) {
    while (caixa != NULL) {
        printf("%d ", caixa->valor);
        caixa = caixa->prox;
    }
    printf("\n");
}

int main() {
    struct Caixa c1, c2, c3, c4, c5;
    c1.valor = 1;
    c2.valor = 3;
    c3.valor = 9;
    c4.valor = 7;
    c5.valor = 5;

    c1.prox = &c2;
    c2.prox = &c3;
    c3.prox = &c4;
    c4.prox = &c5;
    c5.prox = NULL;

    struct Caixa* cabeca = &c1;  // ponteiro cabeça que aponta para o primeiro elemento
    printf("Lista original:\n");
    exibe(cabeca);

    c2.prox = c3.prox;  // para remover c3, liguei c2 direto em c4, pulando o c3

    printf("Após remover o índice 2 (valor 9):\n");
    exibe(cabeca);
  
    c3.prox = cabeca;   // c3 agora aponta para o antigo início
    cabeca = &c3;       // e c3 vira a nova cabeça

    printf("Após reinserir o valor 9 no início:\n");
    exibe(cabeca);

    return 0;
}
