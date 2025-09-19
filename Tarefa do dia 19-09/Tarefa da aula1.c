#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void adicionar_nome(char **todos_nomes, int *tamanho);
void remover_nome(char **todos_nomes, int *tamanho);
void listar_nomes(char *todos_nomes);

int main() {
    char *todos_nomes = NULL; 
    int tamanho = 0;          
    int opcao;

    while (1) {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa \n

        switch (opcao) {
        case 1:
            adicionar_nome(&todos_nomes, &tamanho);
            break;
        case 2:
            remover_nome(&todos_nomes, &tamanho);
            break;
        case 3:
            listar_nomes(todos_nomes);
            break;
        case 4:
            free(todos_nomes);
            return 0;
        default:
            printf("Opção inválida!\n");
        }
    }
}

void menu() {
    printf("\n=== MENU ===\n");
    printf("1. Adicionar nome\n");
    printf("2. Remover nome\n");
    printf("3. Listar\n");
    printf("4. Sair\n");
}

void adicionar_nome(char **todos_nomes, int *tamanho) {
    char novo[50];
    printf("Digite um nome: ");
    fgets(novo, sizeof(novo), stdin);
    novo[strcspn(novo, "\n")] = '\0';

    int extra = strlen(novo) + 2; 
    *todos_nomes = realloc(*todos_nomes, *tamanho + extra);
    if (*todos_nomes == NULL) {
        printf("Erro de memória!\n");
        exit(1);
    }

    if (*tamanho == 0) {
        strcpy(*todos_nomes, novo);
    } else {
        strcat(*todos_nomes, ",");
        strcat(*todos_nomes, novo);
    }

    *tamanho = strlen(*todos_nomes) + 1;
    printf("Nome adicionado!\n");
}

void remover_nome(char **todos_nomes, int *tamanho) {
    if (*todos_nomes == NULL || strlen(*todos_nomes) == 0) {
        printf("Nenhum nome para remover!\n");
        return;
    }

    char alvo[50];
    printf("Digite o nome a remover: ");
    fgets(alvo, sizeof(alvo), stdin);
    alvo[strcspn(alvo, "\n")] = '\0';

    char *pos = strstr(*todos_nomes, alvo);
    if (pos == NULL) {
        printf("Nome não encontrado!\n");
        return;
    }

    int len_alvo = strlen(alvo);

    
    if (pos > *todos_nomes && *(pos - 1) == ',') {
        pos--; 
    } else if (*(pos + len_alvo) == ',') {
        len_alvo++; 
    }

    memmove(pos, pos + len_alvo, strlen(pos + len_alvo) + 1);

    *tamanho = strlen(*todos_nomes) + 1;
    *todos_nomes = realloc(*todos_nomes, *tamanho);

    printf("Nome removido!\n");
}

void listar_nomes(char *todos_nomes) {
    if (todos_nomes == NULL || strlen(todos_nomes) == 0) {
        printf("Nenhum nome cadastrado.\n");
        return;
    }

    printf("Lista de nomes:\n");
    char copia[1000];
    strcpy(copia, todos_nomes);

    char *token = strtok(copia, ",");
    int i = 1;
    while (token != NULL) {
        printf("%d: %s\n", i++, token);
        token = strtok(NULL, ",");
    }
}
