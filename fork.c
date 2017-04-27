#include <stdio.h>
#include <stdlib.h>


void __attribute__((constructor))console_setting_for_eclipse_debugging(void)
{
	setvbuf(stdout,NULL, _IONBF,0);
	setvbuf(stderr,NULL, _IONBF,0);
}
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
void* main_func()
{
	int nCount=0;
	char ch;
	while(1)
	{
		printf("I'm main thread\n");
		//죽는 코드
		/*if(nCount++ ==10)
		{
			memcpy(ch,"1",1);
		}*/
		sleep(1);
	}
}
int main()
{
    int pid;
    int status;
    pthread_t thread;
    while(1)
    {
		pid = fork();

		if (pid < 0)
		{
			perror("fork error : ");
			exit(0);
		}
		if (pid == 0)
		{
			printf("Im Child\n");
			pthread_create(&thread, NULL, main_func, NULL);
			pthread_join(thread,NULL);
			return 2;
		}
		else
		{
			printf("Parent: wait (%d)\n", pid);
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
			{
				printf("정상종료\n");
				printf("리턴값 %d\n", WEXITSTATUS(status));
			}
			else
			{
				printf("죽음 되살림\n");
				printf("리턴값 %d\n", WEXITSTATUS(status));
			}
		}
    }
    exit(0);
}
