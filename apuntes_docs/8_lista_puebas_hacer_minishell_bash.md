# Listado de pruebas a realizar en Minishell / Bash

## Extraido de Slack

### 240320 by @ltreser on _world_pedagogy 

[Link de la consulta en Sack](https://app.slack.com/client/T039P7U66/CN9RHKQHW)

- ```sh
	exit | exit
	echo  a' '" "b
	and export and unset in pipes
  ```

- `echo hello > a > b > c >d`

- `Ctrl + c on Heredoc`

- `export USER+=hello`

- ```sh
	$$
	cat << "here"
	cat << 'doc'
	export WHAT='"'; echo $WHAT yes, this should work $WHAT
	exit abc 123
	exit 123 abc
	
	yes the two exit result in different outputs
  ```
- position of redirections in command string, it isn't common to many. basically the redir can be anywhere in the command. "echo >outfile hello <infile" would still take input from infile and output hello to outfile

- `Cat | cat << here | ls`

- Running minishell in minishell and handling signals such as Ctrl+C

- Several Test 
	- `export test='o a' && ech$test`  -> prints a in bash.
	- `export test="'" && echo $test` -> prints ’ in bash.
	- `export test="'" && echo "$test"` -> prints ’ in bash.
	- [here’s a stackoverflow question about these ^](https://stackoverflow.com/questions/77717294/which-runs-first-in-bash-lexer-or-expander).
	- `cd -`  -> changes directory to $OLDPWD in bash.
	- `cd`  -> changes directory to $HOME in bash.
	- **This is not in mandatory part** `mkdir ~/afoldername && chmod 000 ~/afoldername && export HOME=~/afoldername && cd`  -> permission denied error shows in bash.
	- heredoc expands variables.
	- `cat | echo a`  prints `a` and waits one newline in bash.
	- `ls 1>outfile 2>&1`  redirects error outputs to file in bash.
	- `echo -nnnn -n -n smthng`  works like `echo -n` in bash.
	- `echo "\n"`  -> ‘\n’  and `echo \n`  -> ‘n’ in bash.
	- `>outfile echo a` works like `echo a > outfile` in bash.
	- `export $number="lol"`  doesn’t work in bash.
	- if you run bash using `env -i` bash the PATH variable will not shown in `env` but if you use echo $PATH  you’ll see the actual value of it. However if you use unset PATH it really deletes the invisible variable.

- if you do cat then press `ctrl + D`  or `ctrl + C`  and check the return value and `cat | cat | ls` then press `ctrl + D` or `ctrl + c` and check return value

## Pruebas propias 

### Iniciar minishell con variables de entrada o con redirecciones de entrada salidad

- `./minishell < /dev/urandom`
- `./minishell << EOF`
- `./minishell > borrame.txt`

### Quitar el Enviroment de bash/minishell:

- `env -i bash` :   Elimina el environment de bash
- `env`	: Vemos que environmet queda en bash

> NOTA : El subject no indica nada de eliminar el **Enviroment** al ejectuar *minishell*

> *Lajara* No tiene encuenta esto. Al ejecutar `env -i ./minishell` y despues `env` , no aparece nada en pantalla , con las limitaciones que implica.

#### Soluciones

Si se detecta que el **env** es **NULL** :

1. lanzar un aviso y pemitir la ejecucion del *minishell* con esta limitación.

2. lanzar un error y parar *minishell*

3. Usar un *entorno* por defecto los más parecido al que genera bash

### HereDocs

- `cat << "2"`
- `cat << 2`
- `cat << 2 > borrame.txt`
- `cat << 1 | cat << 2 | cat << 3 > borrame.txt`
- `cat << 1 | cat << 2 | cat << 3 > ls`

### Redirecciones < ,  >

- `< /dev/urandom`
- `< /dev/random`
- `< /dev/random cat`

### Pruebas varias

- `cat | ls`
- `cat | cat | ls`
- `cat /dev/random`: presenta en pantalla lineas aleatorias
- `cat /dev/random | head -n 1`:  presenta solo una línea aleatoria

### prueba de exit
	
- `exit 5`
- `echo $?`

### Prueba : definir una variable y realizar diferentes tipos de echos

```sh
bash-3.2$ MIVAR=100
bash-3.2$ echo $MIVAR
100
bash-3.2$ echo '$MIVAR'
$MIVAR
bash-3.2$ echo "$MIVAR"
100
bash-3.2$ echo "MIVAR = $MIVAR"
MIVAR = 100
bash-3.2$ echo 'MIVAR = $MIVAR'
MIVAR = $MIVAR
```

### Pruebas cerrando ' i/o "

- `'ls'`
- `"ls"`
- `"'ls'"`
- `"'ls"`
- `'"ls'`
- `'ls''ls''ls'`

### Pruebas con ' o " sin cerrar .

- `'`
- `"`
- `"ls`
- `'"ls`
- `'"ls`
- `'"ls"`

### Tratar de ejecutar un fichero mediante el uso de bashe 

- Crear fichero con HereDoc

```sh
minishell$ cat <<EOF > print.sh
> #!/bin/bash
> echo \$PWD
> echo $PWD
> EOF
```

- Ejecutar fichero dentro de minishell con **bash**: `minishell$ bash print.h`
- Ejecutar fichero dentro de minishell con **bash**: `minishell$ ./minishell  print.h` -> **No se pide en el subject** por lo tanto, se espera un mensaje minishell no acepta parametros de entrada .


## Links con pruebas para minishell

- [by tjensen42](https://github.com/tjensen42/42-minishell) : Son para ejecutar en SHELL , pero pueden ser utilies extraer los comandos a probar en minishell.
