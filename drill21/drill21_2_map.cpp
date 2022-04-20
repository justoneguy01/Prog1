//drill21_2_map

/*
1. Define a map<string,int> called msi.

2. Insert ten (name,value) pairs into it, e.g., msi["lecture"]=21.

3. Output the (name,value) pairs to cout in some format of your choice.

4. Erase the (name,value) pairs from msi.

5. Write a function that reads value pairs from cin and places them in msi.

6. Read ten pairs from input and enter them into msi.

7. Write the elements of msi to cout.

8. Output the sum of the (integer) values in msi.

9. Define a map<int,string> called mis.

10. Enter the values from msi into mis; that is, if msi has an element ("lecture",21), mis should have an element (21,"lecture").

11. Output the elements of mis to cout.*/

//g++ drill21_2_map.cpp -o drill21_2_map

#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <numeric>
using namespace std;

//3.
template <typename T,typename U>
void print(map<T,U>& m){

	cout << "=============" << '\n';
	for(const auto& a : m){

		cout << a.first << " " << a.second << endl;
	}
	cout << "=============" << '\n';
}

//5.
template <typename T,typename U>
void read(map<T, U>& m) {

    string key;
    int value;  
    for (int i = 0; i < 10; i++){

        cin >> key >> value;
        m.insert(make_pair(key, value));
    }
}

int main()
try{
	
	//1.
  	map<string, int> msi;
   	
   	//2.
	msi["Robert"] = 4;
	msi["Margret"] = 34;
	msi["Irene"] = 6;
	msi["Gregory"] = 38;
	msi["Lyle"] = 64;
	msi["Anne"] = 62;
	msi["Barbara"] = 33;
	msi["Young"] = 24;
	msi["Turk"] = 13;
	msi["Chloe"] = 9;

        //3.
        cout << "=============" << '\n';
        cout <<"MAP CONTENTS:"<< endl;
        print(msi);

        //4.
	msi.erase(msi.begin(), msi.end());
	//print(msi);

	//6.
	cout <<"READ:"<< endl;
	read(msi);
	cout <<"\nMAP NEW CONTENTS:"<< endl;

	//7.
	print(msi);

	//8.
	int sum =0;
	for(const auto& a : msi){

		sum +=a.second;
	}
	cout << "Sum of elements: " << sum << endl;

	//9.
	map<int, string> mis;

	//10.
	for (const auto& a : msi)
	{
	   	mis[a.second] = a.first;
	}

	//11.
	print(mis);
        
} catch(exception& e) {
	cerr << "Exception: " << e.what() << '\n';
	return 1;
} catch(...) {
	cerr << "Unknown exception!" << '\n';
	return 2;
}
