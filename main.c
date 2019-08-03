//Gil Glick 206128712 and Omri Habas 311343255 - Tom is the king! good luck in final exams!

#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Kindergarten.h"
#include "Child.h"
#include "City.h"

//Get a parameter from user and check it
int main(int argc, char* argv[]) {
	if ((argc != 2) || (*argv[1] != '0' && *argv[1] != '1')) {
		printf(
				"Please enter one parameter; 0 - for text file and 1- for binary file");
		return -1;
	}
	int mainParameter = atoi(argv[1]);
	City utz = { NULL, 0 };
	int uReq;

	//first time read
	readCity(&utz, mainParameter);
	do {
		uReq = menu();
		switch (uReq) {
		case READ_CITY:
			readCity(&utz, mainParameter);
			break;

		case SHOW_CITY:
			showCityGardens(&utz);
			break;

		case SHOW_GARDEN:
			showSpecificGardenInCity(&utz);
			break;

		case WRITE_CITY:
			saveCity(&utz, mainParameter);
			break;

		case ADD_GARDEN:
			cityAddGarden(&utz);
			break;

		case ADD_CHILD:
			addChildToSpecificGardenInCity(&utz);
			break;

		case CHILD_BIRTHDAY:
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE:
			printf("There are %d children going to school next year\n",
					countChova(&utz));
			break;

		case SORT_BY_GARDEN_NAME:
			SortCityByGardensName(&utz);
			break;

		case SORT_BY_GARDEN_TYPE_AND_CHILDERN_NUMBER:
			SortCityByGardensTypeAndChildrenNumber(&utz);
			break;

		case SORT_BY_CHILD_ID:
			SortGardenByChildId(&utz);
			break;

		case CREATE_LINKED_LIST:
			kindergartensLinkedList(&utz);
			break;
		}

	} while (uReq != EXIT);

	ReleaseCity(&utz); //free all allocations

	return EXIT_SUCCESS;
}
