
#include<stdio.h>
#define MAX_STUDENTS 10
struct student
{
	char name[50];
	int roll;
	float marks;
};
void readstudent(struct student*s)
{
	printf("Enter a students First name:");
	scanf("%s",s->name);
	printf("Enter student roll:");
	scanf("%d",&s->roll);
	printf("Enter student CPI:");
	scanf("%f",&s->marks);
}
void printstudent(struct student s)
{
	printf("Name:%s\n",s.name);
	printf("Roll:%d\n",s.roll);
	printf("CPI:%.2f\n",s.marks);
}
int main()
{
	struct student students[MAX_STUDENTS];
	int n,i;
	printf("Enter the number of students(MAx:%d):",MAX_STUDENTS);
	do
	{
		scanf("%d",&n);
		if(n<=0)
		{
			printf("(invalid)Enter a non-zero number:");
		}
	}while(n<=0);
	 for(i=0;i<n;i++)
	 {
	 	printf("\nEnter Information for student%d:\n",i+1);
	 	readstudent(&students[i]);
	 }
	 for(i=0;i<n;i++)
	 {
	 	printf("\nInformation of student %d:\n",i+1);
	 	printstudent(students[i]);
	 }
	 return 0;
}
