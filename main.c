#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Produto {
  int codigo;
  char descricao[50];
  int quantidade;
  int valor;
  struct Produto *prox;
} Produto;

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
};

Produto *inicializarLista() {
  return NULL;
};

void mostrarOpcoes() {
  printf("\npara continuar selecione uma opção\n");
  printf("1. adicionar novo produto\n");
  printf("2. relatório dos produtos\n");
  printf("3. pesquisar produto\n");
  printf("4. remover produto\n");
};

Produto *criarProduto()
{
  Produto *novoProduto = (Produto*)malloc(sizeof(Produto));

  if(novoProduto == NULL)
  {
    printf("Erro de alocação");
    exit(EXIT_FAILURE);
  }
  novoProduto->prox = NULL;
  return novoProduto;
}

Produto *cadastrar(Produto *lista)
{
  Produto *novoProduto = criarProduto();

  printf("\nDigite o código do produto: ");
  scanf("%d", &novoProduto->codigo);

  clearBuffer();
  printf("\nDigite a descrição do produto: ");
  fgets(novoProduto->descricao, 50, stdin);

  printf("\nDigite a quantidade do produto: ");
  scanf("%d", &novoProduto->quantidade);

  printf("\nDigite a valor do produto: ");
  scanf("%d", &novoProduto->valor);

  if(lista == NULL)
    return novoProduto;
  else
  {
    Produto *atual = lista;
    while(atual->prox != NULL)
    {
      atual = atual->prox;
    }
    atual->prox = novoProduto;
    return lista;
  }
}

void mostrarRelatorio(Produto *lista) {
  int i = 1;
  printf("ESTOQUE\n\n");
  while(lista != NULL)
  {
    printf("PRODUTO %d\n", i);
    printf("codigo: %d\n", lista->codigo);
    printf("descrição: %s\n", lista->descricao);
    printf("quantidade: %d\n", lista->quantidade);
    printf("valor: %d\n", lista->valor);

    lista = lista->prox;
    i++;
  }
};

void pesquisarProduto(Produto *lista, int codigo)
{
  Produto *atual = lista;
  
  while(atual != NULL && atual->codigo != codigo)
    atual = atual->prox;

   if(atual != NULL)
    {
      printf("codigo: %d\n", codigo);
      printf("descrição: %s\n", lista->descricao);
      printf("quantidade: %d\n", lista->quantidade);
      printf("valor: %d\n", lista->valor);
    }
    else
      printf("produto não encontrado no estoque");
}

void removerProduto(Produto *lista, int codigo)
{
  Produto *anterior = NULL;
  Produto *atual = lista;

  
  while(atual != NULL && atual->codigo != codigo)
  {
    anterior = atual;
    atual = atual->prox;
  }
    

  if(atual != NULL)
  {
    if(anterior != NULL)
      anterior->prox = atual->prox;
    else
      lista = atual->prox;

    free(atual);
    printf("produto excluido com sucesso!");
  }
  else
    printf("produto não encontrado no estoque");
}

void selecionarOpcao(Produto *lista) {
  int option;
  scanf("%d", &option);

  switch (option) {
  int codigo;
  clearBuffer();
  case 1:
    lista = cadastrar(lista);
    printf("produto adicionado!\n");
    break;
  case 2:
    mostrarRelatorio(lista);
    break;
  case 3:
    printf("digite o codigo do produto a ser buscado: ");
    scanf("%d", &codigo);
    pesquisarProduto(lista, codigo);
    break;
  case 4:
    printf("digite o codigo do produto a ser excluido: ");
    scanf("%d", &codigo);
    removerProduto(lista, codigo);
    break;
  default:
    printf("opção inválida");
    mostrarOpcoes();
    break;
  }

  sleep(2);
  mostrarOpcoes();
  selecionarOpcao(lista);
};

int main(void) {
  Produto *lista = inicializarLista();

  printf("bem vindo ao sistema de controle do estoque!\n\n");
  mostrarOpcoes();
  selecionarOpcao(lista);

  return 0;
}
