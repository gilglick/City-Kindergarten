#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "City.h"
#include "Kindergarten.h"
#include "General.h"

void readCity(City* pCity, int mainParameter) {
	if (pCity->pGardenList != NULL) { //we have a list
		ReleaseCity(pCity);
		pCity->count = 0;
	}
	pCity->pGardenList = readAllGardensFromFile(&pCity->count, mainParameter);

	if (pCity->pGardenList == NULL)
		printf("Error reading city information\n");
}

void showCityGardens(City* pCity) {
	showAllGardens(pCity->pGardenList, pCity->count);
}

void showSpecificGardenInCity(City* pCity) {
	showGardenMenu(pCity->pGardenList, pCity->count);
}

void saveCity(City* pCity, int mainParameter) {
	writeGardensToFile(pCity->pGardenList, pCity->count, mainParameter);
}

void cityAddGarden(City* pCity) {
	pCity->pGardenList = addGarden(pCity->pGardenList, &pCity->count);
	if (pCity->pGardenList == NULL) //Allocation error
		printf("Error adding kindergarten\n");
}

void addChildToSpecificGardenInCity(City* pCity) {
	addChildToGarden(pCity->pGardenList, pCity->count);
}

void birthdayToChild(City* pCity) {
	handleBirthdayToChild(pCity->pGardenList, pCity->count);
}

int countChova(City* pCity) {
	int i;
	int count = 0;
	for (i = 0; i < pCity->count; i++) {
		if (pCity->pGardenList[i]->type == Chova)
			count += pCity->pGardenList[i]->childCount;
	}
	return count;
}

void SortCityByGardensName(City* pCity) {
	insertionSort((void*) pCity->pGardenList, pCity->count, sizeof(Garden*),
			gardenNameComparator);
}

void SortCityByGardensTypeAndChildrenNumber(City* pCity) {
	insertionSort((void*) pCity->pGardenList, pCity->count, sizeof(Garden*),
			gardenTypeComparator);
}

void SortGardenByChildId(City* pCity) {
	SortChildrenById(pCity->pGardenList, pCity->count);
}

void kindergartensLinkedList(City* pCity) {
	GardenType gardenType = getTypeOption();
	Node* list = createLinkedListForKindergartenType(pCity, gardenType);
	displayKindergartensFromList(list);
}

//create linked list from Kindergartens by the type they have and return the head of the list
void* createLinkedListForKindergartenType(City* pCity, GardenType gardenType) {
	int i;
	Node* headNode = (Node*) calloc(1, sizeof(Node));
	Node* newNode;
	Node* lastNode;
	if (!checkAllocation(headNode))
		return NULL;
	lastNode = headNode;
	for (i = 0; i < pCity->count; i++) {
		if (pCity->pGardenList[i]->type == gardenType) {
			if (lastNode->data == NULL)
				lastNode->data = pCity->pGardenList[i];
			else {
				newNode = (Node*) calloc(1, sizeof(Node));
				newNode->data = pCity->pGardenList[i];
				lastNode->next = newNode;
				lastNode = newNode;
			}
		}
	}
	return headNode;
}

//print all linked list of Kindergartens
void displayKindergartensFromList(Node* list) {
	int i;
	for (i = 1; list != NULL; i++, list = list->next) {
		printf("Kindergarten number %d:\n", i);
		showGarden((Garden*) (list->data));
		printf("\n");
	}
}

void ReleaseCity(City* pCity) {
	release(pCity->pGardenList, pCity->count);
}
