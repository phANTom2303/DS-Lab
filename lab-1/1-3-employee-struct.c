#include <stdio.h>
#include <strings.h>

struct Employee
{
    char name[100];
    char designation[100];
    float basic_salary;
    float hra;
    float da;
};

void main()
{
   int n;
   printf("Enter Number of emplyees : ");
   scanf("%d",&n);

   struct Employee emp[n];
   for(int i = 0; i < n; i++)
   {
        printf("\nEnter  employee %d information : ",(i+1));
        scanf("%s",&emp[i].name);
        scanf("%s",&emp[i].designation);
        scanf("%f",&emp[i].basic_salary);
        scanf("%f",&emp[i].hra);
        scanf("%f",&emp[i].da);
   }

   printf("Employee Information : \n");

   for(int i = 0 ; i < n ; i++)
   {
        printf("Name : %s \n",emp[i].name);
        printf("Designation : %s \n",emp[i].designation);
        printf("Basic Salary : %f \n",emp[i].basic_salary);
        printf("HRA: %f \n",emp[i].hra);
        printf("DA : %f \n",emp[i].da);
   }
}