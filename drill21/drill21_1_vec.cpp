
/*
1. Define a struct Item { string name; int iid; double value; /. . . . ./ };, 
make a vector<Item>, vi, and fill it withten items from a file.

2. Sort vi by name.

3. Sort vi by iid.

4. Sort vi by value; print it in order of decreasing value (i.e., largest value first).

5. Insert Item("horse shoe",99,12.34) and Item("Canon S400", 9988,499.95).

6. Remove (erase) two Items identified by name from vi.

7. Remove (erase) two Items identified by iid from vi.

8. Repeat the exercise with a list<Item> rather than a vector<Item>*/

//g++ drill21_1_vec.cpp -o drill21_1_vec

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <list>
using namespace std;

struct Item {
    string name; 
    int iid; 
    double value;
};

ostream& operator<<(ostream& os, Item& item){
        os << item.name << " " << item.iid << " " << item.value << endl;
    return os;
}

istream& operator>>(istream& is, Item& item){
    string n; 
    int i; 
    double d;
    is >> n >> i >> d;
    Item it{n,i,d};
    item = it;
    return is;
}

struct sort_by_name{
    bool operator()(const Item& a, const Item& b)
    {
        return a.name < b.name;
    }
};
struct sort_by_iid{
    bool operator()(const Item& a, const Item& b)
    {
        return a.iid < b.iid;
    }
};
struct sort_by_value_desc{
    bool operator()(const Item& a, const Item& b)
    {
        return a.value > b.value;
    }
};

class find_name{
private:
    string name;
public:
    find_name(const string& nn){name=nn;} //: name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};

class find_iid{
private:
    int iid;
public:
    find_iid(int id){iid=id;} //: iid{id} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};


template<typename T>
void print_list(T& t)
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (auto& a : t)
    {
        cout << a;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

template <typename T>
void print_vector(T& t){

    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    for (int i = 0; i < t.size(); ++i){
        cout << t[i];
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int main(){
    
    vector<Item> vi;

    ifstream file;
    file.open("file.txt");

    for (Item i ; file >> i;)
    {
        vi.push_back(i);
    }
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"\nDefault"<<endl<<endl;
    print_vector(vi);

    //8.
    list<Item> li (vi.size());
    copy(vi.begin(), vi.end(), li.begin());

    //2.
    cout<<"\nSort vi by name"<<endl<<endl;    
    sort(vi.begin(), vi.end(),sort_by_name());
    print_vector(vi);

    //3.
    cout<<"\nSort vi by iid"<<endl<<endl; 
    sort(vi.begin(), vi.end(),sort_by_iid());
    print_vector(vi);

    //4.
    cout<<"\nSort vi by value (desc)"<<endl<<endl; 
    sort(vi.begin(), vi.end(),sort_by_value_desc());
    print_vector(vi);

    //5.
    cout<<"\nAdding new elements"<<endl<<endl; 
    vi.push_back(Item{"horse shoe", 99, 12.34});
    vi.push_back(Item{"Canon S400", 9988, 499.95});
    print_vector(vi);

    //6
    cout<<"\nErasing two items identified by name"<<endl<<endl; 
    vi.erase(find_if(vi.begin(), vi.end(), find_name("table")));
    vi.erase(find_if(vi.begin(), vi.end(), find_name("chair")));
    print_vector(vi);

    //7.
    cout<<"\nErasing two items identified by iid"<<endl<<endl; 
    vi.erase(find_if(vi.begin(), vi.end(), find_iid(17)));
    vi.erase(find_if(vi.begin(), vi.end(), find_iid(83)));
    print_vector(vi);

    //8.
    cout<<"\nCopying to the list and repeating the exercise"<<endl<<endl; 
    print_list(li);
    // sort with lambda as predicate
    // list sort is member function since list does not have a random-access
    // iterator as needed by std::sort.
    li.sort([](const Item& a, const Item& b) { return a.name < b.name; });
    li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
    li.sort([](const Item& a, const Item& b) { return a.value > b.value; });

    li.push_back(Item{"horse shoe", 99, 12.34});
    li.push_back(Item{"Canon S400", 9988, 499.95});

    li.erase(find_if(li.begin(), li.end(), find_name("table")));
    li.erase(find_if(li.begin(), li.end(), find_name("chair")));

    li.erase(find_if(li.begin(), li.end(), find_iid(17)));
    li.erase(find_if(li.begin(), li.end(), find_iid(83)));
    cout<<"\nThe final result"<<endl<<endl;
    print_list(li);
}
