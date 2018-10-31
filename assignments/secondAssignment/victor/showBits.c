/*Victor Heredia
CS201 - 10/16/18
This program shows the bits in common between two hexadecimal numbers 
then converst them to decimal signed and unsigned
*/

#include <stdio.h>
#include <stdlib.h>

_Bool printCommonBits(unsigned long commonBits);
void quit();

int main(int argc, char** argv){
	// make sure we have only two  hex numbers to compare
	if(argc != 3){
		quit();

		// else proceed
	} else{
	unsigned long common = 0;
		// ensure only hexadecimals are accepted
		for(int i = 1; i < 3; i++){
			for(int j = 2; j < 32;  j++){
				if( (argv[i][0] == '0' && argv[i][1] == 'x') && !(argv[i][2]) )
					quit();
				// account for the null terminator.  break was the only way I could solve this
				if(!argv[i][j])
					break;
				//validat the hex number
				if((argv[i][0] != '0' || argv[i][1] != 'x') || 
						(argv[i][j] < '0' || (argv[i][j] < 'A' && argv[i][j] > '9') || (argv[i][j] > 'F' && argv[i][j] < 'a') || argv[i][j] > 'f') )
				{
					quit();
				}
			}
		}


		unsigned long first = strtol(argv[1], NULL, 16);
		unsigned long second = strtol(argv[2], NULL, 16);
		common = first & second;


		printf("Bits ");
		if(printCommonBits(common))
			printf(" in common. ");
		else
			printf(" none in common. ");

		printf("Hexacdecimal: 0x%lX, Signed: %ld, Unsigned: %lu\n", common, common, common);

	}

	return(0);
}


_Bool printCommonBits(unsigned long commonBits){
		_Bool isCommon = 0;
		// True && P <==>  P
		unsigned long true_and_P = 0, one = 1;
		for(int i = 0; i < 32  ; i++){
			true_and_P = commonBits & (one << i);

			// print only when true_and_P matches our key, the 1 shifted to that position
			if(true_and_P == (one << i)){
				printf("%d,",  i);
				isCommon = 1;
			}
		}
		return(isCommon);
}

void quit(){
		printf("Error: please provide two hexadecimal number as arguments to the program.\n");
		exit(1);
}
