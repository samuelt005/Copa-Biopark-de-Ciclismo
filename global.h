//Arquivo Header com todas as bibliotecas utilizadas globalmente
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

//Início da biblioteca GLOBAL.H
#ifndef GLOBAL_H
#define GLOBAL_H

// Definindo a estrutura da lista
struct No {
    int numero;
    char primeiroNome[20];
    char sobrenome[20];
    int idade;
    int eElite;
    struct No *esq, *dir;
};

typedef struct No no;
typedef no *ArvBin;

// Variáveis globais
int elite = 0;
int ate18 = 100;
int ate29 = 200;
int ate39 = 300;
int acima40 = 400;

#include "colorCodes.c"
#include "funcoes/funcoes.h"

#endif
//Fim da biblioteca GLOBAL.H