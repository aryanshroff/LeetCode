#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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

template <class T>
void printHeap(priority_queue<T>& pq){
    while(pq.size()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}



// 2d vec of charecter to 2d vec of int
void generate(string s)
{
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            res.push_back('{');
        }
        else if (s[i] == ']')
        {
            res.push_back('}');
        }
        else
        {
            res.push_back(s[i]);
        }
    }
    cout << res << endl;
    cout << endl;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



// call generate function to generate 2d vector from string s

//************************************************************************************************************************************************************************************************
//************************************************************************************************************************************************************************************************
long long totalCost(vector<int> &costs, int k, int pqs)
{
    // pqs i.e size of pq and k=number of hiring rounds takking place
    priority_queue<int, vector<int>, greater<int>> lpq;
    priority_queue<int, vector<int>, greater<int>> rpq;
    int n = costs.size();
    cout<<"n: "<<n<<" k: "<<k<<" pqs: "<<pqs<<endl;
    cout<<endl;
    int i = 0, j = n - 1, cs = 0;
    // cs is the current pq size
    long long sum = 0;
    // fill candidate number of elements in both the pqs
    while (true)
    {
        if (cs >= pqs)
        {
            break;
        }
        cout<<"v[i] = "<<costs[i]<<"  v[j]: "<<costs[j];
        cout<<"         i: "<<i<<" j: "<<j<<endl;
        lpq.push(costs[i]);
        
        i++;
        if(i>=j){
            break;
        }
        rpq.push(costs[j]);
        j--;
        if(i>=j){
            break;
        }
        cs++;
    }
    cout<<endl;
    cout<<"143 i: "<<i<<" j: "<<j<<endl;

    // reached here means both pqs are filled time to hire
    
    int round = 0;
    int lt = 0, rt = 0;
    while (round < k and i <= j)
    {
        long long temp=sum;
        lt = lpq.top();
        rt = rpq.top();
        if (lt <= rt)
        {
            sum += lt;
            lpq.pop();
            lpq.push(costs[i]);
            i++;
        }
        else
        {
            // right top is smaller
            sum += rt;
            rpq.pop();
            rpq.push(costs[j]);
            j--;
        }
        cout<<"167 picked: "<<sum-temp<<endl;
        round++;
    }
    // reached here means either rounds are over or i equals j
    while (round<k and lpq.size()> 0 and rpq.size() > 0)
    {
        long long temp=sum;
        lt = lpq.top();
        rt = rpq.top();
        if (lt <= rt)
        {
            sum += lt;
            lpq.pop();
        }
        else
        {
            // right top is smaller
            sum += rt;
            rpq.pop();
        }
        cout<<"187 picked: "<<sum-temp<<endl;

        round++;
    }
    while (round < k and lpq.size() > 0)
    {
        // reached here means rpq is empty
        lt = lpq.top();
        sum += lt;
        lpq.pop();
        round++;
        cout<<"197 sum: "<<sum<<endl;

    }
    while (round < k and rpq.size() > 0)
    {
        // reached here means lpq is empty
        rt = rpq.top();
        sum += rt;
        rpq.pop();
        round++;
        cout<<"207 sum: "<<sum<<endl;

    }
    // now we are sure rounds are over
    return sum;
}

void mymain()
{
    string s = "";
    vector<int> costs = {48};
    int k = 1;
    int candidates = 1;
    print1d(costs);
    long long result = totalCost(costs, k, candidates);
    cout << "result: " << result << endl;
}

//************************************************************************************************************************************************************************************************
//************************************************************************************************************************************************************************************************

int main()
{
    chrono::system_clock::time_point start = high_resolution_clock::now();
    mymain();
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