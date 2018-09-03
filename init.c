#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
  pid_t p;
	int status;
  int counter;
  int i;

  for(i = 1; i<7; i++)
  {
  	printf("Hola, soy el proceso %d\n hijo# %d\n",getpid(), i);
  	// system("./holamundo"); // Llamada prohibida en la práctica 2
  	p=fork();
  	if(p==0)
  		//execlp("./holamundo","holamundo",NULL);
      execlp("/usr/bin/xterm", "xterm", "-e", "./ejemplo10", NULL);
  	wait(&status);
    //wait(NULL);
  	printf("Adios, soy el proceso %d\n",getpid());
  }
  return 0;
}
