# Pruebas dudas

Pruebas de dudas en diferentes minishell's. Cada título corresponde a una duda.

## usar Macros de wait para gestionar errores


Extraido de *read_heredoc.c* (lajara) :

```c
	wait(&status);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status) && (WTERMSIG(status) == SIGINT))
		return (EXIT_FAILURE);
```

usa : 
- `fd_file = open_file(file, O_CREAT | O_WRONLY | O_TRUNC);`
- acitva señal usando : `set_signals(HEREDOC);`


## `ls -la ; echo ; echo "en la siguiente linea se ejecuta ls" ; ls`

Para *bash* el *;* indica que debe ejectar cada comando por separado y de manera consecutiva

### [maiadegraaf](https://github.com/maiadegraaf/minishell/tree/main)

```sh
minishell$ ls -la ; echo ; es -la ; echo ; echo "en la siguiente linea se ejecuta ls" ; ls
ls: ;: No such file or directory
ls: ;: No such file or directory
ls: ;: No such file or directory
ls: echo: No such file or directory
ls: echo: No such file or directory
ls: ejecuta: No such file or directory
ls: en: No such file or directory
ls: la: No such file or directory
ls: linea: No such file or directory
ls: ls: No such file or directory
ls: ls: No such file or directory
ls: se: No such file or directory
ls: siguiente: No such file or directory
```
En esta prueba no se gestiona el **;** como error sintáctico. Trata el *;* como un caracter más.

## `'"ls"`  

*bash* entra en una especie de editor donde espera cerrar la comilla simple.

### [maiadegraaf](https://github.com/maiadegraaf/minishell/tree/main)

```sh
minishell$ '"ls"
minishell: syntax error: unable to locate closing quotation
```

No cerrar la **'** , se trata como un error sintáctico.

## "ls

*bash* entra en una especie de editor donde espera cerrar la comilla simple.

### [maiadegraaf](https://github.com/maiadegraaf/minishell/tree/main)

```sh
minishell$ "ls
minishell: syntax error: unable to locate closing quotation
```

No cerrar la **"** , se trata como un error sintáctico.

##  cat << 1 | cat << 2 | cat << 3 > borrame

En bash:

```sh
bash-3.2$ cat << 1 | cat << 2 | cat << 3 > borrame
> unos
> 1
> dos
> 2
> tres
> 3
bash-3.2$ cat borrame
tres
bash-3.2$
```

### lajara

```sh
minish$ cat << 1 | cat << 2 | cat << 3 > borrame
> uno
> 1
> dos
> 2
> tres
> 3
minish$ cat borrame
tres
minish$
```

## `ls || grep a`

Previamente se ejecuta:

```sh
bash-3.2$ ls
LICENSE		inc		readline
Makefile	minishell	src
README.md	print.sh
```

En Bash tenemos :

```sh
bash-3.2$ ls || grep a
LICENSE		inc		readline
Makefile	minishell	src
README.md	print.sh
```

### lajara

```sh
minish$ ls || grep a
minish: syntax error near token '|'
```

### maia

```sh
minishell$ ls || grep a
minishell: syntax error near unexpected token '|'
```

## HEARDOCS

### 1 Prueba en bash
y
```sh
bash-3.2$ cat << EOF
> Current dir $PWD
> login : $(whoami)
> EOF
Current dir /Users/apardo-m
login : apardo-m
bash-3.2$
```

#### Lajara

```sh
minish$ cat << EOF
> Current dir $PWD
> login : $(whoami)
> EOF
Current dir /Users/apardo-m/Documents/23-Cursus/03_circle/2_minishell/others/lajara
login : $(whoami)
minish$
```

#### Maia

```sh
minishell$ cat << EOF
> Current dir $PWD
> login : $(whoami)
> EOF
Current dir /Users/apardo-m/Documents/23-Cursus/03_circle/2_minishell/others/maiadegraaf
login :
```

#### 240308  Prueba en fichero : '60_execve_cat_1.c'

Como se ve a continuación , a fecha de 240308 no tengo contemplado la substitucion de variables de entorno con $


```sh
cbr1s3:test_previos (master*) $ ./a.out
Emulando la instrucción 'cat << uno'
> Current dir $PWD
> login : $(whoami)
> uno
Temporal file: .tmp_heredoc
Start of execve call /bin/cat:
=================================
Current dir $PWD
login : $(whoami)
```

### 2 Prueba en bash

```sh
bash-3.2$ cat << EOF
>  Current dir $PWD
>  login : $whoami
> EOF
 Current dir /Users/apardo-m
 login :
bash-3.2$
```

#### Lajara

```sh
minish$ cat << EOF
>  Current dir $PWD
>  login : $whoami
> EOF
 Current dir /Users/apardo-m/Documents/23-Cursus/03_circle/2_minishell/others/lajara
 login :
minish$
```

#### Maia

```sh
minishell$ cat << EOF
> Current dir $PWD
> login : $whoami
> EOF
Current dir /Users/apardo-m/Documents/23-Cursus/03_circle/2_minishell/others/maiadegraaf
login :
minishell$
```
## export

Bash permite usar `export NOMBREVARIABLE+=loquesea`
si no existe `NOMBREVARIABLE` la crea
Si existe añade `loquesea` al final del contenido de `NOMBREVARIABLE`

Tanto *lajara* como *maia* imprimen un error:

```shell
minish$ export MIVAR+=algo
minish: export: 'MIVAR+=algo': not a valid identifier
```
