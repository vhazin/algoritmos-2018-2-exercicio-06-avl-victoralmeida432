#include <stdio.h>
#include <stdlib.h>

int AlturaMin(int a[], int raiz, int numeros){
  int esq = 2*raiz+1;
  int dir = 2*raiz+2;

  if(a[raiz] == -1){
    return 0;
  }

  if(dir < numeros){
    if(a[esq] == -1){
      return 1;
    }

    if(a[dir] == -1 && a[esq] != 12){
      return 1;
    }

    if(a[dir] == -1 && a[esq] == 12){
      return 2;
    }

    if(AlturaMin(a, esq, numeros) >= AlturaMin(a, dir, numeros)){
      return AlturaMin(a, dir, numeros) + 1;
    }else{
      return AlturaMin(a, esq, numeros) + 1;
    }
  }else{
    if(esq < numeros){
        return AlturaMin(a, esq, numeros) + 1;
      }else{
        return 1;
    }
  }
}

int AlturaMax(int a[], int root, int numeros)  
{ 
  int esq = (2*root) + 1;
  int dir = (2*root) + 2;

  if (a[root] == -1){
    return 0;
  } 
  else
  {
    if(dir < numeros){
      int laltura = AlturaMax(a, esq, numeros); 
      int raltura = AlturaMax(a, dir, numeros); 
    
      if (laltura > raltura){
        return(laltura + 1);
      }else{
        return(raltura + 1);
      }
    }
    else{
      if(esq < numeros){
        int laltura = AlturaMax(a, esq, numeros);
        return(laltura + 1);
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
