/*
   Victor Heredia
   CS201 - 10/31/18
   Assignment 3 floating point parser
   It will convert a hex to a float
 */
#include "main.h"


int main(int argc, char** argv){
	if(argc != 4){
		printf("Invalid number of arguments. Try again. " );
		exit(1);
	}

	int numberOfFractBits, numberOfExpBits, hex; 
	// using the return value of sscanf 
	// if any of them fail then report the error and exit because it won't work without any
	if(!sscanf(argv[2], "%d", &numberOfExpBits) || !sscanf(argv[1], "%d", &numberOfFractBits) || !sscanf(argv[3], "%x", &hex) ) {
		printf("Failed to read in the input");
		exit(1);
	}

	// make sure that all the parameters are within the acceptable range	
	if(numberOfFractBits < 2 || numberOfFractBits > 10){
		printf("Illegal number of fraction bits (%d). Should be between 2 and 10", numberOfFractBits);
		exit(1);
	}

	if(numberOfExpBits < 3 || numberOfExpBits > 5){
		printf("Illegal number of exponent bits(%d). Should be between 3 and 5", numberOfExpBits );
		exit(1);
	}
	//********  FRACTION BITS  ********//
	int mask = (1 << numberOfFractBits) - 1;
	// isolate the fractional bits
	float fractionValue = hex & mask;
	// this will determine if a special case is infinity
	_Bool infinity = (fractionValue == 0) ? 1 : 0; 


	//*********  EXPONENTS BITS  *******//
	// get rid of the fractional bits
	hex = hex >> numberOfFractBits;
	//exponent mask        we need a new mask
	mask = (1 << numberOfExpBits) - 1;
	// isolate the exponent
	int exponent = hex & mask;
	// the exponent bits determine if it is a special case
	_Bool special = (exponent == mask) ? 1 : 0;


	//************   SIGN  BIT  *********//
	// get rid of the exponent bits, we are done with them
	hex = hex >> numberOfExpBits;
	// sign mask       we need a new mask again
	mask = 1;
	// isolate the mask bit
	int signBit =  hex & mask;



	//Fractional values
	fractionValue = fractionValue / (1 << numberOfFractBits);


	// call the appropiate function

	//DENORMALIZE
	// EXPONENT is all 0s
	if(exponent == 0){
		denormalizeForm(numberOfExpBits, fractionValue, signBit);

	} else if(special){
		// special case when EXPONENT IS ALL 1s 
		specialForm(infinity, signBit);
	} else{
		// if not the other two then it must be in normal form where the exponent bits is greater than 0
		normalizeForm(numberOfExpBits, exponent, fractionValue, signBit);
	}


	return(0);
}
