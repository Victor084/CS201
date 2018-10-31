/* Victor Heredia
CS201  - 10/16/18
This program will turn on the bits at the given positions
*/

#include <stdio.h>
#include <stdlib.h>

void print(int bits);


int main(int argc, char** argv){
	unsigned short one = 1;
	int collection_of_all_bits = 0, afterEachShift = 0;

	// make sure that some arguments were passed in
	if(argc > 1){
		for(int i = 1; i < argc; ++i){
			long shift = strtol(argv[i], NULL, 10);
			// if not accetable: ERROR
			
			// Should I care if the input are characters??

			if(shift < 0 || shift > 15){
				printf("Error: entered an integer out of the acceptable range\n");
				// EXIT
				exit(1);

				// Otherwise proceed
			} else {
				// capture the shift  (still in decimal)
				afterEachShift = one << shift;
				// the "or" operator will add the newest bit after Each Shift
				// when we have duplicate the "or" returns the same value and the collection doesn't change
				collection_of_all_bits = collection_of_all_bits | afterEachShift;
			}
		}
		print(collection_of_all_bits);
	} else {
		printf("No integers were entered. Pleas run again\n");
	}
	// set the command line at a new line
	printf("\n");

		return(0);
}


void print(int bits){
	int current_leading_bit = 0;
	unsigned short least_significat_bit_only = 1;
	// go reverse, because we print left to right and we are reading right to left
	for(int n = 15; n > 0; --n){
		current_leading_bit = bits >> n;
		// current_leading_bit & 1 so only the least significatn bit is printed 
		// and not any that were previous printed
		printf("%d", current_leading_bit & least_significat_bit_only);
	}
}

