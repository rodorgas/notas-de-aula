## Hashtable
Tabela chave-valor. Suponha que usemos como função de hash o número de caracteres da string:

```C
int hash(char *s) {
    return strlen(s) % 11;
}
```

Tabela:
1.
2.
3.
4. Tatu, Faca => Colisão
5.
6. Dragão
10. Mandragora

Problema: colisão de comprimento de palavra. Solução: armazenar uma lista de valores na tabela.

Buracos: gasta espaço para ganhar eficiência.

Mas a maior parte das palavras tem menos ou igual a cinco letras. Então precisamos de outra função de hash porque essa é ruim: vai ter muitas colisões. Uma boa função deixa as palavras o mais espalhadas o possível. Hash é "espalhar".

Possíveis funções hash: somar os caracteres da palavra, fazer um xor entre os caracteres da palavra.



```C
// Palavras: casa, cachorro, armário, pedra, bola
int hash(char *c) {
    switch(s[0]) {
        case 'p':
            return 0;
        case 'a':
            return 1;
        case 'b':
            return 2;
        case 'a':
            if (s[s] == 's')
                return 3;
            else
                return 4;
    }
}
```

Gerador de funções hash: [gperf](https://www.gnu.org/software/gperf/).

## Compilando
- Shell: `ls`, `gcc`, `as`

## `gcc`:
	- `-o arquivo`: arquivo de saída
	- `-c`: só compila
	- `-l`: biblioteca
	- `-O n`: pode ser 1, 2, 3, é o nível de otimização

