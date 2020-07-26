#include <cstdio>
#include <iostream>
#include "avl.hpp"

int main()
{
    int num;
    avlTree<int>* tree = new avlTree<int>();
    cout << "Input value now!" << endl;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int x;
        cin >> x;
        tree->insert(x);
    }
    cout << "The height of this tree: " << tree->height() << endl;
    tree->inOrder();
    cout << endl;
    tree->remove(4);
    cout << endl;
    tree->inOrder();
    cout << endl;
    tree->destroy();
    return 0;
}