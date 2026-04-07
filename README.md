# Morpheus: O Oráculo de Séries e Filmes

<div align="center">
  <img src="https://img.shields.io/badge/Linguagem-C-00FFFF?style=for-the-badge&logo=c&logoColor=white&labelColor=1A1A1A" alt="C"/>
  <img src="https://img.shields.io/badge/Estrutura-Árvores%20Binárias-FF0000?style=for-the-badge&labelColor=1A1A1A" alt="Árvores Binárias"/>
  <img src="https://img.shields.io/badge/Status-Desenvolvimento-00FFFF?style=for-the-badge&labelColor=1A1A1A" alt="Em Desenvolvimento"/>
  <img src="https://img.shields.io/badge/Instituição-IFMS-FF0000?style=for-the-badge&labelColor=1A1A1A" alt="IFMS"/>
</div>

<br>

## <img src="https://img.shields.io/badge/-Sobre%20o%20Projeto-1A1A1A?style=flat-square&labelColor=1A1A1A&color=00FFFF" height="20"> Sobre o Projeto

**Morpheus** é um jogo interativo desenvolvido em linguagem **C**, inspirado na mecânica do famoso Akinator. O programa atua como um oráculo focado no universo do entretenimento, sendo capaz de adivinhar a série ou o filme que o usuário está pensando por meio de perguntas de "Sim" ou "Não".

O núcleo da inteligência do Morpheus é baseado em **Árvores Binárias de Decisão**. Cada nó interno da árvore representa uma pergunta, enquanto as folhas (`esq` e `dir`) representam os títulos finais. Quando o Morpheus não consegue adivinhar, ele "aprende", solicitando ao jogador qual era a obra correta e qual pergunta a diferenciaria, inserindo um novo nó dinamicamente na árvore.

Este projeto foi desenvolvido como requisito acadêmico para a disciplina de **Estruturas de Dados II**.

## <img src="https://img.shields.io/badge/-Funcionalidades-1A1A1A?style=flat-square&labelColor=1A1A1A&color=FF0000" height="20"> Funcionalidades

* **Adivinhação Dinâmica:** Navegação pelos `vlr` da árvore de decisão com base nas respostas (S/N) do usuário.
* **Aprendizado Contínuo:** Capacidade de adicionar novos filmes, séries e perguntas em tempo de execução, expandindo a base de dados do jogo dinamicamente através de alocação de memória.
* **Estrutura Otimizada:** Gerenciamento eficiente de ponteiros (`esq`, `dir`) para garantir travessias rápidas até os nós folhas.

## <img src="https://img.shields.io/badge/-Tecnologias%20Utilizadas-1A1A1A?style=flat-square&labelColor=1A1A1A&color=00FFFF" height="20"> Tecnologias Utilizadas

* **Linguagem:** C padrão (`<stdio.h>`, `<stdlib.h>`)
* **Estruturas de Dados:** Árvores Binárias, Structs, Ponteiros e Alocação Dinâmica (`malloc`, `free`).
* **Ambiente de Desenvolvimento:** GCC (GNU Compiler Collection).

## <img src="https://img.shields.io/badge/-Como%20Executar-1A1A1A?style=flat-square&labelColor=1A1A1A&color=FF0000" height="20"> Como Executar

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

## <img src="https://img.shields.io/badge/-Integrantes%20da%20Equipe-1A1A1A?style=flat-square&labelColor=1A1A1A&color=00FFFF" height="20"> Integrantes da Equipe

* Bruno Felix da Silva
* Gustavo Bossonal dos Santos
* Isadora de Souza Martins
* Pedro Sperandio

---
> *"Você toma a pílula azul, a história acaba, você acorda na sua cama e acredita no que quiser. Você toma a pílula vermelha, você fica no País das Maravilhas, e eu te mostro até onde vai a toca do coelho."* - Morpheus
