/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PQueue.cpp
 * Author: alifarooqui
 * 
 * Created on March 28, 2019, 6:48 PM
 */
#include <cstdlib>
#include "PQueue.h"
#include "doublenode.h"


PQueue::PQueue() {
    front = nullptr;

}

PQueue::PQueue(const PQueue& orig) {
    
}

PQueue::~PQueue() {
    
}

void PQueue::push(QNode* new_node) {
   
    if(front == nullptr){
        front = new_node;
    }
        
    else if(front->get_bound() < new_node->get_bound()) {
        new_node->set_next(front);
        front = new_node;
    }
    
    else {
        QNode* temp = front;
        while(temp->get_next() != nullptr && temp->get_next()->get_bound() > new_node->get_bound())
            temp = temp->get_next();
        
        if(temp->get_next() == nullptr) {
            temp->set_next(new_node);
            new_node->set_next(nullptr);
        }
        else {
            new_node->set_next(temp->get_next());
            temp->set_next(new_node);
        }
    }
}

//QNode* PQueue::peek_front() {
//    if (!isEmpty())
//        return front;
//    else {
//        QNode* temp = new QNode;
//        temp->set_level(-2);
//        temp->set_bound(0);
//        temp->set_profit(-1);
//        temp->set_weight(-1);
//        temp->untake();
//        
//        return temp;
//    }
//        
//}

QNode* PQueue::pop() {
    
    if(front == nullptr) {
        QNode* temp = new QNode;
        temp->set_level(-2);
        temp->set_bound(0);
        temp->set_profit(-1);
        temp->set_weight(-1);
        temp->untake();
        
        return temp;
    }
    
    else if(front->get_next() == nullptr) {
        QNode* temp = front;
        front = nullptr;    
        return temp;       
    }
    
    else {
        QNode* temp = front;
        front = front->get_next();
        temp->set_next(nullptr);
        return temp;
    }
    
}

bool PQueue::isEmpty() {
    if (front == nullptr)
        return true;
    else 
        return false;
}

