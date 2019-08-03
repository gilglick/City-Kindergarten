#ifndef __KINDERGARTEN__
#define __KINDERGARTEN__
#define FILE_NAME_TEXT "DataFile.txt"
#define FILE_NAME_BIN "DataFile.bin"


#include "Child.h"

typedef enum {
	Chova, TromChova, TromTromChova, NofTypes
} GardenType;

const char* GardenTypeName[NofTypes];

typedef struct {
	char* name;
	GardenType type;
	Child** childPtrArr;
	int childCount;
} Garden;

Garden** readAllGardensFromFile(int* pGardenCount, int mainParameter);
void readGarden(FILE* fp, Garden* pGarden);
void readGardenBinary(FILE* fp, Garden* pGarden);
GardenType getTypeOption();

void showAllGardens(Garden** pGardenList, int count);
void showGarden(const Garden* pGarden);
void writeGardensToFile(Garden** pGardenList, int gardenCount,
		int mainParameter);
void writeGardenBinary(FILE* fp, const Garden* pGarden);
void writeGarden(FILE* fp, const Garden* pGarden);
void addChildToGarden(Garden** pGardenList, int gardenCount);
Garden** addGarden(Garden** pGardenList, int* pGardenCount);
void showGardenMenu(Garden** pGardenList, int count);
Garden* getGardenAskForName(Garden** pGardenList, int count);
Garden* findGardenByName(Garden** pGardenList, int count, const char* name);
Child* getChildAskForId(Garden* pGarden);
void getGardenFromUser(Garden* pGarden, Garden** pGardenList, int count);
void getChildCheckIdFromUser(Child* pChild, const Garden* pGarden);
void handleBirthdayToChild(Garden** pGardenList, int count);
int gardenNameComparator(const void* p, const void* q);
int gardenTypeComparator(const void* p, const void* q);
void SortChildrenById(Garden** pGardenList, int gardenCount);
void release(Garden** pGardenList, int count);

#endif
