/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   customer.cpp
 * Author: alifarooqui
 * 
 * Created on May 6, 2019, 11:20 PM
 */

#include "customer.h"

customer::customer() {
    x = 0;
    y = 0;
    demand = 0;
    facility = -1;
    pos = 0;
}

customer::customer(float & new_x, float & new_y, float & new_demand) {
    x = new_x;
    y = new_y;
    demand = new_demand;
 }

customer::customer(const customer& orig) {
    x = orig.x;
    y = orig.y;
    demand = orig.demand;
    facility = orig.facility;
    pos = orig.pos;
}

customer::~customer() {
}

void customer::set_x(float & new_x) {
    x = new_x;
}

void customer::set_y(float & new_y) {
    y = new_y;
}

void customer::set_demand(float & new_demand) {
    demand = new_demand;
}

void customer::set_facility(int new_fac) {
    facility = new_fac;
}

void customer::set_pos(int & new_pos) {
    pos = new_pos;
}


float customer::get_x() {
    return x;
}

float customer::get_y() {
    return y;
}

float customer::get_demand() {
    return demand;
}

int customer::get_facility() {
    return facility;
}

int customer::get_pos() {
    return pos;
}
