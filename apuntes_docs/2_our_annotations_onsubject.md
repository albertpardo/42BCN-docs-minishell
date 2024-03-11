# Minishell subject

This document is online on this link [HackMD - Minishell subject](https://hackmd.io/8hYRgPaRQpm1hN3Kdk5v3A?both)

## Mandatory part

> You should limit yourself to the subject description. Anything that is not asked is not required.
> If you have any doubt about a requirement, take [bash](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/) as a reference.

### Functions 

> **Libft** is authorized

| Function | Description |
| ----   | ---- |
| [readline](https://man7.org/linux/man-pages/man3/readline.3.html) | get a line from a user with editing  |
| rl_clear_history , rl_on_new_line, rl_replace_line, rl_redisplay, add_history | See [Programming with GNU Readline](https://web.mit.edu/gnu/doc/html/rlman_2.html) and [GNU Readline Library](https://tiswww.case.edu/php/chet/readline/readline.html)  |
| printf    | formatted output |
| malloc, free | memory allocation |
| write     | write output |
| access    | check accessibility of a file|
| open      | open or create a file for reading or writing |
| close     | delete a descriptor |
| read      | read input |
| fork      | create a new process |
| wait, waitpid, wait3, wait4 | wait for process termination |
| signal    | simplified software signal facilities |
| sigaction | software signal facilities |
| sigemptyset, sigaddset | manipulate signal sets |
| kill      | send signal to a process |
| exit      | perform normal program termination |
| getcwd    | get working directory pathname |
| chdir     | change current working directory |
| stat, lstat, fstat | get file status |
| unlink    | remove directory entry |
| execve    | execute a file |
| dup, dup2 | duplicate an existing file descriptor |
| pipe      | create descriptor pair for interprocess communication |
| opendir, readdir, closedir | directory operations |
| perror, strerror |  system error messages |
| isatty, ttyname |  get name of associated terminal (tty) from file descriptor |
| [ttyslot](https://man7.org/linux/man-pages/man3/ttyslot.3.html) | find the slot of the current user's terminal in some file |
| ioctl | control device |
| getenv | obtains the current value of the environment variable, *name*. The application should not modify the string pointed to by the getenv() function. |
| tcsetattr, tcgetattr | manipulating the termios structure |
| tgetent, tgetflag,tgetnum, tgetstr, tgoto, tputs | direct curses interface to the terminfo capability database |

> **unlink** permite borrar un archivo ver [Deleting files](https://www.gnu.org/software/libc/manual/html_node/Deleting-Files.html)
> Se puede usar la carperta del sistema **/tmp/** para tener ficheros temporales y luego borrarlos con **unlink**.

#### Extracted from [Minishell by lavrenovamaria ](https://github.com/lavrenovamaria/42-minishell) 

| External functs.    | Description | Form | Header |
| --- | ----------------------- | ---------- | ---------- |
| **readline**| Prints a prompt, receives a single line of text input from the user, and returns it without line breaks. If prompt is NULL or the empty string, no prompt is issued.  The line returned is allocated with malloc(); | `char *readline (char *prompt)`   | `#include <readline/readline.h>`  |
| **rl_on_new_line**| Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline. | `int rl_on_new_line (void)`   | `#include <readline/readline.h>`  |
| **rl_replace_line**| Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared. | `void rl_replace_line (const char *text, int clear_undo)`   | `#include <readline/readline.h>`  |
| **rl_redisplay**| If non-zero, Readline will call indirectly through this pointer to update the display with the current contents of the editing buffer. By default, it is set t:wqo rl_redisplay, the default Readline redisplay function. | `void rl_redisplay(void)`   | `#include <readline/readline.h>`  |
| **add_history**| Place string at the end of the history list. The associated data field (if any) is set to NULL. If the maximum number of history entries has been set using stifle_history(), and the new number of history entries would exceed that maximum, the oldest history entry is removed. Place the string at the end of the history list. The relevant data field is set to NULL. When the number of history items exceeds the maximum, old items are deleted. | `add_history(const char *string)`   | `#include <readline/readline.h>`  |
| **wait3**| A function that waits for the child process to terminate and reports the status and resource usage of the terminated process. | `pid_t wait3(int *statloc, int options, struct rusage *rusage)`   | `#include <sys/wait.h>`  |
| **wait4**| A function that waits for the child process to terminate and reports the status and resource usage of the terminated process. | `pid_t wait4(pid_t pid, int *statloc, int options, struct rusage *rusage)`   | `#include <sys/wait.h>`  |
| **signal**| Set up signal handling. | `void (*signal(int sig, void (*func)(int)))(int)`   | `#include <signal.h>`  |
| **kill**| Unlike the kill command, which kills a process in the shell, it sends a signal to the process. Sending SIGKILL to a process acts like a shell command kill. | `int kill(pid_t pid, int sig)`   | `#include <signal.h>`  |
| **getcwd**| Copies the absolute path of the current working directory to buf and returns a pointer to buf. If buf is NULL, space is allocated and size is ignored. If the buffer is small, an error may occur, so set it large. | `char *getcwd(char *buf, size_t size)`   | `#include <unistd.h>`  |
| **chdir**| Change the current working directory. You must have execute permission on the (change directory) directory. The beginning of path must not be ' \ '. | `int chdir(const char *path)`   | `#include <unistd.h>`  |
| **stat**| A function to get the status or information of a file, such as the size, permission, creation date, and last modification date of the file. If a file that is a symbolic link is passed to path, information of the original file is obtained. lstatThe function gets information about the symbolic link file itself. | `int stat(const char *path, struct stat *buf)`   | `#include <sys/stat.h>`  |
| **lstat**| It has the same function as the stat function. If a file that is a symbolic link is passed to the path, information about the file that is a symbolic link is obtained. | `int lstat(const char *path, struct stat * buf)`   | `#include <sys/stat.h>`  |
| **fstat**| A function to obtain the status of a file or information about the file, such as the size of the opened file, the authority of the file, the creation date and time of the file, and the last modified date. | `int fstat(int fd, struct stat *buf)`   | `#include <sys/stat.h>`  |
| **open**| Open the file for use. fopen()is a function provided by the C library and open()is a function provided by Linux. | `int open (const char *FILENAME, int FLAGS[, mode_t MODE])`   | `#include <fcntl.h>`  |
| **unlink**| Delete the link. | `int unlink(const char *path)`   | `#include <unistd.h>`  |
| **close**| open() Close the file opened by the function. | `int close(int fd)`   | `#include <unistd.h>`  |
| **read**| open() Read the contents of the file opened with the function. | `ssize_t read(int fd, void *buf, size_t n)`   | `#include <unistd.h>`  |
| **write**| open() Writes to a file opened with a function. | `ssize_t write(int fd, const void *buf, size_t n)`   | `#include <unistd.h>`  |
| **malloc**| Memory is dynamically allocated. | `void *malloc(size_t size)`   | `#include <stdlib.h>`  |
| **waitpid**| wait() like a function, it waits until the child process exits. The difference is that the wait() function is released from waiting when any of the child processes exit, but waits waitpid()until the specific child process exits. | `pid_t waitpid(pid_t pid, int *status, int options)`   | `#include <sys/wait.h>`  |
| **wait**| Waits until the child process task is finished. | `pid_t wait(int *status)`   | `#include <sys/wait.h>`  |
| **free**| malloc()The calloc()memory allocated by or is returned to the system.| `void free(void *ptr)`   | `#include <stdlib.h>`  |
| **pipe**| Create a pipe and assign the fd value for the pipe to fildes.| `int pipe(int fildes[2])`   | `#include <unistd.h>`  |
| **dup**| Make a copy of the file descriptor. The read/write pointers of the original descriptor and the copied descriptor are shared.| `int dup(int fildes)`   | `#include <unistd.h>`  |
| **dup2**| Copy the file descriptor of fd and give it to fd2 as well. (so that fd2 also points to the file pointed to by fd)| `int dup2(int fildes, int fildes2)`   | `#include <unistd.h>`  |
| **execve**| Changes the process that called the execve function to a new process.| `int execve(const char *path, char *const argv[], char *const envp[])`   | `#include <unistd.h>`  |
| **fork**| Creates a copy process for the currently running process.| `pid_t fork(void)`   | `#include <unistd.h>`  |
| **strerror**| Creates a copy process for the currently running process.| `char *strerror(int errnum)`   | `#include <string.h>`  |
| **errno**| Returns: the last error number that occurred| `extern int errno`   | `#include <sys/errno.h>`  |
| **exit**| Terminate the process.| `void exit(int status)`   | `#include <stdlib.h>`  |
| **opendir**| Specified Directory Used to search for files and directories in a specific directory.| `DIR *opendir(const char *filename)`   | `#include <dirent.h>`  |
| **readdir**| opendir(). For a directory opened by, get information about all files and directories in it.| `struct dirent *readdir(DIR *dirp)`   | `#include <dirent.h>`  |
| **closedir**| opendir(). Close the directory opened with.| `int closedir(DIR *dirp)`   | `#include <dirent.h>`  |
| **isatty**|Determining whether a valid terminal type device is referenced for  `fd` | `int isatty(int fd)`   | `#include <unistd.h>`  |
| **ttyname**| isatty. If the function finds a valid device, it returns the device name.| `char *ttyname(int fd)`   | `#include <unistd.h>`  |
| **ttyslot**| When a device file is found, its unique number is returned.| `int ttyslot(void)`   | `#include <unistd.h>`  |
| **ioctl**| Functions to obtain hardware control and status information| `int ioctl(int fd, unsigned long request, ...)`   | `#include <sys/ioctl.h>`  |
| **getenv**| Find the desired variable value from the list of environment variables.| `char *getenv(const char *name)`   | `#include <stdlib.h>`  |
| **tcgetattr**| Store terminal properties for terminal file fd in termios_p| `int tcgetattr(int fd, struct termios *termios_p)`   | `#include <termios.h>`  |
| **tcsetattr**| set terminal properties for terminal file fd| `int tcsetattr(int fd, int optional_actions, const struct termios *termios_p)`   | `#include <termios.h>`  |
| **tgetent**| Extracts the input of the terminal name into the buffer `bp` .| `int tgetent(char *bp, const char *name)`   | `#include <curses.h>` `#include <term.h>` |
| **tgetflag**| Boolean information on whether is present in the terminal entry `id` .| `int tgetflag(char *id)`   | `#include <curses.h>` `#include <term.h>` |
| **tgetnum**| Numeric information about whether is present in the terminal entry `id` .| `int tgetnum(char *id)`   | `#include <curses.h>` `#include <term.h>` |
| **tgetstr**| String information on whether is present in the terminal entry `id` .| `char *tgetstr(char *id, char **area)`   | `#include <curses.h>` `#include <term.h>` |
| **tgoto**| Instantiates the parameter to the specified function. The return value is tputspassed to the function.| `char *tgoto(const char *cap, int col, int row)`   | `#include <curses.h>` `#include <term.h>` |
| **tputs**| output string returned by `tgetstr`| `int tputs(const char *str, int affcnt, int (*putc)(int))`   | `#include <curses.h>` `#include <term.h>` |


#### More info on some funtions

**isatty()** and  **ttyname()** perhaps are usefully with **PIPES**

##### isatty()

```c
#include <unistd.h>
int isatty(int fd);
```

The **isatty()** function determines if the file descriptor fd refers to a valid terminal type device.

##### ttyname()

```c
#include <unistd.h>
char *ttyname(int fd);
```

The **ttyname()** function gets the related device name of a file descriptor for which **isatty()** is true.
The **ttyname()** function returns the name stored in a static buffer which will be overwritten on subsequent calls.

##### ttyslot() 

```c
#include <unistd.h>
int ttyslot(void);
```
### Mandatory part description

Your shell should:
- Display a **prompt** when waiting for a new command.
- Have a working **history**.
- Search and launch the right executable (based on the PATH variable or using a relative or an absolute path).
- Avoid using more than one **global variable** to indicate a received signal. Consider the implications: this approach ensures that your signal handler will not access your main data structures.i

> Be careful. This global variable cannot provide any other information or data access than the number of a received signal.
> Therefore, using "norm" type structures in the global scope is forbidden.

- Not interpret unclosed quotes or special characters which are not required by the subject such as **\ (backslash)** or **; (semicolon)**.
	- > **Suposición** Deberemos gestionar el error con un mensaje propio. Ejemplo para *unclosed quotes* de *maiadegraaf*
	  > ```sh	
	  >  minishell$ "ls
	  >  minishell: syntax error: unable to locate closing quotation
	  > ```

	- >  **\ (backslash)** y **; (semicolon)** se pueden tratar como chars normales.

- Handle **’ (single quote)** which should prevent the shell from interpreting the metacharacters in the quoted sequence.
- Handle **" (double quote)** which should prevent the shell from interpreting the metacharacters in the quoted sequence except for **$ (dollar sign)**.

> **[metacharacter](https://www.gnu.org/software/bash/manual/html_node/Definitions.html#:~:text=A%20metacharacter%20is%20a%20space,'%2C%20or%20'%20%3E%20'.&text=A%20word%20consisting%20solely%20of,shell%20variable%20and%20function%20names.)** : A character that, when unquoted, separates words. A metacharacter is a **space**, **tab**, **newline**, or one of the following characters: **|**, **&**, **;**, **(**, **)**, **<**’, or **>**.

> **DUDA**: como gestionamos algo parecido a esto (cada línea es un ejemplo de comando): 
> - `ls -la ; echo ; echo "en la siguiente linea se ejecuta ls" ; ls`
>	- Probado con 
> - `'"ls"`  . Aqui *bash* entra en una especie de editor donde espera cerrar la comilla simple.

- Implement redirections:
	- *<* should redirect input.
	- *>* should redirect output.
	- *<<* should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!
		- > Creo que aqui hemos de usar el concepto de [here-document](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_07_04) de bash. Extraido de : [How does "cat << EOF" work in bash?](https://stackoverflow.com/questions/2500436/how-does-cat-eof-work-in-bash)
		- En este [Tutorial de uso de Heredoc](https://phoenixnap.com/kb/bash-heredoc) indica que la sintaxis del Heredoc es `[COMMAND] <<[-] 'DELIMITER'` . Este delimitador  **<<-** no esta contemplado en este enunciado. i
		- Casos uando el **DELIMETER** esta entre comillas ya sean simples o dobles.
			- Si aparece un **$** segido de una palbra, (Ejemplo : $VALOR) se ha de sustituir por la variable definida en *environment*
			- Las comillas se tienen en cuenta para validar el **DELIMITER** como delimitador de fin de edición del heredoc. 
 
	- *>>* should redirect output in append mode.
- Implement **pipes (| character)**. The output of each command in the pipeline is connected to the input of the next command via a pipe.
-	Handle environment variables (**$ followed by a sequence of characters**) which should expand to their values.
-	Handle **$?** which should expand to the exit status of the most recently executed foreground pipeline.
	- Para conocer el valor de salida del que genera un programa, se necesita estas macros asociadas con las diversas funciones `wait`  : `WIFEXITED` y `WEXITSTATUS`. El valor devuelto por `WEXITSTATUS` se puede asignar a una *variable global* o a una variable contenida en una *struct que se pase entre las funciones*. Ejemplo de uso (extraido de [link](https://www.ibm.com/docs/en/ztpf/1.1.0.15?topic=zca-wifexitedquery-status-see-if-child-process-ended-normally)):
		- ```c
			pid_t rc_pid;
			int   chld_state;
			...
			rc_pid = wait( &chld_state );
			if (rc_pid > 0)
			{	
			  if (WIFEXITED(chld_state)) {
				    printf("Child exited with RC=%d\n",WEXITSTATUS(chld_state));
 			}
		  ```
	- Otra posibilidad es:
		- ```c
			if (WIFEXITED(status))
				return (WEXITSTATUS(status));
			else if (WIFSIGNALED(status) && (WTERMSIG(status) == SIGINT))
				return (EXIT_FAILURE);				
		  ```
- Handle **ctrl-C**, **ctrl-D** and **ctrl-\\** which should behave like in bash.
- In interactive mode:
	- **ctrl-C** displays a new prompt on a new line.
		- Cuando se usa en `cat` , aparece en pantalla `^C`
			- **240309** Se puede solucionar usando en un fork la siguiente funcion pasando un **FALSE**  (lo ejecuta el hijo):
			- ```c
				 // If print is TRUE signals will be printed, otherwise they won't.
				 void	signals_print_handler(int print)
				 {
					struct termios	tc;

					tcgetattr(0, &tc);
					tc.c_lflag &= ~ECHOCTL;
					if (print == TRUE)
						tc.c_lflag |= ECHOCTL;
					tcsetattr(0, TCSANOW, &tc);
			 	}
			  ```
			-  **240309** Además de la función anterior, se ha de capturar el  con `signal(SIGINT, heredoc_handler);` y manejar lo que se tenga que hacer dentro de la función handler asociadad (en este caso *heredoc_handler*)
	- **ctrl-D** exits the shell. 
	- **ctrl-\\** does nothing.
		- **240309 TODO : resolverlo** Probando heardocs con *61_execve_cat_2.c* y usando `signal(SIGQUIT, SIG_IGN)` imprime lo siguiente en pantalla y se sale del programa:
		- ```sh
			bash-3.2$ ./a.out
			Emulando la instrucción 'cat << uno' ejecutandose desde un fork
			> sadff
			> Quit: 3
			bash-3.2$
		  ```
- Your shell must implement the following builtins:
	- **echo** with option **-n**
	- **cd** with only a relative or absolute path
	- **pwd** with no options
	- **export** with no options
	- **unset** with no options
	- **env** with no options or arguments
	- **exit** with no options

The `readline()` function can cause memory leaks. You don’t have to fix them. But that doesn’t mean your own code, yes the code you wrote, can have memory leaks.

#### Builtins description 

| Builtin Command | Description |
| ------------------ | ----------------- |
| **echo** | write arguments to the standard output |
| [cd](https://man7.org/linux/man-pages/man1/cd.1p.html) | change the working directory |
| **pwd** | return working directory name |
| [export](ihttps://www.man7.org/linux/man-pages/man1/export.1p.html) | set the export attribute for variables |
| [unset](https://man7.org/linux/man-pages/man1/unset.1p.html) | unset values and attributes of variables and functions |
| **env** | set environment and execute command, or print environment |
| [exit](https://man7.org/linux/man-pages/man1/exit.1p.html) | cause the shell to exit  |

### Bonus part

Your program has to implement:

- **&&** and **||** with **parenthesis for priorities**.
- Wildcards * should work for the current working directory


