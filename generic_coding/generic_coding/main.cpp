#include "generic_coding.h"

int main()
{
	// Sort integer type data before print
	int iArray[10] = { 5,2,9,11,1,8,10,15,20,3 };
	genericSort(iArray, sizeof(iArray) / sizeof(iArray[0]), sizeof(iArray[0]), integerCompare);
	display(iArray, sizeof(iArray) / sizeof(iArray[0]), sizeof(iArray[0]), integerPrint);


	// Sort double type data before print
	double dArray[5] = { 12.5, 3.12, 7.7, 20.35, 9.8 };
	genericSort(dArray, sizeof(dArray) / sizeof(dArray[0]), sizeof(dArray[0]), doubleCompare);
	display(dArray, sizeof(dArray) / sizeof(dArray[0]), sizeof(dArray[0]), doublePrint);


	// Sort string data before print
	char sArrary[7][10] = { "Hope", "Dream", "Challenge", "Courge", "effort", "faith", "co-work" };
	//char *pSArray[7] = { "Hope", "Dream", "Challenge", "Courge", "effort", "faith", "co-work" };
	
	genericSort(sArrary, sizeof(sArrary) / sizeof(sArrary[0]), sizeof(sArrary[0]), stringCompare);
	display(sArrary, sizeof(sArrary) / sizeof(sArrary[0]), sizeof(sArrary[0]), stringPrint);

	//genericSort(pSArray, sizeof(pSArray) / sizeof(pSArray[0]), sizeof(pSArray[0]), stringCompare);
	//display(pSArray, sizeof(pSArray) / sizeof(pSArray[0]), sizeof(pSArray[0]), stringPrint);

	return 0;
}