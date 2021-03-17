#include "queue.h"
#include <iostream>
struct Node {

  int key;
  Node* next;

  Node(int k){
    key = k;
    next = nullptr;
  }

};

Queue::Queue() {
  // TODO
  this->front_ = nullptr;
  this->back_ = nullptr;
}

void Queue::push(int k) {

  struct Node *node = new Node(k);

  if(this->front_ == nullptr && this->back_ == nullptr){

    this->front_ = node;
    this->back_ = node;

  } else {

    this->back_->next = node;
    this->back_ = node; 
  } 

}

void Queue::pop() {

  if (this->front_ == nullptr){

    throw EmptyException();

  } else if(count() == 1){

    this->back_ = nullptr;
		this->front_ = nullptr;

  } else {

    this->front_ = this->front_->next;

  }

}

int Queue::front() const {

  if (count() == 0){
      throw EmptyException();
  }
    return this->front_->key;
}

int Queue::back() const {
	//Return the back value or 0.
	if (count() == 0){

		throw EmptyException();
  
  }

	return this->back_->key;
}

int Queue::count() const {

  int qtd = 1;
  Node *node = this->front_;

  if(this->front_ == nullptr){

    return 0;

  } else if(this->front_ != nullptr && this->front_->next == nullptr){ 

    return 1;

  } else {

    while(node->next != nullptr){

      qtd++;
      node = node->next;

    }

    return qtd;

  }

}