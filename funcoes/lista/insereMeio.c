
void insereMeio(ArvBin *lista, ArvBin *raiz) {
    no *novo = (no *) malloc(sizeof(no)); // Cria item
    if (novo == NULL) {
        exit(0);
    }

    novo->numero = (*raiz)->numero;
    strcpy(novo->primeiroNome, (*raiz)->primeiroNome);
    strcpy(novo->sobrenome, (*raiz)->sobrenome);
    novo->idade = (*raiz)->idade;
    novo->eElite = (*raiz)->eElite;

    if ((*lista) == NULL) { // Verifica se a lista esta vazia
        novo->dir = (*lista); // Novo item da lista recebe o apontamento do in�cio da lista
        *lista = novo; // Apontamento inicial da lista recebe o endere�o do novo item
        novo->esq = NULL; // Apontamento anterior do novo item recebe endere�o de NULL, pois � o in�cio da lista
        return;
    } else {
        no *tmp;
        tmp = *lista;

        // Caso em que a lista s� tem um item
        if ((*lista) != NULL && tmp->dir == NULL) { // Verifica se a lista tem apenas um item
            if (tmp->numero > novo->numero) { // Se o �nico item for maior que o novo
                novo->dir = tmp;  // Novo->pr�ximo recebe endere�o do �nico item
                *lista = novo; // Apontamento inicial da lista recebe o endere�o do novo item
                novo->dir->esq = novo; // Antigo primeiro item que j� existia recebe o endere�o anterior o item novo
                novo->esq = NULL; // Apontamento anterior do novo item recebe endere�o de NULL, pois � o in�cio da lista
            } else {
                novo->dir = NULL; // Novo->pr�ximo recebe endere�o NULL
                tmp->dir = novo; // �nico item recebe endere�o do novo
                novo->esq = tmp; // Apontamento do anterior do novo item recebe o antigo �ltimo
            }
            return;
        }

        // Caso para inserir no meio
        do {
            if (tmp->numero > novo->numero) { // Se o n�mero for menor que o primeiro da lista
                novo->dir = tmp; // Novo->pr�ximo recebe endere�o do �nico item
                tmp->esq = novo;
                novo->esq = NULL;
                *lista = novo; // Ponteiro inicial aponta para novo
                return;
            }
            if (tmp->numero < novo->numero &&
                tmp->dir->numero > novo->numero) { // Se o n�mero for maior que o atual e menor que o pr�ximo
                novo->dir = tmp->dir;
                novo->esq = tmp;
                tmp->dir->esq = novo;
                tmp->dir = novo;
                return;
            }
            tmp = tmp->dir;
            if (tmp->numero < novo->numero &&
                tmp->dir == NULL) { // Se o n�mero for maior que o atual e for o �ltimo da lista
                novo->dir = NULL;
                tmp->dir = novo;
                novo->esq = tmp;
                return;
            }
        } while (tmp->dir != NULL); //Repete enquanto n�o entrar em nenhuma das condi��es
    }
}