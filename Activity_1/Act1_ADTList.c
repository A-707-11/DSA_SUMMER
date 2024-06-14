#include <stdio.h>
#include <string.h>

#define MAX 20

typedef struct{
	char fname[MAX];
	char lname[MAX];
}studName;

typedef struct {
	int month;
	int year;
}bday;

typedef struct {
	studName name;
	bday birthDate;
	int age;
	int idNum;
}studentInfo;

typedef struct {
	studentInfo studList[MAX];
	int studCount;
}classRecord;

void displayLisy();
void insertFront();
void insertRear();
void insertAtIndex();
void insertSort();
void deleteFront();
void deleteRear();
void deleteAtIndex();

int main()
{
	classRecord myRecord = {0,0};

	
	studentInfo myStudents[5];
	
	myStudents[0] = (studentInfo){{"Arjoy","Estiola"},{04,2003},2,20101650};
	myStudents[1] = (studentInfo){{"Simon","Yap"},{05,2005},1,20101650};
	myStudents[2] = (studentInfo){{"John","Doe"},{07,2006},5,20101650};
	myStudents[3] = (studentInfo){{"Krizia","Tumulak"},{11,2008},4,20101650};
	myStudents[4] = (studentInfo){{"Kyle","Morabe"},{12,2001},3,20101650};
	
	printf("Insert Front\n\n");
	insertFront(&myRecord,myStudents[1]);
	displayLisy(myRecord);
	printf("Insert Rear\n\n");
	insertRear(&myRecord,myStudents[2]);
	displayLisy(myRecord);
	printf("Insert at Index [1]\n\n");
	insertAtIndex(&myRecord,myStudents[3],1);
	displayLisy(myRecord);
	printf("Sort Data Only if Sort Function is Used\n\n");
	insertSort(&myRecord,myStudents[4]);
	displayLisy(myRecord);
	insertSort(&myRecord,myStudents[1]);
	displayLisy(myRecord);
	insertSort(&myRecord,myStudents[2]);
	printf("Delete Front\n\n");
	deleteFront(&myRecord);
	displayLisy(myRecord);
	printf("Delete Rear\n\n");
	deleteRear(&myRecord);
	displayLisy(myRecord);
	printf("Delete at Index [0]\n\n");
	deleteAtIndex(&myRecord,0);
	displayLisy(myRecord);
	return 0;
}

void displayLisy(classRecord C)
{
	int i;
	
	printf("NAME\tAGE\tYEAR\tID NUMBER\n");
	for(i = 0; i < C.studCount; i++)
	{
		printf("%s\t%2d\t %d\t%d\n", C.studList[i].name.fname,C.studList[i].age,C.studList[i].birthDate.year,C.studList[i].idNum);
	}
	printf("\n----------------------------------\n");
	
}

void insertFront(classRecord *C, studentInfo StudA)
{
	int i;
	
	if(C->studCount < MAX)
	{
		for(i = C->studCount - 1; i >= 0; i--)
		{
			C->studList[i + 1] = C->studList[i];
		}
		C->studList[0] = StudA;
		C->studCount++;
	}

}

void insertRear(classRecord *C, studentInfo StudA)
{
	int i;
	
	if(C->studCount < MAX)
	{
		C->studList[C->studCount++] = StudA;
	}
	
}

void insertAtIndex(classRecord *C, studentInfo StudA, int indx)
{
	int i;
	
	if(C->studCount < MAX)
	{
		for(i = C->studCount - 1; i >= indx; i--)
		{
			C->studList[i + 1] = C->studList[i];
		}
		C->studList[indx] = StudA;
		C->studCount++;
	}	
}

void insertSort(classRecord *C, studentInfo StudA)
{
	int i, j;
	int flag =  -1;
	
	if(C->studCount < MAX)
	{
		for(i = 0; i < C->studCount && C->studList[i].age < StudA.age; i++){}
		flag = i;	

		for(i = C->studCount - 1; i >= flag; i--)
		{
			C->studList[i + 1] = C->studList[i];
		}
		C->studList[flag] = StudA;
		C->studCount++;
	}	
	
}

void deleteFront(classRecord *C)
{
	int i;
	studentInfo dlt = C->studList[0];
	
	if(C->studCount == 0)
	{
		printf("There is nothing to delete!\n\n");
	}
	else
	{
		for(i = 1; i < C->studCount; i++)
		{
			C->studList[i - 1] = C->studList[i];
		}
		C->studCount--;
		printf("%s Successfully Deleted!\n\n", dlt.name);
	}
}

void deleteRear(classRecord *C)
{
	int i;
	studentInfo dlt = C->studList[C->studCount-1];
	
	if(C->studCount == 0)
	{
		printf("There is nothing to delete!\n\n");
	}
	else
	{
		C->studCount--;
		printf("%s Successfully Deleted!\n\n", dlt.name);
	}
}

void deleteAtIndex(classRecord *C, int ndx)
{
	int i;
	studentInfo dlt = C->studList[ndx];
	
	if(C->studCount == 0)
	{
		printf("There is nothing to delete!\n\n");
	}
	else
	{
		for(i = ndx + 1; i < C->studCount; i++)
		{
			C->studList[i - 1] = C->studList[i];
		}
		C->studCount--;
		printf("%s Successfully Deleted!\n\n", dlt.name);
	}
	
}
