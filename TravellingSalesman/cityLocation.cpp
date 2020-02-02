/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cityLocation.cpp
 * Author: alifarooqui
 * 
 * Created on May 4, 2019, 4:11 PM
 */

#include "cityLocation.h"

cityLocation::cityLocation() {
    x = 0;
    y = 0;
}

cityLocation::cityLocation(float & new_x, float & new_y) {
    x = new_x;
    y = new_y;
}

cityLocation::cityLocation(const cityLocation& orig) {
    x = orig.x;
    y = orig.y;
}

cityLocation::~cityLocation() {
}

void cityLocation::set_x(float & new_x) {
    x = new_x;
}

void cityLocation::set_y(float & new_y) {
    y = new_y;
}

float cityLocation::get_x() {
    return x;
}

float cityLocation::get_y() {
    return y;
}


