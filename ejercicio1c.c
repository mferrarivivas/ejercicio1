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

if ( node==0 ) {

  printf("Hola, soy el proceso %d (hay %d procesos) y recibo:\n",node, numtasks);
  int i=1;
  while(i<numtasks){
    MPI_Recv(mensaje, 23, MPI_CHAR, i, 0, MPI_COMM_WORLD, &status);
    printf("%s\n",mensaje);
    i++;
   }
}
else{
  char otro[3];
  sprintf(otro, "%d", node);
  strcat(mensaje,otro);
  strcat(mensaje,")");
  MPI_Send(mensaje, 23, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
}


MPI_Finalize();

}


