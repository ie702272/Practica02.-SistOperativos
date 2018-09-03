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
  	printf("Hijo# %d\n", i);
  	p=fork();
  	if(p==0)
		execlp("/usr/bin/xterm", "xterm", "-e", "./getty", NULL);
  	}
  while(1){
	 wait(&status);
	 p=fork();
  	 if(p==0)
		execlp("/usr/bin/xterm", "xterm", "-e", "./getty", NULL);
	}
  return 0;
}
