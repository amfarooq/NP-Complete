/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PQueue.h
 * Author: alifarooqui
 *
 * Created on March 28, 2019, 6:48 PM
 */

#ifndef PQUEUE_H
#define PQUEUE_H

#include "QNode.h"

class PQueue {
public:
    PQueue();
    PQueue(const PQueue& orig);
    virtual ~PQueue();
    
    void push(QNode* new_node);
    QNode* pop();
    // make a peek function but what type should it be???????
    bool isEmpty();
    
    
private:
    QNode* front;

};

#endif /* PQUEUE_H */

