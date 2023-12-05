#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 10000

int main(){

	srand(time(NULL));

	int * skill = malloc(sizeof(int)*SIZE); 
	int * lucky = malloc(sizeof(int)*SIZE); 

	for(int i = 0; i < SIZE; i++){
		int sk = rand()%950;
		int lk = rand()%50;
		skill[i] = sk;
		lucky[i] = lk;
	}

	for(int i = 0; i < SIZE; i++){
		if(skill[i] + lucky[i] > 980){
			printf("Skill: %d, Lucky: %d \t SUM: %d\n", skill[i], lucky[i], skill[i] + lucky[i]);
		}
	}


	return 0;
}