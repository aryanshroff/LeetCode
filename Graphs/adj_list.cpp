#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// to generate an adjecentcy list  for a unweighted undirected graph of cities interconnected
// between each other, format=> vector of vectors

class Graph
{
public:
    vector<string> city;          // inde3x to city name
    unordered_map<string, int> h; // city name to index
    vector<vector<int>> list;
    void addVertex(string name)
    {
        int index = city.size();
        city.push_back(name);
        h[name] = index;
        vector<int> v;
        list.push_back(v);
        // we have pushed an empty vector in list coz as of now our city has no connected cities
    }

    int getIndex(string source)
    {
        auto it = h.find(source);
        return it->second;
    }

    string getString(int index)
    {
        return city[index];
    }

    void createEdge(string name, vector<string> v)
    {
        // name is name of vertex say Pune
        // v will hold all the names of city that are connected to Pune (weight ==1 of all paths)
        // note: name and all cities are already created and are in hashset
        int source_index = getIndex(name);
        for (int i = 0; i < v.size(); i++)
        {
            int target_index = getIndex(v[i]);
            list[source_index].push_back(target_index);
            list[target_index].push_back(source_index);
        }
    }

    void display()
    {
        for (int i = 0; i < list.size(); i++)
        {
            for (int j = 0; j < list[i].size(); j++)
            {
                cout << list[i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;
        cout<<endl;
    }
    void displayMat()
    {
        cout << "Reference:" << endl;
        for (int i = 0; i < city.size(); i++)
        {
            cout << i << ":" << city[i] << " ";
        }
        cout << endl;
        cout<<endl;
        cout << "Adjecentcy matrix" << endl;
        for (int i = 0; i < city.size(); i++)
        {
            int point = 0;
            int j = 0;
            int last = list[i].back();
            while (j < city.size())
            {

                if (j == list[i][point])
                {
                    cout << 1 << " ";
                    point++;
                }
                else
                {
                    cout << 0 << " ";
                }
                j++;
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph obj1;
    obj1.addVertex("Pune");
    obj1.addVertex("Mumbai");
    obj1.addVertex("Delhi");
    obj1.addVertex("Agra");
    obj1.createEdge("Pune", {"Mumbai", "Delhi"});
    obj1.createEdge("Mumbai", {"Delhi", "Agra"});
    obj1.display();
    obj1.displayMat();

    return 0;
}