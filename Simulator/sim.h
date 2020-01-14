struct Connection{
  double charge{};
};

class Component{
public:
  Component(std::string, Connection*, Connection*);
  virtual void simulate(double tick) = 0;
  std::string name{};
  double voltage();
  virtual double current() = 0;
protected:
  Connection* left{};
  Connection* right{};
  virtual~Component()=default;
};
class Battery:public Component{
private:
  double charge{};
public:
  Battery(std::string,  double, Connection*, Connection*);
  double current() override;
  void simulate(double tick) override;
};

class Resistor:public Component{
private:
  double resistance{};
public:
  Resistor(std::string, double, Connection*, Connection*);
  double current() override;
  void simulate(double tick) override;
};

class Condensator: public Component{
private:
  double capacity{};
  double charge{};
public:
  Condensator(std::string, double, Connection*, Connection*);
  double current() override;
  void simulate(double tick) override;
};
