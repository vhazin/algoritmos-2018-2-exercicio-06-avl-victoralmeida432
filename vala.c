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

  if(data == -1){
    return(elemento);
  }

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
 
int getHeight(elemento* root) {
    return root == NULL ? 0 : 1 +
        max(getHeight(root->esquerda), getHeight(root->direita));
}

 int isBalanced(elemento* root) {
        if (root == NULL) {
            return 1;
        }
        int esquerda = getHeight(root->esquerda);
        int direita = getHeight(root->direita);
        return abs(esquerda - direita) <= 1 && isBalanced(root->esquerda) && isBalanced(root->direita);
  }

int main(void) {
  int casos, numeros, data;

  scanf("%d", &casos);

  while(casos--){
    scanf("%d", &numeros);
    elemento *root;
    root = malloc(sizeof(elemento));
    root = NULL;

    for(int i = 0; i < numeros; i++){
      scanf("%d", &data);
      root = addArvore(root, data);
    }

    int balance = isBalanced(root);

    if(balance){
      printf("T\n");
    }else{
      printf("F\n");
    }
  }
  return 0;
}
