# Relatório da Atividade 03 - Compilação de Código em Contêiner Docker

- Nome:João Pedro Dantas Magalhães
- Data: 10 de junho de 2025


## 1. Objetivo

O objetivo desta prática foi utilizar um `Dockerfile` para construir um ambiente de desenvolvimento isolado e customizado. A meta era criar uma imagem Docker baseada em Fedora contendo as ferramentas necessárias (como o compilador GCC) para compilar e executar um programa em linguagem C, utilizando mapeamento de volumes para vincular o código-fonte do sistema hospedeiro ao contêiner.

## 2. Passos Executados

1.  **Criação do Ambiente:** Foi criada uma pasta local para o projeto, contendo o arquivo de código-fonte em C (`processo.c`) e o `Dockerfile`.
    
2.  **Dockerfile:** Um `Dockerfile` foi escrito para definir as instruções da imagem, incluindo a instalação do compilador `gcc` e a definição do diretório de trabalho `/app`.
    ![Conteúdo do Dockerfile]
    
3.  **Build da Imagem:** A imagem Docker foi construída a partir do `Dockerfile` com o comando:
    `docker build -t compilador-c-fedora .`
    ![Build da imagem Docker
    
4.  **Execução do Contêiner:** O contêiner foi iniciado em modo interativo, mapeando o diretório local para o diretório `/app` do contêiner:
    `docker run -it --rm -v ${PWD}:/app compilador-c-fedora`
    
5.  **Compilação e Execução:** Dentro do contêiner, o código foi compilado com o GCC e o programa resultante foi executado:
    -   `gcc processo.c -o programa_executavel`
    -   `./programa_executavel`

## 3. Resultados Obtidos

Após a compilação, o programa foi executado com sucesso. A saída demonstrou a criação de um processo filho pelo processo pai e a comunicação entre eles, conforme programado no código-fonte.

![Compilação e execução do código C dentro do contêiner

Não foram encontrados problemas durante a execução, pois o ambiente continha todas as dependências necessárias, conforme definido no `Dockerfile`.

## 4. Conclusão

Esta prática demonstrou de forma clara e poderosa a utilidade dos contêineres para criar ambientes de desenvolvimento e compilação portáteis e reproduzíveis. A capacidade de definir todas as dependências (como o compilador `gcc`) em um `Dockerfile` garante que o código possa ser compilado e executado em qualquer máquina que tenha o Docker instalado, eliminando problemas de "funciona na minha máquina". O mapeamento de volumes se mostrou uma ferramenta essencial, permitindo editar o código no sistema hospedeiro com minhas ferramentas preferidas e compilar no ambiente isolado do contêiner instantaneamente.
