//drill19

/*
1. Define template<typename T> struct S { T val; };.

2. Add a constructor, so that you can initialize with a T.

3. Define variables of types S<int>, S<char>, S<double>, S<string>, and S<vector<int>>; initialize them with values of your choice.

4. Read those values and print them.

5. Add a function template get() that returns a reference to val.

6. Put the definition of get() outside the class.

7. Make val private.

8. Do 4 again using get().

9. Add a set() function template so that you can change val.

10. Replace set() with an S<T>::operator=(const T&). Hint: Much simpler than §19.2.5.

11. Provide const and non-const versions of get().

12. Define a function template<typename T> read_val(T& v) that reads from cin into v.

13. Use read_val() to read into each of the variables from 3 except the S<vector<int>> variable.

14. Bonus: Define input and output operators (>> and <<) for vector<T>s. For both input and output use a { val, val, val }
format. That will allow read_val() to also handle the S<vector<int>> variable. Remember to test after each step.*/

//g++ drill19.cpp -o drill19

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
struct S {
	public:	
		S (T vv = 0) : val{vv}{}; 			
		T& get();
		void set(T new_val){val=new_val;}	//set
		void operator=(const T& S);		//(set) operator= 
		const T& get() const;			//const get 
	private: 		
		T val;
};

template<typename T>					//get
T& S<T>::get(){
	return val;
}

template<typename T>					//get
const T& S<T>::get() const{
	return val;
}

template<typename T>					//(set)operator= 
void S<T>::operator=(const T& s){
	val = s;
}

template<typename T>					//read
void read_val(T& v){
	cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
	os << "{ ";
	for (int i = 0; i < v.size(); ++i)
	{
		os << v[i];
		if (i < v.size()-1)
		{
			os << ", ";
		}
	}
	os << "}" << endl;
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
	char ch = 0;
	is >> ch;
	if (ch != '{')
	{
		is.unget();
		return is;
	}
	for (T val; is >> val;)
	{
		v.push_back(val);
		is >> ch;
		if (ch != ',') break;
	}
	return is;
}

int main(){

	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {3.2};
	S<string> ss {"Hello"};
	S<vector<int>> svi {vector<int>{1,1,2,3,5,8}};

	cout << "S<int> : " << si.get() << endl;
	cout << "S<char> : " << sc.get() << endl;
	cout << "S<double> : " << sd.get() << endl;
	cout << "S<string> : " << ss.get() << endl;
	cout << "S<vector<int>> : ";
	for (auto& a : svi.get())
	{
		cout << a << ' ';
	}
	cout << endl;

	//set
	sc.operator=('s');
	cout << "S<char> : " << sc.get() << endl;

	sd.operator=( 42.1);
	cout << "S<double> : " << sd.get() << endl;

	cout << "\nEnter an integer: " <<endl;
	int ii;
	read_val(ii);
	S<int> si2 {ii};

	cout << "\nEnter a double: " <<endl;
	double dd;
	read_val(dd);
	S<double> sd2 {dd};

	cout << "\nEnter a string " <<endl;
	string ss2;
	read_val(ss2);
	S<string> str {ss2};

	cout << "S<int> : " << si2.get() << endl;
	cout << "S<double> : " << sd2.get() << endl;
	cout << "S<string> : " << str.get() << endl;

   	cout << "Vector<int>: (format: { val1, val2, val3 }) ";
   	vector<int> vi2;
   	read_val(vi2);
   	S<vector<int>> svi2 {vi2};
	cout << "S<vector<int>> read: " << svi2.get() << '\n';
}
