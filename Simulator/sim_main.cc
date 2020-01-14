#include <iostream>
#include <vector>
#include <iomanip>
#include "sim.cc"

void Simulate(std::vector<Component*> net, int iterations, int prints, double tick){
  for(int i = 0; i < net.size(); ++i){
    std::cout << std::setw(12) << std::setfill(' ') << net[i]->name;
  }
  std::cout << '\n';
  for(int i = 0; i < net.size(); ++i){
    std::cout << std::setw(6) << "Volt";
    std::cout << std::setw(6) << "Curr";
  }
  std::cout << '\n';

  for(int x{0}; x <= iterations; ++x){
    for (int i = 0; i < net.size(); ++i){
      net[i]->simulate(tick);
      }
      if(x%(iterations / prints) == 0 && x != 0){
          for(int i = 0; i < net.size(); ++i){
            std::cout << std::setw(6)<<std::fixed << std::setprecision(2) << net[i]->voltage();
            std::cout << std::setw(6) << std::setprecision(2) << net[i]->current();
      }
      std::cout << '\n';
    }
  }
}

int main(int argc, char const *argv[]) {
  Connection p{};
  Connection l{};
  Connection n{};
  Connection r{};
  Connection* P{&p};
  Connection* L{&l};
  Connection* N{&n};
  Connection* R{&r};
  std::vector<Component*> net;
  net.push_back(new Battery("Bat", 24.0, P, N));
  net.push_back(new Resistor("R1", 150.0, P, L));
  net.push_back(new Resistor("R2", 50.0, P, R));
  net.push_back(new Condensator("C3", 1.0, L, R));
  net.push_back(new Resistor("R4", 300.0, L, N));
  net.push_back(new Condensator("C5", 0.75, R, N));
  Simulate(net, 200000, 10, 0.01);
}

/*
1-----------------------------------------------
Connection p{};
Connection n{};
Connection r124{};
Connection r23{};
Connection* P{&p};
Connection* N{&n};
Connection* R124{&r124};
Connection* R23{&r23};
std::vector<Component*> net;
net.push_back(new Battery("Bat", 24.0, P, N));
net.push_back(new Resistor("R1", 6.0, P, R124));
net.push_back(new Resistor("R2", 4.0, R124, R23));
net.push_back(new Resistor("R3", 8.0, R23, N));
net.push_back(new Resistor("R4", 12.0, R124, N));
2----------------------------------------------
Connection p{};
Connection l{};
Connection n{};
Connection r{};
Connection* P{&p};
Connection* L{&l};
Connection* N{&n};
Connection* R{&r};
std::vector<Component*> net;
net.push_back(new Battery("Bat", 24.0, P, N));
net.push_back(new Resistor("R1", 150.0, P, L));
net.push_back(new Resistor("R2", 50.0, P, R));
net.push_back(new Resistor("R3", 100.0, L, R));
net.push_back(new Resistor("R4", 300.0, L, N));
net.push_back(new Resistor("R5", 250.0, R, N));
3-----------------------------------------------
Connection p{};
Connection l{};
Connection n{};
Connection r{};
Connection* P{&p};
Connection* L{&l};
Connection* N{&n};
Connection* R{&r};
std::vector<Component*> net;
net.push_back(new Battery("Bat", 24.0, P, N));
net.push_back(new Resistor("R1", 150.0, P, L));
net.push_back(new Resistor("R2", 50.0, P, R));
net.push_back(new Condensator("C3", 1.0, L, R));
net.push_back(new Resistor("R4", 300.0, L, N));
net.push_back(new Condensator("C5", 0.75, R, N));
*/
