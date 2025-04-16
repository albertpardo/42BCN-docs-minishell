# Hoja evaluacion Minishelll

### Compila

- Utiliza `make -n`  para verificar que la compilación utilice `-Wall -Werror -Wextra`, si no utiliza el flag de compilación inválida.
- **minishell** compila sin errores, si no, utiliza el flag apropiado.
- El Makefile no debe hacer relink. Si no, utiliza el flag apropiado.

- [ ] Yes
- [ ] No

### Comandos simples y la variable global

- Ejecuta un comando sencillo con una ruta absoluta de la forma `/bin/ls`, o cualquier otro comando sin argumentos. ¿Cuántas variables globales utiliza? ¿Por qué? Debe dar un ejemplo concreto de por qué le parece necesario o lógico.
- Compruebe la variable global. Esta variable global no puede proporcionar otra información o acceso a datos que el número de una señal recibida.
- Prueba un comando vacío.
- Prueba solo tabuladores o espacios.

- Si el programa termina, utiliza el flag de crash.
- Si algo no funciona, utiliza el flag de trabajo incompleto.

- [ ] Yes
- [ ] No

### Argumentos

- Ejecuta un comando simple con una ruta absoluta como `/bin/ls`, u otro comando con argumentos pero sin comillas simples y comillas dobles.
- Hazlo varias veces con distintos comandos y argumentos.

- Si el programa termina, utiliza el flag de crash.
- Si algo no funciona, utiliza el flag de trabajo incompleto.

- [ ] Yes
- [ ]  No

### echo

- Ejecuta el comando `echo` con o sin argumentos, y con o sin `-n`.
- Hazlo múltiples veces con distintos argumentos.

- Si el programa termina, utiliza el flag de crash.
- Si algo no funciona, utiliza el flag de trabajo incompleto.

- [ ] Yes
- [ ] No

### exit

- Ejecuta el comando `exit` con o sin argumentos.
- Hazlo varias veces con distintos argumentos.
- No olvides lanzar de nuevo minishell.

- Si el programa termina, utiliza el flag de crash.
- Si algo no funciona, utiliza el flag de trabajo incompleto.

- [ ] Yes
- [ ]  No

### Valor de retorno de un proceso

- Ejecuta una prueba simple con una ruta absoluta del tipo `/bin/ls`, o algún otro comando con argumentos pero sin comillas simples o comillas dobles. Después ejecuta `echo $`?
- Comprueba el valor devuelto. Puedes hacer lo mismo en bash y comparar ambos resultados.
- Hazlo varias veces, con distintos comandos y argumentos. Ejecuta algunos comandos que fallen como `/bin/ls archivo_que_no_existe`.
- Algo como `expr $? + $?`.

- Si el programa termina, utiliza el flag de crash.
- Si algo no funciona, utiliza el flag de trabajo incompleto.

- [ ] Yes
- [ ]  No

### Señales

- Verifica que `ctrl-C` en una entrada limpia muestra una nueva línea con una entrada limpia.
- Verifica que `ctrl-\` en una entrada limpia no hace nada.
- Verifica que `ctrl-D` en una entrada limpia termina minishell, ejecútalo de nuevo.
- Verifica que `ctrl-C` en una entrada con texto, muestra una nueva línea con una entrada limpia.
- El buffer debería limpiarse correctamente, pulsa *"enter"* para verificar que nada de lo que habías escrito se ejecute.
- Verifica que `ctrl-D` en una entrada con texto no hace nada.
- Verifica que `ctrl-\` en una entrada con texto no hace nada.
- Verifica que `ctrl-C` después de ejecutar un comando bloqueante como `cat` sin argumentos o `grep "algo"`.
- Verifica que `ctrl-\` después de ejecutar un comando bloqueante como `cat` sin argumentos o `grep "algo"`.
- Verifica que `ctrl-D` después de ejecutar un comando bloqueante como cat sin argumentos o `grep "algo"`.
- Hazlo varias veces con distintos comandos.

- Si el programa termina, utiliza el flag de crash.
- Si algo no funciona, utiliza el flag de trabajo incompleto.

- [ ] Yes
- [ ] No

### Comillas dobles

- Ejecuta un comando simple con argumentos, esta vez con comillas dobles (deberías probar a incluir espacios en blanco también).
- Un comando como `echo "cat lol.c | cat > lol.c"`
- Cualquier cosa, salvo `$`.

- Si el programa termina, utiliza el flag de crash.
- Si algo no funciona, utiliza el flag de trabajo incompleto.

- [ ] Yes
- [ ] No

### Comillas simples

- Ejecuta comandos con comillas simples como argumento.
- Prueba argumentos vacíos.
- Prueba variables de entorno, espacios en blanco, pipes y redirecciones en las comillas simples.
- `echo '$USER'` debe imprimir $USER.
- Nada debe interpretarse.

- [ ] Yes
- [ ] No

### env

- Comprueba si `env` muestra las variables de entorno actuales

- [ ] Yes
- [ ] No

### export

- Exporta variables de entorno, crea nuevas, y reemplaza viejas.
- Comprueba que funcione correctamente con `env`.

- [ ] Yes
- [ ] No

### unset

- Exporta variables de entorno, crea nuevas, y reemplaza viejas.
- Utiliza unset para eliminar algunas de ellas.
- Verifica el resultado con env.

- [ ] Yes
- [ ] No

### cd

- Utiliza el comando `cd` para cambiar de directorio de trabajo, y asegúrate de que estás en el directorio correcto con `/bin/ls`.
- Repite esto varias veces, algunas que funcionen y otras que no.
- Prueba `'.'` y `'..'` como argumentos.

- [ ] Yes
- [ ] No

### pwd

- Utiliza el comando pwd.
- Repite esto varias veces en múltiples directorios.

- [ ] Yes
- [ ] No

### Rutas relativas

- Ejecuta comandos, pero esta vez con rutas relativas.
- Repite esto múltiples veces en múltiples directorios con rutas relativas complejas (muchos ..)

- [ ] Yes
- [ ] No

### La variable de entorno PATH

- Ejecuta comandos, pero esta vez sin rutas (*ls, wc, awk, etc*).
- Elimina `$PATH` y verifica que ya no funcionen.
- Establece `$PATH` para varios directorios (`directorio1:directorio2`) y valida que los directorios se comprueban de izquierda a derecha.

- [ ] Yes
- [ ] No

### Redirecciones

- Ejecuta comandos con redirecciones `<` y/o `>`.
- Repite esto varias veces con diferentes comandos y argumentos, cambia de vez en cuando `>` por `>>`.
- Comprueba si varias redirecciones del mismo tipo fallan.
- Prueba la redirección `<<` (no necesita actualizar el historial).

- [ ] Yes
- [ ] No

### Pipes

- Ejecuta comandos con pipes como 'cat file | grep bla | more'.
- Haz esto varias veces cambiando comandos y argumentos.
- Prueba algunos comandos que fallen como `'ls archivoquenoexiste | grep bla | more'`.
- Prueba a mezclar pipes y redirecciones.

- [ ] Yes
- [ ] No

### Vuélvete loco, y el historial

-Escribe una línea de comandos, utiliza `ctrl-C` y pulsa enter. El buffer deberá estar vacío y nada deberá ejecutarse.
- ¿Puedes navegar en el historial con las flechas de arriba y abajo ¿Puedes volver a probar algún comando?
- Ejecuta comandos que no deberían funcionar como `'wjkgjrgwg4g43go34o'` y verifica que minishell no termina y muestra un error.
- `"cat | cat | ls"` se comporta de forma *"normal"*.
- Prueba a ejecutar un comando largo con muchísimos argumentos.
- Pásatelo bien con este increíble minishell y disfruta.

- [ ] Yes
- [ ] No

### Variables de entorno

- Ejecuta `echo` con algunas `$` variables como argumentos.
- Verifica que `$` se interpreta como una variable de entorno.
- Verifica que las comillas dobles interpolan `$`.
- Verifica que `$USER` existe o créalo.
- `echo "$USER"` deberá imprimir el valor de `$USER`.

- [ ] Yes
- [ ] No

## Bonus

- Se tendrá en cuenta tus bonus si y solo si la parte obligatoria está PERFECTA. Por PERFECTA queremos naturalmente decir que la parte obligatoria está completa, de principio a fin, y la gestión de errores es impecable, incluso en casos retorcidos o de mal uso. Si no has conseguido todos los puntos de la parte obligatoria, la parte bonus será completamente ignorada.

### And, Or

- Utiliza &&, || y paréntesis con comandos y verifica que funciona como en bash.

- [ ] Yes
- [ ] No

### WildCard

- Utiliza wildcards en argumentos para el directorio actual.

- [ ] Yes
- [ ] No

### ¡Sorpresa! (O no...)

- Establece la variable de entorno `USER`.
- Prueba `echo "'$USER'"`, esto deberá imprimir `'VALOR_DE_USER'`.
- Prueba `echo '"$USER"'`, deberá imprimir `"$USER"`.

- [ ] Yes
- [ ] No
