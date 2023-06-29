#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'shortestReach' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY edges
 *  3. INTEGER s
 */

typedef pair<int, int> pi;
vector<int> shortestReach(int n, vector<vector<int>> edges, int s)
{
    // step1 : convert edges to graph
    int parent, child, wt;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    //print2d(edges);
    // 0 means edge doesnt exist and value means edge weight
    for (int i = 0; i < edges.size(); i++)
    {
        parent = edges[i][0] - 1;
        child = edges[i][1] - 1;
        wt = edges[i][2];
        graph[parent][child] = wt;
        graph[child][parent] = wt;
    }
    //print2d(graph);
    int source = s - 1;
    vector<int> res(n, INT32_MAX);
    // putting source in pq
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pi x = {0, source};
    res[source] = 0;
    pq.push(x);
    while (pq.size() != 0)
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        //cout << "Node: " << node << " Dist: " << dist << endl;
        // insert all children of node to pq
        for (int i = 0; i < n; i++)
        {
            int val = graph[node][i];
            if (val != 0)
            {
                // i is the child and there exists an edge between node and child with edgewt=val
                // only push the child if the relaxation is performed on child
                int currDist = res[i];
                int wt = val + res[node];
                //cout << "child: " << i << " currDist: " << currDist << " val: " << val << " wt: " << wt << endl;
                if (wt < currDist)
                {
                    // perform relaxation on child i and then add it to pq
                    res[i] = wt; // res of i gives distance from source to i
                    //cout << "relaxation , dist_from-source : " << wt << " child_index : " << i << endl;
                    //cout << endl;
                    pq.push({res[i], i});
                }
            }
        }

        // all children are inserted
    }
    //print1d(res);
    vector<int> temp;
    for(int i=0; i<n;i++){
        if(res[i]==0){
            continue;
        }
        else if(res[i]==INT_MAX){
            temp.push_back(-1);
        }
        else{
            temp.push_back(res[i]);
        }
    }
    return temp;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        vector<vector<int>> edges(m);

        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 3; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        string s_temp;
        getline(cin, s_temp);

        int s = stoi(ltrim(rtrim(s_temp)));

        vector<int> result = shortestReach(n, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
