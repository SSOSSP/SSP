/*
 * thread_test1.c
 *
 *  Created on: 2017. 4. 25.
 *      Author: LGCNS
 */
#include<stdio.h>
#include<pthread.h>
long nNumber = 0;
pthread_mutex_t mutx;
void * minus(void* arg);
void * plus(void* arg);
void __attribute__((constructor))console_setting_for_eclipse_debugging(void)
{
	setvbuf(stdout,NULL, _IONBF,0);
	setvbuf(stderr,NULL, _IONBF,0);
}
void * minus(void* arg)
{
	int i;
	for(i= 0; i<100000; i++)
	{

		pthread_mutex_lock(&mutx);

		nNumber--;
		printf("[THREAD1]%ld, %d\n",nNumber, i);
		pthread_mutex_unlock(&mutx);


	}

	return NULL;

}
void * plus(void* arg)
{
	int i;
	for(i= 0; i<100000; i++)
	{

		pthread_mutex_lock(&mutx);
		nNumber++;
		printf("[THREAD2]%ld, %d\n",nNumber, i);
		pthread_mutex_unlock(&mutx);


	}

	return NULL;

}
int main()
{
	pthread_t thread;
	pthread_t thread2;
	int *status, *status2;

	pthread_mutex_init(&mutx,NULL);
	pthread_create(&thread, NULL, minus, NULL);
	pthread_create(&thread2, NULL, plus, NULL);

	pthread_join(thread, (void**)&status);
	pthread_join(thread2, (void**)&status2);

	printf("%ld",nNumber);

	pthread_mutex_destroy(&mutx);
	return 0;
}

