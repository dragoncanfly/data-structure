//reference @https://www.cnblogs.com/yuemo/p/9783189.html
//also ref @https://www.cnblogs.com/skywang12345/p/3577360.html

#ifndef __ALG_AVL_HPP__
#define __ALG_AVL_HPP__

#include <algorithm>
#include <stdio.h>

using namespace std;

//definition of avlTree node
template <class T>
struct avlTreeNode{
    T val;
    int height;
    avlTreeNode* left;
    avlTreeNode* right;

    //init with constructor
    avlTreeNode(T val, avlTreeNode* left, avlTreeNode* right):val(val), height(0), left(left), right(right){}
};

//definition of avlTree
template <class T>
class avlTree{
    public:
        avlTree():root(NULL){}
        //insert a val -- external interface
        void insert(T val);
        //query node height -- external interface
        int height();
        int max(int a, int b);
        //delete node with key==val -- external interface
        void remove(T val);
        //find minimum node, return key of this node
        T minimum();
        //find maximum node, return key of this node
        T maximum();
        //find node with key==val
        avlTreeNode<T>* search(T val);
        // iterative finde node with key== val
        avlTreeNode<T>* iterativeSearch(T val);
        //preOrder traverse
        void preOrder();
        //inOrder traverse
        void inOrder();
        //postOrder traverse
        void postOrder();
        //destroy avlTree
        void destroy();
    private:
        avlTreeNode<T>* root;
        //insert a val -- internal interface
        avlTreeNode<T>* insert(avlTreeNode<T>* &treeNode, T val);
        //query the height -- internal interface
        int height(avlTreeNode<T>* treeNode);
        //ll rotate
        avlTreeNode<T>* ll_rotation(avlTreeNode<T>* treeNode);
        //rr rotate
        avlTreeNode<T>* rr_rotation(avlTreeNode<T>* treeNode);
        //lr rotate
        avlTreeNode<T>* lr_rotation(avlTreeNode<T>* treeNode);
        //rl rotate
        avlTreeNode<T>* rl_rotation(avlTreeNode<T>* treeNode);
        //remove node
        avlTreeNode<T>* remove(avlTreeNode<T>* &treeNode, avlTreeNode<T>* removed);
        //find minimum node, return this node
        avlTreeNode<T>* minimum(avlTreeNode<T>* treeNode);
        //find maximum node, return this node
        avlTreeNode<T>* maximum(avlTreeNode<T>* treeNode);
        //recursive search node with key == val
        avlTreeNode<T>* search(avlTreeNode<T>* treeNode, T val) const;
        //iterative search node with key == val
        avlTreeNode<T>* iterativeSearch(avlTreeNode<T>* treeNode, T val) const;
        //preOrder traverse--internal
        void preOrder(avlTreeNode<T>* treeNode) const;
        //inOrder traverse -- internal
        void inOrder(avlTreeNode<T>* treeNode) const;
        //postOrder traverse -- internal
        void postOrder(avlTreeNode<T>* treeNode) const;
        //delete avlTree -- internal
        void destroy(avlTreeNode<T>* &treeNode);
};


template <class T>
int avlTree<T>::height(avlTreeNode<T>* treeNode)
{
    if (treeNode == NULL)
        return 0;
    return treeNode->height;
}

template <class T>
int avlTree<T>::height()
{
    return height(root);
}

template <class T>
int avlTree<T>::max(int a, int b)
{
    return a > b ? a : b;
}

//ll rotate  插入或删除之后，根的左子树的左子树还有非空节点，导致根的左子树高度比根的右子树高度大2
//假设treeNode节点为爷爷节点，此节点左儿子为tLeft，问题原因在于tLeft的左儿子增加了一个节点导致失衡
//解决方法是让tLeft成为爷爷节点，treeNode为tLeft的右儿子，tLeft的右儿子成为现在treeNode的左儿子
template <class T>
avlTreeNode<T>* avlTree<T>::ll_rotation(avlTreeNode<T>* treeNode)
{
    avlTreeNode<T>* tLeft = NULL;
    tLeft = treeNode->left;
    treeNode->left = tLeft->right;
    tLeft->right = treeNode;
    treeNode->height = max(height(treeNode->left), height(treeNode->right)) + 1;
    tLeft->height = max(height(tLeft->left), height(tLeft->right)) + 1;
    return tLeft;
}

//rr rotate  插入或删除之后，根的右子树的右子树还有非空节点，导致根右子树高度比左子树高度大2，导致失衡
//treeNode为爷爷节点，节点右儿子为tRight, 问题原因在于tRight的右儿子增加了一个节点导致
//解决方法是让tRight成为爷爷节点，treeNode成为tRight的左儿子，tRight的左儿子成为treeNode的右儿子
template <class T>
avlTreeNode<T>* avlTree<T>::rr_rotation(avlTreeNode<T>* treeNode)
{
    avlTreeNode<T>* tRight = NULL;
    tRight = treeNode->right;
    treeNode->right = tRight->left;
    tRight->left = treeNode;
    treeNode->height = max(height(treeNode->left), height(treeNode->right)) + 1;
    tRight->height = max(height(tRight->left), height(tRight->right)) + 1;
    return tRight;
}

//lr rotate  插入或删除一个节点之后，根节点的左子树的右子树还有非空子节点，导致根的左子树的高度比根的右子树的高度大2，失衡
//会涉及到四代节点的变换，问题在于根结点的左子树的右子树上存在非空节点，导致根结点的左子树比右子树高度大2，失衡
//解决方法是先对根结点的左子树做一次rr旋转，将根结点左子树的右子树旋转为根节点，此时失衡情况为ll的情形，再对根节点做一次ll旋转即可
template <class T>
avlTreeNode<T>* avlTree<T>::lr_rotation(avlTreeNode<T>* treeNode)
{
    treeNode->left = rr_rotation(treeNode->left);
    return ll_rotation(treeNode);
}

//rl rotate 情形与lr相反
//插入或删除一个节点以后，根节点的右子树的左子树上存在非空节点，此时根结点的右子树比左子树的高度大2，导致失衡
//同样涉及四代节点的变换，问题在与根节点的右子树的左子树上存在非空节点
//解决方法是对根结点的右子节点做一次ll旋转，此时情形变为rr时的状况，再对根结点左一次rr旋转即可
template <class T>
avlTreeNode<T>* avlTree<T>::rl_rotation(avlTreeNode<T>* treeNode)
{
    treeNode->right = ll_rotation(treeNode->right);
    return rr_rotation(treeNode);
}


//insert 插入节点
template <class T>
avlTreeNode<T>* avlTree<T>::insert(avlTreeNode<T>* &treeNode, T val)
{
    if (treeNode == NULL)
        treeNode = new avlTreeNode<T>(val, NULL, NULL);
    else if (val < treeNode->val)
    {
        treeNode->left = insert(treeNode->left, val);
        if (height(treeNode->left) - height(treeNode->right) == 2)
        {
            if (val < treeNode->left->val)
                treeNode = ll_rotation(treeNode);
            else
                treeNode = lr_rotation(treeNode);
        }
    }
    else if (val > treeNode->val)
    {
        treeNode->right = insert(treeNode->right, val);
        if (height(treeNode->right) - height(treeNode->left) == 2)
        {
            if (val > treeNode->right->val)
                treeNode = rr_rotation(treeNode);
            else
                treeNode = rl_rotation(treeNode);
        }
    }
    else
    {
        printf("The node with this val has been in this tree!\n");
    }
    //update height of current node
    treeNode->height = max(height(treeNode->left), height(treeNode->right)) + 1;
    return treeNode;
}

template <class T>
void avlTree<T>::insert(T val)
{
    insert(root, val);
}

//remove node
/*
*delete node removed, return root;
*/
template <class T>
avlTreeNode<T>* avlTree<T>::remove(avlTreeNode<T>* &treeNode, avlTreeNode<T>* removed)
{
    if (treeNode == NULL || removed == NULL)
        return NULL;
    if (removed->val < treeNode->val)
    {
        treeNode->left = remove(treeNode->left, removed);
        if (height(treeNode->right) - height(treeNode->left) == 2)
        {
            avlTreeNode<T>* treeRightNode = treeNode->right;
            if (height(treeRightNode->left) > height(treeRightNode->right))
                treeNode = rl_rotation(treeNode);
            else
                treeNode = rr_rotation(treeNode);
        }
        //update node height
        treeNode->height = max(height(treeNode->left), height(treeNode->right));
    }
    else if (removed->val > treeNode->val)
    {
        treeNode->right = remove(treeNode->right, removed);
        if (height(treeNode->left) - height(treeNode->right) == 2)
        {
            avlTreeNode<T>* treeLeftNode = treeNode->left;
            if (height(treeLeftNode->right) > height(treeLeftNode->left))
                treeNode = lr_rotation(treeNode);
            else
                treeNode = ll_rotation(treeNode);
        }
        //update node height
        treeNode->height = max(height(treeNode->left), height(treeNode->right));
    }
    else
    {
        if ((treeNode->left != NULL) && (treeNode->right != NULL))
        {
            if (height(treeNode->left) > height(treeNode->right))
            {
                //左子树比右子树高，找出左子树中最大节点，将最大节点值赋给根结点，删除最大节点
                avlTreeNode<T>* max = maximum(treeNode->left);
                treeNode->val = max->val;
                treeNode->left = remove(treeNode->left, max);
            }
            else
            {
                //左子树不比右子树高(相等或者右子树比左子树高1)，找出右子树中最小节点，将最小节点值赋给根结点，删除最小节点
                avlTreeNode<T>* min = minimum(treeNode->right);
                treeNode->val = min->val;
                treeNode->right = remove(treeNode->right, min);
            }
        }
        else
        {
            avlTreeNode<T>* tmp = treeNode;
            treeNode = (treeNode->left != NULL) ? treeNode->left : treeNode->right;
            delete tmp;   
        }
        //update height
        treeNode->height = max(height(treeNode->left), height(treeNode->right));
    }
    return treeNode;    
}

template <class T>
void avlTree<T>::remove(T val)
{
    avlTreeNode<T>* removed;
    if ((removed = search(root, val)) != NULL)
        root = remove(root, removed);
}

//recursive search node key==val
template <class T>
avlTreeNode<T>* avlTree<T>::search(avlTreeNode<T>* treeNode, T val) const
{
    if (treeNode == NULL || treeNode->val == val)
        return treeNode;
    if (val < treeNode->val)
        return search(treeNode->left, val);
    else
        return search(treeNode->right, val);    
}

template <class T>
avlTreeNode<T>* avlTree<T>::search(T val)
{
    return search(root, val);
}

//iterative search node key==val
template <class T>
avlTreeNode<T>* avlTree<T>::iterativeSearch(avlTreeNode<T>* treeNode, T val) const
{
    while ((treeNode != NULL) && (treeNode->val != val))
    {
        if (treeNode->val > val)
            treeNode = treeNode->left;
        else
            treeNode = treeNode->right;
    }
    return treeNode;
}

template <class T>
avlTreeNode<T>* avlTree<T>::iterativeSearch(T val)
{
    return iterativeSearch(root, val);
}

// find minimum node, and return this node
template <class T>
avlTreeNode<T>* avlTree<T>::minimum(avlTreeNode<T>* treeNode)
{
    if (treeNode == NULL)
        return NULL;
    while (treeNode->left)
        treeNode = treeNode->left;
    return treeNode;
}

template <class T>
T avlTree<T>::minimum()
{
    avlTreeNode<T>* minNode = minimum(root);
    if (minNode != NULL)
        return minNode->val;
    return (T)NULL;
}

//find maximum node 
template <class T>
avlTreeNode<T>* avlTree<T>::maximum(avlTreeNode<T>* treeNode)
{
    if (treeNode == NULL)
        return NULL;
    while (treeNode->right)
        treeNode = treeNode->right;
    return treeNode;
}

template <class T>
T avlTree<T>::maximum()
{
    avlTreeNode<T>* maxNode = maximum(root);
    if (maxNode != NULL)
        return maxNode->val;
    return (T)NULL;
}

//preOrder traverse
template <class T>
void avlTree<T>::preOrder(avlTreeNode<T>* treeNode) const
{
    if (treeNode != NULL)
    {
        cout << treeNode->val << " ";
        preOrder(treeNode->left);
        perOrder(treeNode->right);
    }
}

template <class T>
void avlTree<T>::preOrder()
{
    preOrder(root);
}

//inOrder traverse
template <class T>
void avlTree<T>::inOrder(avlTreeNode<T>* treeNode) const
{
    if (treeNode != NULL)
    {
        inOrder(treeNode->left);
        cout << treeNode->val << " ";
        inOrder(treeNode->right);
    }
}

template <class T>
void avlTree<T>::inOrder()
{
    inOrder(root);
}

//post order traverse
template <class T>
void avlTree<T>::postOrder(avlTreeNode<T>* treeNode) const
{
    if (treeNode != NULL)
    {
        postOrder(treeNode->left);
        postOrder(treeNode->right);
        cout << treeNode->val << " ";
    }
}

template <class T>
void avlTree<T>::postOrder()
{
    postOrder(root);
}

//destroy a avlTree
template <class T>
void avlTree<T>::destroy(avlTreeNode<T>* &treeNode)
{
    if (treeNode == NULL)
        return;
    if (treeNode->left != NULL)
        destroy(treeNode->left);
    if (treeNode->right != NULL)
        destroy(treeNode->right);
    delete treeNode;
}

template <class T>
void avlTree<T>::destroy()
{
    destroy(root);
}

#endif
//模板类函数声明与实现需要同时都写在.h或.hpp文件中，否则若分离开来会出现为定义函数问题

//private 重载函数接口的作用？
//函数后加const ?