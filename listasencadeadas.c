#include <stdio.h>
#include <stdlib.h>
#include "listasencadeadas.h"


Lista* crialista()
{
  return NULL;
} // CRIA UMA LISTA VAZIA. O INICIO DA LISTA É RETORNADO. O INICIO APONTA PARA NULL PORQUE NAO EXISTE O PRIMEIRO NODO.

// FUNÇÃO DE INSERIR: INSERE NO INICIO DA LISTA
Lista* insere(Lista* ref, int valor)
{
  Lista* novoNo = (Lista*) malloc(sizeof (Lista));
  novoNo->info = valor;
  novoNo-> prox = ref; // ref é o começo da lista que a main enviou(o proximo elemento do no vai ser o antigo inicio da lista)
  ref = novoNo;
  return ref; // retornamos o novo inicio da lista(ref recebeu novo no)

}



void imprime(Lista* ref)
{
  Lista* p;
  printf("\n Imprimindo a lista: \n");
  if (ref == NULL) {
    printf("lista vazia!\n");
    return;
  }
  for (p=ref; p!= NULL ; p= p->prox){
    printf("%4i", p->info);
  }
}

Lista* apaga(Lista* ref, int valor) // remove o no que tenha info== valor
// temos que remover o valor sem perder o encadeamento
{
  Lista* p = ref; // percorrer e checar se é o info desejado
  Lista* ant = NULL; // fica sempre uma casa antes de p
  while((p != NULL) && (p->info != valor)) // enquanto p for diferente de nulo(ou seja, tem elementos na lista) e enquanto p info for diferente do valor desejado, continuamos percorrento a lista.
  {
    ant = p;
    p = p-> prox;
  } // garantimos ant sempre uma casa atras de p
  if ( p == NULL)  return ref; // percorremos toda a lista e nao encontramos a informação desejada;
  if (p == ref) ref = p -> prox; // o percorredor p parou logo no inicio(ref) entao ref(inicio da lista) vai ser p->prox (o segundo elemento da lista)
  else ant-> prox = p -> prox;  // se encontrarmos o valor no meio da lista, fazemos com que o proximo do ant seja o prox de p

  free(p);
  return ref;
}

void libera(Lista** lista){
  Lista* l = *lista; // estamos pegando o inicio da lista, que já é um ponteiro
  while (l != NULL)
  {
    Lista* aux = l-> prox; // aux serve para armazenarmos o proximos, pois assim conseguimos liberar o atual
    free(l);
    l = aux; // (que é o proximo)
  }
  *lista = NULL; // fazemos isso pois quando liberamos toda a memoria, o sistema continua com o ponteiro apontando para o inicio da lista. é uma boa pratica fazer isso!!!
}


Lista* inserenofim(Lista* ref, int valor)
{
  Lista* p = ref; 
  Lista* novoNo = (Lista*) malloc(sizeof (Lista));
  while(p->prox != NULL) 
  {
       p = p-> prox;
  }  


  p->prox = novoNo;
  novoNo->info = valor;
  novoNo-> prox = NULL; 

   
return ref;
}  