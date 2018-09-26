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

Obs: o shell expande os comandos antes de começar a executar. Exemplo:

---------------
Outros assuntos
---------------
- Variáveis de ambiente, `export`

.. code-block::

   $ alias zoio='xeyes -fg yellow' && zoio
   zsh: command not found: zoio
   $ alias zoio='xeyes -fg black'; zoio  # abre xeyes com yellow
