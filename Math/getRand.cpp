#include <bits/stdc++.h>
using namespace std;

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

class RandomizedSet
{
public:
    unordered_map<int, int> h; // value;index
    vector<int> v;
    int n;
    RandomizedSet()
    {
        n = 0;
    }

    bool insert(int val)
    {
        if (h.find(val) == h.end())
        {
            // not ptresent
            v.push_back(val);
            h[val] = n;
            n++;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool remove(int val)
    {
        if (h.find(val) == h.end())
        {
            // val not present
            return false;
        }
        else
        {
            if (n == 1)
            {
                v.pop_back();
                h.erase(val);
                n--;
                return true;
            }
            else
            {
                // remove from array
                auto it = h.find(val);
                int location = it->second;
                int newval = v[n - 1];
                v[location] = newval;
                v.pop_back();
                n--;

                // remove from hashmap
                h.erase(it);

                // update the swaped location in hashmap
                h[newval] = location;
                return true;
            }
        }
    }

    int getRandom()
    {
        int random = rand();
        random = random % n;
        return v[random];
    }

    void display()
    {
        cout << "n: " << n << endl;
        printhash(this->h);
        print1d(this->v);
        cout << "over" << endl;
        cout << endl;
    }
};

int main()
{
    RandomizedSet *obj = new RandomizedSet();
    bool param_1 = obj->insert(0);
    obj->display();
    bool param_2 = obj->remove(0);
    obj->display();
    bool param_4 = obj->insert(0);
    cout << param_1 << " " << param_2 << " " << param_4 << endl;
    int param_3 = obj->getRandom();
    return 0;
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */