#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
};

struct produto {
  int codigo;
  char descricao[50];
  int quantidade;
  int valor;
};

struct estoque {
  struct produto produto[100];
};

struct estoque *inicializarLista() {
  return malloc(sizeof(struct estoque));
};

void mostrarOpcoes() {
  printf("\npara continuar selecione uma opção\n");
  printf("1. adicionar novo produto\n");
  printf("2. relatório dos produtos\n");
  printf("3. pesquisar produto\n");
  printf("4. remover produto\n");
};

void adicionarProduto(struct estoque *e) {
  printf("\nDigite o código do produto: ");
  scanf("%d", &e->produto->codigo);

  // clearBuffer();
  // printf("\nDigite a descrição do produto: ");
  // fgets(e->produto->descricao, 50, stdin);

  // printf("\nDigite a quantidade do produto: ");
  // scanf("%d", &e->produto->quantidade);

  // printf("\nDigite a valor do produto: ");
  // scanf("%d", &e->produto->valor);
};

void mostrarRelatorio(struct estoque *e, int products) {
  for (int i = 0; i < products; i++) {
    printf("%d\n", e[i].produto->codigo);
  }
};

void selecionarOpcao(struct estoque *e, int products) {
  int option;
  scanf("%d", &option);

  switch (option) {
  case 1:
    adicionarProduto(e);
    printf("produto adicionado!\n");
    products++;
    sleep(2);
    mostrarOpcoes();

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
  struct estoque *e = inicializarLista();
  int i = 1;

  printf("bem vindo ao sistema de controle do estoque!\n\n");
  mostrarOpcoes();
  selecionarOpcao(e, products);

  return 0;
}
