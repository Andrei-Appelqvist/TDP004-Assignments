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
    Node* get_next();
    int get_val();
    void change_next(Node*);
    void change_val(int);
  private:
    int val{};
    Node* next{};
  };

  Sorted_List::Node* first{};
public:
  void change_node_val(int, int);
  Sorted_List::Node* get_first();
  int get_length();
  void insert(int);
  void remove();
  bool is_empty();
  int size();

};
