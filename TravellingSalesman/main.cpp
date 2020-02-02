#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "cityLocation.h"

using namespace std;

float best_dist = 0;
vector <int> best_tour(1,0);

float calculate_distance(cityLocation i, cityLocation j) {
    float x_diff = (i.get_x() - j.get_x());
    float y_diff = (i.get_y() - j.get_y());
    float answer = sqrt(((x_diff * x_diff) + (y_diff * y_diff)));
    return answer;
}

void two_opt_swap(vector <int> tour, int & i, int & k) {
    vector <int> new_tour;
    for (int n = 0; n < i; n++)
        new_tour.push_back(tour[n]);
    for(int m = k -1; m > i; m--)
        new_tour.push_back(m);
    for(int l = k; l < tour.size(); l++)
        new_tour.push_back(l);
}

float trivial_solution(vector < vector <float> > & distance, vector <cityLocation> & location, int & tot, string & file, vector <int> &path) {
    float total_dist = 0.0;
    vector <int> not_taken(tot-1, 0);
    
    for(int i = 0; i < not_taken.size(); i++) {
        not_taken[i] = i+1;
    }
       
    while(path.size() != tot) {
        
        int prev_city = path[path.size() - 1];
        float best_dist = 100000;
        int cur_city = 0;
        int best_city = 0;
        
        for(int j = 0; j < not_taken.size(); j++) {
            
            cur_city = not_taken[j];
            if(prev_city < not_taken[j]) {
                if(distance[cur_city][prev_city] < best_dist) {// THIS IS WHERE YOU WERE
                    float f = distance[cur_city][prev_city];
                    best_dist = distance[cur_city][prev_city];
                    best_city = j;
                }
            }

            else 
                if(distance[prev_city][cur_city] < best_dist) {
                    float f = distance[prev_city][cur_city];
                    best_dist = distance[prev_city][cur_city];
                    best_city = j;
                }
        }
        
        path.push_back(not_taken[best_city]);
        not_taken[best_city] = not_taken[not_taken.size()-1];
        not_taken.pop_back();
        
        
                    
        total_dist = total_dist + best_dist;
        
    }

    total_dist = total_dist + distance[path.back()][0];
    
//    string outfilename;
//    outfilename = file + "_output.txt";
//    
//    ofstream fout;
//    fout.open(outfilename);
//    fout.precision(6);
//    
//    fout << total_dist << endl;
//    
//    for(int i = 0; i < path.size(); i++)
//        fout << path[i] << " ";
    
   
    return total_dist;
    
    
    
}


int main() {
    
    ifstream fin;
    string filename;
    
    vector <cityLocation> location;
    int totalCities;

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
    
    fin >> totalCities;
    location.resize(totalCities);
    float temp_x = 0.0;
    float temp_y = 0.0;
    
    int i = 0;
    
    while(fin >> temp_x){

        fin >> temp_y;
        
        location[i].set_x(temp_x);
        location[i].set_y(temp_y);
        
        i++;
    }


    

    vector <vector <float> > distance;
    distance.resize(totalCities);
    for(int i = 0; i < distance.size(); i++) {
        distance[i].resize(i+1, 0.0);
        for(int j = 0; j <= i; j++)
            distance[i][j] = calculate_distance(location[i], location[j]);
    }
    
//    cout << temp;
    
//    float temp = 0.0;
//    
//    for(int i = 0; i < distance.size(); i++){
//        cout << i << ": ";
//        for (int j = 0; j < distance[i].size(); j++) {
//            temp = distance[i][j];
//            cout << temp << " ";        
//        }
//        cout << endl;
//    }
    best_dist = trivial_solution(distance, location, totalCities, filename, best_tour);
    
    
    
    string outfilename;
    outfilename = filename + "_output.txt";
    
    ofstream fout;
    fout.open(outfilename);
    fout.precision(6);
    
    fout << best_dist << endl;
    for(int i = 0; i <best_tour.size(); i++)
        fout << best_tour[i] << " ";
    

//    float total_dist = 0;
//    vector < int > path(1, 0);
//    vector <bool> not_taken(totalCities, true);
//    not_taken[0] = false;
//       
//    while(path.size() != totalCities) {
//        
//        int prev_city = path[path.size() - 1];
//        float best_dist = 100000.0;
//        int best_city = 0;
//        
//        for(int j = 0; j < not_taken.size(); j++) {
//            if(not_taken[j] == true) {
//                if(prev_city < j) {
//                    if(distance[j][prev_city] < best_dist) {// THIS IS WHERE YOU WERE
//                        float f = distance[j][prev_city];
//                        best_dist = distance[j][prev_city];
//                        best_city = j;
//                    }
//                }
//
//                else 
//                    if(distance[prev_city][j] < best_dist) {
//                        float f = distance[prev_city][j];
//                        best_dist = distance[prev_city][j];
//                        best_city = j;
//                    }
//            }
//        }
//        path.push_back(best_city);
//        not_taken[best_city] = false;
//                    
//        total_dist = total_dist + best_dist;
//        
//    }
//
//    total_dist = total_dist + distance[path.back()][0];
//    
//    cout << total_dist << endl;
//    
//    for(int i = 0; i < path.size(); i++)
//        cout << path[i] << " ";
//    
//   
    return 0;
}

