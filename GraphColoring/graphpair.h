/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graphpair.h
 * Author: alifarooqui
 *
 * Created on February 25, 2019, 12:13 AM
 */

#ifndef GRAPHPAIR_H
#define GRAPHPAIR_H

class graphpair {
public:
    graphpair();
    graphpair(const graphpair& orig);
    virtual ~graphpair();
    
    void set_vertex(int & value);
    void set_edge(int & value);
    
    int get_vertex();
    int get_edge();
    
private:
    int vertex;
    int edge;

};

#endif /* PAIR_H */

