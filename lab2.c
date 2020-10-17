#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <malloc.h>
#include <sys/stat.h>
#include <sys/mman.h>
int main(void)

{
    int fd;
    printf("Hello world!\n");
    fd=open("textfile.txt", O_RDONLY);
    if(fd==-1) {
        printf("Can't open file.\n");
        exit(1);
    }

    struct stat fileStat;
    fstat(fd, &fileStat);
    size_t charNum = fileStat.st_size;

    char *buf;
    buf = mmap (0, charNum, PROT_READ, MAP_SHARED, fd, 0);
    
    int stringCounter = 0;
    for (int counter = 0; counter < charNum; counter++)
    {
        if (buf[counter]=='\n')
            ++stringCounter;
        printf("%c", buf[counter]);
    }

    int stringBeginPos[stringCounter];
    stringBeginPos[0] = 0;
    int localStringCounter = 1;
    
    for (int counter=0; counter < charNum; counter++)
    {
        if ((buf[counter]=='\n')  )
        {
            
            stringBeginPos[localStringCounter++] = counter + 1;
        
            
        }    
    }

    for (int counter = 0; counter < stringCounter; ++counter)
    {
        printf("%d\n", stringBeginPos[counter]);
    }

    

    int choosenString = 1;

    while (0==0)
    {
        printf("\n\nВведите номер строки для вывода (1-%d) или 0 для выхода из программы: ", stringCounter);
        scanf("%d", &choosenString);
        if (choosenString == 0)
            break;
        if (choosenString > stringCounter)
        {
            printf("Слишком большое значение");
            continue;
        }
        for (int counter = stringBeginPos[choosenString-1]; buf[counter]!='\n'; counter++)
            printf("%c", buf[counter]);
    }
    
    printf("\nGoodbye world!\n");
    return(0);
}
