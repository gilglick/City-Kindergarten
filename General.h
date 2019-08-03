#ifndef __PROTOTYPE__
#define __PROTOTYPE__

#define TEXT 0
#define BINARY 1

typedef enum {
	EXIT,
	READ_CITY,
	SHOW_CITY,
	SHOW_GARDEN,
	WRITE_CITY,
	ADD_GARDEN,
	ADD_CHILD,
	CHILD_BIRTHDAY,
	COUNT_GRADUATE,
	SORT_BY_GARDEN_NAME,
	SORT_BY_GARDEN_TYPE_AND_CHILDERN_NUMBER,
	SORT_BY_CHILD_ID,
	CREATE_LINKED_LIST,
	NofOptions
} MenuOptions;

const char* optionStr[NofOptions];

int menu();
char* getStrExactLength(char* inpStr);
int checkAllocation(const void* p);
void insertionSort(void* arr, int length, int size,
		int (*compare)(const void*, const void*));
void insert(void* oldElement, const void* newElement, int size);
void variadicFunction(char* name, int childrenNumber, ...);

#endif
