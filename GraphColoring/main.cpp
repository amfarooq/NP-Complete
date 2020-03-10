/*
 * Ali Farooqui
 * 
 * CS Independent Study
 * Assignment 03 - Graph Coloring
 */

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "graphpair.h"

using namespace std;
int callno = 0;

vector <int> bestColorAssignment;

// naive solution
int firstAvailableColor(vector <vector <int > > & graph, int & numVert, string & filename){
    vector <bool> ColorAvailability;
    vector <int> ColorAssignment(numVert, -1);
    
    ColorAvailability.resize(1, true); // we now have 1 color we are working with
    ColorAssignment[0] = 0;
    
    for (int i = 1; i < graph.size(); i++) {
        for(int j = 0; j <graph[i].size(); j++) {
            int cur_edge = graph[i][j];
            if (ColorAssignment[cur_edge] == -1)
                i = i;
            else
                ColorAvailability[ColorAssignment[cur_edge]] = false;            
        }
        int n = 0;
        while( n < ColorAvailability.size()) {
            if(ColorAvailability[n] == true) 
                break;
            
            n++;
        }
        if(n < ColorAvailability.size())
            ColorAssignment[i] = n;
        else {
            ColorAvailability.push_back(true);
            ColorAssignment[i] = n;
        }
        
        for(int m = 0; m <ColorAvailability.size(); m++)
            ColorAvailability[m] = true;
    }
        
    return ColorAvailability.size();

        
    
}

// prints the color selection for the vertices of the graph as defined by the vector "colors"
// useful for debugging and printing final answer
void printColors (vector <int> & colors) {
    for(int i = 0; i < colors.size(); i++)
        cout << colors[i] << " ";
    cout << endl;
}

// check if color col is a valid color choice for the vertex curVert
bool ColorCheck(int & col, vector <vector <int> > & graph, vector < vector <bool> > & adjacency, int curVert, vector<int> & colors) {
    
    for(int i = 0; i < graph[curVert].size(); i++) {
        int curEdge =graph[curVert][i];
        if(adjacency[curVert][curEdge] == 1){
            if(colors[curEdge] == col)
                return false;
        }
    }
    return true;
}

// our backtracking function
bool backtracking(int & n, vector <vector <int> > & graph, vector < vector <bool> > & adjacency, int curVert, int numVert, vector<int> & colors) {
    int cur_call = callno;
    //cout << "This is backtracking call no. " << cur_call << " trying chromatic no. " << n << ":" << endl;
    printColors(colors);
    if(curVert >= numVert) {
        //cout << "call " << cur_call << " returning true";
        return true;
    }
    else {
        for(int i = 0; i < n; i++) {
            if(ColorCheck(i, graph, adjacency, curVert, colors)) {
                colors[curVert] = i;
                callno++;
                if(backtracking(n, graph, adjacency, curVert+1, numVert, colors)) {
                    //cout << "call " << cur_call << " returning true" << endl;
                    return true;
                }
            }
        }
        colors[curVert] = -1;
        //cout << "call " << cur_call << " returning false" << endl;
        return false;
    }
    
}


int main() {
    
    
    ifstream fin;
    string filename;
    
    // an edge (i,j) - edge going from vertex i to vertex j -  is represented in graph as follows:
    // graph[i][k] = j where k is the k'th position, and hence k'th edge starting from vertex i.
    vector <vector <int> > graph;
    
    // adjacency[i][j] is true if there exists an edge from vertex i to vertex j. False otherwise.
    vector <vector <bool> > adjacency;
    
    int numVertices;
    int numEdges;
    
    //***********
    // reading in input from file.
    cout << "please input filename: ";
    cin >> filename;
    
    fin.open(filename);
    
    while (!fin.is_open()) {
        cout << "File not found. ";
        fin.clear();
        cout << "Try again: ";
        cin >> filename;
        fin.open(filename.data());
    }
    
    fin >> numVertices;
    fin >> numEdges;
       
    adjacency.resize(numVertices);
    
    for(int i = 0; i<adjacency.size(); i++) {
        adjacency[i].resize(numVertices, 0);
    }
    
    int vert;
    int edge;
    
    fin >> vert;
    fin >> edge;
    
    adjacency[vert][edge] = 1;
    adjacency[edge][vert] = 1;
          
    graph.resize(numVertices);
    graph[vert].push_back(edge);
    graph[edge].push_back(vert);
    
    int counter = 1;
    
    while(counter < numEdges) {
        fin >> vert;
        fin >> edge;
        
        adjacency[vert][edge] = 1;
        adjacency[edge][vert] = 1;
        
        graph[vert].push_back(edge);
        graph[edge].push_back(vert);
        
        counter++;
    }
    //***********
    
    // colors is a vector that keeps track of current color choices for each vertex
    // resize colors and initialize each choice to -1 meaning no color has been chosen yet
    vector <int> colors(numVertices, -1);
    
    int cur_col = 1;
    
    // starting from n = 1, see what is the lowest chromatic number for this graph
    for(; cur_col < numVertices; cur_col++) {
        callno = 0; // for debugging purposes.
        if(backtracking(cur_col, graph, adjacency, 0, numVertices, colors))
            break;
    }
    
    // print answer
    cout << cur_col << endl;
    printColors(colors);
    
    return 0;
}

