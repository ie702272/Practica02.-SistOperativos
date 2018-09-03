#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define XTERM_PATH "/usr/bin/xterm"
#define XTERM "xterm"

char EXIT[15];
char SHUTDOWN[15];
char command[15] = {0};



int main()
{
	strcpy(EXIT, "Exit");
	strcpy(SHUTDOWN, "Shutdown");
	
	while(1){
	printf("Enter command: ");
	gets(command);

	if(!strcmp(EXIT, command)){
		exit(0);
	}
	else if(!strcmp(SHUTDOWN, command) ){
		printf("apagar\n");
	}
	else if((command[0]=='.'||command[0]=='/')&&command[1]!=0){
		execlp( XTERM_PATH, XTERM, "-e", command, NULL );
	}
		
    }
}


