# Algoritmo minishell

## 240223 Algoritmo

Para tener las variables de entorno al inicio del programa se usa : `int	main(int argc, char **argv, char **envp)`. Donde  `*char **envp`

### Pasos previos

- Gestión errores entrada iniciales.
- Inicializar   con las variables contenidas en una *estructura*  a usar por la funciones del programa . La *estructura* se pasa como parámetro en cualquier función.


### Bucle MINISHELL:

-  Obtener **input** del teclado
- **Tokenizar ( lexer )**  : Distinguir WORD, PIPE, LESS, LESS_LESS, GREAT , GREAT_GREAT
	- Si hay simple comilla  o doble comillas sin cerrar:
		- ERROR y volver al inicio de **Bucle MINISHELL**
	- Si hay más de una PIPE seguidas:
		- ERROR y volver al inicio **Bucle MINISHELL**
- **Parser**:
	- Si se empieza con PIPE 
		-  return(ERROR)
	- Bucle **recorrer la lista de TOKENS**
		- Si el nodo actual es un *operator* del tipo **PIPE** se borra de la lista de TOKENS.(Se actualiza el inicio de lista)
		- Si el nodo actuali es **NULO** :
			- Borrar *lista de TOKENS*
			- return(ERROR)
		- **FALTA TERMINAR LO QIUE HACE ESTE BUCLE**
- Preparación previa  a **Executor**:
	- Activar *SIGNALS*
	- Reservar memoria para los PID de los forks.
- Proceso **Executor** , se tiene encuenta las *redirecciones* (pueden estar en una lista)
	- Bucle **recorrer la lista de COMMANDS**
		- **Expander** para strings (words) : 
			- Expandir el *$* (se ha de comprobar de manera correcta)
			- Si el comando es **export** borrar las comillas simples o dobles
		- **Redirecciones** :
			- Expandir el *$* (se ha de comprobar de manera correcta)
			- Borrar las comillas simples o dobles
		- **Heredoc** :
			- Gestión de **lista de REDIRECCIONES** para detectar **LESS_LESS**
		- **Ejecución** (tener encuenta el caso de un sólo comando):
			- fork hijo:
				- Reasignación STDIN y STDOUT
				- Si REDIRECCIONES no son correctas 
					- exit(1)
				- Si hay **BuiltCommand**
					- ejecutar **BuiltCommand** (puede tener path relativo ,absoluto, o se ha de buscar en *PATH*)
					- exit con el exitcode del **BuiltCommand**
				- Ejecutar **Command** (puede tener path relativo ,absoluto, o se ha de buscar en *PATH*). Lanzar **Error** si no enuentra *Command* y activar el correspondiente **exit code**
			- En padre cerrar *pipes*
			- Enterder `fd_in = check_fd_heredoc(tools, end, tools->simple_cmds);` de **maia**

> Aviso para **Alberto**: Hay que entender la gestión del **HereDOC**			


## 240115 Consideraciones previas

Hay que replicar una parte de lo que hace el **bash**.

Se ha de considerar que el *bash* es un ejecutador de instrucciones o comandos.
Un *bash* puede ejecutar otros tipos de *bash*. Por lo tanto *minishell* se debe poder ejecutar dentro de *minishell*. **DUDA** : Que interacciones implica esto?

Funcionamiento :
- Entradas de intrucciones o comandos : por teclado y/o fichero.
- Salida de resultados, informacion de ejecucion o error : pantalla y/o fichero.


### Main loop extraido de [youtube-Shell Program Explained](https://www.youtube.com/watch?v=ubt-UjcQUYg)

```txt
while(1)
	Print promt
	Read a line
	Parse:
		-> Build tree representation
	Execute
```

## Posible Algoritmo base

- Ejecutar *minishell* como un proceso paralelo (proceso hijo?) al *bash* del ordenador. El *bash* del ordenador seria un proceso *padre*?) .
	- **DUDA**: No deberia alterar las variables de entorno del proceso padre de ninguna manera?
	- Cuando se ejecuta *minishell* , debe presentar su propio promt mientras espera un *comando*. Ejemplo : `msh-1.0$`(extraido de [minishell evaluation of amilliar and sbashir by zskeeter](https://www.youtube.com/watch?v=DAkCD6CsEFI)
- Capturar las instrucciones introducidas desde teclado/fichero.
- **Analisis sintáctico**: 
	- Si las instrucciones introducidas siguen un patron sintatico valido, pasan a ser ejecutadas.
	- En caso contrario, *minishell* debera hacer lo que sea conveniente y presentar un error similar al que hace *bash*. (Puede pasar que no sepamos reproducir el error)
	- Posibles algoritmos para esta parte ( extraido de [medium link](https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218)):
		- **Precedence Climbing**. (*Choosed by the author because he thinks this algorithm is more simple*). Example : [Parsing expressions by precedence climbing](https://eli.thegreenplace.net/2012/08/02/parsing-expressions-by-precedence-climbing)
		- [The Recursive Descent](https://en.wikipedia.org/wiki/Recursive_descent_parser). Also commented by *hhp3 del MIT*. Other possible resources: [Articles in tag "Recursive descent parsing"](https://eli.thegreenplace.net/tag/recursive-descent-parsing)
		- [the shunting-yard algorithm](https://en.wikipedia.org/wiki/Shunting_yard_algorithm)

- Antes de ejecutar hay que hacer un REDIRECT y hacer todos los HereDocs que haya en la instruciones  ??? Consusltar  *process_commands(...)*  en *redirect_and_execute.c* de lajara.

- Ejecucion del comando (**Duda** : El comando toma el control de la ejecucion?):
	- Verificar si es un *builtint* . Es decir , de los que tenemos que implementar.
	- Verificar si el comando es un comando valido en *bash*. Ejecutarlo y capturar su respuesta (por si hay error).
	- En caso contrario verificar si tiene permisos de ejecucion, por que pude ser un script de shell. Ejecutarlo y capturar su respuesta (por si hay error).
	- Reportar error tanto si no tiene permisos de ejecucion como si ha habido algun error durante la ejecucion.


