# Pruebas realizadas en un terminal en modo BASH

Para todas las pruebas , cambias al shell **BASH**

Ejemplo de cambio de *zsh*  a **bash** sobre iMAC de 42 BArcelona a 20240121:

```sh
apardo-m@car15s4 ~ % bash

The default interactive shell is now zsh.
To update your account to use zsh, please run `chsh -s /bin/zsh`.
For more details, please visit https://support.apple.com/kb/HT208050.
bash-3.2$ 
```

## Pruebas en Bash

### Ver como podemos evitar : Crash terminal

[these characters will crash your computer](https://www.youtube.com/watch?v=xqo3xtkfuic&list=PLGU1kcPKHMKj5yA0RPb5AK4QAhexmQwrW&index=17). Instruction :
`:(){ :|:& };:`

### Exit

Estando en el shell por defecto de iMAC , que es *zsh* hago la siguiente prueba:

1. Estar en shell de *bash* y hacer un `exit 5`
3. Ejecutar `echo $?`

Estas son las lineas extraidas del terminal: 

```sh
bash-3.2$ exit 5
exit
apardo-m@car15s4 ~ % echo $?
5
```

## Prueba : definir una variable y realizar diferentes tipos de echos

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

## Pruebas cerrando ' o "

Ejemplos estando en la carpeta *apuntes_mini_github*:

```sh
bash-3.2$ 'ls'
apuntes_mini_github
books
en.subject_minishell_v7_1.pdf
evaluator_docs
mini_repo
update_local_repos_mini.sh
bash-3.2$
```

```sh
bash-3.2$ "ls"
apuntes_mini_github
books
en.subject_minishell_v7_1.pdf
evaluator_docs
mini_repo
update_local_repos_mini.sh
bash-3.2$
```

```sh
bash-3.2$ "'ls'"
bash: 'ls': command not found
```

```sh
bash-3.2$ '"ls"'
bash: "ls": command not found
bash-3.2$
```

```sh
bash-3.2$ "'ls"
bash: 'ls: command not found
bash-3.2$
```

```sh
bash-3.2$ '"ls'
bash: "ls: command not found
bash-3.2$
```

## Pruebas con ' o " sin cerrar .

> **240121**: Por lo que he entendido del subject, no debemos implemenmtar este modo de comportamiento. Si es así, ver como presentar un error propio de nuestro proyecto para diferenciarlo de un error devuelto por *bash*.

Cuando no se cierra la ' o la ", *bash* entra en un modo de editor de linea de comando.


Ejemplos usando *echo*

```sh
bash-3.2$ echo '
>    Hola
>  Mundo
> '

   Hola
 Mundo

bash-3.2$
```

```sh
bash-3.2$ echo 'MIVAR =
>   $MIVAR
> --'
MIVAR =
  $MIVAR
--
bash-3.2$
```

```sh
bash-3.2$ echo "MIVAR = $MIVAR
>  --"
MIVAR = 100
 --
bash-3.2$
```

Pruebas poniendo directamente ' o ":

```sh
bash-3.2$ '
> h
> '
bash:
h
: command not found
bash-3.2$
```

```sh
bash-3.2$ '"ls"
> '
bash: "ls"
: command not found
bash-3.2$
```


## Pruebas con ;

Se incluye el comando *echo*:

```sh
bash-3.2$ ls -la ; echo ; echo "--- en la siguiente linea se ejecuta ls --" ; ls
total 16
drwxr-xr-x   6 apardo-m  2023_barcelona   204 Jan 20 16:08 .
drwxr-xr-x   8 apardo-m  2023_barcelona   272 Jan 21 17:03 ..
drwxr-xr-x  15 apardo-m  2023_barcelona   510 Jan 22 15:11 .git
-rwxr-xr-x   1 apardo-m  2023_barcelona    81 Jan 20 15:44 .gitignore
-rw-r--r--   1 apardo-m  2023_barcelona  1173 Jan 22 14:49 README.md
drwxr-xr-x  12 apardo-m  2023_barcelona   408 Jan 22 12:44 apuntes_docs

--- en la siguiente linea se ejecuta ls --
README.md	apuntes_docs
bash-3.2$
```
Según el subject :
>  Not interpret unclosed quotes or special characters which are not required by the subject such as **\ (backslash)** or **; (semicolon)**.

Prueba entre comillas simples:

```sh
bash-3.2$ 'ls -la ; echo ; echo "--- en la siguiente linea se ejecuta ls --" ; ls'
bash: ls -la ; echo ; echo "--- en la siguiente linea se ejecuta ls --" ; ls: command not found
bash-3.2$
```

## Pruebas con \<\<

Ejemplo extraido de [How does "cat << EOF" work in bash?](https://stackoverflow.com/questions/2500436/how-does-cat-eof-work-in-bash) y ejecutado localmente:

```sh
bash-3.2$ cat <<EOF > print.sh
> #!/bin/bash
> echo \$PWD
> echo $PWD
> EOF
bash-3.2$ ls
README.md	apuntes_docs	print.sh
bash-3.2$ cat print.sh
#!/bin/bash
echo $PWD
echo /Users/apardo-m/Documents/23-Cursus/03_circle/2_minishell/apuntes_mini_github
bash-3.2$
```

## Uso de **|** con **cat**

```sh
bash-3.2$ cat | cat | ls
Makefile	includes	outfile
README.md	infile		src
build		libraries
error.txt	minishell
1
2
```
Orden de ejecución :
1. ls
2. primer cat 
2. segundo cat

Otra prueba:

```sh
bash-3.2$ cat << uno | cat << dos | ls
> uno
> dos
Makefile	includes	outfile
README.md	infile		src
build		libraries
error.txt	minishell
```
Orden de ejecución:
1. cat << uno
2. cat << dos
3. ls

e
Creo que lo que hace es obtener los diferentes comandos con el *pipe* (**|**) sin chequear si hay *<<* entre los argumentos:
1. `cat << uno` a `execve(...)`
2. `cat << uno` a `execve(...)`
2. `ls` a `execve(...)`

