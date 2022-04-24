//drill15_2(struct)

/*
1. Define a struct Person containing a string name and an int age.

2. Define a variable of type Person, initialize it with “Goofy” and 63, and write it to the screen (cout).

3. Define an input (>>) and an output (<<) operator for Person; read in a Person from the keyboard (cin) and write it out to the screen (cout).

4. Give Person a constructor initializing name and age.

5. Make the representation of Person private, and provide const member functions name() and age() to read the name and age.

6. Modify >> and << to work with the redefined Person.

7. Modify the constructor to check that age is [0:150) and that name doesn’t contain any of the characters ; : " ' [ ] * & ^
% $ # @ !. Use error() in case of error. Test.

8. Read a sequence of Persons from input (cin) into a vector<Person>; write them out again to the screen (cout). Test
with correct and erroneous input.

9. Change the representation of Person to have first_name and second_name instead of name. Make it an error not to
supply both a first and a second name. Be sure to fix >> and << also. Test.*/

//g++ drill15_2.cpp -o drill15_2

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

struct Person
{
	private:
	    string f;
	    string l;
	    int a;

	public:
	    Person(){};
	    Person (string first, string last, int age) : f{first}, l{last},a{age}
	    {
	    	if (age < 0 || age > 150)
	    	{
	    		throw runtime_error("invalid age");
	    	}
	    	string n = first + last;
	    	for (int i = 0; i < n.length(); i++)
	    	{
	    		if (n[i] == ';' || n[i] == ':' || n[i] == '"' || n[i] == '[' || n[i] == ']' || n[i] == '*' || n[i] == '&' || n[i] =='^' || n[i] == '%' || n[i] == '$' || n[i] == '#' || n[i] == '@' || n[i] == '!')
			{
				throw runtime_error ("Invalid name!");
			}
	    	}
	  
	    }
		string first()const{return f;}
		string last()const{return l;}
		int age()const{return a;}
	
};

ostream& operator<< (ostream& os, const Person& p)
{
	return os << p.first() << " " << p.last()<< " " << p.age()<<endl;
}

istream& operator>> (istream& is, Person& p)
{
	string f;
	string l;
	int a;
	is >> f >> l >> a;
	p=Person(f,l,a);
	return is;
}

int main(){
	/*
	Person p1;
	p1.name = "Goofy";
	p1.age = 63;*/

	Person p1 {"Goofy","Goofy",63};
	cout << "Name: " << p1.first()<<" "<< p1.last() << " Age: " << p1.age() << endl;
	
	Person p2;
	Person p3;
	cin >> p2 >> p3;
	cout << p2 << p3;

	vector<Person> vec;

	for (Person p; cin >> p;)
	{
		if (p.first() == "end") break;
		vec.push_back(p);
	}

	for (Person p: vec)
	{
		cout << p << endl;
	}
}
