
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>



int main(int argc, char** argv){
	struct timeval startTime, endTime, runTime;
	gettimeofday(&startTime, NULL);

	//suseconds_t 
	char* words[] = {"The", "quick", "brown", "fox", 
					 "jumps", "over", "the", "lazy", "dog"};
	char* input;

	printf("This is a game that tests typing speed\n\n");
	printf("Type the following words:\n");

	//j = rand() % 9;
	//temp = words[i];
	//words[j] = words[i];
	//words[i] = temp;

	do{
		printf("  word #1 is %s:", words[2]);
		scanf("%s", input);

		if(strncmp(input, words[2], strlen(input) ) != 0){
			printf("Incorrect. Try again.\n");

			printf("You entered: %s \n", input);
		}
	} while(strncmp(input, words[2], strlen(input) ) != 0);

	gettimeofday(&endTime, NULL);
	timersub(&endTime, &startTime, &runTime);

	printf("Correct! Your time is: %ld sec and %ld usec", runTime.tv_sec, runTime.tv_usec);
	//printf("You entered %s", words);
	return(0);
}

