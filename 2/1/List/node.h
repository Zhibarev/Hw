#ifndef NODE_H
#define NODE_H

class Node
{
public:
   Node(int number, Node *next);
    int value();
    void changeValue(int number);
    Node* nextNode();
    void changeNext(Listnode* newNext);
private:
    int value;
    Node *next;
}

#endif // NODE_H
