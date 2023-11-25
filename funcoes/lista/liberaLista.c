
void liberaLista(ArvBin *lista) {
    if ((*lista) == NULL) {
        return;
    } else {
        no *tmp;
        while ((*lista) != NULL) {
            tmp = *lista;
            *lista = (*lista)->dir;
            free(tmp);
        }
    }
}