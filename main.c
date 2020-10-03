#include <stdio.h>
#include <stdlib.h>
#include "listasencadeadas.h"

int main(void) {
  
// irei testar o programa

  Lista* minhalista;  

  minhalista = crialista(); 

  for (int i = 0 ; i < 20 ; i++) // inserir os numeros de 0 até 19
  {
    minhalista = insere(minhalista, i);
  }

  imprime(minhalista); // imprimiremos a lista de 0 até 19

  for (int i = 5 ; i < 15 ; i++) // apagar os itens de 5 a 14
  {
     minhalista = apaga(minhalista, i);
  }
  
imprime(minhalista); // imprimimr a lista novamente
 
for (int i = 50 ; i < 60 ; i++) // vamos usar a nova função para inserir os valores de de 50 a 59 no fim da lista
  {
     minhalista = inserenofim(minhalista, i);
  }
  
imprime(minhalista); // imprimimr a lista novamente


libera(&minhalista); // liberar tudo!! 



  return 0;
}