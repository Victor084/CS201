#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	unsigned short one = 1;
	int position[argc -1];
	if(argc > 1){

		for(int i = 1; i < argc; ++i){
			one = 1;
			position[i - 1 ] = strtol(argv[i], NULL, 10);
			// if not accetable: ERROR
			if(position[i-1] < 0 || position[i-1] > 15){
				printf("Error: entered an integer out of the acceptable range\n");
				// EXIT
				exit(1);

				// Otherwise proceed
			} else {
				if(position[i-1] == 0){
					//printf("%d", 1 & one);
				} else {
					one = one << position[i-1];
					//printf("%d", 1 & one);
				}
			}
		}

		// print the bits turned on
		for(int i = 15; i >= 0; --i){
			int shift = position[15 - i] >> i;
			printf("%d",1& shift);
		}
		printf("\n");
	} else {
		printf("No integers were entered. Please run again.\n");
	}

		return(0);
}





//	for(int i = 15; i >= 0; --i){
//		int shift = position >> i;
//		printf("%d",1& shift);
//	}
//	printf("\n");
