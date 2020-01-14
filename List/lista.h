class Sorted_List{
public:
  Sorted_List(){
      first = nullptr;
    }
  ~Sorted_List();
private:
  class Node{
  public:
    Node(int parse_val = 0, Node* parse_node = nullptr)
    : val{parse_val}, next{parse_node}{}
    Node* get_next()const;
    int get_val()const;
    void change_next(Node*);
    void change_val(int);
  private:
    int val{};
    Node* next{};
  };
  Sorted_List::Node* first{};
public:
  Sorted_List::Node* get_first()const;
  void insert(int);
  void remove(int);
  bool is_empty()const;
  int size()const;
  Sorted_List(Sorted_List &);
  Sorted_List(Sorted_List&&);
  Node* copy(Sorted_List &);
  Sorted_List::Node* ins_adress(Node*, int)const;
  void destroy();
  Sorted_List& operator=(Sorted_List &);
};
