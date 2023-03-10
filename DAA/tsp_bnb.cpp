#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void print1d(vector<int> v)
{
    cout << " 1D VECTOR " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << endl;
}

void print2d(vector<vector<int>> v)
{
    cout << " 2D VECTOR " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (v[i][j] < 10 and v[i][j] >= 0)
            {
                cout << "0";
            }
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

class Node
{
public:
    int my_id;
    int my_og_y;
    int my_og_x;
    int my_height; //is also same as my_og_x
    int my_cost;
    int parent_index; // in given vector
    int parent_id;    // location of parent in levels vector
    vector<vector<int>> v;
    Node(vector<vector<int>> v, int my_og_x= -1,int my_og_y=-1, int my_height = -1, int my_cost = -1, int parent_id = -1, int parent_index = -1, int my_id = -1)
    {
        this->my_cost = my_cost;
        this->my_height = my_height;
        this->my_og_x=my_og_x;
        this->my_og_y = my_og_y;
        this->parent_id = parent_id;
        this->parent_index = parent_index;
        this->v = v;
        this->my_id = my_id;
    }
    void myself()
    {
        cout << "My_x: "<<my_og_x<<"  my_y" << my_og_y << "      Position in levels:" << my_height << "," << my_id << " Cost:" << my_cost << endl;
        cout << "Parent details: Index:" << parent_index << " Position:" << my_height - 1 << "," << parent_id << endl;
        cout << endl;
        cout << endl;
    }
};

void print_Node_vector(vector<vector<Node>> v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Node temp = v[i][j];
            if (temp.my_cost != -1)
            {
                temp.myself();
            }
        }
    }
}




void generateChildren(int &parent_index, int &n, vector<vector<Node>> &levels, vector<vector<int>> &og, int &height,int parent_cost)
{
    cout<<"generate children"<<endl;

    for (int i = 0; i < n; i++)
    {
        int child_index=i;
        cout<<"parent: "<<parent_index<<" child: "<<i<<endl;
        int cost = 0;
        if (og[parent_index][child_index] != -1)
        {
            // perform negation
            vector<vector<int>> child_og = og;
            for (int k = 0; k < n; k++)
            {
                child_og[k][child_index] = -1;
                child_og[parent_index][k] = -1;
            }
            child_og[child_index][parent_index] = -1;
            cout<<"Performed negation "<<endl;
            print2d(child_og);
            // perform reduction
            cout<<"performed reduction"<<endl;
            reduce(cost, child_og);
            cost+=parent_cost+og[parent_index][child_index];
            // create node
            Node obj1(child_og,height-1, child_index, height, cost, height - 1, parent_index);
            obj1.myself();

            // append node at correct height and correct index in levels vector
            for (int id = 0; id < n; id++)
            {
                Node temp = levels[height - 1][id];
                if (temp.my_og_y == parent_index)
                {
                    obj1.parent_id = id;
                    break;
                }
            }

            for (int i = 0; i < n; i++)
            {
                Node temp = levels[height][i];
                if (temp.my_cost == -1)
                {
                    obj1.my_id = i;
                    levels[height][i] = obj1;
                }
            }
        }
    }
}

int generateBranch(int &parent_index, int &n, vector<vector<Node>> &levels, vector<vector<int>> &og, int &height, int &cost, Node &temp)
{

    int total = cost;
    while (height <= n)
    {
        generateChildren(parent_index, n, levels, og, height,cost);
        print_Node_vector(levels);
        // once the children are generated we pick the one with min cost
        int m = INT_MAX;

        for (int i = 0; i < levels[height].size(); i++)
        {
            Node obj1 = levels[height][i];
            if (m > obj1.my_cost)
            {
                m = obj1.my_cost;
                temp = obj1;
            }
        }
        // here temp is the object with min cost and we treat it as parent
        total += m;
        og = temp.v;
        parent_index = temp.parent_index;
        height++;
    }
    return total;
}

void tsp(vector<vector<int>> &v)
{
    int n = v.size(); // => and that will be max height
    int cost = 0;
    vector<vector<int>> empty;
    Node temp(empty);
    vector<vector<Node>> levels(n, vector<Node>(n, temp));
    int height = 1;
    int parent_index = 0;
    print2d(v);
    vector<vector<int>> og = v;
    reduce(cost, og);
    print2d(og);
    
    int up = generateBranch(parent_index, n, levels, og, height, cost, temp);
    // check here for upper bound edge case
    cout << "Upper bound: " << up << endl;
    
}

int main()
{
    // take all input here
vector<vector<int>> v = {{-1, 20, 30, 10, 11},
                             {15, -1, 16, 4, 2},
                             {3, 5, -1, 2, 4},
                             {19, 6, 18, -1, 3},
                             {16, 4, 7, 16, -1}};
    
    // input end
    chrono::system_clock::time_point start = high_resolution_clock::now();
    tsp(v);
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