#include <cstdlib>
#include <iostream>
#include "graph.h"
using namespace std;

class GraphMatrix : public Graph {
    int matrix[10][10];
    char s_vertices[10];
    int num_vert;
    int s_edges[100];
    int num_edge;

    public:
    GraphMatrix() {
        num_vert = 0;
        num_edge = 0;
    }

    int numVertices() {
        return num_vert;
    }

    char* vertices() {
        return s_vertices;
    }

    int numEdges() {
        return num_edge;
    }

    int* edges() {
        return s_edges;
    }

    int getEdge(char u, char v)  {
        int uIndex = -1, vIndex = -1;

        for(int i = 0; i < num_vert; i++){
            if(s_vertices[i] == u){
                uIndex = i;
            }
            if(s_vertices[i] == v){
                vIndex = i;
            }
        }
        if(uIndex < 0 || vIndex < 0){
            return 0;
        }
        return matrix[uIndex][vIndex];
    }

    char* endVertices(int e)  {
        char origin = '-', destination = '-';
        bool done = false;
        
        for(int i = 0; i < 10; i++){
            if(done){
                break;
            }
            for(int j = 0; j < 10; j++){
                if(matrix[i][j] == e){
                    origin = s_vertices[i];
                    destination = s_vertices[j];
                    done = true;
                }
            }
        }

        char* list = (char*)malloc(sizeof(char) * 2);
        
        list[0] = origin;
        list[1] = destination;
        
        return list;
    }

    char opposite(char v, int e)  {
        char opp = '-';
        int vIndex = -1;

        for(int i = 0; i < num_vert; i++){
            if(s_vertices[i] == v){
                vIndex = i;
                break;
            }
        }

        if(vIndex < 0){
            return opp;
        }

        for(int i = 0; i < 10; i++){
            if(matrix[vIndex][i] == e){
                opp = s_vertices[i];
                break;
            }
            if(matrix[i][vIndex] == e){
                opp = s_vertices[i];
                break;
            }
        }
    
        return opp;
    }

    int outDegree(char v)  {
        int vIndex = -1;
        int counter = 0;

        for(int i = 0; i < num_vert; i++){
            if(s_vertices[i] == v){
                vIndex = i;
                break;
            }
        }

        for(int i = 0; i < 10; i++){
            if(matrix[vIndex][i]){
                counter++;
            }
        }

        return counter;
    }

    int inDegree(char v)  {
        int vIndex = -1;
        int counter = 0;

        for(int i = 0; i < num_vert; i++){
            if(s_vertices[i] == v){
                vIndex = i;
                break;
            }
        }

        for(int i = 0; i < 10; i++){
            if(matrix[i][vIndex]){
                counter++;
            }
        }

        return counter;
    }

    int* outgoingEdges(char v) {
        int size = outDegree(v);
        int* list = (int*)malloc(sizeof(int)*size);

        int vIndex = -1;

        for(int i = 0; i < num_vert; i++){
            if(s_vertices[i] == v){
                vIndex = i;
                break;
            }
        }

        int counter = 0;

        for(int i = 0; i < 10; i++){
            if(matrix[vIndex][i]){
                list[counter] = matrix[vIndex][i];
                counter++;
            }
        }
        
        return list;
    }

    int* incomingEdges(char v) {
        int size = inDegree(v);
        int* list = (int*)malloc(sizeof(int)*size);

        int vIndex = -1;

        for(int i = 0; i < num_vert; i++){
            if(s_vertices[i] == v){
                vIndex = i;
                break;
            }
        }

        int counter = 0;

        for(int i = 0; i < 10; i++){
            if(matrix[i][vIndex]){
                list[counter] = matrix[i][vIndex];
                counter++;
            }
        }
        
        return list;
    }

    bool insertVertex(char x)  {
        if(num_vert >= 10){
            return false;
        }
        s_vertices[num_vert++] = x;
        return true;
    }

    bool insertEdge(char u, char v, int x)  {
        if(num_edge >= 10){
            return false;
        }

        int index1 = -1, index2 = -1;
        
        s_edges[num_edge++] = x;
        
        for(int i = 0; i < num_vert; i++){
            if(s_vertices[i] == u){
                index1 = i;
            }
            if(s_vertices[i] == v){
                index2 = i;
            }
        }

        if(index1 < 0 || index2 < 0){
            return false;
        }

        matrix[index1][index2] = x;
        return true;
    }

    //KAPOY
    int removeVertex(char v) {
        return 0;
        // int vIndex = -1;

        // for(int i = 0; i < num_vert; i++){
        //     if(s_vertices[i] == v){
        //         vIndex = i;
        //         break;
        //     }
        // }

        // if(vIndex < 0){
        //     return 0;
        // }
    
        // int counter = outDegree(v) + inDegree(v);    
        // for(int i = 0; i < 10; i++){
        //     if(matrix[vIndex][i]){
        //         for(int j = i; j < 9; j++){
        //             if(matrix[vIndex][j]){
        //                 matrix[vIndex][j] = matrix[vIndex][j+1];
        //             }
        //         }
        //     }
        // }

        // for(int i = 0; i < 10; i++){
        //     if(matrix[i][vIndex]){
        //         for(int j = i; j < 9; j++){
        //             if(matrix[j][vIndex]){
        //                 matrix[j][vIndex] = matrix[j+1][vIndex];
        //             }
        //         }
        //     }
        // }

        
        // for(int i = 0; i < num_vert; i++){
        //     if(s_vertices[i] == v){
        //         for(int j = i ; j < num_vert-1; j++){
        //             s_vertices[j] = s_vertices[j+1];
        //         }
        //     }
        // }
        // num_vert--;
        // return counter;
    }

    int distance(char u, char v){
        int* distances = dijkstra(matrix, findVertex(u));
        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < 10; i++){
            cout << i << " \t\t\t\t" << distances[i] << endl;
        }
        return 0;
    }

    int* dijkstra(int matrix[10][10], int src){
        if(src <= -1) return nullptr;

        int dist[10];
        bool processed[10];

        for(int i = 0; i < 10; i++){
            dist[i] = 999999;
            processed[i] = false;
        }

        dist[src] = false;

        for(int i = 0; i < 9; i++){
            int closest = minDistance(dist, processed);

            processed[closest] = true;

            for(int j = 0; j < 10; j++){
                if(!processed[j] && matrix[closest][j]
                && dist[closest] < 999999 && dist[closest] + matrix[closest][j] < dist[j]){
                    dist[j] = dist[closest] + matrix[closest][j];
                }
            }
        }
    }

    int minDistance(int dist[], bool processed[]){
        int min = 999999;
        int min_index;

        for(int i = 0; i < 10; i++){
            if(!processed[i] && dist[i] <= min){
                min = dist[i];
                min_index = i;
            }
        }

        return min_index;
    }

    int findVertex(char u){
        for(int i = 0; i < 10; i++){
            if(s_vertices[i] == 'u'){
                return i;
            }
        }
        return -1;
    }

    bool removeEdge(int e)  {
        bool removed = false;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(matrix[i][j] == e){
                    matrix[i][j] = NULL;
                    removed = true;
                }
            }
        }

    
        for(int i = 0; i < num_edge; i++){
            if(s_edges[i] == e){
                for(int j = i ; j < num_edge-1; j++){
                    s_edges[j] = s_edges[j+1];
                }
            }
        }
        num_edge--;

        return removed;
    }

    void print() {
        cout << "\t";
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
        }
        cout << endl;
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
            for (int j = 0; j < num_vert; j++) {
                if (matrix[i][j] != 0) {
                    cout << matrix[i][j];
                }
                cout << "\t";
            }
            cout << endl;
        }
    }
};