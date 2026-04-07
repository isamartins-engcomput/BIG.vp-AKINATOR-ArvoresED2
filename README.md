# 💊 Morpheus: O Oráculo de Séries e Filmes

<div align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
  <img src="https://img.shields.io/badge/Estruturas_de_Dados-Árvores_Binárias-239120?style=for-the-badge" alt="Árvores Binárias"/>
  <img src="https://img.shields.io/badge/IFMS-Três_Lagoas-008000?style=for-the-badge" alt="IFMS"/>
</div>

## 📖 Sobre o Projeto
**Morpheus** é um jogo interativo desenvolvido em linguagem **C**, inspirado na mecânica do famoso Akinator. O programa atua como um oráculo focado no universo do entretenimento, sendo capaz de adivinhar a série ou o filme que o usuário está pensando por meio de perguntas de "Sim" ou "Não". 

O núcleo da inteligência do Morpheus é baseado em **Árvores Binárias de Decisão**. Cada nó interno da árvore representa uma pergunta, enquanto as folhas (`esq` e `dir`) representam os títulos finais. Quando o Morpheus não consegue adivinhar, ele "aprende", solicitando ao jogador qual era a obra correta e qual pergunta a diferenciaria, inserindo um novo nó dinamicamente na árvore.

Este projeto foi desenvolvido como requisito acadêmico para a disciplina de **Estruturas de Dados II**.

## 🚀 Funcionalidades
* **Adivinhação Dinâmica:** Navegação pelos `vlr` da árvore de decisão com base nas respostas (S/N) do usuário.
* **Aprendizado Contínuo:** Capacidade de adicionar novos filmes, séries e perguntas em tempo de execução, expandindo a base de dados do jogo dinamicamente através de alocação de memória.
* **Estrutura Otimizada:** Gerenciamento eficiente de ponteiros (`esq`, `dir`) para garantir travessias rápidas até os nós folhas.

## 🛠️ Tecnologias Utilizadas
* **Linguagem:** C padrão (`<stdio.h>`, `<stdlib.h>`)
* **Estruturas de Dados:** Árvores Binárias, Structs, Ponteiros e Alocação Dinâmica (`malloc`, `free`).
* **Ambiente de Desenvolvimento:** GCC (GNU Compiler Collection).

## ⚙️ Como Executar
Pré-requisitos: Ter um compilador C instalado (como o GCC em ambientes Linux/Debian).

1. Clone este repositório:
   ```bash
   git clone [https://github.com/isamartins-engcomput/BIG.vp-AKINATOR-ArvoresED2.git](https://github.com/isamartins-engcomput/BIG.vp-AKINATOR-ArvoresED2.git)
