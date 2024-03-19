#include <stdio.h>

// Definindo o limite de crédito para novos clientes
#define LIMITE_CREDITO_NOVO_CLIENTE 500

// Definindo o desconto para clientes fiéis
#define DESCONTO_CLIENTE_FIEL 0.1 // 10%

int main() {
    // Variáveis para armazenar os dados do cliente
    int opcao;
    float valorTotalCompra;
    int compras_ultimos_6_meses;

    // Loop para repetir a pergunta até que o cliente insira uma opção válida
    do {
        // Solicita ao usuário que informe a opção desejada
        printf("Selecione uma opcao:\n");
        printf("1 - Novo cliente\n");
        printf("2 - Cliente fiel\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Novo cliente
                printf("Voce recebeu um limite de ate R$%.2f.\n", LIMITE_CREDITO_NOVO_CLIENTE);
                printf("Informe o valor total da compra: ");
                scanf("%f", &valorTotalCompra);

                // Verifica se o valor da compra excede o limite de crédito
                if (valorTotalCompra > LIMITE_CREDITO_NOVO_CLIENTE) {
                    printf("Compra nao realizada. Valor excede o limite de credito.\n");
                    return 1;
                }
                break;

            case 2:
                // Cliente fiel
                printf("Informe o valor total da compra: ");
                scanf("%f", &valorTotalCompra);

                // Verifica se o cliente fez mais de 5 compras nos últimos 6 meses para aplicar o desconto
                printf("Informe o numero de compras nos ultimos 6 meses: ");
                scanf("%d", &compras_ultimos_6_meses);
                if (compras_ultimos_6_meses > 5) {
                    valorTotalCompra -= valorTotalCompra * DESCONTO_CLIENTE_FIEL;
                }
                break;

            default:
                printf("Opcao invalida! Por favor, escolha uma opcao valida.\n");
        }
    } while (opcao != 1 && opcao != 2);

    printf("Valor final da compra: R$%.2f\n", valorTotalCompra);

    return 0;
}