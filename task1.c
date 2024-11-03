#include <stdio.h>
typedef struct{
	int id;
	char name[50];
	float gpa;
} Student;


int main () {
	int numstu,ID;
	char NAME[100];
	float GPA;
	printf("please enter the number of students\n");
	scanf("%d", &numstu);
	Student student[numstu];
	for (int i=1; i<=numstu;i++){
	printf("enter id number for student\n");
	scanf("%d",&ID);
	student[i].id=ID;
	printf("enter the name of student\n");
	scanf(" %s", student[i].name);
	printf("enter the gpa of the student\n");
	student[i].gpa=scanf("%f",&GPA);
//	printf("Student Records\nID:%d, Name: %s,GPA:%f\n", ID,NAME,GPA);
	}
	printf("student records\n");
	for (int i=1; i<=numstu;i++){
		printf("ID:%d, Name: %s,GPA:%f\n", student[i].id,student[i].name,student[i].gpa);
	}
	


}
