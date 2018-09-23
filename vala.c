#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef struct Elemento{
  int data;
  struct Elemento *direita;
  struct Elemento *esquerda;
}elemento;

elemento *criarArvore(int data){
  elemento *temp;
  temp = malloc(sizeof(elemento));
  temp -> direita = NULL;
  temp -> esquerda = NULL;
  temp -> data = data;
  return(temp);
}

elemento *addArvore(elemento *elemento, int data){
  
  if(elemento == NULL){
    return(criarArvore(data));
  }
  if(data < elemento->data){
    elemento -> esquerda = addArvore(elemento->esquerda, data);
  }else if(data > elemento->data){
    elemento -> direita = addArvore(elemento->direita, data);
  }

  return(elemento);
}

int minDepth(elemento *root) 
{ 

    if (root == NULL) 
        return 0; 
  
 
    if (root->esquerda == NULL && root->direita == NULL) 
       return 1; 
  

    if (!root->esquerda) 
       return minDepth(root->direita) + 1; 
  

    if (!root->direita) 
       return minDepth(root->esquerda) + 1; 
  
    return min(minDepth(root->esquerda), minDepth(root->direita)) + 1; 
} 

int maxDepth(elemento *root) 
{ 
 
    if (root == NULL) 
        return 0; 
  
 
    if (root->esquerda == NULL && root->direita == NULL) 
       return 1; 
  
 
    if (!root->esquerda) 
       return minDepth(root->direita) + 1; 
   
    if (!root->direita) 
       return minDepth(root->esquerda) + 1; 
  
    return max(minDepth(root->esquerda), minDepth(root->direita)) + 1; 
} 

int main(void) {
  int casos, numeros, data;

  scanf("%d", &casos);

  while(casos--){
    scanf("%d", &numeros);
    elemento *root = NULL;
    root = malloc(sizeof(elemento));

    for(int i = 0; i < numeros; i++){
      scanf("%d", &data);
      root = addArvore(root, data);
    }

    int min = minDepth(root);
    int max = maxDepth(root);


    if(max-min<=1){
      printf("T\n");
    }else{
      printf("F\n");
    }
  }
  return 0;
}
