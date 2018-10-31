/*
Victor Heredia
10/4/2018
CS201
This program will test a user's typing speed, 
by printing words from a sentence in random order.
*/

#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>


void randomize(char* list[], int length);


int main(int argc, char** argv){
	struct timeval startTime, endTime, runTime;


	// start recording time, runTime is used just to seed srand(), but will be overriden later
	gettimeofday(&runTime, NULL);             
	srand(runTime.tv_usec);                   // seed rand() with the microseconds

	//initialize my array with the test words
	char* words[] = {"The", "quick", "brown",
					 "fox", "jumps", "over", 
					 "the", "lazy",  "dog"};

	// to store the user input
	char input[10];
	int size = sizeof(words) / sizeof(words[0]); // total bits / type of bits 

	// randomize the list of words
	randomize(words, size);	


	//prompt user
	printf("This is a game that tests typing speed\n\n");
	printf("Type the following words:\n");


	int index = 0;
	do{
		//display one word at a time
		printf(" word #%d is %s:", index+1, words[index]);
		
		// start recording time after first word is given
		if(index == 0)
			gettimeofday(&startTime, NULL);             


		//record input, prevent overflow
		scanf("%10[^\n]", input);

		// clear the input stream buffer
		char c;
		while( (c = getchar()) != '\n' && c != EOF ){};

		//compare input to prompt word and make sure only exact match are accepted
		if( (strncmp(input, words[index], strlen(input) ) == 0 || strncmp(words[index], input, strlen(words[index]) ) == 0) 
			&& strlen(input) == strlen(words[index] ))
		{
			// if we find that it is a match we move on to the next word
			++index;
		} else {
			//words doesnt match, Inform user of error and do not move on to next word
			printf("Incorrect. Try again.\n");
		}
	// do this until the index is less than the size of the list
	} while(index < size );




	// record once the user is done entering words
	gettimeofday(&endTime, NULL);
	//get the total runtime of the program
	timersub(&endTime, &startTime, &runTime);

	// print runtime
	printf("\nCorrect! Your time is: %ld sec and %ld usec\n\n", runTime.tv_sec, runTime.tv_usec);
	return(0);
}



void randomize(char* list[], int length){
	int j = 0;
	char* temp; 

	for(int i = 0; i < length; ++i){
		j = rand() % length;
		// temp holds on to current word
		temp    = list[i];
		// current word is replace
		list[i] = list[j];
		// and replaced word now gets current word
		list[j] = temp;
	}

}

