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
    // Person person("Mary", "12-345");
    // person.print();
    // cout << endl;
    
    // Student student("Bob", "98-764", "Math", 2012);
    // student.changeMajor("English");
    // student.print();
    // cout << endl;
    
    // Student* s = new Student("Carol", "34-927", "Physics", 2014);
    // s -> print();



    Person* pp[100];
    pp[0] = new Person("Alexis", "42-395");
    pp[1] = new Student("Clark", "07-256", "Physics", 2014);
    // cout << "\n";
    // pp[0] -> print();
    // cout << "\n";
    

    Student* sp = dynamic_cast<Student*>(pp[1]);
    sp -> changeMajor("Chemistry");

    // for(int i =0; i < 100; i++){
    //     Student *sp = dynamic_cast<Student*>(pp[i]);
    //     if(sp != NULL){
    //         sp -> changeMajor("Undecided");
    //     }
    // }

    pp[1] -> print();

    return 0;

}