#  Resources

This document is online on this link [hackmd.io - resources Minishell](https://hackmd.io/AjMnIfyBS6m03duCMxFALA?both)

## Readline

Mirar esta carpeta:

`/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/readline/readline.h`

- [Readline by Jon Perez](https://03-jon-perez.gitbook.io/coding-library/c/readline)
- [Programming with GNU Readline](https://web.mit.edu/gnu/doc/html/rlman_2.html)

## General Minishell resources

### Articles

- Instalar cualquier software en ordenadorres de 42 sin ser administrador : [Overcoming Space & Admin Restrictions: A Guide to Flexible Software Installation](https://medium.com/@md.abir1203/overcoming-space-admin-restrictions-a-guide-to-flexible-software-installation-25c7194d2cb5)
- [Minishell: Building a mini-bash (a @42 project) by MannBell](https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218)
- [42Cursus-Minishell by Achrafbelarif](https://achrafbelarif.medium.com/42cursus-minishell-29cd25f972e6)

- Descripcion de las funciones autorizadas [Minishell by Jseo Doodle](https://bigpel66.oopy.io/library/42/inner-circle/10)

### Only Github

A list of Minishell links for topic **minishell-42**. See : https://github.com/topics/minishell-42

- Con links y ejemplos para test  [Kuninoto](https://github.com/Kuninoto/42_minishell)
	- > Su definicion de [structuras](https://github.com/Kuninoto/42_minishell/blob/master/lvl_3_minishell/includes/minishell.h) parece más simple que la de [maia](https://github.com/maiadegraaf/minishell/blob/main/includes/parser.h)

- Dan una idea para debugar Minishell con VSCode (extraido de slack)[Debug throught VSCode](https://github.com/waltergcc/42-Small-Tutorials/tree/main/Debug-throught-VSCode)
- Comenta como instalar readline [Minishell42](https://github.com/tjensen42/42-minishell#install-readline-on-42-macs)
- [Minishell_42 by Hamzaelkhatri](https://github.com/Hamzaelkhatri/minishell). There are some resources links.
- Tiene una carpeta con ficheros de test[Minishell_42 by tjensen42](https://github.com/tjensen42/42-minishell)

- Usa *isatty*, *termios struct*  [Minishell by sophiakoulen](https://github.com/sophiakoulen/minishell)
- Usa *isatty*  y presenta algunos ejemplos para testear Minishell [Minishell by titouanck](https://github.com/titouanck/42-Minishell)

### Videos

- [Conférences 42sh 2019 - Architecture d'un shell](https://www.youtube.com/watch?v=oIFRiwFRSRY)
- [Lista de videos para Minishell by eleman](https://www.youtube.com/playlist?list=PLGU1kcPKHMKj5yA0RPb5AK4QAhexmQwrW)

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

### Test Comands 

#### by Gaspachow/minishell-42 [Test Comands](https://codesandbox.io/p/sandbox/gaspachowminishell-42-04ns1?file=%2Fcorrection%2Ftest_commands) 

```shell
---- Test commands for each part of the subject ----

- SIMPLE COMMAND:
/bin/ls
clear

- ARGUMENTS:
ls .
ls ..
ls parser
cat correction/test_commands
grep bin correction/test_commands


- ECHO:
echo
echo -n
echo -n -n -n ok
echo ok bonjour
echo salut coucou Woop woop -n

- EXIT (don't forget to relaunch minishell after each exit, test with echo $? in bash after each exit):
exit
exit 130
exit wow
exit 1 yo
exit 12 49
exit 255


- RETURN VALUE OF PROCESS:
ls
echo $?

ls oegohe
echo $?

echo cool
echo $?

./minishell
exit 42
echo $?

- SEMICOLONS:
ls . ; ls .. ; cat correction/test_commands ; ls parser
cat ; cat ; echo -n "salut " ; echo cher correcteur ; ls
cat;cat;echo -n "salut "; echo cher correcteur ;ls


- SIGNALS (blocking command to test):
cat
grep
./minishell

- DOUBLE QUOTES:
echo "bonjour l'ami"
echo "wowie!"
echo "allez bonjour ""trop bien" ok" salut"
echo " wow \" top \\" "test du \test \ \\ ok \" \" \' "

- ENV:
env
env | grep PATH

- EXPORT:
export test=ok
echo $test
export test
echo $test
export test=diff
echo $test

- UNSET :
env | grep test
unset test
env | grep test
echo $test

- ENV VARIABLE:
echo $PATH
export ok="woooow salut! ok..."
echo $ok
export ok="-YO-"
echo " topitop $ok cool \$ok cool \\$ok \\\$ok"

- CD and PWD:
cd ..
ls
pwd
cd minishell
ls
pwd
cd
ls
pwd
cd -
ls
pwd
ls parser
pwd ..
pwd parser
pwd .
ls

- Relative PATH:
./minishell
exit
cd parser
../minishell
exit
cd ..

- ENV PATH:
ls
clear
cat main.c
wc
awk
env | grep PATH
unset PATH
ls
wc
cat
export PATH=(include here multiple directories previous env | grep PATH printed)

- SIMPLE QUOTES:
echo 'coco'
echo 'coco \\ wow $ok'
echo ' salut " hoho ''ok ok'
echo ''
cat ''
echo ' ok ; wow ; cat ; ls ; echo $ok'

- REDIRECTION:
echo bonjour > fichier
cat < fichier
cat < fichier > test
cat < test >> fichier
cat < test
cat < fichier
cat < test < test < test < test < test < test
cat < test < test < test < test < fichier
cat < test > a1 > a2 >> a3 > a4 >> a5 > a6

- PIPES:
cat a6 | grep bonjour
cat main.c | grep int
cat correction/test_commands | grep cat
ls | cat | grep m
ls pjoqfpoj | grep bla | cat
cat main.c | grep char > mainchar.txt
ls | cat > ls.txt
ls | cat | cat >> ls.txt
cat < ls.txt | grep m

- CRAZY:
fohreogharpgh
cat main.c parser/parser.c parser/parser_delegator.c parser/input_split.c ; echo wow wowow w w w w w w w w w  w w w w w w  w w w w w w  w w w w  w w w  w w w w  w w ok o k ok ok o ko k ok ok o ko k ok ok o ko k ok ok o ko k ok ok o ko k okkk
```
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
