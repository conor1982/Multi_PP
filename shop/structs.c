#include <string.h>
#include <stdlib.h>
#include <stdio.h>



struct Employee {
    char* empname;
    int age;
    int salary;
    int service;
    char* title;
};

struct Module {
    char* subject;
    int credits;
};

 struct Student {
     char* name;
     int age;
     struct Module modules[10];
     int index;
 
 };

 struct Manager {
    char* name;
    int age;
    int salary;
    struct Employee employees[20];
    int index;
};

//print employee
void printEmployee(struct Employee e)
{
    //printf("-------------------------------------------------------------\n");
    printf("EMPLOYEE NAME:  %s\n AGE: %d\n SALARY %d\n SERVICE (Years) %d\n JOB TITLE %s\n",e.empname,e.age,e.salary,e.service,e.title);
    printf("-------------------------------------------------------------\n");
}

void printEmployeeName(struct Employee e)
{  
    printf("%s ",e.empname);    
}

//module print
void printModule(struct Module m)
{  
    printf("%s ",m.subject);
    printf("%d(credits): ",m.credits);    
}


//prit student and array of subjects
void printStudent(struct Student s)
{   
    //printf("-----------------------------------------------------\n");
    printf("STUDENT NAME: %s\n AGE %d\n",s.name,s.age);
    printf("MODULES: ");
    for(int i = 0;i < s.index;i++)
    {
       printModule(s.modules[i]);
    }    
    printf("\n");
    printf("-------------------------------------------------------------\n");
}    

//prit student and array of subjects
void printManager(struct Manager m)
{   
    //printf("-----------------------------------------------------\n");
    printf("MANAGER NAME: %s\n AGE %d\n SALARY %d\n ",m.name,m.age,m.salary);
    printf("EMPLOYEES: ");
    for(int i = 0;i < m.index;i++)
    {
       printEmployeeName(m.employees[i]);
    }    
    printf("\n");
    printf("-------------------------------------------------------------\n");
} 

int main ( void )
{
    //employee print
    struct Employee conor = {"Conor O'Riordan",39,89000,11,"Analyst"};
    struct Employee aideen = {"Aideen Hughes",38,55000,9,"Teacher"};
    struct Employee sarah = {"Sarah O Shea",22,23000,21,"Accountant"};
    

    
    printEmployee(conor);
    printEmployee(aideen);
    printEmployee(sarah);
    
    //adding to modules
    struct Module module = {"Irish",10};
    struct Module module2 = {"Python",5};
    struct Module module3 = {"JAVA",5};
    struct Module module4 = {"Geography",8};

    //adding to student
    struct Student leo = {"Leo O Riordan",12};
    struct Student john = {"John Mcmahon",14};

    leo.modules[leo.index++] = module;
    leo.modules[leo.index++] = module2;
    leo.modules[leo.index++] = module3;
    leo.modules[leo.index++] = module4;

    john.modules[john.index++] = module2;
    john.modules[john.index++] = module4;

    printStudent(leo);
    printStudent(john);

    struct Manager pep = {"Pep Guardiola",45,234561};
    struct Manager alex = {"Alex Ferguson",82,434561};

    pep.employees[pep.index++] = conor;
    pep.employees[pep.index++] = aideen;
    pep.employees[pep.index++] = sarah;

    alex.employees[alex.index++] = aideen;

    printManager(pep);
    printManager(alex);


    return 0;
}
