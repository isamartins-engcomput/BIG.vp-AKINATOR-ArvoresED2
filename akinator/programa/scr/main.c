    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    //arquivo contendo os includes necessários + main e coisas triviais (chamadas de funções); fase de teste básica. sem distinção de arquivos por enquanto
    typedef struct No
    {
        char eh_personagem;
        struct No * sim;
        struct No * nao;
        char conteudo[51];
    } No;

    int testa_no(struct No * no)
    {
        if(no == NULL) return 0;
        if(no != NULL) return 1;
    }

    void incializa_arvore(struct No ** raiz, char pergunta_0[51])
    {
        *raiz = malloc(sizeof(No) * 1);
        if(testa_no(*raiz))
        {
            (*raiz)->eh_personagem = 'N';
            (*raiz)->sim = NULL;
            (*raiz)->nao = NULL;
            strcpy((*raiz)->conteudo, pergunta_0);
            return;
        }
        else
        {
            printf("Erro para inicializar a arvore");
            return;
        }
    }


    void preenche_arvore(struct No ** raiz,  char pergunta[][51], int pergunta_atual)
    {  
        if(pergunta_atual <= 4)
        { 
            *raiz = malloc(sizeof(No));
            (*raiz)->eh_personagem = 'n';
            strcpy((*raiz)->conteudo, pergunta[pergunta_atual]);
            
            if(testa_no(*raiz))
            {
                (*raiz)->eh_personagem = 'N';
                (*raiz)->sim = NULL;
                (*raiz)->nao = NULL;
                strcpy((*raiz)->conteudo, pergunta[pergunta_atual]);
                preenche_arvore(&(*raiz)->sim, pergunta, pergunta_atual+1);
                preenche_arvore(&(*raiz)->nao, pergunta, pergunta_atual+1);
            }
            else
            {
                printf("Deu gangrena :D\n");
            }
        }
        else
        {
            *raiz = malloc(sizeof(No));
            (*raiz)->eh_personagem = 'S';
            strcpy((*raiz)->conteudo, "vazio");
            (*raiz)->sim = NULL;
            (*raiz)->nao = NULL;
        }
    }

    void processa_linha(struct No ** raiz, char * linha)
    {
        char *token = strtok(linha, ",");
        struct No * atual = *raiz;
        char nome[51];

        while(token != NULL)
        {
            if(strlen(token) == 1 && (token[0] == 'S' || token[0] == 'N'))
            {
                if(token[0] == 'S')
                {
                    atual = atual->sim;
                }
                else
                {
                    atual = atual->nao;
                }
            } // só para ter certeza absoluta
            else
            {
                strcpy(nome, token);
            }
            token = strtok(NULL, ",");
        }
        if(atual != NULL && atual->eh_personagem == 'S') strcpy(atual->conteudo, nome);
    }

    void preenche_folhas(struct No ** raiz)
    {
        FILE * filmes_e_series;
        FILE * temp;
        filmes_e_series = fopen("../../baseDeDados/filmes_e_series", "r");
        int quantidade = 0;
        {
            char linha[100];
            if(filmes_e_series == NULL)
            {
                printf("Erro para abrir\n");
            }
            else
            {
                while(fgets(linha,sizeof(linha),filmes_e_series) != NULL)
                {
                    linha[strcspn(linha, "\n")] = 0; 
                    quantidade++;
                    processa_linha(raiz, linha);
                }
                printf("%d personagens carregados\n", quantidade);
                fclose(filmes_e_series); 
            }
        }
    }

    void Akinator(struct No ** raiz, char perguntas[][51], int pergunta)
    {
            if((*raiz)->eh_personagem == 'N')
            {
                char resposta = '\0';
                printf("Pergunta %d: %s\n", pergunta+1, perguntas[pergunta]);
                scanf(" %c", &resposta);
                if(resposta == 's' || resposta == 'S') Akinator(&(*raiz)->sim,perguntas,pergunta+1);
                else Akinator(&(*raiz)->nao,perguntas,pergunta+1);
            }
            else
            {
                printf("Seu personagem seria: %s\n", (*raiz)->conteudo);
            }
            
    }
        
    void escreve_arvore(struct No ** raiz)
    {
        if((*raiz) != NULL)
        {
            escreve_arvore(&(*raiz)->sim);
            if((*raiz)->eh_personagem == 'N') printf("Pergunta: %s\n", (*raiz)->conteudo);
            else printf("Personagem: %s\n", (*raiz)->conteudo);
            escreve_arvore(&(*raiz)->nao);
        }
    }

    int main()
    {
        char perguntas[5][51] = {"É um filme?", "Tem ação?", "É nacional?", "O tom é leve?", "Tem romance?"};
        struct No *raiz = NULL;
        preenche_arvore(&raiz, perguntas, 0);
        preenche_folhas(&raiz);
        printf("Kinema time\n");
        Akinator(&raiz,perguntas,0);

        free(raiz);
    }