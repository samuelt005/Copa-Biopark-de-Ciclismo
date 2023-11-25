#include "global.h"

int main() {
    setlocale(LC_ALL, "Portuguese");
    int running = 1;

    ArvBin *raiz = criaArvBin();

    while (running == 1) {
        char input[10], *endInput;
        int selector;
        int altura;

        system("cls"); //Limpeza do terminal

        //Menu principal
        printf(CYN "==================================== MENU PRINCIPAL ===================================\n" CR);
        printf("1 - Cadastrar Participante\n");
        printf("2 - Remover Participante\n");
        printf("3 - Listar Participantes\n");
        printf("4 - Editar Participante\n");
        printf("5 - Total de Participantes\n");
        printf("6 - Balancear Lista de Participantes\n");
        printf("7 - Gerar Participantes\n");
        printf("0 - Sair\n\n");
        printf("Selecione a op��o desejada:\n");
        fgets(input, sizeof(input), stdin);

        selector = (int) strtol(input, &endInput, 10);
        if (*endInput != '\0' && *endInput != '\n') {
            system("cls");
            printf(RED "Entrada inv�lida. Digite um n�mero.\n" CR);
            sleep(2);
            continue;
        }

        system("cls");

        switch (selector) {
            // Case para cadastrar na �rvore bin�ria
            case 1:
                system("cls");
                insereArvBin(raiz);
                balancearArvore(raiz);
                system("cls");
                break;

                // Case para excluir n� da �rvore bin�ria
            case 2:
                system("cls");
                aExcluir(raiz);
                balancearArvore(raiz);
                system("cls");
                break;

                // Case imprimirItem a �rvore bin�ria
            case 3:
                system("cls");
                altura = alturaArvore(*raiz);
                imprimirArvore(raiz, altura);
                sleep(2);
                system("cls");
                break;

                // Case para editar n� da �rvore bin�ria
            case 4:
                system("cls");
                aEditar(raiz);
                sleep(2);
                system("cls");
                break;

                // Case para contar a quantidade de n�s
            case 5:
                system("cls");
                int qtdNos = contarArvore(raiz);
                printf("Quantidade de Participantes: %d", qtdNos);
                sleep(2);
                system("cls");
                break;

                // Case para balancear a �rvore bin�ria
            case 6:
                system("cls");
                balancearArvore(raiz);
                system("cls");
                break;

                // Case para popular a �rvore bin�ria
            case 7:
                system("cls");
                geraDados(raiz);
                system("cls");
                break;

                //Case para encerrar o programa
            case 0:
                printf("Saindo... volte sempre!");
                printf(GRN " :)\n" CR);
                sleep(2);
                liberaArvBin(raiz);
                running = 0;
                break;

                //Case de op��o inv�lida
            default:
                printf(RED "Op��o inv�lida!" CR);
                sleep(2);
                break;
        } //End Switch
    }
}
