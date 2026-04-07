<div align="center">
  <img src="https://raw.githubusercontent.com/isamartins-engcomput/BIG.vp-AKINATOR-ArvoresED2/main/akinator/programa/include/logoMORPHEUSblackBackground.gif" alt="Morpheus Logo Animated" width="400">
  
  <br>
  
  <img src="https://img.shields.io/badge/Linguagem-C-00FFFF?style=for-the-badge&logo=c&logoColor=white&labelColor=1A1A1A" alt="C"/>
  <img src="https://img.shields.io/badge/Estrutura-Árvores%20Binárias-FF0000?style=for-the-badge&labelColor=1A1A1A" alt="Árvores Binárias"/>
  <img src="https://img.shields.io/badge/Ponteiros-Sim%20%2F%20Não-00FFFF?style=for-the-badge&labelColor=1A1A1A" alt="Sim/Não Pointers"/>
  <img src="https://img.shields.io/badge/Instituição-IFMS-FF0000?style=for-the-badge&labelColor=1A1A1A" alt="IFMS"/>
</div>

<br>

## <img src="https://img.shields.io/badge/-Sobre%20o%20Projeto-1A1A1A?style=flat-square&labelColor=1A1A1A&color=00FFFF" height="20"> Sobre o Projeto

**Morpheus** é um jogo interativo de adivinhação desenvolvido inteiramente na linguagem **C**. Inspirado no clássico Akinator, o programa atua como um oráculo focado no universo de filmes e séries. Ao iniciar o jogo, o Morpheus guiará o usuário através de perguntas de "Sim" ou "Não" para tentar deduzir o título que o jogador está pensando.

A inteligência por trás do oráculo é baseada em uma **Árvore Binária de Decisão**. O projeto foi estruturado com uma semântica clara e eficiente, onde cada nó interno representa uma pergunta diagnóstica e as folhas (`sim` e `nao`) representam os títulos finais das obras.

Este projeto foi desenvolvido como requisito acadêmico para a disciplina de **Estruturas de Dados II**.

## <img src="https://img.shields.io/badge/-Funcionalidades-1A1A1A?style=flat-square&labelColor=1A1A1A&color=FF0000" height="20"> Funcionalidades

* **Adivinhação Dinâmica:** Navegação recursiva e iterativa pela árvore de decisão baseada diretamente no sistema de ponteiros afirmativos (`sim`) e negativos (`nao`).
* **Carregamento de Dados:** Povoamento automático e dinâmico das folhas da árvore a partir de arquivos CSV/TXT (`baseDeDados/filmes_e_series`) contendo a rota de características (Ex: S,N,S,N) e o nome da obra.
* **Módulo de Aprendizado:** Capacidade de expansão da árvore em tempo de execução. Quando o Morpheus falha na adivinhação, ele solicita ao usuário o título correto e a pergunta que diferencia a obra, inserindo um novo nó na estrutura dinamicamente.

## <img src="https://img.shields.io/badge/-Tecnologias%20Utilizadas-1A1A1A?style=flat-square&labelColor=1A1A1A&color=00FFFF" height="20"> Tecnologias Utilizadas

* **Linguagem:** C padrão (`<stdio.h>`, `<stdlib.h>`, `<string.h>`).
* **Estruturas de Dados:** Árvores Binárias de Decisão, Structs Otimizados, Ponteiros e Alocação Dinâmica de Memória.
* **Lógica de Parsing:** Uso eficiente de `strtok` e `fgets` para processamento de base de dados.
* **Ambiente de Desenvolvimento:** GCC (GNU Compiler Collection).

### Estrutura Semântica do Nó
```c
typedef struct No {
    char eh_personagem; // 'N' para Pergunta, 'S' para Título
    struct No * sim;    // Ponteiro para resposta afirmativa
    struct No * nao;    // Ponteiro para resposta negativa
    char conteudo[51];  // Texto da pergunta ou nome do filme/série
} No;
