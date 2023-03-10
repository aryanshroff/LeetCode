#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void mymain(){
 cout<<"hello world"<<endl;
}

int main()
{
    chrono::system_clock::time_point start = high_resolution_clock::now();
    mymain();
    chrono::system_clock::time_point stop = high_resolution_clock::now();
    chrono::microseconds duration = duration_cast<microseconds>(stop - start);
    cout << endl;
    cout << "Duration: " << duration.count() <<"ms"<< endl;
    return 0;
}