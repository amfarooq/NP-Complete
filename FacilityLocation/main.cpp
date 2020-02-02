#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "facility.h"
#include "customer.h"


using namespace std;

float calculate_distance(facility & i, customer & j) {
    float x_diff = (i.get_x() - j.get_x());
    float y_diff = (i.get_y() - j.get_y());
    float answer = sqrt(((x_diff * x_diff) + (y_diff * y_diff)));
    return answer;
}

int partition_value(vector <facility> & vect, int low, int high, int pivot) {
    
    while (low <= high) {
        while (vect[low].get_cost() < pivot)
            low++;
        while (vect[high].get_cost() > pivot)
            high--;
        
//            swap(&vect[low], &vect[high]);
        if (low <= high) {
            facility temp(vect[low]);
            vect[low] = vect[high];
            vect[high] = temp;
            low++;
            high--;
        }
    }
    
    return low;
}


void quicksort_value(vector <facility> & vect, int low, int high) {
    
    if (low < high) {
        
        double pivot = vect[(low + high) / 2].get_cost();
        int index = partition_value(vect, low, high, pivot);
        quicksort_value(vect, low, index - 1);
        quicksort_value(vect, index, high);
    }
}




int main() {
    
    ifstream fin;
    string filename;
    
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
    
    int tot_facilities = 0;
    int tot_customers = 0;
    
    fin >> tot_facilities;
    fin >> tot_customers;
    
    vector <facility> fac(tot_facilities);
    
    float temp= 0;
    
    for (int i = 0; i < tot_facilities; i++) {
        fin >> temp;
        fac[i].set_cost(temp);
        fin >> temp;
        fac[i].set_capacity(temp);
        fin >> temp;
        fac[i].set_x(temp);
        fin >> temp;
        fac[i].set_y(temp);
        fac[i].set_pos(i);

    }
    
    vector <customer> cust(tot_customers);
    
    float demand = 0;
    float x = 0;
    float y =0;
    
    int count = 0;
    while(fin >> demand) {
        cust[count].set_demand(demand);
        fin >> x;
        cust[count].set_x(x);
        fin >> y;
        cust[count].set_y(y);
        cust[count].set_pos(count);
        count++;
    }
    
    
    vector <vector <float> > distance;
    distance.resize(tot_facilities);
    for(int i = 0; i < distance.size(); i++)
        distance[i].resize(tot_customers, 0.0);
    
    for(int i = 0; i < distance.size(); i++)
        for(int j = 0; j < distance[i].size(); j++)
            distance[i][j] = calculate_distance(fac[i], cust[j]);

    
//    for(int i = 0; i < fac.size(); i++) {
//        cout << fac[i].get_cost() << " "
//                << fac[i].get_capacity() << " "
//                << fac[i].get_x() << " "
//                << fac[i].get_y() << endl;
//    }
    
    quicksort_value(fac, 0, fac.size() - 1);
    
//    for(int i = 0; i < fac.size(); i++)
//        cout << fac[i].get_pos() << " ";
//    cout << endl << endl;
    
    
    float total_cost = 0.0;
        
    vector <bool> f_open(tot_facilities, false);
    
    int n = 0;
    int customers_assigned = 0;
    
    while(customers_assigned < tot_customers){
    
        f_open[n] = true;
        total_cost = total_cost + fac[n].get_cost();

        bool can_assign = true;
        
        while(can_assign && customers_assigned < tot_customers) {

            int closest_cust = 100000000;
            float closest_dist = 100000000;

            for(int i = 0; i < tot_customers; i++)
                if(cust[i].get_facility() == -1) {
                    if(distance[n][i] < closest_dist) 
                        if(cust[i].get_demand() < fac[n].get_capacity()){
                            closest_cust = i;   
                            closest_dist = distance[fac[n].get_pos()][i];
                        }
                }
            if(closest_cust < tot_customers) {
                //assign the closest customer if custoers demand is less than supply
                cust[closest_cust].set_facility(fac[n].get_pos());
                fac[n].set_capacity((fac[n].get_capacity() - cust[closest_cust].get_demand()));
                total_cost = total_cost + closest_dist;
                customers_assigned++;
            }
            
            else{
                can_assign = false;
                n++;
            }
            
        }

    }
    
    cout << total_cost << endl;
    for(int i = 0; i < cust.size(); i++)
        cout << cust[i].get_facility() << " ";
    
    string outfilename;
    outfilename = filename + "_output.txt";
    
    ofstream fout;
    fout.open(outfilename);
    fout.precision(6);
    
    fout << total_cost << endl;
    
    for(int i = 0; i < cust.size(); i++)
        fout << cust[i].get_facility() << " ";

        
       

        
    
    
    
//    cout << tot_facilities << " " << tot_customers << endl;
//    
//    for(int i = 0; i < fac.size(); i++) {
//        cout << fac[i].get_cost() << " "
//                << fac[i].get_capacity() << " "
//                << fac[i].get_x() << " "
//                << fac[i].get_y() << endl;
//    }
//    
//    for(int i = 0; i < cust.size(); i++) {
//        cout << cust[i].get_demand() << " "
//                << cust[i].get_x() << " "
//                << cust[i].get_y() << endl;
//        
//    }


    return 0;
}

