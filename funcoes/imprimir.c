void imprimirItem(ArvBin *raiz) {
    char nomeCompleto[41];
    snprintf(nomeCompleto, sizeof(nomeCompleto), "%s %s", (*raiz)->primeiroNome, (*raiz)->sobrenome);
    char textoElite[4];
    if ((*raiz)->eElite == 1) {
        strcpy(textoElite, "Sim");
    } else {
        strcpy(textoElite, "Não");
    }
    printf("%-10d%-40s%-10d%-10s\n", (*raiz)->numero, nomeCompleto, (*raiz)->idade, textoElite);
}

// Método em Ordem
void imprimirEmOrdem(ArvBin *raiz) {
    if (*raiz != NULL) {
        imprimirEmOrdem(&((*raiz)->esq));
        imprimirItem(raiz);
        imprimirEmOrdem(&((*raiz)->dir));
    }
}

// Método Pré-Ordem
void imprimirPreOrdem(ArvBin *raiz) {
    if (*raiz != NULL) {
        imprimirItem(raiz);
        imprimirPreOrdem(&((*raiz)->esq));
        imprimirPreOrdem(&((*raiz)->dir));
    }
}

// Método Pós-Ordem
void imprimirPosOrdem(ArvBin *raiz) {
    if (*raiz != NULL) {
        imprimirPosOrdem(&((*raiz)->esq));
        imprimirPosOrdem(&((*raiz)->dir));
        imprimirItem(raiz);
    }
}

// Método Bidimensional
void imprimirBidimensional(no *aux, int espaco) {
    if (aux == NULL) {
        return;
    }

    espaco += 5;

    imprimirBidimensional(aux->esq, espaco);

    printf("\n");
    for (int i = 5; i < espaco; i++) {
        printf(" ");
    }
    printf("%d\n", aux->numero);

    imprimirBidimensional(aux->dir, espaco);
}


// Menu de seleção de método
void imprimirArvore(ArvBin *raiz, int altura) {
    int running = 1;

    while (running == 1) {
        char input[10], *endInput;
        int selector;

        printf(CYN "==================================== MÉTODOS DE IMPRESSÃO ===================================\n" CR);
        printf("1 - Em Ordem\n");
        printf("2 - Pré-Ordem\n");
        printf("3 - Pós-Ordem\n");
        printf("4 - Bidimensional\n");
        printf("0 - Voltar\n\n");
        printf("Selecione o método desejado:\n");
        fgets(input, sizeof(input), stdin);

        selector = (int) strtol(input, &endInput, 10);
        if (*endInput != '\0' && *endInput != '\n') {
            printf(RED "Entrada inválida. Digite um número.\n" CR);
            sleep(2);
            continue;
        }

        system("cls");

        switch (selector) {
            // Método em Ordem
            case 1:
                system("cls");
                printf(CYN
                       "====================================== PARTICIPANTES ======================================\n"
                       CR);
                printf("%-10s%-40s%-10s%-10s\n", "Número:", "Nome:", "Idade:", "Elite:");
                imprimirEmOrdem(raiz);
                printf(CYN "--------------------------------------------------------------------------------------------\n" CR);
                sleep(4);
                system("cls");
                break;

                // Método Pré-Ordem
            case 2:
                system("cls");
                printf(CYN
                       "====================================== PARTICIPANTES ======================================\n"
                       CR);
                printf("%-10s%-40s%-10s%-10s\n", "Número:", "Nome:", "Idade:", "Elite:");
                imprimirPreOrdem(raiz);
                printf(CYN "--------------------------------------------------------------------------------------------\n" CR);
                sleep(4);
                system("cls");
                break;

                // Método Pós-Ordem
            case 3:
                system("cls");
                printf(CYN
                       "====================================== PARTICIPANTES ======================================\n"
                       CR);
                printf("%-10s%-40s%-10s%-10s\n", "Número:", "Nome:", "Idade:", "Elite:");
                imprimirPosOrdem(raiz);
                printf(CYN "--------------------------------------------------------------------------------------------\n" CR);
                sleep(4);
                system("cls");
                break;

                // Método Pós-Ordem
            case 4:
                system("cls");
                imprimirBidimensional(*raiz, 0);
                printf("\n");
                sleep(4);
                system("cls");
                break;

                // Case para voltar
            case 0:
                printf(BLK "Voltando...!" CR);
                running = 0;
                break;

                // Case de opção inválida
            default:
                printf(RED "Opção inválida!" CR);
                sleep(2);
                break;
        }
    }
}