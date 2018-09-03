#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define FULL_LENGTH 101
#define USPASS_LENGTH 50

int main()
{
  int status;
  int comparer = 0;
  while(1)
  {
    //We open the user-password file and save them
    char *file_name = "passwd.txt";
    FILE * passf = fopen(file_name, "r");
    if(!passf)
      return 0;
      //Varibles to save the strings of users and passwords
      char users[USPASS_LENGTH], passwords[USPASS_LENGTH];

      printf("Usuario: ");
      scanf("%s", users);
      printf("Password: ");
      scanf("%s", passwords);

      //Variables that compare users and passwords together
      char UsPass[FULL_LENGTH], SavedUsPass[FULL_LENGTH];

      //concatenates user and password together so its ready to compare
      strcpy(UsPass, users);
      strcat(UsPass, ":");
      strcat(UsPass, passwords);
      strcat(UsPass, "\n");

      comparer = 0;
      while(fgets(SavedUsPass, sizeof(SavedUsPass), passf))
      {
        if(strcmp(UsPass, SavedUsPass) == 0)
          comparer = 1;
      }
      if(comparer != 0)
      {
        pid_t child = fork();
		if(child == 0)
			execlp("/usr/bin/xterm", "xterm", "-e", "./sh", NULL );
	 wait(&status);
      }
  }
}
