#include<bits/stdc++.h>
using namespace std;
#define V 5

int minCost = INT_MAX;
bool visited[V];

void tsp(int graph[V][V], int currPos, int n, int count, int cost) {
    if (count == n && graph[currPos][0]) {
        minCost = min(minCost, cost + graph[currPos][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (graph[currPos][i] && !visited[i]) {
            visited[i] = true;
            tsp(graph, i, n, count + 1, cost + graph[currPos][i]);
            visited[i] = false;
        }
    }
}
void tsp_branch_bound(int graph[V][V]) {
    visited[0] = true;
    tsp(graph, 0, V, 1, 0);
    cout << "Minimum cost: " << minCost << endl;
}

int main() {
    int graph[V][V] = {{0, 20, 30, 10, 11},
                       {15, 0, 16, 4, 2},
                       {3, 5, 0, 2, 4},
                       {19, 6, 18, 0, 3},
                       {16, 4, 7, 16, 0}};

    tsp_branch_bound(graph);

    return 0;
}