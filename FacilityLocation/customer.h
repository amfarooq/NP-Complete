/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   customer.h
 * Author: alifarooqui
 *
 * Created on May 6, 2019, 11:20 PM
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

class customer {
public:
    customer();
    customer(const customer& orig);
    customer(float & new_x, float & new_y, float & new_demand);
    virtual ~customer();
    void set_x(float & new_x);
    void set_y(float & new_y);
    void set_demand(float & new_demand);
    void set_facility(int new_fac);
    void set_pos(int & new_pos);
    float get_x();
    float get_y();
    float get_demand();
    int get_facility();
    int get_pos();
    
private:
    float x;
    float y;
    float demand;
    int facility;
    int pos;
};

#endif /* CUSTOMER_H */

