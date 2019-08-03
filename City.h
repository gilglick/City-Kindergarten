#ifndef __CITY__
#define __CITY__

#include "Kindergarten.h"

typedef struct {
	Garden** pGardenList;
	int count;
} City;

typedef struct node{
	void* data;
	struct node* next;
} Node;

void readCity(City* pCity, int mainParameter);
void showCityGardens(City* pCity);
void showSpecificGardenInCity(City* pCity);
void saveCity(City* pCity, int mainParameter);
void cityAddGarden(City* pCity);
void addChildToSpecificGardenInCity(City* pCity);
void birthdayToChild(City* pCity);
int countChova(City* pCity);
void SortCityByGardensName(City* pCity);
void SortCityByGardensTypeAndChildrenNumber(City* pCity);
void SortGardenByChildId(City* pCity);
void kindergartensLinkedList(City* pCity);
void* createLinkedListForKindergartenType(City* pCity,GardenType gardenType);
void displayKindergartensFromList(Node* list);
void ReleaseCity(City* pCity);

#endif
