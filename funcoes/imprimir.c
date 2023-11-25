void imprimirItem(ArvBin *raiz) {
    char nomeCompleto[41];
    snprintf(nomeCompleto, sizeof(nomeCompleto), "%s %s", (*raiz)->primeiroNome, (*raiz)->sobrenome);
    char textoElite[4];
    if ((*raiz)->eElite == 1) {
        strcpy(textoElite, "Sim");
    } else {
        strcpy(textoElite, "N�o");
    }
    printf("%-10d%-40s%-10d%-10s\n", (*raiz)->numero, nomeCompleto, (*raiz)->idade, textoElite);
}

// M�todo em Ordem
void imprimirEmOrdem(ArvBin *raiz) {
    if (*raiz != NULL) {
        imprimirEmOrdem(&((*raiz)->esq));
        imprimirItem(raiz);
        imprimirEmOrdem(&((*raiz)->dir));
    }
}

// M�todo Pr�-Ordem
void imprimirPreOrdem(ArvBin *raiz) {
    if (*raiz != NULL) {
        imprimirItem(raiz);
        imprimirPreOrdem(&((*raiz)->esq));
        imprimirPreOrdem(&((*raiz)->dir));
    }
}

// M�todo P�s-Ordem
void imprimirPosOrdem(ArvBin *raiz) {
    if (*raiz != NULL) {
        imprimirPosOrdem(&((*raiz)->esq));
        imprimirPosOrdem(&((*raiz)->dir));
        imprimirItem(raiz);
    }
}

// M�todo Bidimensional
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


// Menu de sele��o de m�todo
void imprimirArvore(ArvBin *raiz, int altura) {
    int running = 1;

    while (running == 1) {
        char input[10], *endInput;
        int selector;

        printf(CYN "==================================== M�TODOS DE IMPRESS�O ===================================\n" CR);
        printf("1 - Em Ordem\n");
        printf("2 - Pr�-Ordem\n");
        printf("3 - P�s-Ordem\n");
        printf("4 - Bidimensional\n");
        printf("0 - Voltar\n\n");
        printf("Selecione o m�todo desejado:\n");
        fgets(input, sizeof(input), stdin);

        selector = (int) strtol(input, &endInput, 10);
        if (*endInput != '\0' && *endInput != '\n') {
            printf(RED "Entrada inv�lida. Digite um n�mero.\n" CR);
            sleep(2);
            continue;
        }

        system("cls");

        switch (selector) {
            // M�todo em Ordem
            case 1:
                system("cls");
                printf(CYN
                       "====================================== PARTICIPANTES ======================================\n"
                       CR);
                printf("%-10s%-40s%-10s%-10s\n", "N�mero:", "Nome:", "Idade:", "Elite:");
                imprimirEmOrdem(raiz);
                printf(CYN "--------------------------------------------------------------------------------------------\n" CR);
                sleep(4);
                system("cls");
                break;

                // M�todo Pr�-Ordem
            case 2:
                system("cls");
                printf(CYN
                       "====================================== PARTICIPANTES ======================================\n"
                       CR);
                printf("%-10s%-40s%-10s%-10s\n", "N�mero:", "Nome:", "Idade:", "Elite:");
                imprimirPreOrdem(raiz);
                printf(CYN "--------------------------------------------------------------------------------------------\n" CR);
                sleep(4);
                system("cls");
                break;

                // M�todo P�s-Ordem
            case 3:
                system("cls");
                printf(CYN
                       "====================================== PARTICIPANTES ======================================\n"
                       CR);
                printf("%-10s%-40s%-10s%-10s\n", "N�mero:", "Nome:", "Idade:", "Elite:");
                imprimirPosOrdem(raiz);
                printf(CYN "--------------------------------------------------------------------------------------------\n" CR);
                sleep(4);
                system("cls");
                break;

                // M�todo P�s-Ordem
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

                // Case de op��o inv�lida
            default:
                printf(RED "Op��o inv�lida!" CR);
                sleep(2);
                break;
        }
    }
}