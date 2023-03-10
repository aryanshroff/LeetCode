#include <iostream>
#include <string>
using namespace std;

class Person
{

private:
    static int active_person;
    int id;
    string name;
    int power;

public:
    Person(string name = "none", int id = 0, int power = 0)
    {
        this->id = get_active();
        active_person++;
        this->name = name;
        this->power = power;
    }
    friend istream &operator>>(istream &in, Person &obj);
    static int get_active()
    {
        return active_person;
    }
    void display()
    {
        cout << "Name :" << this->name << endl;
        cout << "id : " << this->id << endl;
        cout << "power : " << this->power << endl;
        cout << endl;
    }
    string get_name()
    {
        return this->name;
    }
    int get_id()
    {
        return this->id;
    }
    int get_power()
    {
        return this->power;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_power(int power)
    {
        this->power = power;
    }
    ~Person()
    {
        active_person--;
    }
};
int Person::active_person = 0;

ostream &operator<<(ostream &out, Person &obj)
{
    out << "Person name: " << obj.get_name() << endl;
    ;
    out << "Person id: " << obj.get_id() << endl;
    ;
    out << "Person power:" << obj.get_power() << endl;
    cout << endl;
    return out;
}

istream &operator>>(istream &in, Person &obj)
{
    cout << "Enter person name: " << endl;
    in >> obj.name;
    cout << " Enter object power: " << endl;
    in >> obj.power;
    return in;
}

int main()
{
    // testing the class

    Person p1("Aryan", 0, 75);
    Person p2("Larry");
    cout << p1 << endl;
    Person p3;
    cout << p3 << endl;
    cin >> p3;
    cout << p3 << endl;
    return 0;
}
