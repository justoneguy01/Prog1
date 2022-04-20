//drill21_3_vec.cpp

/*
1. Read some floating-point values (at least 16 values) from a file into a vector<double> called vd.

2. Output vd to cout.

3. Make a vector vi of type vector<int> with the same number of elements as vd; copy the elements from vd into vi.

4. Output the pairs of (vd[i],vi[i]) to cout, one pair per line.

5. Output the sum of the elements of vd.

6. Output the difference between the sum of the elements of vd and the sum of the elements of vi.

7. There is a standard library algorithm called reverse that takes a sequence (pair of iterators) as arguments; reverse vd, and output vd to cout.

8. Compute the mean value of the elements in vd; output it.

9. Make a new vector<double> called vd2 and copy all elements of vd with values lower than (less than) the mean into vd2.

10. Sort vd; output it again.*/

//g++ drill21_3_vec.cpp -o drill21_3_vec

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

template<typename T>
void print(const vector<T>& t){
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (const auto a : t)
    {
        cout<<a<<endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
} 

template<typename T>
double sum(const vector<T>& t)
{
    double vec_sum;
    for (const auto a : t)
        vec_sum += a;
    return vec_sum;
}
int main(){
   
    try {   

            //1.
            vector<double> vd;
            ifstream input {"float.txt"};
            double value;
            while (input >> value)
            vd.push_back(value);

            //2.
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Float vector<double>:\n";
            print(vd); 
            cout <<"\n";

            //3.  
            vector<int> vi (vd.size());
            cout << "Float vector<int>:\n";
            copy(vd.begin(), vd.end(), vi.begin());
            print(vi); 

            //4.
            cout<<"\nVector pairs (vd[i],vi[i]):\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            for (int i = 0; i < vd.size(); ++i)
            {
                cout << vd[i]<<"\t\t"<< vi[i]<<endl; 
            }

            //5.
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "Sum of the elements of vd= " << sum(vd) << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

            //6.
            cout << "Difference sum(vd)-sum(vi)= " << sum(vd)-sum(vi) << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            
            //7.
            cout << "Reverse(vd): "<<endl;
            reverse(vd.begin(), vd.end());
            print(vd);
            cout <<"\n";

            //8.
            double vd_mean =sum(vd)/vd.size();
            cout << "Mean value of vd= " << vd_mean << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

            //9.
            cout << "Elements of vd2: " <<endl;
            vector<double> vd2;
            for(auto i: vd)
            {
                if (i < vd_mean)
                {
                    vd2.push_back(i);
                }
            }
            print(vd2);
            cout <<"\n";

            //10.
            cout << "Sorted vd2 elements: " <<endl;
            sort(vd.begin(),vd.end());
            print(vd);
            cout <<"\n";
    }
    catch(exception& e) {
        cerr << "Exception: " << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "Unknown exception\n";
        return 2;
    }
}
