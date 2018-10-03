====
Heap
====

É uma estrutura hierárquica (árvore) com as propriedades:

1. Completa até o penúltimo nível;
2. As folhas do último nível começam mais à esquerda;
3. Cada elemento é maior ou menor que os filhos.

Fila de prioridade
==================

Uma fila de prioridade é uma estrutrua que permite as seguintes operações:

1. Inserção
2. Remove o elemento de prioridade máxima
3. Altera a prioridade de um elemento.

Exemplo: imagine um sistema operacional  com várias tarefas sendo executadas "ao mesmo tempo". Cada tarefa tem uma certa prioridade e queremos saber qual a tarefa de maior/menor prioridade.

Implementações:

=================== ============ =============== =======
Tipo de vetor       Inserção     Remove o max    alterar
=================== ============ =============== =======
Desordenado         O(1)         O(n)            O(n)
Ordenado <=         O(logn)      O(1)            O(n)
Ordenado >=         O(logn)      O(n)            O(n)
=================== ============ =============== =======

Se implementarmos a fila de prioridade usando um max-heap,

1. Remove o elemento de maior prioridade
    devolve 42, troca com o último, rebaixa (:math:`O(log_2{n})`)

::

            ___42___
           /        \
       ___35        _17
      /     \      /   \
     10      9    15    7
    /  \
   2    8

2. Inserir: :math:`O(log_2{n})`

.. code-block:: C

   void ascende(float v[], int n, int i) {
       int pai, filho;
       filho = i; pai = (i-1)/2;

       while (filho > 0) {
           if (v[pai] > v[filho])
               break;
           troca(v, pai, filho);
           filho = pai;
           pai = (pai - 1)/2;
       }
   }

Complexidade: :math:`O(\log_2{n})` pois cada nível é visitado uma vez e o heap tem :math:`\lfloor \log_2{n}\rfloor + 1` níveis.

Outras aplicações
=================
Outra aplicação de fila de prioridade ocorre no problema de encontrar um caminho de custo mínimo em um grafo com custos positivos (Dijkstra).

Ordenação
=========
Será que é possível ordenar um vetor comparando seus elementos em tempo menor que :math:`n\log{n}`?

Qualquer algoritmo de ordenação que use comparações vai consumir tempo pelo menos :math:`n\log{n}`. Dizemos que o tempo é limitado inferiormente por :math:`\Omega({n\log{n}})`.

Poderíamos imaginar a execução do algoritmo como um percurso em uma árvore de decisão.

Exemplo: imagine um vetor com 3 elementos:

::

                               _________v[0]<v[1]_______
                              /                         \
                 _______v[0]<v[2]__                 v[1]<v[2]
                /                  \                    .
          _v[1]<v[2]_           v[2]v[0]v[1]            .
         /           \                                  .
    v[0]v[1]v[2]  v[0]v[2]v[1]


Note que a execução de qualquer algoritmo de ordenação baseado em comparações dá origem a uma árvore niária dessas con n! folhas (as possíveis n! permutações dos n elementos).

O consumo de tempo de qualquer algoritmo é limitado inferiormente pela altura desta árvore.

Uma árvore com k folhas tem k-1 nós internos. Portanto, a árvore de decisão tem :math:`n!-1` nós internos.

Obs 2: uma árvore com t nós tem altura pelo menos :math:`\log_2{t}`.
