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
