#include <iostream>
using namespace std;

class employee {
    public:
    string name;
    string company;
    int age;

    void introduceyourself(){
    cout<<"name="<<name<<endl;
    cout<<"company="<<company<<endl;
    cout<<"age="<<age<<endl;
    }

};

int main()
{
    employee employee1;
    employee1.name="Winnie";
    employee1.company="campus";
    employee1.age=19;

    employee1.introduceyourself();

    employee employee2;
    employee2.name="Lucy";
    employee2.company="Home";
    employee2.age=30;

    employee2.introduceyourself();

    return 0;
}

