#include "BST.cpp"

int main()
{
    BST b;
    //inserting values into the tree
    b.insert(56);
    b.insert(34);
    b.insert(70);
    b.insert(5);
    b.insert(1);
    b.insert(42);
    b.insert(40);
    b.insert(52);
    b.insert(62);
    b.insert(57);
    b.insert(89);
    b.insert(90);

    //looks for 44 and 62
    //should return 0, 1
    cout << b.find(44);
    cout << endl;

    cout << b.find(62);
    cout << endl;

    //removes 62 from the tree
    //looks for 62, should return 0
    b.remove(62);
    cout << b.find(62);
    cout << endl;
    
    //inserts 44 to the tree
    //looks for 44, should return 1
    b.insert(44);
    cout << b.find(44);
    cout << endl;

    cout << "postOrder: ";
    b.postOrder(cout);
    cout << endl; 

    cout << "preOrder: ";
    b.preOrder(cout);
    cout << endl;

    cout << "inOrder: ";
    b.inOrder(cout);
    cout << endl;

    return 0;

}