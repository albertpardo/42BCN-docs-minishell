# Tips for Minishell

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

### "cat | ls"

Creo que hay que gestionar señales. Pero no estoy seguro. Hay que mirar otros códigos.

Posibles links para mirar:

- [How does head stops cat in following command : cat /dev/urandom | head -c 10 ](https://unix.stackexchange.com/questions/613848/how-does-head-stops-cat-in-following-command-cat-dev-urandom-head-c-10)

###  feaguila
**cat /dev/random** presenta en pantalla lineas aleatorias
**cat /dev/random | head -n 1** presenta solo una linea

Creo que cuando un comando no se puede ejecutar el Bash genera un 127 y se puede consultar con **echo $?** 

Tendriamos que probar formatos null de entrada para temas de errores.

## Tips otros alumnos 42 Barcelona

### Tips by *jocorrea*

- Mirar **execve** : por lo que entendido ejecuta el codigo guardado en un fichero
- Usar **sigaction** si se han de pasar parametros. Si no usar **signal**.
- `pipe` tiene limitada la memoria que puede usar . Si ha de ejecutar algo grande es mejor usar un archivo temporal y borrarlo cuando termine de ejecutar lo que tenga que ejecutar.
- Mirar la Gramatica del Shell. Me ha indicado estos links:
	- [Minishell by maiadegraaf in Github](https://github.com/maiadegraaf/minishell)
	- Le ayudo el codigo que parece en la pagina 11 de este documento [Chapter 5  Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf) para entender y comprobar la sintaxis de las instrucciones.
- La instruccion `echo $?` permite saber el valor entero devuelto por el ultima instruccion ejecutada.

###  Tips by *@alajara-*

- Tener encuenta **CDPATH**.  **@alajara-** indica que se comenta muchas veces en el manual de bash. (Lo he comprobado haciendo una busqueda por palabra clave en el pdf y aparece bastantes veces). A su parecer, considera que es importante y por lo que ha indagado durante la realizacion del proyecto, poca gente lo tiene encuenta.
- [Github de su equipo](https://github.com/LAG-jara/minishell) y un [Manual del proyecto](https://github.com/Liam-McHara/minishell-manual/blob/main/manual.md)

### Tips para pruebas

- Extraido de [intra 42Barcelona](https://projects.intra.42.fr/projects/42cursus-minishell/projects_users/3339786) : curiosamente cuando intento ejecutar unos 600-700 cat| el programa no hace lo mismo que bash, punto a mejorar sin duda

- Extraido de [intra 42Barcelona](https://projects.intra.42.fr/projects/42cursus-minishell/projects_users/3247950) :
	- como limpiar el promt al hacer Cntrl+C.
	- Parsear el **echo** con flags -nnn.
	- tener en cuenta `cd -`

- Extraido de [intra 42Barcelona](https://projects.intra.42.fr/projects/42cursus-minishell/projects_users/3355130) : los comandos sin permisos no salen con el error correcto ni imprimen el mensaje correspondiente. **ESTE COMENTARIO NO LO ENTIENDO**

- vigilar con el pipe entre comillas: **"|"** o **'|'**
- `cat | cat | ls` . Extraido de [intra 42Barcelona](https://projects.intra.42.fr/projects/42cursus-minishell/projects_users/3237012)

