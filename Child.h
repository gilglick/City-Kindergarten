#ifndef __CHILD__
#define __CHILD__

typedef struct {
	int id;
	int age;
} Child;

void readChild(FILE* fp, Child* pChild);
void readChildBinary(FILE* fp, Child* pChild);
void getChildFromUser(Child* pChild, int id);
void showChild(const Child* pChild);
void writeChild(FILE* fp, const Child* pChild);
void writeChildBinary(FILE* fp, const Child* pChild);
int findChildById(Child** pChildList, int count, int id);
int ChildIdComparator(const void* p, const void* q);
void birthday(Child* pChild);
void releaseChild(Child* pChild);
#endif
