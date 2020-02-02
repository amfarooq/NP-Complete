/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   item.cpp
 * Author: alifarooqui
 * 
 * Created on March 13, 2019, 1:26 PM
 */

#include "item.h"

item::item() {
    value = 0;
    weight = 0;
    pos = 0;
    taken = false;
}

item::item(int & val, int & wei, int & p) {
    value = val;
    weight = wei;
    pos = p;
    taken = false;
}

item::item(const item& orig) {
    value = orig.value;
    weight = orig.weight;
    pos = orig.pos;
    taken = orig.taken;
}

void item::set_value(const int & val) {
    value = val;
}

void item::set_weight(const int & w) {
    weight = w;
}

void item::take(){
    taken = true;
}

void item::untake() {
    taken = false;
}

int item::get_value() {
    return value;
}

int item::get_weight(){
    return weight;
}

int item::get_pos() {
    return pos;
}

double item::get_ratio() {
    return (double)value/(double)weight;
}

bool item::is_taken() {
    return taken;
}

item::~item() {
}


