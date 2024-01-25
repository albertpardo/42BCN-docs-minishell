# Tips for Minishell

This document is online on this link [hackmd.io - Tips for Minishell](https://hackmd.io/InOPD08lSJKHJGMwg1M5VQ?both)

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

### Tips para pruebas

- Extraido de [intra 42Barcelona](https://projects.intra.42.fr/projects/42cursus-minishell/projects_users/3339786) : curiosamente cuando intento ejecutar unos 600-700 cat| el programa no hace lo mismo que bash, punto a mejorar sin dudai

- Extraido de [intra 42Barcelona](https://projects.intra.42.fr/projects/42cursus-minishell/projects_users/3247950) :
	- como limpiar el promt al hacer Cntrl+C.
	- Parsear el **echo** con flags -nnn.
	- tener en cuenta `cd -`

- Extraido de [intra 42Barcelona](https://projects.intra.42.fr/projects/42cursus-minishell/projects_users/3355130) : los comandos sin permisos no salen con el error correcto ni imprimen el mensaje correspondiente. **ESTE COMENTARIO NO LO ENTIENDO**

- vigilar con el pipe entre comillas: **"|"** o **'|'**
- `cat | cat | ls` . Extraido de [intra 42Barcelona](https://projects.intra.42.fr/projects/42cursus-minishell/projects_users/3237012)

