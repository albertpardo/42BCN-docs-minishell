# Pruebas realizadas en un terminal en modo BASH

Para todas las pruebas , cambiar al shell **BASH**

Ejemplo de cambio de *zsh*  a **bash** sobre iMAC de 42 BArcelona a 20240121:

```sh
apardo-m@car15s4 ~ % bash

The default interactive shell is now zsh.
To update your account to use zsh, please run `chsh -s /bin/zsh`.
For more details, please visit https://support.apple.com/kb/HT208050.
bash-3.2$ 
```

## Pruebas CRASH
A probar :

- **< /dev/urandom** 
- **< /dev/random**
- **< /dev/random cat**

Creo que esto esta en la hoja del evaluador:

> Set the $PATH to a multiple directory value (directory1:directory2)

### Cambiar el TTY(teclado) de entrada por un fichero al arrancar

- **./minishell < /dev/urandom**

Se puede solucionar usando **isatty()**


### Quitar el ENVIRONMENT bash

Ejemplo en bash:

```sh
bash-3.2$ env -i bash

The default interactive shell is now zsh.
To update your account to use zsh, please run `chsh -s /bin/zsh`.
For more details, please visit https://support.apple.com/kb/HT208050.
bash-3.2$ env
PWD=/Users/apardo-m
SHLVL=1
_=/usr/bin/env
bash-3.2$ echo $PATH
/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.
```

A partir de aqui se puede hacer una funcion que replique el minimo entorno que tiene bash.



### heredocs

####  cat << "2"

Las comillas del string usado como EOF se ignoran . Si no se ponen, *cat* lo acepta igual.

```sh
bash-3.2$ cat << "2"
> 1
> "2"
> dos
> 3
> 2
1
"2"
dos
3
bash-3.2$
```

### "cat | ls"

Creo que hay que gestionar señales. Pero no estoy seguro. Hay que mirar otros códigos.

Posibles links para mirar:

- [How does head stops cat in following command : cat /dev/urandom | head -c 10 ](https://unix.stackexchange.com/questions/613848/how-does-head-stops-cat-in-following-command-cat-dev-urandom-head-c-10)

###  feaguila
**cat /dev/random** presenta en pantalla lineas aleatorias
**cat /dev/random | head -n 1** presenta solo una linea

Creo que cuando un comando no se puede ejecutar el Bash genera un 127 y se puede consultar con **echo $?** 

Tendriamos que probar formatos null de entrada para temas de errores.

## Pruebas en Bash

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

Ejemplo extraido de [How does cat \<\< EOF  work in bash?](https://stackoverflow.com/questions/2500436/how-does-cat-eof-work-in-bash) y ejecutado localmente:

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
1. `cat << uno`
2. `cat << dos`
3. `ls`


Creo que lo que hace es obtener los diferentes comandos con el *pipe* (**|**) sin chequear si hay *<<* entre los argumentos:
1. `cat << uno` a `execve(...)`
2. `cat << uno` a `execve(...)`
2. `ls` a `execve(...)`

## Varias pruebas con redirecciones

Generar ficheros para pruebas 

```sh
echo f1 > f1; echo f2 > f2; echo f3 > f3; echo f4 > f4
```

### prueba básicas sin comando

#### ` <f1 <<1`

```sh
bash-3.2$ <f1 <<1
> hola
> 1
```

#### ` <f1 <<1 >borrame` 

```sh
bash-3.2$ <f1 <<1 >borrame
> hola
> 1
bash-3.2$ cat borrame
bash-3.2$
```

#### ` <f1 <<1 <<2 <<3 >borrame` 

```sh
bash-3.2$ <f1 <<1 <<2 <<3 >borrame
> hola
> 1
> hola
> 2
> hola
> 3
bash-3.2$ cat borrame
bash-3.2$
```

### prueba básicas comando "cat"

#### ` <f1 cat` 
```sh
bash-3.2$ <f1 cat
f1
```

#### ` <f1 <f2 <f3 cat` 
```sh
bash-3.2$ <f1 <f2 <f3 cat
f3
```

#### ` <f1 <f2 <f3 <<1 cat` 
```sh
bash-3.2$ <f1 <f2 <f3 <<1 cat
> hola
> 1
hola
```

#### ` <f1 <f2 <f3 <<1 <<2 <<3 cat`

```sh
bash-3.2$ <f1 <f2 <f3 <<1 <<2 <<3 cat
> hola
> 1
> hola
> 2
> hola3
> 3
hola3
```

#### ` <f1 <f2 <f3 <<1 <<2 <<3 < f4 cat` 

```sh
bash-3.2$ <f1 <f2 <f3 <<1 <<2 <<3 < f4 cat
> hola1
> 1
> hola2
> 2
> hola3
> 3
f4
```

### prueba básicas comando "exit"

#### `<f1 <f2 <f3 <<1 <<2 <<3 < f4 exit ` 

```sh
bash-3.2$ <f1 <f2 <f3 <<1 <<2 <<3 < f4 exit
> hola1
> 1
> hola2
> 2
> hola3
> 3
exit
```

#### ` ` 

```sh

```

### `<< 2 cat >delete.txt | << 1 cat > delete2.txt | cat > final.txt`

```bash
bash-3.2$ << 2 cat >delete.txt | << 1 cat > delete2.txt | cat > final.txt
> dos
> 2
> uno
> 1
bash-3.2$ cat delete.txt
dos
bash-3.2$ cat delete2.txt
uno
bash-3.2$ cat final.txt
bash-3.i2$
```

### `<< 2 cat | << 1 cat | cat > final.txt`

```bash
bash-3.2$ << 2 cat | << 1 cat | cat > final.txt
> dos
> 2
> uno
> 1
bash-3.2$ cat final.txt
uno
bash-3.2$
```

### `<< 2 cat | << 1 cat | <tem.txt cat > final.txt`

```bash
bash-3.2$ echo "to the final" > tem.txt
bash-3.2$ << 2 cat | << 1 cat | <tem.txt cat > final.txt
> dos
> 2
> uno
> 1
bash-3.2$ cat final.txt
to the final
bash-3.2$
```

## Pruebas PIPE

### `'ls || grep a'`

Ejecución previa:

```sh
bash-3.2$ ls
LICENSE		inc		readline
Makefile	minishell	src
README.md	print.sh
```

Ejecución de `ls || grep a`:

```sh
bash-3.2$ ls || grep a
LICENSE		inc		readline
Makefile	minishell	src
README.md	print.sh
```

### `'ls | | grep a'`

```sh
bash-3.2$ ls | | grep a
bash: syntax error near unexpected token `|'
```

### `'ls ||| grep a'`

```sh
bash-3.2$ ls ||| grep a
bash: syntax error near unexpected token `|'
```

## Pruebas PIPES y comillas

### `'echo "Mensaje Salida"' | grep a`

```sh
bash-3.2$ 'echo "Mensaje Salida"' | grep a
bash: echo "Mensaje Salida": command not found
```

### `'echo 'Mensaje Salida'' | grep a`

```sh
bash-3.2$ 'echo 'Mensaje Salida'' | grep a
bash: echo Mensaje: command not found
```

### `'echo ' Mensaje Salida''`

```sh
bash-3.2$ 'echo ' Mensaje Salida''
bash: echo : command not found
bash-3.2$
```

## Pruebas con variable de entorno

La definición variable se ha de hacer con `export`, de esta manera queda en el entorno de la sesión actual de *bash*: 

```sh
export MIVAR=100
```

### 'echo' 'Mensaje Salida:$MIVAR'

```sh
bash-3.2$ 'echo' 'Mensaje Salida:$MIVAR'
Mensaje Salida:$MIVAR
```

### 'echo' "Mensaje Salida:$MIVAR"

```sh
bash-3.2$ 'echo' "Mensaje Salida:$MIVAR"
Mensaje Salida:100
```

## Pruebas con $

```sh
bash-3.2$ echo $
$
bash-3.2$ echo $0
bash
bash-3.2$ echo $5

bash-3.2$ echo $$
8403
bash-3.2$ echo $$$$
84038403
```


## cd . Comprobar PWD y OLDPWD

1. Comprobamos PWD y OLDPWD

```sh
bash-3.2$ echo $OLDPWD
/Users/apardo-m
bash-3.2$ echo $PWD
/Users/apardo-m
```
2. Cambiamos de carpeta *Documents* . Comprobamos PWD y OLDPWD:

```sh
ash-3.2$ cd Documents/
bash-3.2$ echo $PWD
/Users/apardo-m/Documents
bash-3.2$ echo $OLDPWD
/Users/apardo-m
```
3. Cambiamos de carpeta *23-Cursus* . Comprobamos PWD y OLDPWD:

```sh
bash-3.2$ cd 23-Cursus
bash-3.2$ echo $PWD
/Users/apardo-m/Documents/23-Cursus
bash-3.2$ echo $OLDPWD
/Users/apardo-m/Documents
```

**Conclusión**
Si se trabaja con una copia dentro del programa del ENVIRONMENT del bash , en esta copia hemos de actualizar *PWD* y *OLDPWD*

## exit
Según el valor númerico que se le da a `exit` , al realizar  `echo $` da un número mayor que 1

### exit 9223372036854775807

```sh
bash-3.2$ exit 9223372036854775807
exit
car15s5:~ $ echo $?
255
```

### exit 9223372036854775808

```sh
bash-3.2$ exit 9223372036854775808
exit
bash: exit: 9223372036854775808: numeric argument required
car15s5:~ $ echo $?
255
```

### exit -9223372036854775808

```sh
bash-3.2$ exit -9223372036854775808
exit
car15s5:~ $ echo $?
0
```

### exit -9223372036854775809

```sh
bash-3.2$ exit -9223372036854775809
exit
bash: exit: -9223372036854775809: numeric argument required
car15s5:~ $ echo $?
255
```

## Pruebas SHELLS anidados 

Se compueba la variable de entorno **SHLVL** cada vez que se ejecuta un *bash* dentro de otro *bash*

```sh
car15s4:~ $ env | grep SHL
SHLVL=1
car15s4:~ $ bash

The default interactive shell is now zsh.
To update your account to use zsh, please run `chsh -s /bin/zsh`.
For more details, please visit https://support.apple.com/kb/HT208050.
bash-3.2$ env | grep SHL
SHLVL=2
bash-3.2$ bash

The default interactive shell is now zsh.
To update your account to use zsh, please run `chsh -s /bin/zsh`.
For more details, please visit https://support.apple.com/kb/HT208050.
bash-3.2$ env | grep SHL
SHLVL=3
bash-3.2$ zsh
car15s4:~ $ env | grep SHL
SHLVL=4
```

Cada vez que se ejecuta un nuevo *Shell* , al comprobar **SHLVL** , esta variable se incrementa en 1.

## Expansión $

Diversas pruebas de expasion de $

```sh
bash-3.2$ export MYVAR=algo
bash-3.2$ echo 111-'$MYVAR='$MYVARR
111-$MYVAR=
bash-3.2$ echo 111-'$MYVAR='$MYVAR-
111-$MYVAR=algo-
bash-3.2$ echo 111-'$MYVAR='$MYVAR2
111-$MYVAR=
bash-3.2$ echo 111-'$MYVAR='
111-$MYVAR=
bash-3.2$ echo 111-'$MYVAR='$MYVAR2qwrqewr
111-$MYVAR=
bash-3.2$ echo 111-'$MYVAR='$MYVAR2qwrqewr rer
111-$MYVAR= rer
bash-3.2$ echo 111-'$MYVAR='$MYVAR"rer"
111-$MYVAR=algorer
bash-3.2$
```

## Pruebas para obtener $?=127, $?=126 y el valor devuelto por el ultimo comando

### $?=127

```sh
bash-3.2$ la
bash: la: command not found
bash-3.2$ echo $?
127
```
### $?=126

```sh
bash-3.2$ echo ls > eje.sh
bash-3.2$ chmod 222 eje.sh
bash-3.2$ ./minishell "bash eje.sh"
bash-3.2$ echo $?
126
```

### valor devuelto por el último comando

Toma como base el ultimo ejemplo.

```sh
bash-3.2$ bash eje.sh | echo pepe
bash-3.2$ echo $?
pepe
bash: eje.sh: Permission denied
0
```
