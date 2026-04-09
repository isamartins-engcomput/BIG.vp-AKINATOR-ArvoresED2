<div align="center">
  <img src="https://raw.githubusercontent.com/isamartins-engcomput/BIG.vp-AKINATOR-ArvoresED2/main/akinator/programa/include/logoMORPHEUSblackBackground.gif" alt="Morpheus Logo Animated" width="400">
  
  <br>
  
  <img src="https://img.shields.io/badge/Linguagem-C-00FFFF?style=for-the-badge&logo=c&logoColor=white&labelColor=435cd5" alt="C"/>
  <img src="https://img.shields.io/badge/Estrutura-Árvores%20Binárias-FF0000?style=for-the-badge&labelColor=1A1A1A" alt="Árvores Binárias"/>
  <img src="https://img.shields.io/badge/Ponteiros-Sim%20%2F%20Não-00FFFF?style=for-the-badge&labelColor=435cd5" alt="Sim/Não Pointers"/>
  <img src="https://img.shields.io/badge/Instituição-IFMS-FF0000?style=for-the-badge&labelColor=1A1A1A" alt="IFMS"/>
</div>

<br>

## <img src="https://img.shields.io/badge/-Sobre%20o%20Projeto-1A1A1A?style=flat-square&labelColor=1A1A1A&color=2572E8" height="20"> Sobre o Projeto

**Morpheus** é um jogo interativo de adivinhação desenvolvido inteiramente na linguagem **C**. Inspirado no clássico Akinator, o programa atua como um oráculo focado no universo de filmes e séries. Ao iniciar o jogo, o Morpheus guiará o usuário através de perguntas de "Sim" ou "Não" para tentar deduzir o título que o jogador está pensando.

A inteligência por trás do oráculo é baseada em uma **Árvore Binária de Decisão**. O projeto foi estruturado com uma semântica clara e eficiente, onde cada nó interno representa uma pergunta diagnóstica e as folhas (`sim` e `nao`) representam os títulos finais das obras.

Este projeto foi desenvolvido como requisito acadêmico para a disciplina de **Estruturas de Dados II**.

## <img src="https://img.shields.io/badge/-Tecnologias%20Utilizadas-1A1A1A?style=flat-square&labelColor=1A1A1A&color=2572E8 height="20"> Tecnologias Utilizadas

* **Linguagem:** C padrão (`<stdio.h>`, `<stdlib.h>`, `<string.h>`).
* **Estruturas de Dados:** Árvores Binárias de Decisão, Structs Otimizados, Ponteiros e Alocação Dinâmica de Memória.
* **Lógica de Parsing:** Uso eficiente de `strtok` e `fgets` para processamento de base de dados.
* **Ambiente de Desenvolvimento:** GCC (GNU Compiler Collection).

## <img src="https://img.shields.io/badge/-Como%20Executar-1A1A1A?style=flat-square&labelColor=1A1A1A&color=2572E8" height="20"> Como Executar

Pré-requisitos: Ter um compilador C instalado (como o GCC em ambientes Linux/Debian).

1.  Clone este repositório:
    ```bash
    git clone [https://github.com/isamartins-engcomput/BIG.vp-AKINATOR-ArvoresED2.git](https://github.com/isamartins-engcomput/BIG.vp-AKINATOR-ArvoresED2.git)
    ```
2.  Acesse a pasta do projeto:
    ```bash
    cd BIG.vp-AKINATOR-ArvoresED2
    ```
3.  Compile o código-fonte:
    ```bash
    gcc -o morpheus main.c
    ```
4.  Execute o programa:
    ```bash
    ./morpheus
    ```

## <img src="https://img.shields.io/badge/-Integrantes%20da%20Equipe-1A1A1A?style=flat-square&labelColor=1A1A1A&color=2572E8" height="20"> Integrantes da Equipe

* Bruno Felix da Silva
* Gustavo Bossolan dos Santos
* Isadora de Souza Martins
* Pedro Lucas Lima Sperandio
* Vinicius Fonseca Santos Freitas

---
> *"Você toma a pílula azul, a história acaba, você acorda na sua cama e acredita no que quiser. Você toma a pílula vermelha, você fica no País das Maravilhas, e eu te mostro até onde vai a toca do coelho."* - Morpheus
