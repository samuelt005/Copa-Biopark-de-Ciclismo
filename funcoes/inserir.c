
int geraNumero(int idade, int eElite) {
    if (eElite) {
        elite++;
        return elite;
    }
    if (idade <= 18) {
        ate18++;
        return ate18;
    }
    if (idade <= 29) {
        ate29++;
        return ate29;
    }
    if (idade <= 39) {
        ate39++;
        return ate39;
    }
    acima40++;
    return acima40;
}


void insereArvBin(ArvBin *raiz) {
    no *novo = (no *) malloc(sizeof(no));
    char input[21], *endInput;

    if (novo == NULL) {
        printf("Sem mem�ria dispon�vel!\n");
        exit(0);
    }

    printf("Idade: ");

    fgets(input, sizeof(input), stdin);

    novo->idade = (int) strtol(input, &endInput, 10);
    if (*endInput != '\0' && *endInput != '\n') {
        printf("Entrada inv�lida.\n");
        sleep(2);
        return;
    }

    printf("Primeiro nome: ");
    fgets(novo->primeiroNome, sizeof(novo->primeiroNome), stdin);
    size_t len = strlen(novo->primeiroNome);
    if (len > 0 && novo->primeiroNome[len - 1] == '\n') {
        novo->primeiroNome[len - 1] = '\0';
    }

    printf("Sobrenome: ");
    fgets(novo->sobrenome, sizeof(novo->sobrenome), stdin);
    len = strlen(novo->sobrenome);
    if (len > 0 && novo->sobrenome[len - 1] == '\n') {
        novo->sobrenome[len - 1] = '\0';
    }

    printf("Deseja participar da categoria Elite (S/N)?\n");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Erro ao ler a entrada.\n");
        exit(1);
    } else if (input[1] != '\n' && input[1] != '\0') {
        printf("Entrada inv�lida.\n");
        sleep(2);
        return;
    }

    char escolha = toupper(input[0]);
    if (escolha == 'S') {
        printf("Voc� escolheu participar da categoria Elite.\n");
        sleep(2);
        novo->eElite = 1;
    } else if (escolha == 'N') {
        printf("Voc� escolheu n�o participar da categoria Elite.\n");
        sleep(2);
        novo->eElite = 0;
    } else {
        printf("Entrada inv�lida.\n");
        sleep(2);
        return;
    }

    novo->numero = geraNumero(novo->idade, novo->eElite);

    novo->dir = NULL;
    novo->esq = NULL;
    if (*raiz == NULL) {
        *raiz = novo;
    } else {
        no *atual = *raiz;
        no *ant = NULL;
        while (atual != NULL) {
            ant = atual;
            if (novo->numero == atual->numero) {
                printf("Elemento j� existe...");
                sleep(2);
                free(novo);
                return;
            }
            if (novo->numero > atual->numero) {
                atual = atual->dir;
            } else {
                atual = atual->esq;
            }
        }
        if (novo->numero > ant->numero) {
            ant->dir = novo;
        } else {
            ant->esq = novo;
        }
    }
}