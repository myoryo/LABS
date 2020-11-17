#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/fcntl.h>
#include <semaphore.h>


int main(int argc, char* argv[]) {
	sem_t *sem1;
	sem_t *sem2;
	char *name1 = "/sem1";
	char *name2 = "/sem2";
	sem1 = sem_open(name1, O_CREAT | O_EXCL, O_RDWR, 0); //O_EXCL - если имя такое уже есть то вернется ошибка
	sem2 = sem_open(name2, O_CREAT | O_EXCL, O_RDWR, 1);
	int n = 3; //сколько логов надо
	if(fork()) {
		for(int i = 0; i<=n; i++){
			sem_wait(sem1); //уменьшаем(блокируем)
			FILE *f = fopen("log.txt", "a+"); //открыть
			fprintf(f, "Log %d\n", getpid()); //типа лог
			fclose(f); //закрыть
			sem_post(sem2); //увеличиваем
		}
	} 
	else {
		for(int i = 0; i<=n; i++){
			sem_wait(sem2);
			FILE *f = fopen("log.txt", "a+");
			fprintf(f, "Log %d\n", getpid());
			fclose(f);
			sem_post(sem1);
		}

	}
	sem_unlink(name1);
	sem_unlink(name2);
}
