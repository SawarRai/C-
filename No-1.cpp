#include <iostream>
#include <array>
#include <string>
using namespace std;
class Person 
{
public:
    
string name;  
string date_of_birth;

Person(const string& name, const string& date_of_birth): name(name), date_of_birth(date_of_birth) {}
};

void find_persons_by_dob(const array<Person, 10>& persons, const string& dob)
{   
cout << "Persons with date of birth " << dob << ":" << 
endl;
    for (const auto& person : persons) {
        if (person.date_of_birth == dob) 
        {            
            cout << person.name << endl;
        }
    }
}

int main() {
    
array<Person, 10> persons = 
{
        Person("Ram", "2061-01-01"),
        Person("Hari", "2061-03-15"),
        Person("Shyam", "2062-01-01"),
        Person("Emonika", "2064-07-21"),
        Person("Bhuwan", "2060-04-2"),
        Person("Aditya", "2062-03-21"),
        Person("Yunisha", "2061-05-04"),
        Person("Sawar", "2062-09-29"),
        Person("Natasha", "2062-07-22"),
        Person("Pratima", "2060-03-18"),
};

    
string dob;
    
cout << "Enter a date of birth (YYYY-MM-DD): ";
    
cin >> dob;

    find_persons_by_dob(persons, dob);

    return 0;
}
