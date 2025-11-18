struct Caixa {
    int valor;
    struct Caixa* prox;
};
struct Caixa* insere(struct Caixa* L, int valor) {
    struct Caixa* novo = malloc(sizeof(struct Caixa)); //criei novo nó com um ponteiro novo (aloquei nó)
    novo->valor = valor;
    novo->prox = NULL;

    if (L == NULL || valor < L->valor) {   // se lista vazia ou valor é menor que o primeiro elemento
        novo->prox = L;
        return novo;
    }
