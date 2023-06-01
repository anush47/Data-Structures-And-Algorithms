#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

// No. of vertices
#define V 6

// Vertex with minimum time, from vertices in shortest path tree
int minTime(vector<int> time, bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && time[v] <= min)
			min = time[v], min_index = v;

	return min_index;
}

// Print the constructed distance array
void printSolution(vector<int> time)
{
	cout << "City -\t";
	for (int i = 0; i < V; i++){
		cout << i << " \t ";
    }
    cout<<endl<<"Time -\t";
    for (int i = 0; i < V; i++){
		cout << time[i] << " \t ";
    }
    cout<<endl;
}

//Dijkstra's SSSP for a adjacency matrix
void dijkstra(int graph[V][V], int src, vector<int> &time)
{
	bool sptSet[V]; // included in shortest path tree - bools

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		time[i] = INT_MAX, sptSet[i] = false;

	// Distance of source is 0
	time[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		int u = minTime(time, sptSet);

		// Mark as included
		sptSet[u] = true;

		// Update value of the adjacent vertices
		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v]
				&& time[u] != INT_MAX
				&& time[u] + graph[u][v] < time[v])
				time[v] = time[u] + graph[u][v];
	}

	// print the array
	printSolution(time);
}

int main() {
    int graph[6][6] = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    //dijkstra(graph, 0);
    
    int numCities = V;
    vector<int> time(numCities, 0);

    // Calculate the average time taken from each source city to the other cities
    vector<int> avgTimes(numCities, 0);
    for (int source = 0; source < numCities; source++) {
        // Output the shortest distances from the source city to all other cities
        cout << "Shortest times from City " << source << ":"<<endl;
        dijkstra(graph, source, time);
        cout<<"-------------------------------------------------------------------"<<endl;

        int sumTimes = 0;
        int count = 0;
        for (int i = 0; i < numCities; i++) {
            if (i != source && time[i] != INT_MAX) {
                sumTimes += time[i];
                count++;
            }
        }
        avgTimes[source] = sumTimes / count;
    }

    // Find the city/cities with the smallest average time
    int minAvgTime = INT_MAX;
    vector<int> minAvgCities;
    for (int i = 0; i < numCities; i++) {
        if (avgTimes[i] < minAvgTime) {
            minAvgTime = avgTimes[i];
            minAvgCities.clear();
            minAvgCities.push_back(i);
        } else if (avgTimes[i] == minAvgTime) {
            minAvgCities.push_back(i);
        }
    }

    // Output the city/cities with the smallest average time
    cout <<endl<< "City/Cities with the smallest average time ("<<minAvgTime<<"):\n";
    for (int city : minAvgCities) {
        cout << "City " << city << endl;
    }

    return 0;
}
