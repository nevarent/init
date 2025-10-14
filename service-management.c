// NOT INCLUDED IN init.c YET
// REQUIRES CODE MODIFICATIONS (change main() name and other minor stuff)
// TODO: MAKE HEADER FILE AND MAKE USE OF config.h

// parse and execute services
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

//#include "config.h"

#define MAX_ARGS 64
#define MAX_BUFFER 256

int main()
{
	FILE *serviceFile;
	char lineBuffer[MAX_BUFFER];

	//serviceFile = fopen(*fileLocation, "r");
	serviceFile = fopen("/etc/rc.local", "r");
	if (serviceFile == NULL)
	{
		fprintf(stderr, "Unable to read services file (/etc/rc.local). Does it exist?\n");
		return 1;
	}




		// process every line of *fileLocation
	while (fgets(lineBuffer, sizeof(lineBuffer), serviceFile) != NULL)
	{
			// skip line if it begins with # or //
			// TODO: improve this garbage
		if (lineBuffer[0] == '\n' || lineBuffer[0] == '#' || (lineBuffer[0] == '/' && lineBuffer[1] == '/'))
		{
			continue;
		}

			// remove newline character at the end of the string
		lineBuffer[strcspn(lineBuffer, "\n")] = 0;


			// switching to pointer to lineBuffer for efficiency
		char *command = lineBuffer;
			// skip spaces and tabs at line beginning: POINTER++ until it points to a real character
		while (*command == ' ' || *command == '\t')
		{
			command++;
		}

			// skip line if it's empty after this stage
		if (*command == '\0')
		{
			continue;
		}
			// self-explanatory
		printf("[service] Executing %s\n", command);




			/*	forking to tokenize and execute command	*/
		pid_t servicePid = fork();
		if (servicePid == -1)
		{
			fprintf(stderr, "[service] Fork failed!!!\n");
		}

			// in child
		else if (servicePid == 0)
		{
			char *args[MAX_ARGS];
			int argCount = 0;

				// tokenizer, parse entire string into arguments
			char *token = strtok(command, " ");
			while (token != NULL && argCount < MAX_ARGS-1)		// MAX_ARGS-1 cause null terminator must fit
			{
				args[argCount++] = token;
				token = strtok(NULL, " ");	// reminder for me: NULL is required to continue
								// tokenizing the same string
			}
			args[argCount] = NULL;			// null terminator

				// execute
			execvp(args[0], args);

			fprintf(stderr, "[service] Failed to execute!!!\n");	// in case execvp returns
										// (unreachable if executes)
		}


			// wait for the forked daemon to finish
		int pidStatus;
		waitpid(servicePid, &pidStatus, 0);

			// check if process exited successfully
		if (WIFEXITED(pidStatus) != 1)
		{
			fprintf(stderr, "[service] Process exited abnormally!!!\n");
		}


			// small delay
		usleep(10000);
	}

	fclose(serviceFile);
	return 0;
}
