#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Compare_class;
class Job
{
    static int counter;
    char object_id;
    int object_value;
    int object_deadline;

public:
    int getProfit()
    {
        return object_value;
    }
    int getDeadline()
    {
        return object_deadline;
    }
    Job(int profit, int deadline)
    {
        this->object_value = profit;
        this->object_deadline = deadline;
        int val = counter;
        object_id = char(val + 97);

        counter++;
    }
    void display_object()
    {
        cout << "id: " << object_id << " profit:" << object_value << " object_deadline:" << object_deadline << endl;
        cout << endl;
    }
};
int Job::counter = 0;

class Compare_class
{
public:
    bool operator()(Job &a, Job &b)
    {
        // max profit at top:  return true for what you want at top
        if (a.getProfit() < b.getProfit())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

bool compare_function(Job &a, Job &b)
{
    if (a.getDeadline() < b.getDeadline())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void schedule(vector<int> &profit, vector<int> &due)
{
    int n = profit.size();
    vector<Job> job_vector;
    for (int i = 0; i < profit.size(); i++)
    {

        Job x(profit[i], due[i]);
        job_vector.push_back(x);
    }
    // vector of objects created
    sort(job_vector.begin(), job_vector.end(), compare_function);
    // sorted in ascending order of deadline
    for (int i = 0; i < job_vector.size(); i++)
    {
        job_vector[i].display_object();
    }
    vector<Job> res;

    priority_queue<Job, vector<Job>, Compare_class> pq; // highest profit on top

    for (int i = n - 1; i >= 0; i--)
    {
        int slot;
        if (i == 0)
        {
            slot = job_vector[i].getDeadline();
        }
        else
        {
            slot = job_vector[i].getDeadline() - job_vector[i - 1].getDeadline();
        }
        pq.push(job_vector[i]);
        while (slot > 0 and pq.size() > 0)
        {
            // cout << "slot: " << slot << endl;
            Job x = pq.top();
            // cout << "top object: ";
            // x.display_object();
            pq.pop();
            slot--;
            res.push_back(x);
        }
    }
    sort(res.begin(), res.end(), compare_function);
    cout << endl;
    int total_profit = 0;
    cout << "Selected Jobs: " << endl;
    for (int i = 0; i < res.size(); i++)
    {
        Job x = res[i];
        x.display_object();
        total_profit += x.getProfit();
    }
    cout << "Net profit earned: " << total_profit << endl;

    // vector of objects has been created
}

int main()
{
    // take all input here

    vector<int> profit = {100, 19, 27, 25, 15};
    vector<int> due = {2, 1, 2, 1, 3};

    // input end
    chrono::system_clock::time_point start = high_resolution_clock::now();
    schedule(profit, due);
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