# Pruebas dudas

Pruebas de dudas en diferentes minishell's. Cada título corresponde a una duda.

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

