#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_COR 10
#define TAM_NOME 30
#define MAX_TERRITORIOS 5

struct Territorio
{
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
};

// -- FUNÇÃO PARA LIMPAR O BUFFER DE ENTRADA
void limparBufferdEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

//-  Função Principal ( main )
int main()
{

    struct Territorio territorios[MAX_TERRITORIOS];
    int quantidadeTerritorios = 0;
    int opcao;

    // -- EXIBE O MENU DE OPÇÕES
    do
    {
        printf("\n   -- Cadastro de Territorios --   \n");
        printf("\n");
        printf(" 1 - Cadastrar novos Territorios \n");
        printf(" 2 - Listar todos os Territorios \n");
        printf(" 0 - Sair  \n");
        printf("-----------------------------\n");
        printf("Escolha uma opção: \n");

        // LÊ A OPÇÃO DO USUARIO
        scanf("%d", &opcao);
        limparBufferdEntrada();

        switch (opcao)
        {
        case 1: // Cadastro de Novos Territorios
            printf(" --- Cadastro de novo Territorio --- ");
            if (quantidadeTerritorios < MAX_TERRITORIOS)
            {
                printf("\nDigite o nome do territorio: "); // Cadastra o nome dos territorios
                fgets(territorios[quantidadeTerritorios].nome, TAM_NOME, stdin);

                printf("Digite a cor das tropas: "); // Cadastra a cor das tropas dos territorios
                fgets(territorios[quantidadeTerritorios].cor, TAM_COR, stdin);

                printf("Digite a quantidade das Tropas: "); // Cadastra a quantidade de tropas
                scanf("%d", &territorios[quantidadeTerritorios].tropas);

                territorios[quantidadeTerritorios].nome[strcspn(territorios[quantidadeTerritorios].nome, "\n")];
                territorios[quantidadeTerritorios].cor[strcspn(territorios[quantidadeTerritorios].cor, "\n")];

                limparBufferdEntrada();

                quantidadeTerritorios++;
                printf("\nTerritorio Cadastrado com Sucesspo\n");
            }
            else
            {
                printf("Territorios Ocupados! Nao e possivel cadastrar mais territorios.\n");
            }
            printf("\nPressione Enter para continuar...");
            getchar();
            break;
        case 2: // Listagem de Territorios
            printf("\n --- Territorios Cadastrados ---\n");

            if (quantidadeTerritorios == 0)
            {
                printf("\n -- Nenhum Territorio cadastrado --\n");
            }
            else
            {
                for (int i = 0; i < quantidadeTerritorios; i++)
                {
                    printf("-------------------------------\n");
                    printf("\nNome do Territorio %s", territorios[i].nome);
                    printf("Cor das Tropas: %s", territorios[i].cor);
                    printf("Numero de Tropas: %d\n", territorios[i].tropas);
                }
                printf("\n--------------------------\n");
            }
            printf("\nPressione Enter para continuar...");
            getchar();
            break;
        case 0:
            printf("Saindo do sistema");
            break;
        default:
            printf("\nOpcao invalida !  tente novmanete.");
            printf("\nPressione Enter para continuar");
            getchar();
            break;
        }
    } while (opcao != 0);
    {
        return 0;
    }
}