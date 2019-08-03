#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Child.h"
#include "General.h"

/**************************************************/
/*             Read a Child from a file in Binary */
/**************************************************/
void readChildBinary(FILE* fp, Child* pChild) {
	unsigned int originalBytes;
	fread(&originalBytes, sizeof(char), 2, fp);
	pChild->id = originalBytes & 0x1fff;
	pChild->age = originalBytes >> 13;
}
/**************************************************/
/*             Read a Child from a file in Text   */
/**************************************************/
void readChild(FILE* fp, Child* pChild) {
	//Child ID
	fscanf(fp, "%d", &pChild->id);
	fscanf(fp, "%d", &pChild->age);
}

/**************************************************/
/*            show a Child				          */
/**************************************************/
void showChild(const Child* pChild) {
	printf("\nID:%d  ", pChild->id);
	printf("Age:%d  ", pChild->age);
}

void getChildFromUser(Child* pChild, int id) {
	pChild->id = id;

	puts("\nAge:\t");
	scanf("%d", &pChild->age);
}

//*************************************************
/*Write a Child to the open file in Binary	*/
//*************************************************

void writeChildBinary(FILE* fp, const Child* pChild) {
	unsigned int bytes;
	bytes = pChild->id & 0x1fff;
	bytes |= pChild->age << 13;
	fwrite(&bytes, sizeof(char), 2, fp);
}

/**************************************************/
/*Write a Child to the open file in Text		*/
/**************************************************/
void writeChild(FILE* fp, const Child* pChild) {
	fprintf(fp, "%d %d\n", pChild->id, pChild->age);
}

//binary search
int findChildById(Child** pChildList, int count, int id) {
	int index;
	Child child = { id, 0 };
	Child* pChild = &child;
	qsort(pChildList, count, sizeof(Child*), ChildIdComparator);
	Child** address = (Child**) bsearch(&pChild, pChildList, count,
			sizeof(Child*), ChildIdComparator);
	if (address != NULL) {
		index = address - pChildList;
		return index;
	}
	return -1;

}

int ChildIdComparator(const void* p, const void* q) {
	return ((*(Child**) p)->id - (*(Child**) q)->id);
}

void birthday(Child* pChild) {
	pChild->age++;
}

void releaseChild(Child* pChild) {
	//nothing to release
}
