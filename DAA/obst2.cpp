#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print1d(vector<T> v)
{
    cout << " 1D VECTOR " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << endl;
}

template <typename T>
void print2d(vector<vector<T>> v)
{
    cout << " 2D VECTOR " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

template <typename T>
void printstack(stack<T> s)
{
    cout << " STACK " << endl;
    while (s.empty() == false)
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
    cout << endl;
}

template <typename T>
void printq(queue<T> q)
{
    cout << " QUEUE " << endl;
    while (q.empty() == false)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << endl;
}

template <class K, class V>
void printhash(unordered_map<K, V> h)
{
    cout << " HASHMAP " << endl;
    for (auto it = h.begin(); it != h.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    cout << endl;
    cout << endl;
}

class cell
{
public:
    int child1;
    int child2;
    int parent;
    int x1;
    int y1;
    int x2;
    int y2;
    cell(int child1 = -1, int parent = -1, int x1 = -1, int y1 = -1, int child2 = -1, int x2 = -1, int y2 = -1)
    {
        this->child1 = child1;
        this->child2 = child2;
        this->parent = parent;
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    void myself()
    {
        cout << "Child1: " << child1 << " Parent:" << parent << " child1 cordinates:[" << x1 << "," << y1 << "]    Child2:" << child2 << " child2 coordinates:[" << x2 << "," << y1 << "]" << endl;
    }
};

int query(int i, int j, vector<int> &ps)
{
    // i and j are both inclusive
    if (i == 0)
    {
        return ps[j];
    }
    return ps[j] - ps[i - 1];
}

int solve(int &n, vector<vector<cell>> &storage, vector<vector<int>> &dp, vector<vector<int>> &root, vector<int> &v, vector<int> &f, vector<int> ps, unordered_map<int, int> &map)
{
    for (int i = 0; i < n; i++)
    {
        map[v[i]] = i;
        vector<int> temp;
        vector<int> temp2;
        vector<cell> temp3;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {

                temp.push_back(f[i]);
                temp2.push_back(v[i]);
                cell obj1(-2, v[j]);
                temp3.push_back(obj1);
            }
            else
            {
                temp.push_back(0);
                temp2.push_back(0);
                cell obj1;
                temp3.push_back(obj1);
            }
        }
        dp.push_back(temp);
        root.push_back(temp2);
        storage.push_back(temp3);
    }
    // print2d(dp);
    //  filling the matrix diagonally
    for (int g = 1; g < n; g++)
    {
        for (int j = g; j < n; j++)
        {
            // difference between i and j are same for every inner loop iteration and is equal to the value of g at any given time
            int i = j - g;
            if (g == 1)
            {
                int f1 = f[i];
                int f2 = f[j];
                int x = f1 + 2 * f2;
                int y = f2 + 2 * f1;
                if (x < y)
                {
                    dp[i][j] = x;
                    root[i][j] = v[i];

                    cell obj2(v[j], v[i], j, j);
                    storage[i][j] = obj2;
                }
                else
                {
                    dp[i][j] = y;
                    root[i][j] = v[j];

                    cell obj2(v[i], v[j], i, i);
                    storage[i][j] = obj2;
                }

                continue;
            }
            // cout<<"i: "<<i<<" j: "<<j<<" g:"<<g<<endl;
            int a = i;
            int b = j;
            // number of comparisions made is equal to length of corresponding subarray which is equal to value of g

            // k varies from  a to b with both bound boundaries inclusive
            int minval = INT16_MAX;
            int leftchild = -1;
            int rightchild = -1;
            int currRoot = 0;
            int total = 0;
            int x1 = -1;
            int y1 = -1;
            int x2 = -1;
            int y2 = -1;
            for (int k = a; k <= b; k++)
            {
                int left = 0, right = 0;
                if (k != a)
                {
                    left = dp[a][k - 1];
                }
                if (k != b)
                {
                    right = dp[k + 1][b];
                }
                total = left + right;
                if (total < minval)
                {
                    minval = total;
                    currRoot = v[k];
                    if (left != 0)
                    {
                        // parent of root of left subtree is current cell
                        // step 1 : finding root of left subtree
                        leftchild = root[a][k - 1];
                        x1 = a;
                        y1 = k - 1;
                    }
                    if (right != 0)
                    {
                        // parent of root of right subtree is current cell
                        rightchild = root[k + 1][b];
                        x2 = k + 1;
                        y2 = b;
                    }
                }
            }

            cell obj2(leftchild, currRoot, x1, y1, rightchild, x2, y2);
            storage[i][j] = obj2;
            minval += query(a, b, ps);
            dp[i][j] = minval;
            root[i][j] = currRoot;
        }
    }
    return dp[0][n - 1];
}

void generateBst2(int &n, vector<vector<cell>> &storage, unordered_map<int, int> &h)
{
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cell obj1 = storage[i][j];
            obj1.myself();
        }
    }
    */
    // backtrack untill we reach child1=-2
    queue<cell> q;
    q.push(storage[0][n - 1]);

    while (q.empty() == false)
    {
        cell obj1 = q.front();
        q.pop();
        if (obj1.child1 > 0)
        {
            h[obj1.child1] = obj1.parent;
            // add child to the queue
            int x1 = obj1.x1;
            int y1 = obj1.y1;
            q.push(storage[x1][y1]);
        }
        if (obj1.child2 > 0)
        {
            h[obj1.child2] = obj1.parent;
            int x2 = obj1.x2;
            int y2 = obj1.y2;
            q.push(storage[x2][y2]);
        }
    }
    // printhash(h);
}

void generateBst(vector<vector<int>> &root, unordered_map<int, int> &h, vector<vector<int>> &mat, unordered_map<int, int> &map, vector<int> &v, int &n)
{

    // printhash(h);
    vector<vector<int>> children;
    // cout<<"matrix representation: "<<endl;
    for (auto it = h.begin(); it != h.end(); it++)
    {
        int a = it->first;
        int b = it->second;
        a = map[a];
        b = map[b];
        mat[a][b] = 1;
    }
    // print2d(mat);
    cout << "metadata" << endl;
    vector<int> leaf;
    for (int j = 0; j < n; j++)
    {
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][j] == 1)
            {
                temp.push_back(v[i]);
            }
        }
        if (temp.size() == 0)
        {
            leaf.push_back(v[j]);
        }
        children.push_back(temp);
    }
    cout << "Root node: " << root[0][n - 1] << endl;

    // print1d(leaf);
    cout << "parent: list of  children" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " : [";
        for (int j = 0; j < children[i].size(); j++)
        {
            cout << children[i][j] << " ,";
        }
        cout << "]";
        cout << endl;
    }
}

int main()
{
    vector<int> v = {10, 20, 30, 40};
    vector<int> f = {4, 2, 6, 3};
    vector<int> ps;
    int n = f.size();

    vector<vector<int>> root;
    ps.push_back(f[0]);
    for (int i = 1; i < n; i++)
    {
        ps.push_back(f[i] + ps[i - 1]);
    }
    // print1d(ps);
    //  1 child will have only 1 parent but a parent can have 2 children
    //  hashmap format => child,parent
    vector<vector<cell>> storage;
    unordered_map<int, int> h;
    vector<vector<int>> dp;
    unordered_map<int, int> map; // integer to index mapping => this question will not have duplicates
    vector<vector<int>> mat(n, vector<int>(n, 0));
    int ans = solve(n, storage, dp, root, v, f, ps, map);
    cout << "Memoised Values" << endl;
    print2d(dp);
    cout << "The cost of Optimal Binary search Tree is: " << ans << endl;
    cout << endl;

    unordered_map<int, int> ultimateHashmap;
    generateBst2(n, storage, ultimateHashmap);
    generateBst(root, ultimateHashmap, mat, map, v, n);
    return 0;
}