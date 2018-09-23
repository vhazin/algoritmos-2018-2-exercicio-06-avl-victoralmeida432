#include <stdio.h>
#include <stdlib.h>

int AlturaMin(int lista[], int raiz, int numeros){
  int esquerda = 2*raiz+1;
  int direita = 2*raiz+2;

  if(lista[raiz] == -1){
    return 0;
  }

  if(direita < numeros){
    if(lista[esquerda] == -1){
      return 1;
    }

    if(lista[direita] == -1 && lista[esquerda] != 12){
      return 1;
    }

    if(lista[direita] == -1 && lista[esquerda] == 12){
      return 2;
    }

    if(AlturaMin(lista, esquerda, numeros) >= AlturaMin(lista, direita, numeros)){
      return AlturaMin(lista, direita, numeros) + 1;
    }else{
      return AlturaMin(lista, esquerda, numeros) + 1;
    }
  }else{
    if(esquerda < numeros){
        return AlturaMin(lista, esquerda, numeros) + 1;
      }else{
        return 1;
    }
  }
}

int AlturaMax(int lista[], int raiz, int numeros)  
{ 
  int esquerda = (2*raiz) + 1;
  int direita = (2*raiz) + 2;

  if (lista[raiz] == -1){
    return 0;
  } 
  else
  {
    if(direita < numeros){
      int alturaEsquerda = AlturaMax(lista, esquerda, numeros); 
      int alturaDireita = AlturaMax(lista, direita, numeros); 
    
      if (alturaEsquerda > alturaDireita){
        return(alturaEsquerda + 1);
      }else{
        return(alturaDireita + 1);
      }
    }
    else{
      if(esquerda < numeros){
        int alturaEsquerda = AlturaMax(lista, esquerda, numeros);
        return(alturaEsquerda + 1);
      }
      else{
        return 1;
      }
    }
  }
} 

int main(void) {
  int casos, numeros;

  scanf("%d", &casos);

  while(casos--){
    scanf("%d", &numeros);
    int arvore[numeros];

    for(int i = 0; i < numeros; i++){
      scanf("%d", &arvore[i]);
    }

    int min = AlturaMin(arvore, 0, numeros);
    int max = AlturaMax(arvore, 0, numeros);

    //printf("min = %d", min);
    //printf("   max = %d\n", max);
    if(max-min<=1){
      printf("T\n");
    }else{
      printf("F\n");
    }
  }
  return 0;
}
