
ArvBin *criaArvBin() {
    ArvBin *raiz = (ArvBin *) malloc(sizeof(ArvBin));
    if (raiz != NULL) {
        *raiz = NULL;
    } else {
        printf(RED "Erro na aloca��o...\n" CR);
        exit(0);
    }
    return raiz;
}