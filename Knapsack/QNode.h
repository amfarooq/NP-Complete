/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QNode.h
 * Author: alifarooqui
 *
 * Created on March 28, 2019, 6:53 PM
 */

#ifndef QNODE_H
#define QNODE_H
#include <vector>
#include "item.h"

using namespace std;

class QNode {
public:
    QNode();
    QNode(int & c, double & b, int & l, int & w, bool & t);
    QNode(const QNode& orig);
    virtual ~QNode();
    
    int get_level();
    void set_level(const int & l);    
    
    int get_profit();
    void set_profit(const int & n);
        
    double get_bound();
    void set_bound(const double & b);
    
    int get_weight();
    void set_weight(const int & w);

    void take();
    void untake();
    
    QNode* get_next();
    void set_next(QNode* new_node);
    
    QNode* get_prev();
    void set_prev(QNode* new_node);
    
    vector <bool> get_took();
    void set_took(const vector <bool> & v);
    void save(const bool & t);
        
    
private:
    QNode * next;
    QNode * prev;
    int profit;
    double bound;
    int level;
    int weight; 
    
    vector <bool> took;
    bool taken;

};

#endif /* QNODE_H */

