====
Bash
====

-----------------------------
Executando listas de comandos
-----------------------------
- `xeyes & xeyes`: executa os dois comandos ao mesmo tempo
- `xeyes ; xeyes`: executa um, espera acabar, e depois o outro
- Lista `E`: `comando1 && comando2` o `comando2` é executado se e somente se a execução do `comando1` terminou com sucesso.
- Lista `OU`: `comando1 || comando2` o `comando2` é executado se e somente se a execução do `comando1` **não** terminou com sucesso.

---------------
Outros comandos
---------------
- `fg`: coloca em primeiro plano o último processo em segundo plano
- `history`
- `pwd`
- `alias`
- `Ctrl+D`: Fecha a entrada padrão;
- `pushd`: Empilha diretórios, útil pra navegar pelo filesystem e depois voltar onde estava com `popd`.

-----
Loops
-----
.. code-block:: bash

    for i in $(ls); do
      echo item: $i
    done

    for i in `seq 1 10`; do
      echo $i
    done

-----------
Condicional
-----------

If
--
.. code-block:: bash

    if {}

Case
----
.. code-block:: bash

    case $ANIMAL in
       cavalo | cachorro | gato) echo -n "quatro";;
       homem | canguru) echo -n "duas";;
       \*) echo -n "um número desconhecido de";;
    esac
    echo "pernas"

Select
------
.. code-block:: bash

    select PROG in xeyes fortune break; do $PROG; done

-------
Funções
-------
.. code-block:: bash

    function soma {
        bc $1 + $2
    }

---------------
Outros assuntos
---------------
- Variáveis de ambiente, `export`

Obs: o shell expande os comandos antes de começar a executar. Exemplo:
::

   $ alias zoio='xeyes -fg yellow' && zoio
   zsh: command not found: zoio
   $ alias zoio='xeyes -fg black'; zoio  # abre xeyes com yellow

- :code:`. script` vs :code:`./script`: (. = source) executa no shell atual, o :code:`./` abre um novo bash.
