====
Bash
====

------------------
Listas de comandos
------------------

- `xeyes & xeyes`: executa os dois comandos ao mesmo tempo
- `xeyes ; xeyes`: executa um, espera acabar, e depois o outro
- `fg`: coloca em primeiro plano o último processo em segundo plano
- `history`
- `pwd`
- `alias`
- `Ctrl+D`: Fecha a entrada padrão

- Lista `E`: `comando1 && comando2` o `comando2` é executado se e somente se a execução do `comando1` terminou com sucesso.
- Lista `OU`: `comando1 || comando2` o `comando2` é executado se e somente se a execução do `comando1` **não** terminou com sucesso.


Obs: o shell expande os comandos antes de começar a executar. Exemplo:

.. code-block::

   $ alias zoio='xeyes -fg yellow' && zoio
   zsh: command not found: zoio
   $ alias zoio='xeyes -fg black'; zoio  # abre xeyes com yellow
