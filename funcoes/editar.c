no *encontrarNo(ArvBin *raiz, int valor) {
    no *atual = *raiz;

    while (atual != NULL) {
        if (valor == atual->numero) {
            return atual;
        } else if (valor < atual->numero) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
    return NULL;
}

void editarNo(ArvBin *raiz, int aEditar) {
    char input[10], *endInput;
    int selector;

    no *noAEditar = encontrarNo(raiz, aEditar);

    if (noAEditar == NULL) {
        printf(RED "Participante não encontrado!\n" CR);
        return;
    }

    system("cls");

    printf(CYN
           "================================= PARTICIPANTE SELECIONADO =================================\n"
           CR);
    printf("%-10s%-40s%-10s%-10s\n", "Número:", "Nome:", "Idade:", "Elite:");
    imprimirItem(&noAEditar);
    printf(CYN "--------------------------------------------------------------------------------------------\n" CR);

    printf("1 - Primeiro nome\n");
    printf("2 - Sobrenome\n");
    printf("3 - Idade\n");
    printf("4 - Categoria Elite\n");
    printf("0 - Voltar\n\n");
    printf("O que deseja editar?\n");
    fgets(input, sizeof(input), stdin);

    selector = (int) strtol(input, &endInput, 10);
    if (*endInput != '\0' && *endInput != '\n') {
        printf(RED "Entrada inválida.\n" CR);
        sleep(2);
        return;
    }

    system("cls");

    switch (selector) {
        // Editar nome
        case 1:
            system("cls");
            printf("Primeiro nome: ");
            fgets(noAEditar->primeiroNome, sizeof(noAEditar->primeiroNome), stdin);
            size_t len = strlen(noAEditar->primeiroNome);
            if (len > 0 && noAEditar->primeiroNome[len - 1] == '\n') {
                noAEditar->primeiroNome[len - 1] = '\0';
            }
            system("cls");
            printf(GRN "Participante editado com sucesso!" CR);
            break;

            // Editar sobrenome
        case 2:
            system("cls");
            printf("Sobrenome: ");
            fgets(noAEditar->sobrenome, sizeof(noAEditar->sobrenome), stdin);
            len = strlen(noAEditar->sobrenome);
            if (len > 0 && noAEditar->sobrenome[len - 1] == '\n') {
                noAEditar->sobrenome[len - 1] = '\0';
            }
            system("cls");
            printf(GRN "Participante editado com sucesso!" CR);
            break;

            // Editar idade
        case 3:
            system("cls");
            printf("Idade: ");

            fgets(input, sizeof(input), stdin);

            noAEditar->idade = (int) strtol(input, &endInput, 10);
            if (*endInput != '\0' && *endInput != '\n') {
                printf(RED "Entrada inválida.\n" CR);
                sleep(2);
                return;
            }

            noAEditar->numero = geraNumero(noAEditar->idade, noAEditar->eElite);

            system("cls");
            printf(GRN "Participante editado com sucesso!\n" CR);
            printf("Novo número emitido: %d", noAEditar->numero);
            balancearArvore(raiz);
            break;

            // Editar categoria elite
        case 4:
            system("cls");
            printf("Deseja participar da categoria Elite (S/N)?\n");

            if (fgets(input, sizeof(input), stdin) == NULL) {
                printf(RED "Erro ao ler a entrada.\n" CR);
                exit(1);
            } else if (input[1] != '\n' && input[1] != '\0') {
                printf(RED "Entrada inválida.\n" CR);
                return;
            }

            char escolha = toupper(input[0]);
            if (escolha == 'S') {
                system("cls");
                printf("Você escolheu participar da categoria Elite.\n");
                if (noAEditar->eElite == 1) {
                    return;
                } else {
                    noAEditar->eElite = 1;
                    noAEditar->numero = geraNumero(noAEditar->idade, noAEditar->eElite);
                    printf(GRN "Participante editado com sucesso!\n" CR);
                    printf("Novo número emitido: %d", noAEditar->numero);
                    balancearArvore(raiz);
                }
            } else if (escolha == 'N') {
                system("cls");
                printf("Você escolheu não participar da categoria Elite.\n");
                if (noAEditar->eElite == 0) {
                    return;
                } else {
                    noAEditar->eElite = 0;
                    noAEditar->numero = geraNumero(noAEditar->idade, noAEditar->eElite);
                    printf(GRN "Participante editado com sucesso!\n" CR);
                    printf("Novo número emitido: %d", noAEditar->numero);
                    balancearArvore(raiz);
                }
            } else {
                system("cls");
                printf(RED "Entrada inválida.\n" CR);
                return;
            }
            break;

            // Case para voltar
        case 0:
            printf(BLK "Voltando...!" CR);
            break;

            // Case de opção inválida
        default:
            printf(RED "Opção inválida!" CR);
            sleep(2);
            break;
    }
}

void aEditar(ArvBin *raiz) {
    if (*raiz == NULL) {
        printf(BLK "Não há participantes para editar!" CR);
        sleep(2);
        return;
    }

    printf(CYN
           "====================================== PARTICIPANTES ======================================\n"
           CR);
    printf("%-10s%-40s%-10s%-10s\n", "Número:", "Nome:", "Idade:", "Elite:");
    imprimirEmOrdem(raiz);
    printf(CYN "--------------------------------------------------------------------------------------------\n" CR);

    int aEditar;
    char input[10], *endInput;

    printf("Número do participante a editar: ");
    fgets(input, sizeof(input), stdin);

    aEditar = (int) strtol(input, &endInput, 10);
    if (*endInput != '\0' && *endInput != '\n') {
        printf(RED "Entrada inválida.\n" CR);
        sleep(2);
        return;
    } else {
        editarNo(raiz, aEditar);
    }
}