/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   facility.h
 * Author: alifarooqui
 *
 * Created on May 6, 2019, 11:09 PM
 */

#ifndef FACILITY_H
#define FACILITY_H

class facility {
public:
    facility();
    facility(const facility& orig);
    virtual ~facility();
    
    
    void set_x(float & new_x);
    void set_y(float & new_y);
    void set_cost(float & new_cost);
    void set_capacity(float new_cap);
    void set_pos(int & new_pos);
    float get_x();
    float get_y();
    float get_cost();
    float get_capacity();
    int get_pos();
    
private:
    float cost;
    float capacity;
    float x;
    float y;
    int pos;

};

#endif /* FACILITY_H */

