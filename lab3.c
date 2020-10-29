#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
char *strtok(char *str, const char *sep); 
int main(int argc, char *argv[]) {
    
    int n=1;
    while(argv[n]!=NULL){
        struct stat buff;
        stat(argv[n], &buff);
        char *tp;
        char size[100]={};  

        if(S_ISREG(buff.st_mode)==1){ //обычный файл
            tp = "-";
            sprintf(size,"%ld",buff.st_size);
        }
        else if(S_ISDIR(buff.st_mode)){ // папка
            tp="d";
        } 
        else tp="?"; 
    
        char *access; //доступ
        if(buff.st_mode & S_IRUSR){ 
            access="r";
        }
        else if(buff.st_mode & S_IWUSR){
            access="w";
        }
        else if(buff.st_mode & S_IXUSR){
            access="x";
        }
        else{
            struct passwd *pw = getpwuid(buff.st_uid);
            struct group  *gr = getgrgid(buff.st_gid);
            access=strcat(pw->pw_name," ");
            access=strcat(access,gr->gr_name);
        }
        time_t lt; //последняя модификация
        lt = buff.st_mtime;
        char *time = ctime(&lt);
        time = strncpy(time,time,strlen(time)-3);

        char pars[] ="/"; //название файла
        char *str;
        str = strtok(argv[n],pars);
        char *name;
        do {
            name = str;
            str=strtok(NULL,pars);
        } while (str!=NULL);
        n++;
        printf("| %s | %10s | %10s | %10s | %s\n",tp, access, size, name, time );
    }
   
}