    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define TAM_NOME 50
    #define TAM_EMAIL 50
    #define TAM_PESSOA (TAM_NOME + sizeof(int) + TAM_EMAIL)
    #define TAM_CONTROLE (5 * sizeof(int) + TAM_NOME)
    #define CAPACIDADE_INICIAL 5
    #define FATOR_AUMENTO 2

    //acessando
    int*get_total(void*pBuffer){return(int*)pBuffer;}//total de pessoas 
    int*get_capacidade(void*pBuffer){return(int*)((char*)pBuffer+sizeof(int));}//capacidade maxima atual
    int*get_indice_temp(void*pBuffer){return(int*)((char*)pBuffer+2*sizeof(int));}//variavel temporaria de loop
    int*get_flag_temp(void*pBuffer){return(int*)((char*)pBuffer+3*sizeof(int));}//variavel temporaria para fazer busqueda
    int*get_opcao_menu(void*pBuffer){return(int*)((char*)pBuffer+4*sizeof(int));}//variavel temporaria da opção escolhida  
    char*get_termo_busca(void*pBuffer){return(char*)pBuffer+5*sizeof(int);}//usa o ponteiro paro a string , para armazenar o nome a ser buscado
    char*get_base_dados(void*pBuffer){return(char*)pBuffer+TAM_CONTROLE;}//ponteiro para o inicio da area de dados, apps a toda a area de controle

    char*get_bloco_por_indice(void*pBuffer,int indice){//calcula o endereço de memoria onde os dados de uma pessoa especifica começam 
        return get_base_dados(pBuffer)+(indice*TAM_PESSOA);//simula o acesso de um elemento array utilizando ponteiros, usando base da agenda + indice x Tam_pessoa.
    }

    void inicializar_pbuffer(void*pBuffer){
        *get_total(pBuffer)=0;
        *get_capacidade(pBuffer)=CAPACIDADE_INICIAL;
        *get_indice_temp(pBuffer)=0;
        *get_flag_temp(pBuffer)=0;
        *get_opcao_menu(pBuffer)=0;  
        *get_termo_busca(pBuffer)='\0';
    }

    void*redimensionar_pbuffer(void*pBuffer){
        int*pCapacidade=get_capacidade(pBuffer);
        size_t novoTamanho=TAM_CONTROLE+(*pCapacidade*FATOR_AUMENTO*TAM_PESSOA);
        
        void*novoBuffer=realloc(pBuffer,novoTamanho);
        if(!novoBuffer){
            printf("ERRO: Falha ao redimensionar memoria!\n");
            exit(1);
        }
        
        *get_capacidade(novoBuffer)*=FATOR_AUMENTO;
        printf("Memoria redimensionada.Nova capacidade:%d\n",*get_capacidade(novoBuffer));
        return novoBuffer;
    }

    void*adicionar_pessoa(void*pBuffer){
        int*pTotal=get_total(pBuffer);
        int*pCapacidade=get_capacidade(pBuffer);
        
        if(*pTotal>=*pCapacidade){
            pBuffer=redimensionar_pbuffer(pBuffer);
            pTotal=get_total(pBuffer);
            pCapacidade=get_capacidade(pBuffer);
        }

        char*bloco=get_bloco_por_indice(pBuffer,*pTotal);
        char*nome=bloco;
        int*idade=(int*)(bloco+TAM_NOME);
        char*email=bloco+TAM_NOME+sizeof(int);

        printf("Nome:");
        scanf("%49s",nome);
        printf("Idade:");
        scanf("%d",idade);
        printf("Email:");
        scanf("%49s",email);

        (*pTotal)++;
        printf("Pessoa adicionada! Total:%d\n",*pTotal);
        return pBuffer;
    }

    void*remover_pessoa(void*pBuffer){
        int*pTotal=get_total(pBuffer);
        int*pIndiceTemp=get_indice_temp(pBuffer);
        
        if(*pTotal==0){
            printf("Agenda vazia!\n");
            return pBuffer;
        }

        printf("Digite o ID (0 a %d) para remover:",*pTotal-1);
        scanf("%d",pIndiceTemp);

        if(*pIndiceTemp<0||*pIndiceTemp>=*pTotal){
            printf("ID invalido!\n");
            return pBuffer;
        }

        char*blocoRemover=get_bloco_por_indice(pBuffer,*pIndiceTemp);
        char*proximoBloco=blocoRemover+TAM_PESSOA;
        size_t bytesParaMover=(*pTotal-*pIndiceTemp-1)*TAM_PESSOA;
        
        if(bytesParaMover>0){
            memmove(blocoRemover,proximoBloco,bytesParaMover);
        }
        
        (*pTotal)--;
        printf("Pessoa removida! Novo total:%d\n",*pTotal);
        return pBuffer;
    }

    void buscar_pessoa(void*pBuffer){
        int*pTotal=get_total(pBuffer);
        int*pIndiceTemp=get_indice_temp(pBuffer);
        int*pFlag=get_flag_temp(pBuffer);
        char*termoBusca=get_termo_busca(pBuffer);
        
        if(*pTotal==0){
            printf("Agenda vazia!\n");
            return;
        }

        printf("Digite o nome para buscar:");
        scanf("%49s",termoBusca);
        
        printf("\n--- Resultados da Busca ---\n");
        *pFlag=0;
        
        *pIndiceTemp=0;
        while(*pIndiceTemp<*pTotal){
            char*bloco=get_bloco_por_indice(pBuffer,*pIndiceTemp);
            char*nome=bloco;
            int*idade=(int*)(bloco+TAM_NOME);
            char*email=bloco+TAM_NOME+sizeof(int);
            
            if(strcmp(nome,termoBusca)==0){
                printf("ID:%d|Nome:%s|Idade:%d|Email:%s\n",
                    *pIndiceTemp,nome,*idade,email);
                *pFlag=1;
            }
            (*pIndiceTemp)++;
        }
        
        if(*pFlag==0){
            printf("Nenhuma pessoa encontrada com nome '%s'.\n",termoBusca);
        }
    }

    void listar_todos(void*pBuffer){
        int*pTotal=get_total(pBuffer);
        int*pIndiceTemp=get_indice_temp(pBuffer);
        
        if(*pTotal==0){
            printf("Agenda vazia!\n");
            return;
        }

        printf("\n--- Lista de Pessoas ---\n");
        *pIndiceTemp=0;
        while(*pIndiceTemp<*pTotal){
            char*bloco=get_bloco_por_indice(pBuffer,*pIndiceTemp);
            char*nome=bloco;
            int*idade=(int*)(bloco+TAM_NOME);
            char*email=bloco+TAM_NOME+sizeof(int);
            
            printf("ID:%d|Nome:%s|Idade:%d|Email:%s\n",
                *pIndiceTemp,nome,*idade,email);
            (*pIndiceTemp)++;
        }
    }

    int main(){
        void*pBuffer=malloc(TAM_CONTROLE+CAPACIDADE_INICIAL*TAM_PESSOA);
        if(!pBuffer){
            printf("ERRO: Falha ao alocar memoria inicial!\n");
            return 1;
        }

        inicializar_pbuffer(pBuffer);
        int*opcao=get_opcao_menu(pBuffer);

        while(1){
            printf("\n--- Menu Agenda ---\n");
            printf("1-Adicionar Pessoa\n");
            printf("2-Remover Pessoa\n");
            printf("3-Buscar Pessoa\n");
            printf("4-Listar Todos\n");
            printf("5-Sair\n");
            printf("Escolha uma opcao:");
            
            scanf("%d",opcao);

            switch(*opcao){
                case 1:
                    pBuffer=adicionar_pessoa(pBuffer);
                    break;
                case 2:
                    pBuffer=remover_pessoa(pBuffer);
                    break;
                case 3:
                    buscar_pessoa(pBuffer);
                    break;
                case 4:
                    listar_todos(pBuffer);
                    break;
                case 5:
                    printf("Saindo...\n");
                    free(pBuffer);
                    return 0;
                default:
                    printf("Opcao invalida!\n");
            }
        }
    }
