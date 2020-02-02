/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graphpair.cpp
 * Author: alifarooqui
 * 
 * Created on February 25, 2019, 12:13 AM
 */

#include "graphpair.h"

graphpair::graphpair() {
}

graphpair::graphpair(const graphpair& orig) {
}

graphpair::~graphpair() {
}

void graphpair::set_vertex(int & value) {
    vertex = value;
}

void graphpair::set_edge(int & value) {
    edge = value;
}

int graphpair::get_vertex() {
    return vertex;
}

int graphpair::get_edge() {
    return edge;
}

