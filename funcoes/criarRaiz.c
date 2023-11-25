
ArvBin *criaArvBin() {
    ArvBin *raiz = (ArvBin *) malloc(sizeof(ArvBin));
    if (raiz != NULL) {
        *raiz = NULL;
    } else {
        printf(RED "Erro na alocação...\n" CR);
        exit(0);
    }
    return raiz;
}