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

//void updateDomain(vector < vector <int> > & graph, vector < vector <int> > domain, int & vert, int & col, bool & empty) {
//    
//    for(int i = 0; i < graph[vert].size(); i++) {
//        int cur_vert = graph[vert][i];
//        for(int j = 0; j < domain[cur_vert].size(); j++)
//            if(domain[cur_vert][j] == col)
//                domain[cur_vert].erase(j);
//                          
//    }
//}

void firstAvailableColor(vector <vector <int > > & graph, int & numVert, string & filename){
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
        
    string outfilename;
    outfilename = filename.substr(0, filename.size()) + "_output.txt";
    
    ofstream fout;
    fout.open(outfilename);
    
    fout << ColorAvailability.size() << endl;
    for(int i = 0; i < ColorAssignment.size(); i++) {
        fout << ColorAssignment[i] << " ";
    }


        
    
}

//void backtracking(int & n, vector <vector <int> > & graph, vector < vector <bool> > & adjacency, int numVert) {
//    vector <vector <bool> > domain;
//    
//    domain.resize(numVert);
//    int n = 0;
//}


int main() {
    
    
    ifstream fin;
    string filename;
    vector <vector <int> > graph;
    vector <vector <bool> > adjacency;
    vector <vector <bool> > domain; // represents domain of each node i such that
    // domain[i][j] means that vertex i is either true or false for color j.
    // all domain[i]'s should always have the same size() which should be the total number of colors m.
    
    int numVertices;
    int numEdges;
    
    
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
        
//        if(prev != vert){

        graph[vert].push_back(edge);
        graph[edge].push_back(vert);

//        }
        
//        else
//            graph[vert].push_back(edge);
        
        
        counter++;
    }
            
    vector <int> vertColors(numVertices, -1); // -1 indicates that the element (vertex) has not been assigned a color yet
    vector <bool> available(numVertices, true);
    vector <int> colors;
    
    firstAvailableColor(graph, numVertices, filename);
    
    
    
    
//    for(int i = 0; i < adjacency.size(); i++){
//        for(int j = 0; j < adjacency[i].size(); j++)
//            cout << adjacency[i][j];
//        cout << endl;
//    }
//
// 
    cout << endl << endl;
//    for(int i = 0; i < graph.size(); i++) {
//        cout << i << ": ";
//        for(int j = 0; j < graph[i].size(); j++)
//            cout << graph[i][j] << " ";
//        cout << endl; 
//    }
//    cout << endl << endl;
//
    
    
    
    
    
    return 0;
}

