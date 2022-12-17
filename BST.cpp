#include "BST.h"

bool BST::insert(Node*& node, int data)
{
    //if a node is pointing to nothing create a new node
    if (node == nullptr)
    {
        node = new Node(data);
        return true;
    }
    //if the node data is less than the nodes data, insert to the left
    if (data < node->data)
    {
        return insert(node->left, data);
    }
    //if the node data is greater than the nodes data, insert to the right
    if (data > node->data)
    {
        return insert(node->right, data);
    }
    return false;
}

bool BST::find(Node* node, int data)
{
    //creates a temporary pointer to a node 
    Node* tmp = node;
    //while the pointer is pointing to nothing
    while (tmp != nullptr)
    {
        //check to see if the node has data
        if (tmp->data == data)
        {
            return true;
        }
        //if the data is greater, point to the other node, else
        if (tmp->data > data)
        {
            tmp = tmp->left;
        }
        else 
        {
            tmp = tmp->right;
        }
    }
    return false;
}

bool BST::remove(Node*& node, int data)
{
    //if a node is empty, nothings there to remove
    if (node == nullptr)
    {
        return false;
    }
    //if the data is less than the nodes data, remove the lefts data
    if (data < node->data)
    {
        return remove(node->left, data);
    }
    //if the data is greater than the nodes data, remove the rights data
    if (data > node->data)
    {
        return remove(node->right, data);
    }

    //a variable for the degree
    int deg = node->degree();

    //if the degree is 0, delete it and make it point to nothing
    if (deg == 0)
    {
        delete node;
        node = nullptr;
    }
    //iff the degree is 1
    //if a nodes left data is empty delete the left, else delete the right
    else if (deg == 1)
    {
        Node* tmp = node;
        if (node->left == nullptr)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
        delete tmp;
    }
    //if the degree is 2+
    //while the right is not empty, delete the right
    else
    {
        Node *tmp = node->left;
        while (tmp->right != nullptr)
        {
            tmp = tmp->right;
        }
        node->data = tmp->data;
        remove(node->left, tmp->data);
    }
    return true;
}

//tells how many children the node has
int Node::degree() const
{
    //set the default to 0
    int degree = 0;
    //if the right node is not empty
    if (right != nullptr)
    {
        degree++;
    }
    //if the left node is empty
    if (left != nullptr)
    {
        degree++;
    }
    return degree;
}
//if node is empty, theres nothing there
//displays by left child, right child, value 
void BST::postOrder(Node* node, ostream& os)
{
    //if a node is empty, return
    if (node == nullptr)
    {
        return;
    }
    //print the left, right, then the data in the middle
    postOrder(node->left, os);
    postOrder(node->right, os);
    os << node->data << " ";
}

//if node is empty, theres nothing there
//displays by value, left child, right child 
void BST::preOrder(Node* node, ostream& os)
{
    //if the node is empty, return
    if (node == nullptr)
    {
        return;
    }
    //print the data, the left, then the right
    os << node->data << " ";
    preOrder(node->left, os);
    preOrder(node->right, os);
}

//if node is empty, theres nothing there
//displays by left child, value, right child 
void BST::inOrder(Node* node, ostream& os)
{
    //if the node is empty, return
    if (node == nullptr)
    {
        return;
    }
    //print the left, the middle, and the right
    inOrder(node->left, os);
    os << node->data << " ";
    inOrder(node->right, os);

}

//public facing versions of each function
bool BST::insert(int data)
{
    return insert(root, data);
}

bool BST::find(int data)
{
    return find(root, data);
}

bool BST::remove(int data)
{
    return remove(root, data);
}

void BST::inOrder(ostream &os)
{
    inOrder(root, os);
}

void BST::preOrder(ostream &os)
{
    preOrder(root, os);
}

void BST::postOrder(ostream &os)
{
    postOrder(root, os);
}

//destructor
BST::~BST()
{
    delete(root);
}