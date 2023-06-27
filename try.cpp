long long totalCost(vector<int> &costs, int k, int pqs)
{
    // pqs i.e size of pq and k=number of hiring rounds takking place
    priority_queue<int, vector<int>, greater<int>> lpq;
    priority_queue<int, vector<int>, greater<int>> rpq;
    int n = costs.size();

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
        cout << "v[i] = " << costs[i] << "  v[j]: " << costs[j];
        cout << "         i: " << i << " j: " << j << endl;
        lpq.push(costs[i]);

        i++;
        if (i >= j)
        {
            break;
        }
        rpq.push(costs[j]);
        j--;
        if (i >= j)
        {
            break;
        }
        cs++;
    }
    cout << endl;

    // reached here means both pqs are filled time to hire

    int round = 0;
    int lt = 0, rt = 0;
    while (round < k and i <= j)
    {

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

        round++;
    }
    // reached here means either rounds are over or i equals j
    while (round < k and lpq.size() > 0 and rpq.size() > 0)
    {

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

        round++;
    }
    while (round < k and lpq.size() > 0)
    {
        // reached here means rpq is empty
        lt = lpq.top();
        sum += lt;
        lpq.pop();
        round++;
    }
    while (round < k and rpq.size() > 0)
    {
        // reached here means lpq is empty
        rt = rpq.top();
        sum += rt;
        rpq.pop();
        round++;
    }
    // now we are sure rounds are over
    return sum;
}