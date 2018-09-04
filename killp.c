#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
int main(){
//read .txt files with child pids and the other with father pid
	FILE* file1 = fopen("pids.txt", "r"); 
	FILE* file2 = fopen("pidPadre.txt", "r"); 
    	char number[16];
	while(fgets(number,16,file1)){
		kill(atoi(number), SIGTERM);
	}
	fclose(file1);
	while(fgets(number,16,file2)){
		kill(atoi(number), SIGTERM);
	}
    	fclose(file2);

    return 0;
}
