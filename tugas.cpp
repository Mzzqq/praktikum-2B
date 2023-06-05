#include <iostream>
#include <climits>

#define V 4 // Jumlah simpul

/*
    Note:
    Untuk menghindari conflict name pada global, disini tidak mendeklarasikan
    using namespace std;. sebagai gantinya di dalam code ini mendeklarasikan
    std:: secara eksplisit
*/

int tsp(int graph[V][V], int path[], int curr, int mask){
    if (mask == (1 << V) - 1) // Jika semua simpul telah dikunjungi
        return graph[curr][0]; // Kembali ke simpul awal

    int ans = INT_MAX;
    for (int i = 0; i < V; i++){
        if ((mask & (1 << i)) == 0){ // Periksa simpul yang belum dikunjungi
            int new_mask = mask | (1 << i); // Tandai simmpul baru sebagai dikunjungi
            int new_ans = graph[curr][i] + tsp(graph, path, i, new_mask); // Recursion ke simpul berikutnya
            ans = std::min(ans, new_ans);
        }
    }

    return ans;
}

void printPath(int path[]){
    for (int i = 0; i < V; i++)
        std::cout << path[i] + 1 << " -> ";
    std::cout << path[0] + 1 << std::endl;
}

void printGraph(int graph[V][V]){
    std::cout << "Graph:" << std::endl;
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++)
            std::cout << graph[i][j] << " ";
        std::cout << std::endl;
    }
}

int main(){
    int graph[V][V] = {{0, 4, 1, 3},    // Matrix cost route antar simpul
                       {4, 0, 2, 1},
                       {1, 2, 0, 5},
                       {3, 1, 5, 0}};

    int start_node;
    std::cout << "Masukkan titik awal (1-" << V << "): ";
    std::cin >> start_node;

    if (start_node < 1 || start_node > V){
        std::cout << "Titik awal tidak valid.\n";
        return 0;
    }

    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = i;

    // Geser titik awal berdasarkan input
    int geser = start_node - 1;
    for (int i = 0; i < V; i++)
        path[i] = (path[i] + geser) % V;

    //std::cout << "Input Graph:" << std::endl;
    printGraph(graph);

    int min_cost = tsp(graph, path, 0, 1);

    std::cout << "Jalur terpendek: ";
    printPath(path);

    std::cout << "Minimum cost: " << min_cost << std::endl;

    return 0;
}
