#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para imprimir o menu
void menu()
{
    printf("\n********* MENU *********\n[1] Entrada de veículo\n[2] Saída de veículo\n[3] Listagem de veículos\n[4] Sair\n");
    printf("-------------------------\n");
    printf("Selecione uma das opções acima: ");
}

// Criação do struct No
struct No
{
    char placa[9];
    int manobras;
    struct No *proximo;
};

int main()
{
    // Declaração das variáveis
    int op, vagas = 10;
    char placa[9];
    struct No *head = NULL;
    struct No *atual;
    struct No *anterior;
    struct No *novoNo;

    do
    {
        menu();
        // Verificação de entrada do usuário para aceitar somente números;
        if (scanf("%d", &op) != 1)
        {
            printf("Entrada inválida. Por favor, digite um número válido.\n");

            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            continue;
        }

        switch (op)
        {
        case 1:
        // Case 1 para adicionar veículos ao estacionamento
            if (vagas > 0)
            {
                printf("\nInforme a placa: ");
                scanf(" %8s", placa);

                novoNo = (struct No *)malloc(sizeof(struct No));
                strcpy(novoNo->placa, placa);
                novoNo->proximo = NULL;
                novoNo->manobras = 0;

                if (head == NULL)
                {
                    head = novoNo;
                    atual = head;
                }
                else
                {
                    atual = head;
                    while (atual->proximo != NULL)
                    {
                        atual = atual->proximo;
                    }
                    atual->proximo = novoNo;
                }

                vagas--;
                printf("Veículo estacionado.\n");
            }
            else
            {
                printf("Não há vagas.\n");
            }
            break;

        case 2:
        // Case 2 para remover veículos do estacionamento
            printf("Informe a placa: ");
            scanf(" %8s", placa);
            anterior = NULL;

            if (head == NULL)
            {
                printf("Lista de veículos está vazia.\n");
                break;
            }

            atual = head;
            while (atual != NULL && strcmp(atual->placa, placa) != 0)
            {
                atual->manobras++;
                anterior = atual;
                atual = atual->proximo;
            }
            if (atual == NULL)
            {
                printf("Veículo não cadastrado.\n");
                break;
            }
            else
            {

                if (anterior != NULL)
                {
                    anterior->proximo = atual->proximo;
                }
                else
                {
                    head = atual->proximo;
                }
                free(atual);
                vagas++;
                printf("Veículo saiu do estacionamento\n");
            }
            break;

        case 3:
        // Case 3 para imprimir os veículos estacionados
            atual = head;
            if (atual == NULL)
            {
                printf("Estacionamento está vazio.\n");
                break;
            }

            while (atual != NULL)
            {
                printf("Placa do veículo: %s  Número de manobras: %d\n", atual->placa, atual->manobras);

                atual = atual->proximo;
            }
            break;
        case 4:
        // Case 4 para finalizar o programa
            printf("Finalizando o programa...\n");
            break;
        default:
        // Default caso o número digitado seja inválido
            printf("Número inválido...\n");
            break;
        }
    } while (op != 4);
    // Liberação da memória 
    atual->manobras = 0;
    atual = head;
    while (atual != NULL)
    {
        struct No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    return 0;
}
