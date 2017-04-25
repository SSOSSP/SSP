/*
 * goodsManager.c
 *
 *  Created on: 2017. 4. 10.
 *      Author: LGCNS
 */

#include<stdio.h>
#include<glib.h>
#include<stdlib.h>
#include"./server.h"
#include "./goodsList.h"
void __attribute__((constructor))console_setting_for_eclipse_debugging(void)
{
	setvbuf(stdout,NULL, _IONBF,0);
	setvbuf(stderr,NULL, _IONBF,0);
}


void* inputMenuLoop();
void printMenu();


int main()
{
	pthread_t thread;
	loadGoods();
	pthread_create(&thread, NULL, inputMenuLoop, NULL);
	connectServer();

}
void printMenu()
{
	printf("===============================\n");
	printf("=1. add goods                 =\n");
	printf("=2. print goods               =\n");
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
			printf(" add goods \n");
			addGoods();
			break;
		case 2:
			printf(" print goods \n");
			printGoods();
			break;
		default:
			printf(" quit program\n");
			destroyGoods();
			break;
		}

	}
}


