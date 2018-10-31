#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// I dont thinkg we need to pass exponentBits
float denormalizeForm(long exponentBits, long fractBits, int signBit){
	//biase is 2^(exponentBits -1) -1
	int biase = (1 << (exponentBits-1) ) - 1;   // pow(2, k-1) - 1

	//denormalize form
	int bigE = 1 - biase;
	int manteca = fractBits;
	float value = 0;

	printf("The biase in Decimal is: %d\n", biase);
	value = pow(2, signBit) * manteca * pow(2, e);

	return(value);
}





float normalizeForm(long exponentBits, long fractBits, int signBit){
	//biase is 2^(exponentBits -1) -1
	int biase = (1 << (exponentBits-1) ) - 1;   // pow(2, k-1) - 1


	//normalize form
	int bigE = exponentBits - biase;
	int manteca = 1 + fractBits;
	float value = 0;

	printf("The biase in Decimal is: %d\n", biase);
	value = pow(2, signBit) * manteca * pow(2, e);

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


