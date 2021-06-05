#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<mpi.h>

void main(int argc, char **argv){

int node, numtasks;
char mensaje[23]="(Hola soy el proceso ";
MPI_Status status;

MPI_Init(&argc, &argv);

MPI_Comm_size(MPI_COMM_WORLD, &numtasks);

MPI_Comm_rank(MPI_COMM_WORLD, &node);

if(argc!=2) {
  printf("Falta especificar el numero de proceso que imprimira.\n"); 
  exit(1);
} 

if ( node == atoi(argv[1]) ) {

  printf("Hola, soy el proceso %d (hay %d procesos) y recibo:\n", node, numtasks);
  int i=0;
  while(i<numtasks){
    if (i != atoi(argv[1])){
      MPI_Recv(mensaje, 23, MPI_CHAR, i, 0, MPI_COMM_WORLD, &status);
      printf("%s\n",mensaje);
    }
    i++;
   }
}
else{
  char otro[3];
  sprintf(otro, "%d", node);
  strcat(mensaje,otro);
  strcat(mensaje,")");
  MPI_Send(mensaje, 23, MPI_CHAR, atoi(argv[1]), 0, MPI_COMM_WORLD);
}


MPI_Finalize();

}

