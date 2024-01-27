#  Resources

This document is online on this link [hackmd.io - resources Minishell](https://hackmd.io/AjMnIfyBS6m03duCMxFALA?both)

## Readline

Mirar esta carpeta en el iMAC de 42 Barcelona:

`/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/readline/readline.h`

- [Readline by Jon Perez](https://03-jon-perez.gitbook.io/coding-library/c/readline)
- [Programming with GNU Readline](https://web.mit.edu/gnu/doc/html/rlman_2.html)

## General Minishell resources

### Articles

- Instalar cualquier software en ordenadorres de 42 sin ser administrador : [Overcoming Space & Admin Restrictions: A Guide to Flexible Software Installation](https://medium.com/@md.abir1203/overcoming-space-admin-restrictions-a-guide-to-flexible-software-installation-25c7194d2cb5)
- [Minishell: Building a mini-bash (a @42 project) by MannBell](https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218)
- [42Cursus-Minishell by Achrafbelarif](https://achrafbelarif.medium.com/42cursus-minishell-29cd25f972e6)

- Descripción de las funciones autorizadas [Minishell by Jseo Doodle](https://bigpel66.oopy.io/library/42/inner-circle/10)

- [Building a shell commands interpreter similar to BASH from scratch with C (Part 1 Theory) by hel-mefe](https://medium.com/@hichamelmefeddel/building-a-shell-commands-interpreter-similar-to-bash-from-scratch-with-c-part-1-theory-64fdc141617d)
	- [GitHub Minihshell by hel-mefe](https://github.com/hel-mefe/Minishell-42)
	- > *240125* : Este artículo ha dado la idea de como solucionar el tema de *here doscuments* usando *C* . Se ha de utilizar **readline()** imprmimiendo el mismo prompt que imprime *bash* cuando entra en modo  *here doscuments*. Esto parece coincidir con el Tip del subject donde indica : **<** *should be given a delimiter, then read the input until a line containing the delimiter is seen. However, it doesn’t have to update the history!*

- Consulta sobre *Here Documents* in c [Automate C program standard inputs with bash](https://www.codeproject.com/Questions/5300405/Automate-C-program-standard-inputs-with-bash) 
	- > *240125* : Una de las respuestas indica como implementar el comportamiento de `<<` usando bash.

### Github or similar

A list of Minishell links for topic **minishell-42**. See : https://github.com/topics/minishell-42

- Con links y ejemplos para test  [Kuninoto](https://github.com/Kuninoto/42_minishell)
	- > Su definicion de [structuras](https://github.com/Kuninoto/42_minishell/blob/master/lvl_3_minishell/includes/minishell.h) parece más simple que la de [maia](https://github.com/maiadegraaf/minishell/blob/main/includes/parser.h)

- Dan una idea para debugar Minishell con VSCode (extraido de slack)[Debug throught VSCode](https://github.com/waltergcc/42-Small-Tutorials/tree/main/Debug-throught-VSCode)
- Comenta como instalar readline [Minishell42](https://github.com/tjensen42/42-minishell#install-readline-on-42-macs)
- [Minishell_42 by Hamzaelkhatri](https://github.com/Hamzaelkhatri/minishell). There are some resources links.
- Tiene una carpeta con ficheros de test[Minishell_42 by tjensen42](https://github.com/tjensen42/42-minishell)
- Usa *isatty*, *termios struct*  [Minishell by sophiakoulen](https://github.com/sophiakoulen/minishell)
- [Minishell by gmartin](https://github.com/gemartin99/Minishell)
- [Github by alajara team](https://github.com/LAG-jara/minishell) y un [Manual del proyecto](https://github.com/Liam-McHara/minishell-manual/blob/main/manual.md)

### Videos

- [Conférences 42sh 2019 - Architecture d'un shell](https://www.youtube.com/watch?v=oIFRiwFRSRY)
- [Lista de videos para Minishell by eleman](https://www.youtube.com/playlist?list=PLGU1kcPKHMKj5yA0RPb5AK4QAhexmQwrW)

- [My own shell by tnam](https://www.youtube.com/watch?app=desktop&v=DaiAOOJ5oR4). Hace una comparativa simultanea del comportamiento de su *minishell* con el *bash*. Para ello , activa una ventana con dos terminales y hace que lo que escriba en su terminal con *minishell* aparezca a la vez en el otro terminal con *bash* (en Mac se consigue con **Cmd + Option + i**  y se desactiva con el mismo combinación)
	> Interesante por que implementa la siguiente instrucción : `< infile cat | cat -e << here1 | cat -e | cat -e > outfile`. [link minuto donde lo hace](https://www.youtube.com/watch?app=desktop&v=DaiAOOJ5oR4) [link desde el  minuto donde lo hace](https://www.youtube.com/watch?app=desktop&v=DaiAOOJ5oR4). **DUDA CON LOS DIRECCIONAMIENTOS **
	> He realizado un par de modificaciones de la instrucción anterior en bash y su comportamiento en bahs es diferente a la instrucción `< infile cat | cat -e << here1 | cat -e | cat -e > outfile`:
	> - `cat | cat -e << here1 | cat -e | cat -e < infile > outfile`
	> - `cat | cat -e << here1 | cat -e | cat -e > outfile < infile`

#### 240109 by Sergio

- [OS Miniproyecto MiniShell 2021 01](https://www.youtube.com/watch?v=2pTLmw9E30o)
- [Proyecto "Mini Shell".](https://www.youtube.com/watch?v=6Nd7pbMwHU4)
- [shell desarrollada en C](https://www.youtube.com/watch?v=xxCyAUix8WA&t=106s)
- [Un shell básico en C](https://www.youtube.com/watch?v=THcaaF6Gj0w&t=159s)

#### 240110 by Sergio
- [Writing a Simple Shell](https://www.youtube.com/watch?v=z4LEuxMGGs8)

##### MIT

- [Shell Program Explained](https://www.youtube.com/watch?v=ubt-UjcQUYg)
- [Shell Code-- More Detail](https://www.youtube.com/watch?v=ZjzMdsTWF0U&t=660s)
- [github SHELL MIT - xv6](https://github.com/mit-pdos/xv6-public)

#### 240115 by Sergio

- [Serie de videos : Write Your Own Shell by Jess-Inspired](https://www.youtube.com/watch?v=cIBmeEpsMj0&list=PLxIRFba3rzLzxxZMMbrm_-mkI7mV9G0pj)

### Testers

> **231231 : 42 HA PEDIDO QUE RETIRE EL REPOSITORIO** 
>
> This github contains evaluation sheets for 42 : https://github.com/rphlr/42-Evals.git

Use mainly a 42 evaluation sheet to check this project.
- [Minishell evaluation in french](https://github.com/rphlr/42-Evals/tree/main/Cursus/Minishell) **231231 : 42 HA PEDIDO QUE RETIRE EL REPOSITORIO** 

Next list of tests is only to detect important issues in our program:

- https://github.com/ethanolmethanol/minishell42tester
- Minishell-test:
	- https://pypi.org/project/minishell-test/
    - [minishell-test Documentation](https://minishell-test.readthedocs.io/en/latest/)

## Markdown resources

### Online Markdown editors to collaborative editing

Several Markdown online editor to edit online in collaborative way. 
Posibilities : free & paid mode. Some its necesary to sign in to store documents in the site.


- [peerpad](https://peerpad.net)
- https://onlinemarkdowneditor.dev/
- https://stackedit.io/
- https://hackmd.io/
- https://cryptpad.fr/
