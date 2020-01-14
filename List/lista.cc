#include <iostream>
#include "lista.h"

Sorted_List::Node* Sorted_List::Node::get_next()const{
  return next;
}

int Sorted_List::Node::get_val()const{
  return val;
}

void Sorted_List::Node::change_next(Node *new_next){
  next = new_next;
}

void Sorted_List::Node::change_val(int new_val){
  val = new_val;
}

Sorted_List::Node* Sorted_List::get_first()const{
  return first;
}

Sorted_List::Node* Sorted_List::ins_adress(Node* current, int val)const{
  if(current->get_next() != nullptr && val <= current->get_next()->get_val()){
    return current;
  }
  else if(current->get_next() == nullptr){
    return current;
  }
  else{
    return ins_adress(current->get_next(), val);
  }
}

void Sorted_List::insert(int ins_val){
  if(is_empty()){
    first = new Node{ins_val, nullptr};
  }
  else if(first->get_val() > ins_val){
    first = new Node(ins_val, first);
  }
  else{
    Sorted_List::Node* obj = ins_adress(first, ins_val);
    Sorted_List::Node* new_node = new Node{ins_val, obj->get_next()};
    obj->change_next(new_node);
  }
}

void Sorted_List::remove(int val){
  Sorted_List::Node* current = first;
  if(first->get_val() == val){
    Node* new_point = first->get_next();
    delete first;
    first = new_point;
    }
  else if(size() > 1){
    while(current->get_next()->get_val() != val){
      current = current->get_next();
    }
    Node* new_point = current->get_next()->get_next();
    current->get_next()->change_next(nullptr);
    delete current->get_next();
    current->change_next(new_point);
  }
  else if(size() == 1){
    if(current->get_val() == val){
      delete current;
      first = nullptr;
  }
}
}

bool Sorted_List::is_empty()const{
  return (first == nullptr);
}

int Sorted_List::size()const{
  int size{};
  Sorted_List::Node* current = first;
  while(current != nullptr){
    size = size + 1;
    current = current->get_next();
  }
  return size;
}

Sorted_List::Sorted_List(Sorted_List &obj){
  first = copy(obj);
}

Sorted_List::Node* Sorted_List::copy(Sorted_List &other){
    if(other.first == nullptr){
      first = nullptr;
    }
    else{
      Node* current = other.first;
      first = new Node(current->get_val(), nullptr);
      Node* copy_current = first;
      current = current->get_next();
      while(current != nullptr){
        copy_current->change_next(new Node{current->get_val(), nullptr});
        copy_current = copy_current->get_next();
        current = current->get_next();
      }
    }
    return first;
}

void Sorted_List::destroy(){
  Node* current = first;
  Node* new_curr{};
  while(current != nullptr){
    new_curr = current->get_next();
    delete current;
    current = new_curr;
  }
  first = nullptr;
}

Sorted_List::~Sorted_List(){
  destroy();
}

Sorted_List::Sorted_List(Sorted_List &&other)
      : first{other.first}{
     other.first = nullptr;
}

Sorted_List& Sorted_List::operator=(Sorted_List &obj){
  destroy();
  first=copy(obj);
  return *this;
}
