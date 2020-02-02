// Sean McCulloch
// 3/27/02
// node.h- defines an integer node class for use in a linked list
// (or other dynamic structure)  Defines basic accessor
// and mutator functions
#ifndef DOUBLENODE_H
#define DOUBLENODE_H
#include <vector>
#include "item.h"

template <typename T>
class DoubleNode{
	public:
		//default constructor, which will get called when
		// we create a node
		DoubleNode();
		//destructor which will get called when we delete a node
		~DoubleNode();
		
		//accessor and mutator for the "item"- the data the
		// node holds
		T get_item() const;
		void set_item(const T& new_item);
		
		//accessor and mutator for the "next"- the pointer to
		// the next node in the list
		DoubleNode<T>* get_next() const;
		void set_next(DoubleNode<T>* next_item);

		// accessor and mutator for the "prev"- the pointer to the previous node in the list
		DoubleNode<T>* get_prev() const;
		void set_prev(DoubleNode<T>* prev_node);
		
	private:
	
		DoubleNode<T>* Next;
		DoubleNode<T>* Prev;
		int item;
};

template <typename T>
DoubleNode<T>::DoubleNode(){
  item = T();
  Next = NULL; // note that the compiler knows what NULL is,
  // as long as we include cstdlib
  Prev = NULL;

}

//destructor- called when the item is deleted.  
// We could delete the next item in the list, but since we 
//won't always want that behavior, it's better to make that be
// the job of the structure that uses the node
template <typename T>
DoubleNode<T>::~DoubleNode(){
	Next = NULL; // because I'm really paranoid, and I want to
	             // make sure it's done, in case someone forgets
	Prev = NULL;
	// there's no need to set item to anything..
}

//Accessor function for the _item_- the value that is stored in 
// the node
// Notice that this function is declared _const_.  That's important, 
// because it means that it can be used by const items.
template <typename T>
T DoubleNode<T>::get_item() const{
  return item;
 }
 
// Mutator function for the item
template <typename T>
void DoubleNode<T>::set_item(const T&new_item){
	item = new_item;
}

// now, the accessor and mutator functions for the next field.
// the next field points to the next node in the list, which
// is why it is of type "pointer to a node"
template <typename T>
DoubleNode<T>* DoubleNode<T>::get_next() const{
	return Next;
}

template <typename T>
void DoubleNode<T>::set_next(DoubleNode<T>* next_item){
	Next= next_item;
}

// accessor and mutator functions for the prev pointer
template <typename T>
DoubleNode<T>* DoubleNode<T>::get_prev() const{
  return Prev;
}

template <typename T>
void DoubleNode<T>::set_prev(DoubleNode<T>* prev_item){
  Prev = prev_item;
}

#endif
