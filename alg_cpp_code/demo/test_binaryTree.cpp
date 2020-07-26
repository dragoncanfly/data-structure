#include "binaryTree.hpp"
#include <iostream>

int main()
{
    int num;
    cout << "Input the node num of binary tree!" << endl;
    cin >> num;
    vector<int>input;
    binaryTree<int> myTree;
    int x;
    for (int i = 0; i < num; i++)
    {
        cin >> x;
        input.push_back(x);
    }
    myTree.buildTree(input);
    
    cout << "Pre order traverse! " << endl;
    cout << "First-recursive: ";
    myTree.recurPreOrder();
    cout << endl;
    cout << "Second-iterative: ";
    myTree.iterPreOrder();
    cout << endl;
    cout << "Third-morris: ";
    myTree.morrisPreOrder();
    cout << endl;

    cout << "In order traverse!" << endl;
    cout << "First-recursive: ";
    myTree.recurInOrder();
    cout << endl;
    cout << "Second-iterative: ";
    myTree.iterInOrder();
    cout << endl;
    cout << "Third-morris: ";
    myTree.morrisInOrder();
    cout << endl;

    cout << "Post order traverse!" << endl;
    cout << "First-recursive: ";
    myTree.recurPostOrder();
    cout << endl;
    cout << "Second-iterative: ";
    myTree.iterPostOrder();
    cout << endl;
    cout << "Third-morris: ";
    myTree.morrisPostOrder();
    cout << endl;

    myTree.destroy();

    return 0;
}