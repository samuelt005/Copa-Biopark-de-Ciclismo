
void converterParaLista(ArvBin *raiz, ArvBin *inicioLista) {
    if (*raiz != NULL) {
        converterParaLista(&((*raiz)->esq), inicioLista);
        if (*raiz != NULL) {
            insereMeio(inicioLista, raiz);
        }
        converterParaLista(&((*raiz)->dir), inicioLista);
    }
}

ArvBin encontrarItem(ArvBin *inicioLista, int posicao) {
    ArvBin atual = *inicioLista;
    int contador = 0;

    while (atual != NULL && contador < posicao) {
        atual = atual->dir;
        contador++;
    }

    ArvBin copia = (ArvBin) malloc(sizeof(struct No));
    if (copia != NULL) {
        copia->numero = atual->numero;
        copia->idade = atual->idade;
        strcpy(copia->primeiroNome, atual->primeiroNome);
        strcpy(copia->sobrenome, atual->sobrenome);
        copia->eElite = atual->eElite;
    } else {
        printf("Erro na alocação...\n");
        exit(0);
    }

    return copia;
}



void insereBalanceado(ArvBin *raiz, ArvBin *novo) {

    (*novo)->esq = NULL;
    (*novo)->dir = NULL;

    if (*raiz == NULL) {
        *raiz = *novo;
    } else {
        no *atual = *raiz;
        no *ant = NULL;
        while (atual != NULL) {
            ant = atual;
            if ((*novo)->numero == atual->numero) {
                printf("Elemento já existe...");
                sleep(2);
                return;
            }
            if ((*novo)->numero > atual->numero) {
                atual = atual->dir;
            } else {
                atual = atual->esq;
            }
        }
        if ((*novo)->numero > ant->numero) {
            ant->dir = *novo;
        } else {
            ant->esq = *novo;
        }
    }
}


void criarArvoreBalanceada(ArvBin *novaRaiz, ArvBin *inicioLista, int inicio, int fim) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        ArvBin meioItem = encontrarItem(inicioLista, meio);

        insereBalanceado(novaRaiz, &meioItem);

        criarArvoreBalanceada(novaRaiz, inicioLista, inicio, meio - 1);
        criarArvoreBalanceada(novaRaiz, inicioLista, meio + 1, fim);
    }
}


void balancearArvore(ArvBin *raiz) {

    int qtdNos = contarArvore(raiz);

    ArvBin *inicioLista = (ArvBin *) malloc(qtdNos * sizeof(ArvBin));
    if (inicioLista != NULL) {
        *inicioLista = NULL;
    } else {
        printf("Erro na alocação...\n");
        exit(0);
    }

    converterParaLista(raiz, inicioLista);

    ArvBin *novaRaiz = criaArvBin();

    criarArvoreBalanceada(novaRaiz, inicioLista, 0, qtdNos - 1);

    liberaLista(inicioLista);

    *raiz = *novaRaiz;
}
