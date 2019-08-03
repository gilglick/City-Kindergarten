#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "General.h"

const char* optionStr[NofOptions] = { "Exit", "Read City information from file",
		"Show all Kindergartens", "Show a specific Kindergarten",
		"Save City information to file", "Add a Kindergarten", "Add a Child",
		"Birthday to a Child", "Count Hova childres", "Sort by garden name",
		"Sort by garden type and number of children", "Sort by child ID",
		"Create linked list" };

/**************************************************/
int menu()
/**************************************************/
/**************************************************/
{
	int option, i;

	printf("\n==========================");
	printf("\nSelect:\n");
	for (i = 0; i < NofOptions; i++)
		printf("\n\t%d. %s.", i, optionStr[i]);
	printf("\n");
	scanf("%d", &option);
	return option;
}

char* getStrExactLength(char* inpStr) {
	char* theStr = NULL;
	size_t len;

	len = strlen(inpStr) + 1;
	//allocate a place for the string in the right location in the array 
	theStr = (char*) malloc(len * sizeof(char));
	//Copy the string to the right location in the array 
	if (theStr != NULL)
		strcpy(theStr, inpStr);

	return theStr;
}

int checkAllocation(const void* p) {
	if (!p) {
		printf("ERROR! Not enough memory!");
		return 0;
	}
	return 1;
}

//*************************************************
// generic insertion sort
//*************************************************

void insertionSort(void* arr, int length, int size,
		int (*compare)(const void*, const void*)) {
	int i, j;
	void* key = malloc(size);
	for (i = 1; i < length; i++) {
		key = memcpy(key,arr + i*size,size);
		for (j = i - 1; j >= 0 && (compare(arr + j*size, key)) > 0; j--) {
			insert(arr + (j + 1)*size, arr + j*size, size);
		}
		insert(arr + (j + 1)*size, key, size);
	}
	free(key);
}

void insert(void* oldElement, const void* newElement, int size) {
	memmove(oldElement, newElement, size);
}

//*************************************************
// variadicFunction for printing 3 kindergarten info
//*************************************************

void variadicFunction(char* name, int childrenNumber, ...) {
	va_list gardens;
	char* currentName = name;
	int currentChildrenNumber = childrenNumber;

	printf("Kindergarten Info:\n");
	va_start(gardens, childrenNumber);
	while (currentName != NULL) {
		printf("%s ----->  %d\n", currentName, currentChildrenNumber);
		currentName = va_arg(gardens, char*);
		currentChildrenNumber = va_arg(gardens, int);
	}
	va_end(gardens);
}
