class Solution
{
public:
    bool dfs(int n, vector<int> &v, unordered_map<string, bool> &h, int len, bool Alice)
    {
        // do not make calls on negative n
        if (Alice == true)
        {
            string s = "alice_" + to_string(n);
            auto it = h.find(s);
            if (it != h.end())
            {
                return it->second;
            }
            bool res = false;
            for (int i = 0; i < len; i++)
            {
                int temp = n - v[i];
                if (temp == 0)
                {
                    // alice ke time pe 0 hua hai means alice wins
                    res = true;
                    break;
                }
                if (temp == 0)
                {
                    continue;
                }
                bool branch_value = dfs(temp, v, h, len, false);
                if (branch_value == true)
                {
                    res = true;
                    break;
                }
            }
            h[s] = res;
            return res;
        }
        else
        {
            // its bobs turn
            string s = "bob_" + to_string(n);
            auto it = h.find(s);
            if (it != h.end())
            {
                return it->second;
            }
            bool res = true;
            for (int i = 0; i < len; i++)
            {
                int temp = n - v[i];
                if (temp == 0)
                {
                    // bob ke time pe 0 hua hai means alice looses
                    res = false;
                    break;
                }
                if (temp < 0)
                {
                    continue;
                }
                bool branch_value = dfs(temp, v, h, len, true);
                if (branch_value == false)
                {
                    res = false;
                    break;
                }
            }
            h[s] = res;
            return res;
        }
    }

    bool winnerSquareGame(int n)
    {
        // return true for alice win and false for bob
        // when its alices turn if any of the branch returns true then we return true
        // when its bobs turn  if any branch returns false then we return false
        unordered_map<string, bool> h;
        // inevery recursive call only 2 things change : value of n and whose turn it is
        vector<int> v;
        int limit = pow(n, 0.5);
        for (int i = 1; i <= limit; i++)
        {
            v.push_back(i * i);
        }
        int len = v.size();
        reverse(v.begin(), v.end());
        bool res = dfs(n, v, h, len, true);
        //printhash(h);
        return res;
    }
};