/*
   Victor Heredia
   CS201 - 10/31/18
   Assignment 3 floating point parser
   It will convert a hex to a float
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(float fractValue, float manteca, int bigE, int signBit){
	float value = 0;
	value = pow(-1, signBit) * manteca * pow(2, bigE);
	printf("The  VALUE in Decimal is: %f\n", value);
}


// I dont thinkg we need to pass numberOfExpBits
void denormalizeForm(int numberOfExpBits, float fractValue, int signBit){
	//biase is 2^(numberOfExpBits -1) -1
	int biase = (1 << (numberOfExpBits-1) ) - 1;   // pow(2, k-1) - 1

	//denormalize form
	int bigE = 1 - biase;
	float manteca = fractValue;

	print(fractValue, manteca, bigE, signBit);

}





void normalizeForm(int numberOfExpBits, int exp, float fractValue, int signBit){
	//biase is 2^(numberOfExpBits -1) -1
	int biase = (1 << (numberOfExpBits-1) ) - 1;   // pow(2, k-1) - 1

	//normalize form
	int bigE = exp - biase;
	float manteca = 1 + fractValue;

	print(fractValue, manteca, bigE, signBit);
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



