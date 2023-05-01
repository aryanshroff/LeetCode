#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Knapsack
{
public:
    int serial_number;
    int item_value;
    int item_weight;
    double ratio; //ratio of poorofit to weight
    double fraction;  //denotes the accepted fraction of the object

    Knapsack(int i, int p, int w)
    {
        serial_number = i;
        item_value = p;
        item_weight = w;
        ratio = (double)p / (double)w;
        fraction = 0.0;
    }

    void display_item_specification()
    {
        cout << "Object: " << serial_number << "    Value:" << item_value << "      Weight:" << item_weight << "       Ratio:" << ratio << endl;
    }
    void display_item_stats()
    {
        if (fraction == 1)
        {
            cout << "Object: " << serial_number << "      FULL" << endl;
        }
        else
        {

            cout << "Object: " << serial_number << "      qty: " << fraction << endl;
        }
    }
};

bool cmp(Knapsack *pointer_to_obj1, Knapsack *pointer_to_obj2)
{
    if (pointer_to_obj1->ratio > pointer_to_obj2->ratio)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print_vector(vector<Knapsack *> &items)
{
    Knapsack *temp;
    cout << endl;
    cout << "Item specification: " << endl;
    for (int i = 0; i < items.size(); i++)
    {
        temp = items[i];
        temp->display_item_specification();
    }
    cout << endl;
}

void fractional(vector<int> &weight, vector<int> &profit, int &capacity)
{
    int n = profit.size();
    vector<Knapsack *> items;
    for (int i = 0; i < n; i++)
    {
        int p = profit[i];
        int w = weight[i];
        Knapsack *temp = new Knapsack(i + 1, p, w);
        items.push_back(temp);
    }
    sort(items.begin(), items.end(), cmp);
    print_vector(items);
    vector<Knapsack *> selected;
    int index = 0;
    double gain = 0;
    while (index < items.size())
    {
        Knapsack *temp = items[index];
        if (temp->item_weight <= capacity)
        {

            capacity -= temp->item_weight;
            temp->fraction = 1;
            gain += temp->item_value;
            selected.push_back(temp);
            index++;
        }
        else
        {
            // select a fraction of item;
            double wt = temp->item_weight;
            double fract = (double)capacity / wt;
            capacity = 0;
            temp->fraction = fract;
            int val = temp->item_value;
            gain += val * fract;
            selected.push_back(temp);
            break;
        }
    }
    cout << "Profit earned:" << gain << endl;
    cout << endl;
    cout << "Objects picked: " << selected.size() << endl;
    for (int i = 0; i < selected.size(); i++)
    {
        Knapsack *temp = selected[i];
        temp->display_item_stats();
    }
}

int main()
{
    // take all input here
    vector<int> profit = {5, 5, 6, 7, 7, 8, 9, 10, 10, 14, 20, 24};
    //{60,100,120,88};

    vector<int> weight = {3, 5, 2, 8, 12, 4, 10, 12, 16, 17, 16, 25};
    int capacity = 125;

    // input end
    chrono::system_clock::time_point start = high_resolution_clock::now();
    fractional(weight, profit, capacity);
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