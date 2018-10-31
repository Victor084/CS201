#include "main.h"


int main(int argc, char** argv){
	if(argc != 4){
		printf("Invalid number of arguments. Try again. " );
		exit(1);
	}
	
	//unsigned long numberOfExpBits = strtol(argv[2], NULL, 10);
	//long numberOfFractBits = strtol(argv[1], NULL, 10);
	//long hex = strtol(argv[3], NULL, 16);
	int numberOfFractBits, numberOfExpBits, hex; 
	if(!sscanf(argv[2], "%d", &numberOfExpBits) || !sscanf(argv[1], "%d", &numberOfFractBits)
	|| !sscanf(argv[3], "%x", &hex) )
		printf("Failed to read in the input");
	
	if(numberOfFractBits < 2 || numberOfFractBits > 10 || numberOfExpBits < 3 || numberOfExpBits > 5){

		printf("Parameteres outside the acceptable bounds" );
		exit(1);
	}

	int mask = (1 << numberOfFractBits) - 1;
	float fractionValue = hex & mask;
	_Bool infinity = (fractionValue == 0) ? 1 : 0;

	printf("The Original HEX in Decimal is: %d\n", hex);

	// get rid of the fractional bits
	hex = hex >> numberOfFractBits;
	//exponent mask
	mask = (1 << numberOfExpBits) - 1;

	long exponent = hex & mask;
	_Bool special = (exponent == mask) ? 1 : 0;
	hex = hex >> numberOfExpBits;
	mask = 1;
	int signBit =  hex & mask;


	//TIP dont bother checking for the normal
	//check for Denormalized or Special case, it neither than it must be normalize.
	printf("The fractionValue in Decimal is: %f\n", fractionValue);
	printf("The exponent in Decimal is: %ld\n", exponent);
	printf("The signBit in Decimal is: %d\n", signBit);

	printf("The number Of Fract Bits in Decimal is: %d\n", numberOfFractBits);
	printf("The number Of EXPONENT  Bits in Decimal is: %d\n", numberOfExpBits);
	//THIS SHOULD BE ITS OWN FUNCTION
	 //Fractional values
	fractionValue = fractionValue / (1 << numberOfFractBits);
		
	//printf("The fractionValueVALUE in Decimal is: %f\n", fractionValue);



	//DENORMALIZE
	// EXPONENT is all 0s
	if(exponent == 0){
		denormalizeForm(numberOfExpBits, exponent, numberOfFractBits, fractionValue, signBit);

	} else if(special){
		// special case when EXPONENT IS ALL 1s 
		specialForm(infinity, signBit);
	} else{
		// if not the other two then it must be in normal form where the exponent bits is greater than 0
		normalizeForm(numberOfExpBits, exponent, numberOfFractBits, fractionValue, signBit);
	}
	return(0);
}
