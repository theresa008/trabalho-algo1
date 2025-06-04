#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[80];
    float preco;
    int codigo;
    int quantidade;
    int tamanho;
} produto;

produto cadastrarProduto();
void  exibirProduto(produto p);
void  removerProduto(produto produtos[], int *total);
void atualizarProduto(produto produtos[], int total);
void listarProdutos(produto produtos[], int total);

int main(){
    produto produtos[100];
    int total=0;
    int opcao;
    char confirmar;

    do
    {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("\n1- cadastrar numero\n");
        printf("\n2- listar produtos\n");
        printf("\n3- remover produto\n");
        printf("\n4- atualizar produto\n");
        printf("\n5- sair\n");
        printf("\nescolha uma opcao:\n");
        scanf("%d",&opcao);
        getchar();

        switch (opcao) {
        case 1: 
            produtos[total] = cadastrarProduto();
            exibirProduto(produtos[total]);

            printf("\nConfirmar cadastro? (S/N)");
            scanf("%c", &confirmar);
            getchar();

            if (confirmar == 'S' || confirmar == 's'){
                total++; //contador
                printf("produto cadastrado com sucesso.");
            }else{
                printf("produto nao cadastrado.");
            }
            break;
       case 2:
             listarProdutos(produtos, total);
             break;
        case 3: 
            if (total ==0 ) {
                printf("\nNenhum produto cadastrado para remover.\n");
            }else{
                removerProduto(produtos, &total);
            }
            break;
        case 4:
           if (total == 0){
              printf("\nNenhum produto cadastrado para atualizar.\n");
           }else{
               atualizarProduto(produtos, total);
           }
           break;
      case 5:
           printf("\nSaindo do programa.\n");
           break;

        default:
             printf("\nOpcao invalida. Tente novamente.\n");
            break;
        }
    } while (opcao != 5);
    
}
