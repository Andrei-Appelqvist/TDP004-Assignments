#include <iostream>
#include "l_test.h"

Sorted_List::Node* Sorted_List::Node::get_next(){
  return next;
}
int Sorted_List::Node::get_val(){
  return val;
}
void Sorted_List::Node::change_next(Node* new_next){
  next = new_next;
}
void Sorted_List::Node::change_val(int new_val){
  val = new_val;
}
Sorted_List::Node* Sorted_List::get_first(){
  return first;
}

void Sorted_List::change_node_val(int new_val, int pos){
  Node* current = get_first();
  //if(pos > size() || pos < 1){
    //std::cerr << "Desired position out of range!" << std::endl;
  //}
  //else{
  for(int x{1}; x < pos; ++x){
    current = current->Node::get_next();
  }
  current->Node::change_val(new_val);
}

//}
void Sorted_List::insert(int ins_val){
  if(is_empty()){
    first = new Node{ins_val, nullptr};
  }
  else{
    Sorted_List::Node* current = first;
    while(current->get_next() != nullptr){
      current = current->Node::get_next();
  }
    Sorted_List::Node* new_node = new Node{ins_val, nullptr};
    current->Node::change_next(new_node);
  }
}




void Sorted_List::remove(){
  if(is_empty()){
    std::cerr << "List is already empty" << '\n';
  }
  else{
    Sorted_List::Node* current = first;
    while(current->get_next()->get_next() != nullptr){
      current = current->Node::get_next();
    }
    std::cout << current->get_next() << "-< del" << '\n';
    delete current->get_next();
    current->Node::change_next(nullptr);
  }
}

bool Sorted_List::is_empty(){
  return (first == nullptr);
}

int Sorted_List::size(){
  int size{};
  Sorted_List::Node* current = get_first();
  while(current != nullptr){
    size = size + 1;
    current = current -> get_next();
  }
  return size;
}


Sorted_List::~Sorted_List(){
  Node* current = first;
  Node* new_curr{};
  while(current != nullptr){
    new_curr = current->get_next();
    delete current;
    current = new_curr;
    if(current == nullptr){
      break;
    }
  }
}




int main(){
  Sorted_List t{};
  t.insert(5);
  t.insert(3);
  t.insert(4);
std::cout << t.get_first()->Node::get_val() << '\n';
}
