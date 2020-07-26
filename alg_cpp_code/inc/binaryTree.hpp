//base base base try learn something with binary tree
#ifndef __BINARYTREE_HPP__
#define __BINARYTREE_HPP__

#include <algorithm>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

template <class T>
struct binaryTreeNode{
    T val;
    binaryTreeNode* left;
    binaryTreeNode* right;

    binaryTreeNode(T Val, binaryTreeNode* Left, binaryTreeNode* Right):val(Val), left(Left), right(Right){}
};

template <class T>
class binaryTree{
    public:  //interface to external

        //traverse tree recursive
        void recurPreOrder();
        void recurInOrder();
        void recurPostOrder();
        //traverse tree iterative
        void iterPreOrder();
        void iterInOrder();
        void iterPostOrder();
        //traverse tree morris
        void morrisPreOrder();
        void morrisInOrder();
        void morrisPostOrder();
        //build tree
        void buildTree(vector<T>& arr);
        //destroy
        void destroy();

    private:  
        binaryTreeNode<T>* root;

        //interface to internal
        //traverse tree recursive
        void recurPreOrder(binaryTreeNode<T>* node);
        void recurInOrder(binaryTreeNode<T>* node);
        void recurPostOrder(binaryTreeNode<T>* node);
        //traverse tree iterative
        void iterPreOrder(binaryTreeNode<T>* node);
        void iterInOrder(binaryTreeNode<T>* node);
        void iterPostOrder(binaryTreeNode<T>* node);
        //traverse tree morris
        void morrisPreOrder(binaryTreeNode<T>* node);
        void morrisInOrder(binaryTreeNode<T>* node);
        void morrisPostOrder(binaryTreeNode<T>* node);
        void printOutForMorrisPost(binaryTreeNode<T>* node);
        //to build a binary tree
        void buildBinaryTree(binaryTreeNode<T>* &node, vector<T>&arr, int size, int pos);
        //destroy tree
        void destroyTree(binaryTreeNode<T>* node);
};

//pre order traverse
template <class T>
void binaryTree<T>::recurPreOrder(binaryTreeNode<T>* node)
{
    if (node == NULL)
        return;
    cout << node->val << " ";
    recurPreOrder(node->left);
    recurPreOrder(node->right);
}

template <class T>
void binaryTree<T>::recurPreOrder()
{
    recurPreOrder(root);
}

//in order traverse
template <class T>
void binaryTree<T>::recurInOrder(binaryTreeNode<T>* node)
{
    if (node == NULL)
        return;
    recurInOrder(node->left);
    cout << node->val << " ";
    recurInOrder(node->right);
}

template <class T>
void binaryTree<T>::recurInOrder()
{
    recurInOrder(root);
}

// post order traverse
template <class T>
void binaryTree<T>::recurPostOrder(binaryTreeNode<T>* node)
{
    if (node == NULL)
        return;
    recurPostOrder(node->left);
    recurPostOrder(node->right);
    cout << node->val << " ";
}

template <class T>
void binaryTree<T>::recurPostOrder()
{
    recurPostOrder(root);
}

//iterative pre order
template <class T>
void binaryTree<T>::iterPreOrder(binaryTreeNode<T>* node)
{
    if (node == NULL)
        return;
    stack<binaryTreeNode<T>*> ts;
    binaryTreeNode<T>* cur = node;
    while (cur || !ts.empty())
    {
        if (cur)
        {
            cout << cur->val << " ";
            ts.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = ts.top();
            cur = cur->right;
            ts.pop();
        }      
    }
}

template <class T>
void binaryTree<T>::iterPreOrder()
{
    iterPreOrder(root);
}

//iterative in order traverse
template <class T>
void binaryTree<T>::iterInOrder(binaryTreeNode<T>* node)
{
    if (node == NULL)
        return;
    stack<binaryTreeNode<T>*> ts;
    binaryTreeNode<T>* cur = node;
    while (cur || !ts.empty())
    {
        if (cur)
        {
            ts.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = ts.top();
            cout << cur->val << " ";
            ts.pop();
            cur = cur->right;
        }
    }
}

template <class T>
void binaryTree<T>::iterInOrder()
{
    iterInOrder(root);
}

//iterative post order traverse
//different with preOrder and InOrder, should access root node before left and right node, 
//at the same time, first access left node, so set the right node in stack first;
//which case can access the node val: 1、left and right node all NULL, 2、there is left and right child, but one of them or all have been access
template <class T>
void binaryTree<T>::iterPostOrder(binaryTreeNode<T>* node)
{
    if (node == NULL)
        return;
    stack<binaryTreeNode<T>*> ts;
    binaryTreeNode<T>* cur = NULL;
    binaryTreeNode<T>* pre = NULL;
    ts.push(node);
    while (!ts.empty())
    {
        cur = ts.top();  //stay the root in stack bottom
        if ((cur->left == NULL && cur->right == NULL) || ((pre != NULL) && (pre == cur->left || pre == cur->right)))
        {
            cout << cur->val << " ";
            pre = cur;
            ts.pop();
        }
        else
        {
            //first push two child node to stack, then choose pop stack or not
            if (cur->right)
                ts.push(cur->right);
            if (cur->left)
                ts.push(cur->left);
        }
        
    }
}

template <class T>
void binaryTree<T>::iterPostOrder()
{
    iterPostOrder(root);
}


//morris pre order traverse
//with morris , can traverse binary tree with O(1) space and O(n) time
//morris 实现原则
//1 若当前节点无左孩子，则cur向右移动
//2 cur有左孩子，找到cur左子树上的最右节点，记为mostright
//2.1 如果mostright的right指针为空，则使其指向cur，cur向左移动（cur=cur->left）
//2.2 如果mostright的right指针指向cur，则令其指空，cur向右移动
template <class T>
void binaryTree<T>::morrisPreOrder(binaryTreeNode<T>* node)
{
    if (node == NULL)
        return;
    binaryTreeNode<T>* cur = node;
    binaryTreeNode<T>* mostRight = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            cout << cur->val << " ";
            cur = cur->right;
        }
        else
        {
            mostRight = cur->left;
            while (mostRight->right != NULL && mostRight->right != cur)
                mostRight = mostRight->right;
            if (mostRight->right == NULL)
            {
                mostRight->right = cur;
                cout << cur->val << " ";
                cur = cur->left;
            }
            else
            {
                mostRight->right = NULL;
                cur = cur->right;
            }
        }
    }        
}

template <class T>
void binaryTree<T>::morrisPreOrder()
{
    morrisPreOrder(root);
}

//morris inOrder traverse, same solution with morrisPreOrder, but different output position
template <class T>
void binaryTree<T>::morrisInOrder(binaryTreeNode<T>* node)
{
    if (node == NULL)
        return;
    binaryTreeNode<T>* cur = node;
    binaryTreeNode<T>* mostRight = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            cout << cur->val << " ";
            cur = cur->right;
        }
        else
        {
            mostRight = cur->left;
            while (mostRight->right != NULL && mostRight->right != cur)
            {
                mostRight = mostRight->right;
            }
            if (mostRight->right == NULL)
            {
                mostRight->right = cur;
                cur = cur->left;
            }
            else
            {
                mostRight->right = NULL;
                cout << cur->val << " ";
                cur = cur->right;
            }
        }
    }
}

template <class T>
void binaryTree<T>::morrisInOrder()
{
    morrisInOrder(root);
}

//morris postOrder traverse, different with other two, the order of output have definitely different operation
//
template <class T>
void binaryTree<T>::morrisPostOrder(binaryTreeNode<T>* node)
{
    if (node == NULL)
        return;
    binaryTreeNode<T>* cur = node;
    binaryTreeNode<T>* mostRight = NULL;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            cur = cur->right;
        }
        else
        {
            mostRight = cur->left;
            while (mostRight->right != NULL && mostRight->right != cur)
                mostRight = mostRight->right;
            if (mostRight->right == NULL)
            {
                mostRight->right = cur;
                cur = cur->left;
            }
            else
            {
                mostRight->right = NULL;
                printOutForMorrisPost(cur->left);
                cur = cur->right;
            }
        }
    }
    printOutForMorrisPost(node);
}

//try print post output
template <class T>
void binaryTree<T>::printOutForMorrisPost(binaryTreeNode<T>* node)
{
    stack<T>ts;
    if (node == NULL)
        return;
    while (node)
    {
        ts.push(node->val);
        node = node->right;
    }
    while (!ts.empty())
    {
        T tmp = ts.top();
        cout << tmp << " ";
        ts.pop();
    }
}

template <class T>
void binaryTree<T>::morrisPostOrder()
{
    morrisPostOrder(root);
}

//Here dream begin, used to build a binary tree
template <class T>
void binaryTree<T>::buildBinaryTree(binaryTreeNode<T>* &node, vector<T>&arr, int size, int pos)
{
    if (size <= 0 || pos >= size)
        return ;
    node = new binaryTreeNode<T>(arr[pos], NULL, NULL);
    //root->val = arr[pos];
    buildBinaryTree(node->left, arr, size, 2*pos+1);
    buildBinaryTree(node->right, arr, size, 2*pos+2);
}

template <class T>
void binaryTree<T>::buildTree(vector<T>& arr)
{
    int len = arr.size();
    int start = 0;
    buildBinaryTree(root, arr, len, start);
}

//destroy a whole binary tree
template <class T>
void binaryTree<T>::destroyTree(binaryTreeNode<T>* node)
{
    if (node == NULL)
        return;
    if (node->left != NULL)
        destroyTree(node->left);
    if (node->right != NULL)
        destroyTree(node->right);
    delete node;
}

template <class T>
void binaryTree<T>::destroy()
{
    destroyTree(root);
}


#endif