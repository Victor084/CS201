
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(float fractValue, float manteca, int bigE, long exp, int biase, float value, int signBit){
	printf("The fraction in Decimal is: %f\n", fractValue);
	printf("The MANTECA in Decimal is: %f\n", manteca);
	printf("The E in Decimal is: %d\n", bigE);
	printf("The exponent in Decimal is: %ld\n", exp);
	printf("The biase in Decimal is: %d\n", biase);
	value = pow(-1, signBit) * manteca * pow(2, bigE);
	printf("The  VALUE in Decimal is: %f\n", value);
}


// I dont thinkg we need to pass numberOfExpBits
float denormalizeForm(long numberOfExpBits, long exp, long numberOfFractBits, float fractValue, int signBit){
	//biase is 2^(numberOfExpBits -1) -1
	int biase = (1 << (numberOfExpBits-1) ) - 1;   // pow(2, k-1) - 1

	//denormalize form
	int bigE = 1 - biase;
	float manteca = fractValue;
	float value = 0;

	print(fractValue, manteca, bigE, exp, biase, value, signBit);
	printf("The DENORMALIZED VALUE in Decimal is: %f\n", value);

	return(value);
}





float normalizeForm(long numberOfExpBits, long exp, long numberOfFractBits, float fractValue, int signBit){
	//biase is 2^(numberOfExpBits -1) -1
	int biase = (1 << (numberOfExpBits-1) ) - 1;   // pow(2, k-1) - 1


	//normalize form
	int bigE = exp - biase;
	float manteca = 1 + fractValue;
	float value = 0;
	print(fractValue, manteca, bigE, exp, biase, value, signBit);
	printf("The NORMALIZE VALUE in Decimal is: %f\n", value);

	return(value);
}


void specialForm(_Bool infinity, int signBit){
	if(infinity){
		if(signBit)
			printf("-infinity");
		else
			printf("+infinity");
	} else {
		printf("NaN");
	}
}



