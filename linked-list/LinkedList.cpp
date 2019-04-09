class Node
{
  public:
    int data;
    Node *next;
};

class LinkedList
{
  private:
    Node *initNode;

  public:
    void insert(int data, Node *ptr)
    {
        Node *node = new Node();
        ptr->next = node;
        node->next = ptr->next;
    }

    void display()
    {
    }
}