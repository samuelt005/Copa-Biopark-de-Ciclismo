
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
        novo->dir = (*lista); // Novo item da lista recebe o apontamento do início da lista
        *lista = novo; // Apontamento inicial da lista recebe o endereço do novo item
        novo->esq = NULL; // Apontamento anterior do novo item recebe endereço de NULL, pois é o início da lista
        return;
    } else {
        no *tmp;
        tmp = *lista;

        // Caso em que a lista só tem um item
        if ((*lista) != NULL && tmp->dir == NULL) { // Verifica se a lista tem apenas um item
            if (tmp->numero > novo->numero) { // Se o único item for maior que o novo
                novo->dir = tmp;  // Novo->próximo recebe endereço do único item
                *lista = novo; // Apontamento inicial da lista recebe o endereço do novo item
                novo->dir->esq = novo; // Antigo primeiro item que já existia recebe o endereço anterior o item novo
                novo->esq = NULL; // Apontamento anterior do novo item recebe endereço de NULL, pois é o início da lista
            } else {
                novo->dir = NULL; // Novo->próximo recebe endereço NULL
                tmp->dir = novo; // Único item recebe endereço do novo
                novo->esq = tmp; // Apontamento do anterior do novo item recebe o antigo último
            }
            return;
        }

        // Caso para inserir no meio
        do {
            if (tmp->numero > novo->numero) { // Se o número for menor que o primeiro da lista
                novo->dir = tmp; // Novo->próximo recebe endereço do único item
                tmp->esq = novo;
                novo->esq = NULL;
                *lista = novo; // Ponteiro inicial aponta para novo
                return;
            }
            if (tmp->numero < novo->numero &&
                tmp->dir->numero > novo->numero) { // Se o número for maior que o atual e menor que o próximo
                novo->dir = tmp->dir;
                novo->esq = tmp;
                tmp->dir->esq = novo;
                tmp->dir = novo;
                return;
            }
            tmp = tmp->dir;
            if (tmp->numero < novo->numero &&
                tmp->dir == NULL) { // Se o número for maior que o atual e for o último da lista
                novo->dir = NULL;
                tmp->dir = novo;
                novo->esq = tmp;
                return;
            }
        } while (tmp->dir != NULL); //Repete enquanto não entrar em nenhuma das condições
    }
}