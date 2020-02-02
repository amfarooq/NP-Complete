/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QNode.cpp
 * Author: alifarooqui
 * 
 * Created on March 28, 2019, 6:53 PM
 */

#include "QNode.h"
#include <cstdlib>
#include <vector>

QNode::QNode() {
    profit = 0;
    bound = 0;
    level = 0;
    weight = 0;
    taken = false;
    next = nullptr;
    prev = nullptr;
}

QNode::QNode(int & c, double & b, int & l, int & w, bool & t) {
    profit = c;
    bound = b;
    level = l;
    weight = w;
    taken = t;
    next = nullptr;
    prev = nullptr;
}

QNode::QNode(const QNode& orig) {
}

QNode::~QNode() {
    next = nullptr;
    prev = nullptr;
}

int QNode::get_level() {
    return level;
}

void QNode::set_level(const int & l) {
    level = l;
} 

int QNode::get_profit(){
    return profit;
}

void QNode::set_profit(const int & n) {
    profit = n;
}

double QNode::get_bound() {
    return bound;
}

void QNode::set_bound(const double & b){
    bound = b;
}

int QNode::get_weight() {
    return weight;
}

void QNode::set_weight(const int & w) {
    weight = w;
}


void QNode::take() {
    taken = true;
}

void QNode::untake() {
    taken = false;
}

QNode* QNode::get_next() {
    return next;
}

void QNode::set_next(QNode* new_node) {
    next = new_node;
}
    
QNode* QNode::get_prev() {
    return prev;
}

void QNode::set_prev(QNode* new_node) {
    prev = new_node;
}

vector <bool> QNode::get_took() {
    return took;
}

void QNode::set_took(const vector <bool> & v) {
    took = v;
}

void QNode::save(const bool & t) {
    took.push_back(t);
}