#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

bool dfs(unordered_map<pair<int,int>,bool,hash_pair> &visited)

 int closedIsland(vector<vector<int>>& g) {
        //store all zeros in hmap as unvisited
        //pick a 0 , apply dfs on it and mark all the 0s that u find as dfs traversal as visited
        //in 1 dfs call you will comp0lete 1 island , if in entire dfs call closed island prop was maintained its closed island
        unordered_map <pair<int,int>,bool,hash_pair> visited;
        int r=g.size();
        int c=g[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(g[i][j]==0){
                    visited[{i,j}]=false;
                }
            }
        }
        //visited has indices of all 0s on the grid initially marked as false
        //once i visited a cell with 0 i ll mark the cell true on hmap
        //algo ends when i have completly traversed hmap
    }

int main()
{
    // take all input here
    vector<vector<int>> g={{1,1,1,1,1,1,1,0},{1,0,0,0,0,1,1,0},{1,0,1,0,1,1,1,0},{1,0,0,0,0,1,0,1},{1,1,1,1,1,1,1,0}};
    // input end
    chrono::system_clock::time_point start = high_resolution_clock::now();
    closedIsland(g);
    chrono::system_clock::time_point stop = high_resolution_clock::now();
    chrono::milliseconds duration = duration_cast<milliseconds>(stop - start);

    double time = duration.count();
    string unit = "ms";
    if (time >= 1000 and time < 60000)
    {
        time = time / 1000;
        unit = "sec";
    }
    cout << endl;
    cout << endl;
    cout << "Code Execution Time: " << time << " " << unit << endl;
    return 0;
}