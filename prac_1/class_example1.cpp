#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
        string name;
        string idNum;
    public:
        Person(const string& nm, const string& id)
        :name(nm),
        idNum(id){}
        virtual void print();
        string getName();  
};

    void Person::print(){
    cout << "Name " << name << endl;
    cout << "IDnum " << idNum << endl;
}

string Person::getName() {return name;}

class Student : public Person{
    private:
        string major1;
        int gradYear;
    public:
          Student(const string& nm, const string& id, const string& maj, int year)
        :Person(nm, id),
         major1(maj),
         gradYear(year){}
        virtual void print();
        void changeMajor(const string& newMajor);
 
};

void Student::print(){
        Person::print();
        cout << "Major " << major1 << endl;
        cout << "Year " << gradYear << endl;
}

void Student::changeMajor(const string& newMajor)
{
    major1 = newMajor;
}

int main()
{
    Person person("Mary", "12-345");
    person.print();
    cout << endl;
    
    Student student("Bob", "98-764", "Math", 2012);
    student.changeMajor("English");
    student.print();
    cout << endl;
    
    Student* s = new Student("Carol", "34-927", "Physics", 2014);
    s -> print();

   return 0;
}