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

> En la correcion de su *minishell* , en la que sus tres evaluadores encontraron algun error y los suspendieron, tuvieron a **@eralonso** como evaluador y ha comentdo lo siguiente:
    > - **Como persona** : Amistoso, amable y simpatico. Si le consultas , siempre trata de darte su mejor explicacion.
    > - **Como Evaluador**: Es muy meticuloso y esto le lleva a que su evaluacion sea muy larga. Por lo que parece, siempre trata de buscar alguna condicion que hace que el programe tenga funcionamiento anomalo o falle. En su caso llegaron a estar mas de dos horas, hasta que encontro un error.e
