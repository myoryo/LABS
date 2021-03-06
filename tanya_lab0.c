#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

 
int main(int argc, char* argv[]) 
{
	pid_t pid = fork();

	if ( pid == 0 ) {
		execvp(argv[1], &argv[2]);
	}
	if(pid ==-1){
		printf("Process was not created");
		exit(-1);	
	}
	if (pid>0){
		int status;
		waitpid(pid, &status, 0);
		if ( WIFEXITED(status) ) {
			int exit_status = WEXITSTATUS(status);
			printf("Exit status of the child was %d\n", exit_status);
		}
	}
	return 0;
} 
