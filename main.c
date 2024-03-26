#include "tarefa.h"
#include <stdio.h>

int main() {
  int pos = 0;
  Tarefa tarefas[TOTAL];

  Erro e = carregar(tarefas, TOTAL, &pos);  
  if (e == ABRIR){
    printf("Erro ao abrir o arquivo\n");
    pos = 0;
  }
  else if (e == LER)
    printf("Erro ao ler o arquivo\n");
  else if (e == FECHAR)
    printf("Erro ao fechar o arquivo\n");if (e != OK)
    pos = 0;

  int opcao;
  do {
    printf("\nMenu principal\n");
    printf("1 - Criar tarefa\n");
    printf("2 - Deletar tarefa\n");
    printf("3 - Listar tarefas\n");
    printf("0 - Sair\n");
    printf("Entre com uma opção: ");
    int i = scanf("%d", &opcao);
    printf("Opção escolhida: %d\n", opcao);
    if(opcao == 1){
      e = criar(tarefas, &pos);
      if (e == MAX_TAREFAS)
        printf("Máximo de tarefas alcançadas\n");
    } else if (opcao == 2) {
      e = deletar(tarefas, &pos);
      if (e == SEM_TAREFAS)
        printf("Não há tarefas para deletar\n");
      else if (e == NAO_EXISTE)
        printf("Posição não existe\n");
    } else if (opcao == 3) {
      e = listar(tarefas, pos);
      if(e == SEM_TAREFAS)
        printf("Não há tarefas para listar\n");
    } else if (opcao == 0) {
      printf("Sair\n");
      e = salvar(tarefas, TOTAL, pos);
      if (e == ABRIR)
        printf("Erro ao abrir o arquivo\n");
      else if (e == ESCREVER)
        printf("Erro ao escrever no arquivo\n");
      else if (e == FECHAR)
        printf("Erro ao fechar o arquivo\n");
    }
    else {
      printf("Opção inválida");
    }
  } while (opcao != 0);
}