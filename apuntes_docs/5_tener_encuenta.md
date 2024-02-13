## Instrucciones shell

## Combinaciones con tecla 'Ctrl'

| Combinacion 'Ctrl' | Descripcion |
| ------------------ | ----------------- |
| **Ctrl-C**         | abandona la linea actual crea una nueva linea. |
| **Ctrl-D**         |	si hay algo escrito suena la campana, si no hay nada escrito imprime 'exit' y sale del bash actual (si esta anidado vuelve al bash padre) |
| **Ctrl-\\**         |  No hace nada (*minishell* Deberia capturar esta llamada y no hacer nada) |

## Caracteres \*,  *&* y *&&*

- **&** : El enunciado no indica  que se deba implementar
- **&&** : Aparece en la parte del Bonus
- * : Aparece en la parte del Bonus

## CD

En el miniuto [14:47] de  [youtube-Shell Program Explained](https://www.youtube.com/watch?v=ubt-UjcQUYg) indican que es mejor que lo ejecute el proceso padre.  En su ejemplo, su main para el shell verifica si **cd** es el primer comando introducido en la shell.

## Instrucciones a ejecutar por Minishell

Las instrucciones que indica como implement , es que el **minishell** las ha de simular, es decir ejecutarlas como si lo hiciera el **bash**.

| Builtin Command | **C** commands to use or **libft** function |
| ------------------ | ----------------- |
| **echo** with option **-n** | **write** , **ft_printf** , **ft_putchar** , **ft_putsrt** |
| **cd** with only a relative or absolute path | **chdir** |
| **pwd** with no options | **getcwd** |
| **export** with no options |  **write** , **ft_printf** , **ft_putchar** , **ft_putsrt** , **getenv** |
| **unset** with no options |  |
| **env** with no options or arguments | **getenv** |
| **exit** with no options |  **exit** |

Cuando se ejecuta **cd** se ha de actualizar las variables de entorno *OLDPWD* y *PWD* (usar una funcion que pueda actualizar cualquier variable de entorno)  
> **240114** No tengo claro como actualizar  *OLDPWD* y *PWD* 

> **240114** No tengo claro la utilidad de  : isatty, ttyname, ttyslot, ioctl, tcsetattr, tcgetattr, tgetent, tgetflag,tgetnum, tgetstr, tgoto, tputs

## External Links for Bash and C commands

Why? Because the man of iMac don't give info or the info is not enough

The rigth wayt to acces to some info is acces to bash and use **help** .

> Note: *env* use **man env** 

### C

- [readline](https://man7.org/linux/man-pages/man3/readline.3.html)
- [ttyslot](https://man7.org/linux/man-pages/man3/ttyslot.3.html)

### Bash

- [cd](https://man7.org/linux/man-pages/man1/cd.1p.html)
- [export](https://www.man7.org/linux/man-pages/man1/export.1p.html)
	- set the export attribute for variables
- [unset](https://man7.org/linux/man-pages/man1/unset.1p.html)
	- unset values and attributes of variables and functions
- [exit](https://man7.org/linux/man-pages/man1/exit.1p.html)
	- cause the shell to exit

### Help bash

Those are the info extracted in bash mode

#### echo

```sh
bash-3.2$ help unset
echo: echo [-neE] [arg ...]
    Output the ARGs.  If -n is specified, the trailing newline is
    suppressed.  If the -e option is given, interpretation of the
    following backslash-escaped characters is turned on:
    	\a	alert (bell)
    	\b	backspace
    	\c	suppress trailing newline
    	\E	escape character
    	\f	form feed
    	\n	new line
    	\r	carriage return
    	\t	horizontal tab
    	\v	vertical tab
    	\\	backslash
    	\0nnn	the character whose ASCII code is NNN (octal).  NNN can be
    		0 to 3 octal digits

    You can explicitly turn off the interpretation of the above characters
    with the -E option.
```

#### cd 

```sh
bash-3.2$ help cd
cd: cd [-L|-P] [dir]
    Change the current directory to DIR.  The variable $HOME is the
    default DIR.  The variable CDPATH defines the search path for
    the directory containing DIR.  Alternative directory names in CDPATH
    are separated by a colon (:).  A null directory name is the same as
    the current directory, i.e. `.'.  If DIR begins with a slash (/),
    then CDPATH is not used.  If the directory is not found, and the
    shell option `cdable_vars' is set, then try the word as a variable
    name.  If that variable has a value, then cd to the value of that
    variable.  The -P option says to use the physical directory structure
    instead of following symbolic links; the -L option forces symbolic links
    to be followed.
```

#### pwd

```sh
bash-3.2$ help pwd
pwd: pwd [-LP]
    Print the current working directory.  With the -P option, pwd prints
    the physical directory, without any symbolic links; the -L option
    makes pwd follow symbolic links.
```

#### export

```sh
bash-3.2$ help export
export: export [-nf] [name[=value] ...] or export -p
    NAMEs are marked for automatic export to the environment of
    subsequently executed commands.  If the -f option is given,
    the NAMEs refer to functions.  If no NAMEs are given, or if `-p'
    is given, a list of all names that are exported in this shell is
    printed.  An argument of `-n' says to remove the export property
    from subsequent NAMEs.  An argument of `--' disables further option
    processing.
```

#### unset

```sh
bash-3.2$ help unset
unset: unset [-f] [-v] [name ...]
    For each NAME, remove the corresponding variable or function.  Given
    the `-v', unset will only act on variables.  Given the `-f' flag,
    unset will only act on functions.  With neither flag, unset first
    tries to unset a variable, and if that fails, then tries to unset a
    function.  Some variables cannot be unset; also see readonly.
```

#### exit

```sh
bash-3.2$ help exit
exit: exit [n]
    Exit the shell with a status of N.  If N is omitted, the exit status
    is that of the last command executed.
```


