# Listado de pruebas a realizar en Minishell / Bash

## Pruebas propias 

### Iniciar minishell con variables de entrada o con redirecciones de entrada salidad

- `./minishell < /dev/urandom`
- `./minishell << EOF'
- `./minishell > borrame.txt`

### Quitar el Enviroment de bash/minishell:

- `env -i bash`   Elimina el environment de bash
- `env`		: Vamos que environmet queda en bash

### HerrDocs

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
