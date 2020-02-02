/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   facility.cpp
 * Author: alifarooqui
 * 
 * Created on May 6, 2019, 11:09 PM
 */

#include "facility.h"

facility::facility() {
    cost = 0;
    capacity = 0;
    x = 0;
    y = 0;
    pos = 0;
}

facility::facility(const facility& orig) {
    cost = orig.cost;
    capacity = orig.capacity;
    x = orig.x;
    y = orig.y;
    pos = orig.pos;
}

facility::~facility() {
}

void facility::set_x(float & new_x){
    x = new_x;
}

void facility::set_y(float & new_y){
    y = new_y;
}

void facility::set_cost(float & new_cost){
    cost = new_cost;
}

void facility::set_capacity(float new_cap){
    capacity = new_cap;
}

void facility::set_pos(int & new_pos) {
    pos = new_pos;
}

float facility::get_x() {
    return x;
}

float facility::get_y(){
    return y;
}

float facility::get_cost(){
    return cost;
}

float facility::get_capacity(){
    return capacity;
}

int facility::get_pos() {
    return pos;
}
