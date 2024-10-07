# Filas e Pilhas - Implementação manual das Estruturas de Dados
Um projeto simples criado para demonstrar na prática o uso de Estrutura de Dados.s

1. [[#Introdução]]
2. [[#Estrutura de Dados]]
3. [[#Pilhas (Stacks)]]
4. [[#Filas (Queues)]]
5. [[#Definições do projeto]]
6. [[#Qual é o propósito?]]
7. [[#Quais foram as regras definidas?]]
8. [[#Qual linguagem está sendo utilizada?]]
9. [[#Quem somos?]]
10. [[#Considerações finais.]]

## Introdução
A Estrutura de Dados é uma disciplina fundamental na área da computação, tem como objetivo tornar a manipulação e o tratamento de grandes conjuntos de dados o mais eficiente possível, evitando assim desperdício de processamento e memória com soluções computacionalmente ruins.

## Estrutura de Dados
### Pilhas (Stacks)
O conceito de uma Pilha *(Stack)* é simples de entender, seu funcionamento segue a lógica *LiFo (Last in First Out)*, "Primeiro a entrar, último a sair". Imagine uma abstração como uma pilha de pratos, na maioria dos casos quando queremos remover um prato da nossa pilha iremos começar pelo o último prato adicionado à nossa pilha, sendo este o **topo** e assim continuamos o nosso processo de remoção até chegar o final da pilha.

Se utilizarmos essa representação como exemplo temos o seguinte funcionamento: se é necessário acessar o prato (A) é preciso remover todos os pratos anteriores.
```
   -----
2 |  C  |
   -----
1 |  B  |
   -----
0 |  A  |
   -----
```
Então temos a sequência de acesso: `C -> B -> A`.

Com isso em mente todas as operações que podemos utilizar como **adicionar** ou **remover** algum elemento irão seguir a risca esse procedimento...

### Filas (Queues)
A fila segue um principio diferente da estrutura anterior, aqui o primeiro elemento a entrar será o primeiro a sair *FiFo (First in First Out)*. É possível imaginar uma fila de pessoas ou uma fila de impressão, todas as operações irão seguir uma ordem definida. Quando a primeira "pessoa" for atendida ela será dispensada e anterior será a próxima.

Nesse exemplo se desejo visitar o último elemento (C), terei que percorrer toda a fila até chegar no elemento desejado.
```
   -----     -----     -----
 0|  A  |  1|  B  |  2|  C  |
   -----     -----     -----
```
Nossa sequência atual é exatamente `A -> B -> C`.


## Definições do projeto:
### Qual é o propósito?
___
Demonstrar, aplicar, analisar e compreender os benefícios existentes ao utilizar algum tipo de estrutura de dados.
### Quais foram as regras definidas?
___
A utilização das bibliotecas `<queue>` e `<stack>` oferecidas no `C++` foi proibida, tendo em vista que a utilização das mesmas iria abstrair a complexidade dessas estruturas.
### Qual linguagem está sendo utilizada?
___
A linguagem em questão é o `C++` por conta da capacidade de manipularmos espaços de memória com o uso de ponteiros.
### Quem somos?
___
Victor Gustavo e Leonardo Oliveira, somos estudantes de Sistemas para Internet e juntos aliamos nossos conhecimentos para que fosse possível a realização desse projeto.
### Considerações finais.
___
***tldr: Existem formas mais simples, elegantes e eficientes de implementar esses algoritmos.***

Como dito acima, o projeto foi feito com o intuito de por em prática todo o conhecimento adquirido durante as aulas de Estrutura de Dados (Ponteiros, Filas e Pilhas). As limitações definidas nesse código são propositais para que o foco seja exclusivamente o entendimento dos fundamentos dos tópicos abordados.
