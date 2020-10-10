#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <malloc.h>
int main(void)

{
    //int open(const char *path, int oflag, mode_t mode);
    int fd;
    printf("Hello world!\n");
    fd=open("textfile.txt", O_RDONLY);
    if(fd==-1) {
        printf("Cannot open file.\n");
        exit(1);
    }

    int charNum = lseek(fd, 0, SEEK_END);
    lseek (fd, 0, SEEK_SET);

    char buf[charNum];
    read(fd, buf, charNum);
    
    int stringCounter = 0;
    for (int counter = 0; counter < charNum; counter++)
    {
        if (buf[counter]=='\n')
            ++stringCounter;
        printf("%c", buf[counter]);
    }

    int t = 1;
    int stringBeginPos[stringCounter];
    stringBeginPos[0] = 0;
    int localStringCounter = 1;
    
    for (int counter=0; counter < charNum; counter++)
    {
     /*   if(buf[counter]=='\0'){
            stringBeginPos[localStringCounter++] = counter + 1;
            t=0;
        }*/
        
        if ((buf[counter]=='\n')  )
        {
            
            stringBeginPos[localStringCounter++] = counter + 1;
        
            
        }    
    }
    /*{
        
        if ((buf[counter]=='\0' && firststring==true) || buf[counter]=='\n')
        {
            stringBeginPos[localStringCounter++] = counter + 1;
        }    
    }*/

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
    

    /*lseek(fd,stringBeginPos[choosenString-1],SEEK_SET);
    char ch;
    ssize_t ret;
    while ((read (fd, &ch, 1)) > 0 || ch == '\n')
	{
        putchar(ch);
    }*/
    printf("\nGoodbye world!\n");
    return(0);
}
