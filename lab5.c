#include <sys/fcntl.h>
#include <signal.h>
#include <sched.h>
#include <ctype.h> 
#include <stdio.h>
#include <unistd.h>
#include <string.h>


void main(int argc, char* argv[]) {

    int fdpipe[2];
    pipe(fdpipe);
    if(fork()>0) { 

        char str[] = "text TEXT te2Xt"; 
        close(fdpipe[0]); /*закрывает неиспользуемый конец для чтения */
        write(fdpipe[1], str, sizeof(string));

    }
    else { 
        close(fdpipe[1]); /*закрывает неиспользуемый конец для записи */
        char text[15]; 
        int size = read(fdpipe[0], text, 15);
        for(int counter = 0; counter<size; counter++) 
        {
            printf("%c", toupper(text[counter]));
        }
    }
}
