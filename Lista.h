#include <iostream>
#include <string>


struct tpNo
{
    string  nomedoArquivo;
    string conteudodoArquivo;
    struct tpNo* proximo;
    struct tpNo* anterior;
};

typedef tpNo * No;


struct tpLista
{
    No cabeca;
    No cauda;
    int tamanho;
};


typedef tpLista * Lista;

void LIS_Imprimir(Lista);

Lista LIS_Criar();

void LIS_Destruir(Lista);

bool LIS_InserirFim(Lista, string);
