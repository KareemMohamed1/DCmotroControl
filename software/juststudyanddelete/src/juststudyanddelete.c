/*
 ============================================================================
 Name        : juststudyanddelete.c
 Author      : Kareem
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

unsigned char powerof2(int x)
{
	unsigned char y;
	y=x&&(!(x&(x-1)));
	return x&&(!(x&(x-1)));
}
int main(void)
{
	int x=8;
	unsigned char y;
	y=powerof2(x);
	printf("\n%d",x);
	printf("\n%d",y);
	//	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
