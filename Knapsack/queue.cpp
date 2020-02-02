// Ali Farooqui
// CS210
// Queue class implementation file

#include <cstdlib>
#include <iostream>
#include "queue.h"
#include "doublenode.h"

using namespace std;

// Default constructor- sets all pointers to NULL
Queue::Queue(){
  Front = NULL;
  Back = NULL;
  last_error = false;
}

Queue::~Queue(){
  ;
}


// Copy constructor- makes a deep copy of the parameter
Queue::Queue(const Queue& other){

  Front = NULL;
  Back = NULL;
  if(!other.Is_Empty()){
    DoubleNode<int>* other_p = other.Front;
    while(other_p != NULL){
      Enqueue(other_p->get_item());
      other_p = other_p->get_prev();
    }
  }
}

// if the queue is empty, returns -1, otherwise returns item at the front.
int Queue::Peek_front() const{
    if(!Is_Empty())
    return Front->get_item();
    
    else
        return -1;
}

// adds an item to the back of the queue
void Queue::Enqueue(const int& new_val){
    
    // special case if there is nothing in the queue    
    if(Front == NULL){
        DoubleNode<int>* new_front = new DoubleNode<int>;
        new_front->set_item(new_val);
        new_front->set_prev(Back);
        new_front->set_next(NULL);
        Front = new_front;
    }
    
    // special case if there is only one item in the queue
    else if(Back == NULL && Front != NULL){
        Back = new DoubleNode<int>;
        Back->set_item(new_val);
        Back->set_next(Front);
        Back->set_prev(NULL);
        Front->set_prev(Back);
    }
    
   // if there are more than 2 items in the queue
    else {
        DoubleNode<int>* new_back = new DoubleNode<int>;
        new_back->set_item(new_val);
        new_back->set_next(Back);
        new_back->set_prev(NULL);
        Back->set_prev(new_back);
        Back = new_back;
    }
    
}

// removes the front item from the queue, and if there is an item behind
// Front, makes that item the new Front.
void Queue::Dequeue() {
    if (Is_Empty())
        last_error = true;
    
    else {
        DoubleNode<int>* kill = Front;
        
        // special case if there is only one item in the queue, hence if 
        // Front's get_prev is NULL.
        if (Front->get_prev() == NULL) {
            Front = NULL;
            delete kill;
            kill = NULL;            
        }
        
        else {
        Front = Front->get_prev();
        kill->set_prev(NULL);
        Front->set_next(NULL);
        delete kill;
        kill = NULL;
        }
    }
}

// checks whether queue is empty
bool Queue::Is_Empty() const{
    if(Front == NULL)
        return true;
    else
        return false;
}

bool Queue::Error() const{
    if (last_error == true)
        return true;
    else
        return false;
}

// Prints out the queue. 
void Queue::Print() {
    
    DoubleNode<int>* p = Front;
    while(p != NULL) {
        cout << p->get_item() << " ";
        p = p->get_prev();
    }
}
