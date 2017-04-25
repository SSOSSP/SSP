/*
 * goodsViewer.c
 *
 *  Created on: 2017. 4. 12.
 *      Author: LGCNS
 */


#include<stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include"./client.h"
void __attribute__((constructor))console_setting_for_eclipse_debugging(void)
{
	setvbuf(stdout,NULL, _IONBF,0);
	setvbuf(stderr,NULL, _IONBF,0);
}


void* inputMenuLoop();
void printMenu();
void requestGoods();
int main(int argc, char **argv)
{

	pthread_t thread;
	if(argc != 2){
	  printf("Usage : %s <client name> \n", argv[0]);
	  exit(1);
	}
	pthread_create(&thread, NULL, inputMenuLoop, NULL);
	connectServer(argv[1]);

}

void printMenu()
{
	printf("===============================\n");
	printf("=1. print goods                 =\n");
	printf("===============================\n");
}
void* inputMenuLoop()
{
	int nMenu;
	while(1)
	{
		printMenu();
		scanf("%d",&nMenu);

		switch(nMenu)
		{
		case 1:
			printf(" print goods \n");
			requestGoods();
			break;

		default:
			printf(" quit program\n");

			break;
		}

	}
}
void requestGoods()
{
	send_message("REQ");
}
