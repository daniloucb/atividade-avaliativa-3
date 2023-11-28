#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
};

typedef struct Produto {
  int codigo;
  char descricao[50];
  int quantidade;
  int valor;
  struct Produto *prox;
} Produto;

Produto *inicializarLista(int *lista) {
  return NULL;
};

void mostrarOpcoes() {
  printf("\npara continuar selecione uma opção\n");
  printf("1. adicionar novo produto\n");
  printf("2. relatório dos produtos\n");
  printf("3. pesquisar produto\n");
  printf("4. remover produto\n");
};

Produto* criarProduto() {
  Produto *novoProduto = (Produto*)malloc(sizeof(Produto))

  if(novoProduto == NULL)
  {
    printf("Erro de alocação");
    exit(EXIT_FAILURE)
  }
  novoProduto->prox = NULL;
  return novoProduto;
}

Produto* cadastrar(Pessoa *lista) {
  Produto *novoProduto = criarProduto();

  srand(time(NULL));

  printf("\nDigite o código do produto: ");
  scanf("%d", &e->produto->codigo);

  clearBuffer();
  printf("\nDigite a descrição do produto: ");
  fgets(e->produto->descricao, 50, stdin);

  printf("\nDigite a quantidade do produto: ");
  scanf("%d", &e->produto->quantidade);

  printf("\nDigite a valor do produto: ");
  scanf("%d", &e->produto->valor);

  if(lista == NULL)
    return novoProduto;
  else
  {
    while(atual->prox != NULL)
    {
      atual = atual->prox;
    }
    atual->prox = novoProduto;
  }
};

// void mostrarRelatorio(struct estoque *e, int products) {
//   for (int i = 0; i < products; i++) {
//     printf("%d\n", e[i].produto->codigo);
//   }
// };

void selecionarOpcao() {
  int option;
  scanf("%d", &option);
  
  Pessoa *lista = inicializarLista();

  switch (option) {
  case 1:
    lista = cadastrar(&lista);
    // adicionarProduto(e);
    // printf("produto adicionado!\n");
    // products++;
    // sleep(2);
    // mostrarOpcoes();

    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  default:
    printf("opção inválida");
    mostrarOpcoes();
    break;
  }
};

int main(void) {
  Produto *produto = inicializarLista();

  printf("bem vindo ao sistema de controle do estoque!\n\n");
  mostrarOpcoes();
  selecionarOpcao();

  return 0;
}
