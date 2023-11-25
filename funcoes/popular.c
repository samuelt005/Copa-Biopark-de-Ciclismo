// Função para gerar nomes aleatórios
const char *nomes[] = {"Joao", "Maria", "Pedro", "Ana", "Carlos",
                       "Luis", "Fernanda", "Ricardo", "Eduarda", "Lucas"};
const char *sobrenomes[] = {"Silva", "Oliveira", "Santos", "Pereira",
                            "Costa", "Almeida", "Lima", "Martins", "Gomes", "Rodrigues"};


const char *gerarNomeAleatorio(void) {
    return nomes[rand() % (sizeof(nomes) / sizeof(nomes[0]))];
}

const char *gerarSobrenomeAleatorio(void) {
    return sobrenomes[rand() % (sizeof(sobrenomes) / sizeof(sobrenomes[0]))];
}

void popularArvBin(ArvBin *raiz, int idade, int eElite) {
    no *novo = (no *) malloc(sizeof(no));

    if (novo == NULL) {
        printf("Sem memória disponível!\n");
        exit(0);
    }

    novo->numero = geraNumero(idade, eElite);
    novo->eElite = eElite;

    novo->idade = idade;
    strcpy(novo->primeiroNome, gerarNomeAleatorio());
    strcpy(novo->sobrenome, gerarSobrenomeAleatorio());
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
                printf("Elemento já existe...");
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

// Função para gerar dados aleatórios na árvore
void geraDados(ArvBin *raiz) {
    srand(time(NULL));

    popularArvBin(raiz, 28, 0);
    popularArvBin(raiz, 41, 0);
    popularArvBin(raiz, 22, 1);
    popularArvBin(raiz, 38, 0);
    popularArvBin(raiz, 24, 0);
    popularArvBin(raiz, 50, 0);
    popularArvBin(raiz, 15, 0);
    popularArvBin(raiz, 47, 1);
    popularArvBin(raiz, 19, 0);
    popularArvBin(raiz, 44, 1);
    popularArvBin(raiz, 32, 0);
    popularArvBin(raiz, 12, 0);
    popularArvBin(raiz, 23, 0);
    popularArvBin(raiz, 45, 0);
    popularArvBin(raiz, 23, 0);
    popularArvBin(raiz, 38, 0);
    popularArvBin(raiz, 24, 1);
    popularArvBin(raiz, 13, 0);
    popularArvBin(raiz, 87, 0);
    popularArvBin(raiz, 53, 0);
    popularArvBin(raiz, 19, 0);
    popularArvBin(raiz, 65, 0);
}