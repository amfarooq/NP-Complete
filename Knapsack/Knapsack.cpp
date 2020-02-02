#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "item.h"
#include "pqueue.h"
#include <cmath>

using namespace std;

double greedy_solve(int & cap, vector <item> & vect) {

    double total = 0;
    int weight = 0;
    
    int i = 0;
    
    while(i < vect.size() && weight + vect[i].get_weight() <= cap) {
        total = total + vect[i].get_value();        
    }
    
    if (i < vect.size())
        total = (cap - weight) * vect[i].get_ratio();
    
    return total;
}

int partition_value(vector <item> & vect, int low, int high, int pivot) {
    
    while (low <= high) {
        while (vect[low].get_value() < pivot)
            low++;
        while (vect[high].get_value() > pivot)
            high--;
        
//            swap(&vect[low], &vect[high]);
        if (low <= high) {
            item temp(vect[low]);
            vect[low] = vect[high];
            vect[high] = temp;
            low++;
            high--;
        }
    }
    
    return low;
}

int partition_weight(vector <item> & vect, int low, int high, int pivot) {
    
    while (low <= high) {
        while (vect[low].get_weight() < pivot)
            low++;
        while (vect[high].get_weight() > pivot)
            high--;
        
//            swap(&vect[low], &vect[high]);
        if (low <= high) {
            item temp(vect[low]);
            vect[low] = vect[high];
            vect[high] = temp;
            low++;
            high--;
        }
    }
    
    return low;
}

int partition_pos(vector <item> & vect, int low, int high, int pivot) {
    
    while (low <= high) {
        while (vect[low].get_pos() < pivot)
            low++;
        while (vect[high].get_pos() > pivot)
            high--;
        
//            swap(&vect[low], &vect[high]);
        if (low <= high) {
            item temp(vect[low]);
            vect[low] = vect[high];
            vect[high] = temp;
            low++;
            high--;
        }
    }
    
    return low;
}

double partition_ratio(vector <item> & vect, int & left, int & right, double & pivot) {
    
    while (left <= right) {
        while (vect[left].get_ratio() > pivot)
            left++;
        while (vect[right].get_ratio() < pivot)
            right--;
        
        if (left <= right) {
            item temp(vect[left]);
            vect[left] = vect[right];
            vect[right] = temp;
            left++;
            right--;
        }
    }
    
    return left;
}


void quicksort_value(vector <item> & vect, int low, int high) {
    
    if (low < high) {
        
        double pivot = vect[(low + high) / 2].get_value();
        int index = partition_value(vect, low, high, pivot);
        quicksort_value(vect, low, index - 1);
        quicksort_value(vect, index, high);
    }
}

void quicksort_ratio(vector <item> & vect, int left, int right) {
    
    if (left < right) {
        
        double pivot = vect[(left + right) / 2].get_ratio();
        double index = partition_ratio(vect, left, right, pivot);
        quicksort_ratio(vect, left, index - 1);
        quicksort_ratio(vect, index, right);
    }
}


void quicksort_weight(vector <item> & vect, int low, int high) {
    
    if (low < high) {
        
        int pivot = vect[(low + high) / 2].get_weight();
        int index = partition_weight(vect, low, high, pivot);
        quicksort_weight(vect, low, index - 1);
        quicksort_weight(vect, index, high);
    }
}

void quicksort_pos(vector <item> & vect, int low, int high) {
    
    if (low < high) {
        
        int pivot = vect[(low + high) / 2].get_pos();
        int index = partition_pos(vect, low, high, pivot);
        quicksort_pos(vect, low, index - 1);
        quicksort_pos(vect, index, high);
    }
}

double calculate_bound(vector <item> & items, const int & cap, QNode* node) {
    double total = node->get_profit();
    int weight = node->get_weight();
    
    for(int i = (node->get_level() + 1); i < items.size(); i++) {
        if (weight + items[i].get_weight() < cap) {
            weight += items[i].get_weight();
            total += items[i].get_value();
        }
        else if(i < items.size()) {
            total += (items[i].get_ratio() * (cap - weight));
            i = items.size() + 1;
        }
        
    }
    
    return total;
}


int knapsack(vector <item> & vect, const int & cap, PQueue & q, const int & total) {
        
    double upper = 0; // upper bound
    int profit = 0; // max profit
    
    QNode* bestNode = new QNode;
    int n = 0;
    const int stopper = abs((total * total * total)/2);
    int prev_profit = 0;
    
    while (!q.isEmpty()) {
                
        QNode* u = new QNode;    
        QNode* w = new QNode;   
        
        // pop a node off the queue       
        QNode* v = q.pop();
        
        if (v->get_bound() < profit)
            ;
        
        else {
            // see if that node has a greater profit than max profit. If so,
            // update max profit.
            if(v->get_weight() <= cap && v->get_profit() > profit){
                profit = v->get_profit();
                bestNode = v;
            }

            if(v->get_level() + 1 < vect.size()) {
                u->set_level(v->get_level() + 1);
                u->take();
                u->set_weight(v->get_weight() + vect[u->get_level()].get_weight());
                if(u->get_weight() <= cap) {
                    u->set_took(v->get_took());
                    u->save(true);
                    u->set_profit(v->get_profit() + vect[u->get_level()].get_value());
                    u->set_bound(calculate_bound(vect, cap, u));


                    if (u->get_bound() > profit) {
                        q.push(u);
                    }
                
                }

                w->set_level(v->get_level() + 1);
                w->untake();
                w->set_weight(v->get_weight());
                w->set_took(v->get_took());
                w->save(false);                
                w->set_profit(v->get_profit());
                w->set_bound(calculate_bound(vect, cap, w));


                if (w->get_bound() > profit) {
                    q.push(w);
                }
                
                  // for debugging purposes:
    //            cout << n << ": " << profit << endl;
                
            }
        }

        if (profit == prev_profit)
            n++;
        else 
            n = 0;
        
        prev_profit = profit;
        
        if (n >= stopper) {
            vector <bool> track = bestNode->get_took();
    
            for (int i = 0; i < track.size(); i++) {
                if(track[i] == true) 
                   vect[i].take();
                else
                   vect[i].untake();
            }
            quicksort_pos(vect, 0, vect.size() -1);
            return profit;
        }

    }
    
    vector <bool> track = bestNode->get_took();
    
    for (int i = 0; i < track.size(); i++) {
        if(track[i] == true) 
            vect[i].take();
        else
            vect[i].untake();
    }
    
    quicksort_pos(vect, 0, vect.size() -1);
           
    
    return profit;
    
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
    
    int total;
    int capacity;
    vector <item> data;
    
    int v;
    int w;
    
    fin >> total;
    fin >> capacity;
    
    data.resize(total);
    
    int c = 0; // counter to keep track of original index in list
    
    while (c < total){
        fin >> v;
        fin >> w;
        
        item temp(v, w, c);
        
        data[c] = temp;
        c++;
    }
    
    quicksort_ratio(data, 0, data.size()-1);
    
    data[0].take();
    
    QNode* u = new QNode;
    u->set_level(-1);
    
    PQueue Q;
    Q.push(u);
    
    int score = knapsack(data, capacity, Q, total);
    
    string outfilename;
    outfilename = filename + "_output.txt";
    
    ofstream fout;
    fout.open(outfilename);
    
    fout << score << endl;
    for(int i = 0; i < data.size(); i++) {
        fout << data[i].is_taken() << " ";
    }

       
//    for(int i = 0; i < data.size(); i++) {
//        cout << i << ": " << data[i].get_value() << " " 
//                << data[i].get_weight() <<  " " 
//                << data[i].is_taken() << endl;
//    }
       
    
//    for(int i = 0; i < data.size(); i++) {
//        cout << i << ": " << data[i].get_value() << " " 
//                << data[i].get_weight() << endl;
//    }

    
    
    

    return 0;
}

 