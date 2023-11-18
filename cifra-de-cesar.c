#include <stdio.h>
#include <string.h>

// Função para decodificar a mensagem usando a cifra de César
void decript(char *texto, int deslocamento)
{
    int i;
    for (i = 0; i < strlen(texto); i++)
    {
        if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            texto[i] = (texto[i] - 'A' - deslocamento + 26) % 26 + 'A';
        }
        else if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            texto[i] = (texto[i] - 'a' - deslocamento + 26) % 26 + 'a';
        }
    }
}

void encript(char *texto, int deslocamento)
{
    int i;
    for (i = 0; i < strlen(texto); i++)
    {
        if (texto[i] >= 'A' && texto[i] <= 'Z')
        {
            // Para letras maiúsculas, aplicamos o deslocamento no alfabeto
            texto[i] = (texto[i] - 'A' + deslocamento) % 26 + 'A';
        }
        else if (texto[i] >= 'a' && texto[i] <= 'z')
        {
            // Para letras minúsculas, aplicamos o deslocamento no alfabeto
            texto[i] = (texto[i] - 'a' + deslocamento) % 26 + 'a';
        }
        // Caso seja um espaço, não faz nada
    }
}

int main()
{
    char mensagem[100];
    int deslocamento;

    int opt;
    printf("1 - Encriptar\n2 - Desencriptar\n");
    printf("Opcao: ");
    scanf("%i", &opt);

    switch (opt)
    {
    case 1:
        printf("Texto a encriptar: ");
        scanf(" %99[^\n]", mensagem); // Lê uma linha inteira com espaços
        printf("Deslocamento: ");
        scanf("%i", &deslocamento);
        encript(mensagem, deslocamento);
        printf("Texto Encriptado: \n%s\n", mensagem);
        break;
    case 2:
        printf("Digite a mensagem cifrada: ");
        scanf(" %99[^\n]", mensagem); // Lê uma linha inteira com espaços
        printf("Tentando todas as combinacoes possiveis:\n");

        for (deslocamento = 1; deslocamento <= 25; deslocamento++)
        {
            // Faz uma cópia da mensagem original para preservar os dados
            char mensagemDecodificada[100];
            strcpy(mensagemDecodificada, mensagem);
            decript(mensagemDecodificada, deslocamento);
            printf("Deslocamento %d: %s\n", deslocamento, mensagemDecodificada);
        }
        break;
    default:
        break;
    }

    return 0;
}
