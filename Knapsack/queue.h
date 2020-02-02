// Ali Farooqui
// CS210
// Queue class .h file

#ifndef QUEUE_H
#define QUEUE_H

#include "doublenode.h"
#include <cstdlib>

class Queue{
 public:
  //Constructor- creates an empty queue
  Queue();
  
  // Destructor- removes and deletes all nodes from the queue.
  ~Queue();

  // Copy constructor- makes a deep copy
  Queue(const Queue& other);

  // enqueue- inserts an item into the back of the queue
  void Enqueue(const int& new_val);

  // dequeue- removes an item from the front of the queue
  // sets the error state if the queue is empty
  void Dequeue();
  
  // returns the item at the front of the queue
  int Peek_front() const;
  
  // prints the queue in order
  void Print();

  // returns true if queue is empty
  bool Is_Empty() const;

  // returns true if the last operation caused an error- false otherwise
  bool Error() const;
  
  
 private:
  DoubleNode<int>* Front;  
  DoubleNode<int>* Back;
  bool last_error;
};

#endif
