#include<iostream>
using namespace std;
class Employee
{
    protected: string name_;
    public:
        virtual void processSalary()=0;
};
class Engineer: public Employee
{
    public: Engineer(const string& name) {name_=name;}
    void processSalary() {cout<<name_<<"\t\t process salary for \tEngineer "<<endl;}
};
class Manager: public Engineer
{
    Engineer *reports_[10];
    public: Manager(const string& name):Engineer(name) {}
    void processSalary() {cout<<name_<<"\t\t process salary for \tManager "<<endl;}
};
class Director: public Manager
{
    Manager *reports_[10];
    public: Director(const string& name):Manager(name) {}
    void processSalary() {cout<<name_<<"\t\t process salary for \tDirector "<<endl;}
};
class Sales: public Employee
{
    public: Sales(const string& name) {name_=name;}
    void processSalary() {cout<<name_<<"\t\t process salary for \tSales "<<endl;}
};
int main()
{
    Engineer e1("Rohit"), e2("Aman"),e3("Rana");
    Manager m1("Arvind"), m2("Madhav"), m3("Adarsh"),m4("Kalpana");
    Director d1("Raghav");
    Sales s1("Subham"), s2("Sagar");
    Employee *staff[]={&m1,&e1,&m3,&e2,&s1,&d1,&e3,&s2,&m2,&m4};
    for(int i=0;i<sizeof(staff)/(sizeof(Employee*));i++)
    {
        staff[i]->processSalary();
    }
    return 0;

}
