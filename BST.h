#include <iostream>
using namespace std;

class Node
{
    //creates the node that we are storing data in.
    public:
    int data;
    Node* left;
    Node* right;

    //the node points to the left and right 
    //   o
    //  / \ 
    // o   o

    Node(): data(0), left(nullptr), right(nullptr) {}
    Node(int data): data(data), left(nullptr), right(nullptr) {}

    //degree is the number of children it possesses
    int degree() const;
};

class BST
{
    //the root is the top-most node
    //arguments storing the address and data
    //the order(s) point to a node and are able to display
    private:
    Node *root;
    bool insert(Node *&node, int data);
    bool remove(Node *&node, int data);
    bool find(Node* node, int data);
    void inOrder(Node* node, ostream& os);
    void preOrder(Node* node, ostream& os);
    void postOrder(Node* node, ostream& os);
    // void destroy(Node*& node); omit

    public:
    BST(): root(nullptr) {}
    ~BST();
    bool insert(int data);
    bool remove(int data);
    bool find(int data);
    void inOrder(ostream& os);
    void preOrder(ostream& os);
    void postOrder(ostream& os);
    
};