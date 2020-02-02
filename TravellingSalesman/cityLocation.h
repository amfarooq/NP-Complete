/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cityLocation.h
 * Author: alifarooqui
 *
 * Created on May 4, 2019, 4:11 PM
 */

#ifndef CITYLOCATION_H
#define CITYLOCATION_H

class cityLocation {
public:
    cityLocation();
    cityLocation(float & new_x, float & new_y);
    cityLocation(const cityLocation& orig);
    virtual ~cityLocation();
    
    void set_x(float & new_x);
    void set_y(float & new_y);
    float get_x();
    float get_y();
    
private:
    float x;
    float y;

};

#endif /* CITYLOCATION_H */

