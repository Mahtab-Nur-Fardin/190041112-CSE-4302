///lab 13
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;


int main()
{
    int even[] = {4, 2,6 , 12 ,8};

    set<int> oddset;

    oddset.insert(5);
    oddset.insert(29);
    oddset.insert(17);

    vector<int> vec(30);

    merge(even, even+5, oddset.begin(),oddset.end(),vec.begin());

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    return 0;
}
