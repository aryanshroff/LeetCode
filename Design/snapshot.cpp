#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
public:
    vector<int> v;
    vector<vector<int>> memories;
    SnapshotArray(int length)
    {
        for (int i = 0; i < length; i++)
        {
            v.push_back(0);
        }
    }

    void set(int index, int val)
    {
        v[index] = val;
    }

    int snap()
    {
        // id and indexing both begin from 0 for this problem statement
        memories.push_back(this->v);
        int n = memories.size();
        return n - 1;
    }

    int get(int index, int snap_id)
    {
        return memories[snap_id][index];
    }
};

int main()
{
    SnapshotArray *obj = new SnapshotArray(3);
    obj->set(0, 5);

    int param_2 = obj->snap();
    cout<<param_2<<endl;

    int param_3 = obj->get(0, 0);
    cout<<param_3<<endl;

    obj->set(0, -1);
    int param_4 = obj->snap();

    obj->set(2,4);
    obj->set(1,8);
    int param_5 = obj->snap();

    int param_6 = obj->get(0,1);
    cout<<param_6<<endl;
}