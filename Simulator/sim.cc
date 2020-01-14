#include <iostream>
#include "sim.h"
Component::Component(std::string name, Connection*left, Connection*right)
  : name{name}, left{left}, right{right}{}

Battery::Battery(std::string name, double charge, Connection*left, Connection*right)
  : Component{name, left, right}, charge{charge}{}

Resistor::Resistor(std::string name, double resistance, Connection*left, Connection*right)
  : Component{name, left, right}, resistance{resistance}{}

Condensator::Condensator(std::string name, double capacity, Connection* left, Connection* right)
  : Component{name, left, right}, capacity{capacity}{}

void Battery::simulate(double tick){
  left->charge = charge;
  right->charge = 0;
}
void Resistor::simulate(double tick){
  if(left->charge > right->charge){
      left->charge = left->charge - (voltage()/resistance*tick);
      right->charge = right->charge + (voltage()/resistance*tick);
  }
  else{
    left->charge = left->charge + (voltage()/resistance*tick);
    right->charge = right->charge - (voltage()/resistance*tick);
  }
}



void Condensator::simulate(double tick){
  charge += current() * tick;
  if(left->charge > right->charge){
    left->charge -= current() * tick;
    right->charge += current() * tick;
  }
  else{
    left->charge += current() * tick;
    right->charge -= current() * tick;
  }
}

double Component::voltage(){
  if(left->charge > right->charge){
    return(left->charge - right->charge);
  }
  else{
    return(right->charge - left->charge);
  }
}

double Resistor::current(){
  return(voltage()/resistance);
}

double Condensator::current(){
  return(capacity * (voltage()-charge));
}

double Battery::current(){
  return(0.0);
}
