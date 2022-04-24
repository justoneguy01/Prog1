//drill20

/*
1. Define an array of ints with the ten elements { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 } array<int, size>.

2. Define a vector<int> with those ten elements.

3. Define a list<int> with those ten elements.

4. Define a second array, vector, and list, each initialized as a copy of the first array, vector, and list, respectively.

5. Increase the value of each element in the array by 2; increase the value of each element in the vector by 3; increase the
value of each element in the list by 5.

6. Write a simple copy() operation,
Click here to view code image
template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2);
that copies [f1,e1) to [f2,f2+(e1–f1)) and returns f2+(e1–f1) just like the standard library copy function. Note that if
f1==e1 the sequence is empty, so that there is nothing to copy.

7. Use your copy() to copy the array into the vector and to copy the list into the array.

8. Use the standard library find() to see if the vector contains the value 3 and print out its position if it does; use find() to
see if the list contains the value 27 and print out its position if it does. The “position” of the first element is 0, the
position of the second element is 1, etc. Note that if find() returns the end of the sequence, the value wasn’t found.
Remember to test after each step.*/

//g++ drill20.cpp -o drill20

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
using namespace std;

template<typename T>
void print(const T& t)
{
	for (auto& i : t)
	{
		cout << i << ' ';
	}
	cout << endl;
}

template <typename C>
void inc(C& c, int n){
	for (auto& i : c)
	{
		i+=n;
	}
}

//6.
template<typename Iter1, typename Iter2>
Iter2 orai_copy(Iter1 f1, Iter1 e1, Iter2 f2){ //nem értem xd
	for (Iter1 p = f1; p != e1; ++p)
	{
		*f2++ = *p;
	}
	return f2;
}

int main(){

	constexpr int size = 10;
	int numbers[]={ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 

	//1.
	array<int, size> ai;
	copy(numbers, numbers+size, ai.begin());
	//print(ai);

	//2.
	vector<int> vi(size);
	copy(numbers, numbers+size, vi.begin());
	//print(vi);

	//3.
	list<int> li(size);
	copy(numbers, numbers+size, li.begin());
	//print(li);

	//4.
	array<int, size> ai2 = ai;
	print(ai2);
	vector<int> vi2 = vi;
	print(vi2);
	list<int> li2 = li;
	print(li2);
	cout <<"\n";

	//5.
	inc(ai2,2);
	inc(vi2,3);
	inc(li2,5);

	print(ai2);
	print(vi2);
	print(li2);
	cout <<"\n";

	//7.
	orai_copy(ai2.begin(), ai2.end(), vi2.begin());
	orai_copy(li2.begin(), li2.end(), vi2.begin());

	print(ai2);
	print(vi2);
	print(li2);

	//8.
	//find(ai2.begin(), ai2.end(), 3);
	//std::distance() cppreference.com

	vector<int>::iterator vit;
	vit = find(vi2.begin(),vi2.end(),3);
	if (vit != vi2.end())
	{
		cout << "Found at: " << distance(vi2.begin(), vit) << endl;
	}else{
		cout << "Not found" << endl;
	}
	
	vit = find(vi2.begin(),vi2.end(),27);
	if (vit != vi2.end())
	{
		cout << "Found at: " << distance(vi2.begin(), vit) << endl;
	}else{
		cout << "Not found" << endl;
	}
}
