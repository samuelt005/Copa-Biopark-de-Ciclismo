
void removeNo(ArvBin *raiz, int aExcluir) {

    no *atual = *raiz;
    no *ant = NULL;

    while (atual != NULL) {
        if (aExcluir == atual->numero) {
            if (ant == NULL) {
                // Caso em que o n� a ser removido � a raiz da �rvore
                if (atual->esq == NULL && atual->dir == NULL) {
                    // Se for uma folha, a �rvore ficar� vazia
                    free(atual);
                    *raiz = NULL;
                    printf("Participante n�mero %d removido.\n", aExcluir);
                    sleep(2);
                    return;
                } else if (atual->esq == NULL) {
                    // Se n�o houver filho na esquerda, atualize a raiz
                    *raiz = atual->dir;
                } else if (atual->dir == NULL) {
                    // Se n�o houver filho na direita, atualize a raiz
                    *raiz = atual->esq;
                } else {
                    // Caso em que h� filhos em ambas as dire��es
                    no *substituto = atual->dir;
                    no *antSubstituto = atual;
                    while (substituto->esq != NULL) {
                        antSubstituto = substituto;
                        substituto = substituto->esq;
                    }
                    atual->numero = substituto->numero;

                    if (antSubstituto == atual) {
                        antSubstituto->dir = substituto->dir;
                    } else {
                        antSubstituto->esq = substituto->dir;
                    }

                    free(substituto);
                }
            } else {
                // Caso em que o n� a ser removido n�o � a raiz
                if (atual->esq == NULL && atual->dir == NULL) {
                    // O n� a ser removido � uma folha
                    if (ant->esq == atual) {
                        ant->esq = NULL;
                    } else {
                        ant->dir = NULL;
                    }
                    system("cls");
                    printf("Participante n�mero %d removido.\n", aExcluir);
                    free(atual);
                    sleep(2);
                    return;
                } else if (atual->esq == NULL) {
                    // O n� a ser removido tem filhos a direita
                    if (ant->esq == atual) {
                        ant->esq = atual->dir;
                    } else {
                        ant->dir = atual->dir;
                    }
                    system("cls");
                    printf("Participante n�mero %d removido.\n", aExcluir);
                    free(atual);
                    sleep(2);
                    return;
                } else if (atual->dir == NULL) {
                    // O n� a ser removido tem filhos a esquerda
                    if (ant->esq == atual) {
                        ant->esq = atual->esq;
                    } else {
                        ant->dir = atual->esq;
                    }
                    system("cls");
                    printf("Participante n�mero %d removido.\n", aExcluir);
                    free(atual);
                    sleep(2);
                    return;
                } else {
                    // Caso em que h� filhos em ambas as dire��es
                    no *substituto = atual->dir;
                    no *antSubstituto = atual;
                    while (substituto->esq != NULL) {
                        antSubstituto = substituto;
                        substituto = substituto->esq;
                    }
                    atual->numero = substituto->numero;

                    if (antSubstituto == atual) {
                        antSubstituto->dir = substituto->dir;
                    } else {
                        antSubstituto->esq = substituto->dir;
                    }

                    free(substituto);
                }
            }
            printf("Participante n�mero %d removido.\n", aExcluir);
            sleep(2);
            return;
        }

        ant = atual;
        if (aExcluir > atual->numero) {
            atual = atual->dir;
        } else {
            atual = atual->esq;
        }
    }

    printf("Participante n�o encontrado!\n");
    sleep(2);
}


void aExcluir(ArvBin *raiz) {
    if (*raiz == NULL) {
        printf("N�o h� participantes para remover!");
        sleep(2);
        return;
    }

    printf("%-10s%-40s%-10s\n", "N�mero:", "Nome:", "Idade:");
    imprimirArvoreEmOrdem(raiz);

    int aExcluir;
    char input[10], *endInput;

    printf("N�mero do participante a remover: ");
    fgets(input, sizeof(input), stdin);

    aExcluir = (int) strtol(input, &endInput, 10);
    if (*endInput != '\0' && *endInput != '\n') {
        printf("Entrada inv�lida.\n");
        sleep(2);
        return;
    } else {
        removeNo(raiz, aExcluir);
    }
}

