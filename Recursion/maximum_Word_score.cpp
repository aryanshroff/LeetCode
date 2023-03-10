#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> words, vector<char> letters, vector<int> score)
{
    
}

int main()
{
    vector<string> words = {"dog", "cat", "dad", "good"};
    vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'g', 'o', 'o'};
    vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << solve(words, letters, score) << endl;
    return 0;
}