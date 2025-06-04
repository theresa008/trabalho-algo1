#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { //apelido
    char nome[80];
    float preco;
    int codigo;
    int quantidade;
    int tamanho;
} produto;

//prototipos da função
produto cadastrarProduto();
void exibirProduto(produto p);
void  removerProduto(produto produtos[], int *total);
void atualizarProduto(produto produtos[], int total);
void listarProdutos(produto produtos[], int total);

int main(){
    produto produtos[100];
    int total=0; //contador
    int opcao;
    char confirmar;

    do
    {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1- cadastrar numero\n");
        printf("2- listar produtos\n");
        printf("3- remover produto\n");
        printf("4- atualizar produto\n");
        printf("5- sair\n");
        printf("escolha uma opcao:\n");
        scanf("%d",&opcao);
        getchar();

        switch (opcao) {
        case 1: 
            produtos[total] = cadastrarProduto();
            printf("%s", produtos[total].nome);
            // exibirProduto(produtos[total]);

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
              //listarProdutos(produtos, total);
             break;
        case 3: 
            if (total ==0 ) {
                printf("\nNenhum produto cadastrado para remover.\n");
            }else{
                //removerProduto(produtos, &total);
            }
            break;
        case 4:
           if (total == 0){
              printf("\nNenhum produto cadastrado para atualizar.\n");
           }else{

              //atualizarProduto(produtos, total);
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

produto cadastrarProduto() {
    produto p;

    printf("\n--- CADASTRO DO PRODUTO ---\n");

    printf("\ndigite o nome do produto: \n");
    scanf("%s", p.nome);

    printf("\ndigite o preco do produto: \n");
    scanf("%f", &p.preco);

    printf("\ndigite a quantidade em estoque: \n");
    scanf("%d", &p.quantidade);

    printf("\ndigite o tamanho do produto: \n");
    scanf("%d", &p.tamanho);

    printf("\ndigite o codigo do produto: \n");
    scanf("%d", &p.codigo);

    return p;

    
}

void  exibirProduto(produto p) {
        printf("\n--- DADOS DO PRODUTO ---\n");
        printf("codigo:%d\n ", p.codigo);
        printf("nome: %s\n", p.nome);
        printf("preco: %.2f\n", p.preco);
        printf("quantidade: %d\n", p.quantidade);
        printf("tamanho: %d\n", p.tamanho);
    } 

void listarProduto(produto produtos[], int total) {
    if (total == 0){
        printf("\nNenhum produto cadastrado para listar.\n");
    }else{
        printf("\n---LISTAR PRODUTOS: ---\n");
        for (int i = 0; i < total; i++){
           printf("\nProduto: %d\n", i+ 1);
           exibirProduto(produtos[i]);
        }
        
    }
    
}

void atualizarProduto(produto produtos[], int total) {
    int codigo; //variável para declarar o código
    printf("\ndigite o codigo do produto para ser atualizado:\n");
    scanf("%d\n", &codigo);
    getchar();

    int encontrado = 0; //false
    for(int i = 0; i < total; i++) {
        if(produtos[i].codigo == codigo) { //se o produto tiver com o mesmo código ele imprime 
            encontrado = 1; //true
            printf("\nProduto encontrado:\n");
            exibirProduto(produtos[i]); // exibe o produto

            printf("\nDigite os novos dados (deixe em branco para manter o atual):\n"); //novos dados atualizados
            
            printf("Nome (%s): ", produtos[i].nome);
            char novo_nome[80];
            fgets(novo_nome, sizeof(novo_nome), stdin);
            novo_nome[strcspn(novo_nome, "\n")] = '\0';
            if(strlen(novo_nome) > 0) {
                strcpy(produtos[i].nome, novo_nome);
            }

            printf("Preco (%.2f): ", produtos[i].preco);
            char input[20];
            fgets(input, sizeof(input), stdin);
            if(strlen(input) > 1) {
                produtos[i].preco = atof(input);
            }

            printf("Quantidade (%d): ", produtos[i].quantidade);
            fgets(input, sizeof(input), stdin);
            if(strlen(input) > 1) {
                produtos[i].quantidade = atoi(input);
            }

            printf("Tamanho (%d): ", produtos[i].tamanho);
            fgets(input, sizeof(input), stdin);
            if(strlen(input) > 1) {
                produtos[i].tamanho = atoi(input);
            }

            printf("\nProduto atualizado com sucesso!\n");
            exibirProduto(produtos[i]);
            break;
        }
    }

    if(!encontrado) {
        printf("Produto nao encontrado!\n");
    }
    
}