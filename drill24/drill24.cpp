//drill24

/*
1. Print the size of a char, a short, an int, a long, a float, a double, an int*, and a double* (use sizeof, not <limits>).

2. Print out the size as reported by sizeof of Matrix<int> a(10), Matrix<int> b(100), Matrix<double> c(10), Matrix<int,2> d(10,10), Matrix<int,3> e(10,10,10).

3. Print out the number of elements of each of the Matrixes from 2.

4. Write a program that takes ints from cin and outputs the sqrt() of each int, or “no square root” if sqrt(x) is illegal for 
some x (i.e., check your sqrt() return values).

5. Read ten floating-point values from input and put them into a Matrix<double>. Matrix has no push_back() so be
careful to handle an attempt to enter a wrong number of doubles. Print out the Matrix.

6. Compute a multiplication table for [0,n)*[0,m) and represent it as a 2D Matrix. Take n and m from cin and print out
the table nicely (assume that m is small enough that the results fit on a line).

7. Read ten complex<double>s from cin (yes, cin supports >> for complex) and put them into a Matrix. Calculate
and output the sum of the ten complex numbers.

8. Read six ints into a Matrix<int,2> m(2,3) and print them out.*/

//g++ drill24.cpp -o drill24

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <cerrno>
#include <complex>
#include <numeric>
#include "../header/MatrixIO.h"
#include "../header/Matrix.h"
using namespace std;
using namespace Numeric_lib;

int main(){

	try{		

		//1.
		cout << "SIZEOFs:\n";
		cout << "char:\t\t" << sizeof(char) << '\n';
		cout << "short:\t\t" << sizeof(short) << '\n';
		cout << "int:\t\t" << sizeof(int) << '\n';
		cout << "long:\t\t" << sizeof(long) << '\n';
		cout << "float:\t\t" << sizeof(float) << '\n';
		cout << "double:\t\t" << sizeof(double) << '\n';
		cout << "int*:\t\t" << sizeof(int*) << '\n';
		cout << "double*:\t" << sizeof(double*) << "\n\n";

		//2.
		Matrix<int> a(10);
		Matrix<int> b(100);
		Matrix<double> c(10);
		Matrix<int,2> d(10,10);
		Matrix<int,3> e(10,10,10);

		cout << "MATRIX SIZEOFs:\n";
		cout << "1D Matrix<int>(10):\t\t" << sizeof(a) << '\n';
		cout << "1D Matrix<int>(100):\t\t" << sizeof(b) << '\n';
		cout << "1D Matrix<double>(10):\t\t" << sizeof(c) << '\n';
		cout << "2D Matrix<int,2>(10,10):\t" << sizeof(d) << '\n';
		cout << "3D Matrix<int,3>(10,10,10):\t" << sizeof(e) << '\n';

		//3.
		cout << "\nNUMBER OF MATRIX ELEMENTS:\n";
		cout << "(a) 1D Matrix<int>(10):\t\t" << a.size() << '\n';
		cout << "(b) 1D Matrix<int>(100):\t" << b.size() << '\n';
		cout << "(c) 1D Matrix<double>(10):\t" << c.size() << '\n';
		cout << "(d) 2D Matrix<int,2>(10,10):\t" << d.size() << '\n';
		cout << "(e) 3D Matrix<int,3>(10,10,10):\t" << e.size() << '\n';

		//4.
		cout << "\nENTER SOME INTEGER TO SQRT: ";
		int val;
		while (cin >> val) //exit=> any charachter
		{
			if (val<=0)
			{
				cout << "THE VALUE MUST BE GREATER THAN ZERO" << endl;
			}
			else
			{
				cout << "SQRT: " << sqrt(val) << endl;
			}
		}

		//5.
		cin.clear();
		cin.ignore();
		cout<<"\nENTER 10 FLOATING POINT VALUES:\n";
		Matrix<double> m(10);
		int float_val;
		for (int i = 0; i < m.size(); ++i)
		{
			cin >> float_val;
			if(!cin) throw runtime_error("Problem reading from cin.");	
			m[i]=float_val;
		}
		cout << "FLOAT MATRIX: "<< m << '\n';

		//6.
		cout << "ENTER THE DIMENSION OF THE MULTIPLICATION TABLE : ";
		int dim_m, dim_n;
		cin >> dim_m >> dim_n;
		cout << '\n';

		Matrix<double,2> mult_table(dim_m,dim_n);

		for (int i = 0; i < mult_table.dim1(); ++i)
		{
			for (int j = 0; j < mult_table.dim2(); ++j)
			{
				mult_table(i,j)=(j+1)*(i+1); 
			}
		}
		
		for (int i = 0; i < mult_table.dim1(); ++i) 
		{
			for (int j = 0; j < mult_table.dim2(); ++j)
			{
				cout << setw(5) << mult_table(i,j);

			}
			cout << '\n';
		}

		//7. 
   		cout << "\nENTER 10 COMPLEX NUMBERS (Re, Im): \n";
   		complex<double> complex_val;
   		Matrix<complex<double>> complex_m (10);

   		for (int i = 0; i < complex_m.size(); ++i) 
   		{
        	cin >> complex_val;
        	if(!cin) throw runtime_error("Problem reading complex number!");
        	complex_m[i]=complex_val;
   		}
   		cout<<"COMPLEX MATRIX: "<<complex_m<<'\n';
   		complex<double> complex_sum_val;

   		for(Index i=0; i<complex_m.size();i++)
		{
			complex_sum_val+=complex_m[i];
		}
		cout<<"COMPLEX MATRIX SUM: "<<complex_sum_val<<'\n';
	
		//8.
		cout << "\nENTER VALUES TO THE (2x3) CUSTOM_MATRIX\n";
		Matrix<int,2> custom_m (2,3);
		for (int i = 0; i < custom_m.dim1(); ++i)
		{
			for (int j = 0; j < custom_m.dim2(); ++j)
		    cin >> custom_m[i][j];
		}
		cout << custom_m;

	}
	catch (exception& e)
	{
		cerr<<"Exception: "<<e.what()<<'\n';
	}
	catch(...) 
	{
		cerr<<"Exception!\n";
	}
}
