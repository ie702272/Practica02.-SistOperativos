#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
  pid_t p;
  int status;
  int i;
//open files for saving pids
  FILE *f = fopen("pids.txt", "w");
  FILE *fp = fopen("pidPadre.txt", "w");

//save father pid
  fprintf(fp, "%d\n",getpid());
  fclose(fp);
    
for(i = 1; i<7; i++)
  {
//fork for creating childs
  	printf("Hijo# %d\n", i);
  	p=fork();
	
  	if(p==0){
//save child pid and exec getty
		fprintf(f, "%d\n",getpid());
 		fclose(f);
		execlp("/usr/bin/xterm", "xterm", "-e", "./getty", NULL);
		}
  	}
//if exec window is closed, continue having 6 childs
  while(1){
	 wait(&status);
	 p=fork();
  	 if(p==0){
		fprintf(f, "%d\n",getpid());
 		fclose(f);
		execlp("/usr/bin/xterm", "xterm", "-e", "./getty", NULL);
		}
	}
	
 return 0;
}
