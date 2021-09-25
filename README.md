Ejercicio 1: Hello World.

a) El siguiente código resuelve un saludo en paralelo de todos los procesos que
trabajan en paralelo

#include<stdio.h> #include<mpi.h>
main(int argc, char **argv){
int node;
MPI_Init(&argc, &argv); MPI_Comm_rank(MPI_COMM_WORLD, &node); printf("Hello World fromNode %d\n",node); MPI_Finalize();
}

Ejecutar el programa para distinta cantidad de procesos. Analizar la salida de las ejecuciones y compararlas entre ellas.

b) Modificar el programa anterior de manera que los procesos paralelos envíen el mensaje de saludo “Saludos desde el proceso #” al Proceso 0, quien será el responsable de imprimirlo en la salida estándar. La salida tendrá las siguientes características:

Hola, soy el proceso 0 (hay “n” procesos) y recibo: (Hola desde el proceso #) (Hola desde el proceso #)
...

c) Modificar el programa anterior, de manera tal que sea posible recibir e imprimir los mensajes enviados al Proceso 0 en orden ascendente. Es decir, para cuatro procesos la salida debería ser la siguiente:

Hola, soy el proceso 0 (hay 4 procesos) y recibo: (Hola desde el proceso 1) (Hola desde el proceso 2) (Hola desde el proceso 3) (Hola desde el proceso 4)

d) ¿Qué modificaciones debe hacer al programa anterior para que el proceso responsable de imprimir es otro proceso distinto del Proceso 0? Realícelas.
