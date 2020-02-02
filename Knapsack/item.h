/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   item.h
 * Author: alifarooqui
 *
 * Created on March 13, 2019, 1:26 PM
 */

#ifndef ITEM_H
#define ITEM_H

class item {
    
public:
    
    item();
    item(const item& orig);
    item(int & val, int & wei, int & p);
    
    void set_value(const int & val);
    void set_weight(const int & w);
    void take();
    void untake();
    
    int get_value();
    int get_weight();
    int get_pos();
    double get_ratio();
    bool is_taken();
    
    virtual ~item();
    
private:
    int value;
    int weight;
    int pos;
    bool taken;

};

#endif /* ITEM_H */

