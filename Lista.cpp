#include <iostream>
#include <string>
#include "Lista.h"

//#define VALOR_QUALQUER "extremos"

No CriarNo(string);

bool DestruirNo(No);

/**
    Função que aloca memória para uma instância da estrutura Lista e inicializa os seus campos.
 */
Lista LIS_Criar()
{
    string VALOR_QUALQUER = "valor";

    Lista lista = new (tpLista);
    if( lista == NULL )
    {
        return NULL;
    }

    
    lista->tamanho = 0;
    
    lista->cauda = CriarNo((string)VALOR_QUALQUER);
    

    if( lista->cauda == NULL )
    {
        return NULL;
    }

    lista->cabeca = CriarNo(VALOR_QUALQUER);
    if( lista->cabeca == NULL )
    {
        return NULL;
    }
    
    lista->cauda->anterior = lista->cabeca;
    lista->cauda->proximo = NULL;

    lista->cabeca->proximo  = lista->cauda;
    lista->cabeca->anterior = NULL;
    
    return lista;
}

/*
 Função que insere um valor no fim da lista. Após a execução desta função, o elemento inserido será o último elemento da lista.
 @param lista - lista em que será feita a inserção
 @param v - valor a ser inserido na lista
 @return true se inseriu com sucesso, false caso contrário
 */
bool LIS_InserirFim(Lista lista, string conteudodoarquivo)
{
    No no = CriarNo(conteudodoarquivo);
    if( no == NULL )
    {
        return false;
    }
    
    No ultimo = lista->cauda->anterior;

    lista->cauda->anterior = no;
    no->proximo = lista->cauda;
    no->anterior = ultimo;    
    ultimo->proximo = no;

    lista->tamanho++;
    return true;
}



/*
 Função que remove um valor no início da lista.
 */
string LIS_RemoverInicio(Lista lista)
{
    string tiradocomeco = "tiradocomeco";
    if (lista->cabeca->proximo == lista->cauda){
        return tiradocomeco;
    }
    else{
        No primeiro = lista->cabeca->proximo;

        lista->cabeca->proximo = primeiro->proximo;
        primeiro->proximo->anterior = lista->cabeca;
        
        string valorremovido = primeiro->conteudodoArquivo;

        DestruirNo(primeiro);

        lista->tamanho--;

        return valorremovido;
    }
}

/*
 Função que remove um valor numa determinada posição da lista.
 */
string LIS_Remover(Lista lista, int indice)
{    
    string tiradocomeco = "tiradocomeco"
    if (indice > lista->tamanho || indice <= 0){  
        return tiradocomeco;
    }
    
    if(lista->tamanho == 0){
        return tiradocomeco;
    }
    if (indice == 1){
        return LIS_RemoverInicio(lista);
    }
    
    No no = lista->cabeca;

    while (--indice){   
        no = no->proximo;
    }

    string valorremovido = no->conteudodoArquivo;

    no->anterior->proximo = no->proximo;
    no->proximo->anterior = no->anterior;
    lista->tamanho--;

    return valorremovido;
}

int LIS_Buscar(Lista lista, string chave)
{
    No no = lista->cabeca->proximo;
    for (int i=0; i < lista->tamanho; i++){
        if (no->conteudo.substr(0,chave.size()) == chave){ // 0 é a posição do primeiro caracter a ser copiado na substr (do primeiro caracter)
            i++;                  // numero de caracteres a serem copiados é o mesmo numero de caracteres da chave
            return i;
        }
        no = no->proximo;
    }

    return -1;
}

/*
    Função que imprime todos os elementos de uma lista.
 */
void LIS_Imprimir(Lista lista)
{
    //std::cout << "Tamanho " << lista->tamanho << std::endl;
    for(No i = lista->cabeca->proximo; i != lista->cauda; i = i->proximo)
    {
        std::cout << "\t-  \""<< i->nome <<"\"\n";
    }
    std::cout << std::endl;
}

/**
 Função que libera a memória de uma instância da estrutura Lista, liberando a memória de todos os nós encadeados na lista, incluindo os nós cabeça e cauda.
 */
void LIS_Destruir(Lista lista)
{
    No atual = lista->cabeca;
    while( atual != NULL )
    {
        No destruido = atual;
        atual = atual->proximo;
        DestruirNo(destruido);
    }
    free(lista);
}

/*
 Função que aloca a memória para um nó e inicializa os atributos do nó.
 */
No CriarNo(string indice)
{



    No no = new tpNo;
    if( no == NULL )
    {
        return NULL;
    }
    
    no->proximo = NULL;
    no->anterior = NULL;
    no->nomedoArquivo = "";
    no->conteudodoArquivo = indice;
    
    
    return no;
}


/*
 Função que libera a memória alocada para um nó.
 */
bool DestruirNo(No no)
{
    free(no);
    return true;
}


