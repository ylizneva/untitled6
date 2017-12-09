//
// Created by Yulia Lizneva on 2017-11-15.
//

#include "Student.h"
#include "Employee.h"
#include <iostream>


using namespace std;

int main(void)
{

    Student *s1 = new Student("Lisa", "lisa@mail.com", 1234);
    cout<<s1->toString()<<endl;

    Employee *e1 = new Employee("Kalle", "kalle@mail.com", "12wq");
    cout<<e1->toString()<<endl;



    Person *p1 = new Student("Bob", "bob@mail.com", 312);
    cout<<p1->toString()<<endl;

    Person *p2 = new Employee("Sara", "sara@mail.com", "DIDO");
    cout<<p2->toString()<<endl;

    //Person *p = new Person("Tom", "tom@mail.com"); //måste vara med pekare*
    //cout<<p->toString()<<endl;


    delete s1;
    delete e1;
    delete p1;
    delete p2;
   // delete p;

    return 0;
}