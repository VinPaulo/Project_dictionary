/* 
strcspn conta caracteres de string1 até encontrar um de string2, retornando o índice do primeiro. 
Usado para remover '\n' de entradas. 
*/
#include "dictionary.h"

int main() {
    No* dicionario = inicializa_disc();

    inserir_palavra(dicionario, "mugiwara", "straw hat");
    inserir_palavra(dicionario, "pirata", "pirate");
    inserir_palavra(dicionario, "navio", "ship");
    inserir_palavra(dicionario, "tesouro", "treasure");
    inserir_palavra(dicionario, "fruta", "fruit");

    printf("Dicionario carregado\n");
    imprimir_dicionario(dicionario);

    printf("\n");

    int n = -1;
    char palavra[100];
    char trad[100];


    do{
        printf("DICIONARIO INGLES-PORTUGUES\nEscolha uma opcao:\n1- Incluir Palavra\n2 - Excluir Palavra\n3 - Buscar Palavra\n4 - Imprimir dicionario\n5 - Imprimir texto\n6 - Sair");
        scanf("%d", &n);
        fflush(stdin);

        switch (n)
        {
        case 1:
            printf("Digite a palavra em portugues:\n");
            gets(palavra);
            printf("Digite a palavra em ingles:\n");
            gets(trad);
            inserir_palavra(dicionario, palavra, trad);
            break;
        
        case 2:
             printf("Digite a palavra para excluir:\n");
            gets(palavra);
            remover_palavra(dicionario, palavra);
            break;

        case 3:
            printf("Digite a palavra para buscar:\n");
            gets(palavra);
            buscar_palavra(dicionario, palavra);
            break;
        
        case 4:
            imprimir_dicionario(dicionario);
            break;
        
        case 5:
            printf("Digite a palavra para buscar:\n");
            gets(palavra);
            imprimir_texto(dicionario, palavra);
            break;

        case 6: 
            break;

        default:
            printf("Opcao invalida\n");
            n = -1;
            break;
        }

    } while(n != 6);

    /*No* resultado = buscar_palavra(dicionario, "pirata");
    if (resultado != NULL) {
        printf("A palavra '%s' significa '%s'\n", resultado->palavra, resultado->trad);
    } else {
        printf("Palavra 'pirata' nao encontrada.\n");
    }

    dicionario = remover_palavra(dicionario, "mugiwara");
    printf("\nDicionario apos remover 'mugiwara':\n");
    imprimir_dicionario(dicionario);

    char text[] = "gato cachorro pirata";
    printf("Texto traduzido:\n");
    imprimir_texto(dicionario, text);*/

    return 0;
}
