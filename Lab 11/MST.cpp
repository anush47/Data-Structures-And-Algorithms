#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int min_distance(vector<int>& distances, vector<bool> &is_in_MST) {
    int minDistance = INT_MAX, minIndex = -1;
    for (int v = 0; v < distances.size(); ++v) {
        if (!is_in_MST[v] && distances[v] < minDistance) {
        minDistance = distances[v];
        minIndex = v;
        }
    }
    return minIndex;
}

void print_MST(vector<int>& parents, vector<vector<int>>& graph) {
    cout << "MST:" << endl;
    for (int i = 0; i < parents.size(); ++i) {
        if (parents[i] != -1) {
        cout << parents[i] << " - " << i << " --> cost = " << graph[i][parents[i]] << endl;
        }
    }
}

int prim_algo_MST(vector<vector<int>>& graph, int startNode) {
    int no_vertices = graph.size();
    vector<int> parents(no_vertices, -1);
    vector<int> distances(no_vertices, INT_MAX);
    vector<bool> is_in_MST(no_vertices, false);

    distances[startNode] = 0;

    for (int count = 0; count < no_vertices - 1; ++count) {
        int minIndex = min_distance(distances, is_in_MST);
        is_in_MST[minIndex] = true;

        for (int v = 0; v < no_vertices; ++v) {
        if (graph[minIndex][v] && !is_in_MST[v] && graph[minIndex][v] < distances[v]) {
            parents[v] = minIndex;
            distances[v] = graph[minIndex][v];
        }
        }
    }

    int min_cost = 0;
    for (int i = 0; i < no_vertices; ++i) {
        if (parents[i] != -1) {
        min_cost += graph[i][parents[i]];
        }
    }

    print_MST(parents, graph);

    return min_cost;
}

int main() {
    vector<vector<int>> graph = {   {0, 3, 0, 0, 0, 1},
                                    {3, 0, 2, 1, 10, 0},
                                    {0, 2, 0, 3, 0, 5},
                                    {0, 1, 3, 0, 5, 0},
                                    {0, 10, 0, 5, 0, 4},
                                    {1, 0, 5, 0, 4, 0}};

    int startNode = 0;
    int min_cost = prim_algo_MST(graph, startNode);

    cout<<"------------------------"<<endl;
    cout << "MST cost: " << min_cost << endl;

    return 0;
}