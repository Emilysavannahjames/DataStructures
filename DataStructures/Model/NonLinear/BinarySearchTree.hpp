//
//  BinarySearchTree.hpp
//  DataStructures
//
//  Created by James, Emily on 4/12/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#iclude "Tree.hpp"
#include <iostream>

using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
protected:
    int calculateSize(BinaryTreeNode<Type>* startNode);
    int calculateHeight(BinaryTreeNode<Type>* startNode);
    bool isBalanced(BinaryTreeNode<Type> * startNode);
    bool isComplete(BinaryTreeNode<Type> * startNode, int index, int size);
    
    void inOrderTraversal(BinaryTreeNode<Type>* inStart);
    void preOrderTraversal(BinaryTreeNode<Type>* preStart);
    void postOrderTraversal(BinaryTreeNode<Type>* postStart);
    
    void destroyTree(BinaryTreeNode<Type>* node);
    
    BinaryTreeNode<Type> * getRightMostChild(BinaryTreeNode<Type> * current);
    BinaryTreeNode<Type> * getLeftMostChild(BinaryTreeNode<Type> * current);
    
    void removeNode(BinaryTreeNode<Type> * removeMe);
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinaryTreeNode<Type> * getRoot();
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void demoTraversalSteps(BinaryTreeNode<Type> * node);
    
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
    
    Type findMinimum();
    Type findMaximum();
};

template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    return calculateHeight(this->root);
}
template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinaryTreeNode<Type>*  current)
{
    if(current != nullptr)
    {
        return max(calculateHeight(current->getLeftChild()), calculateHeight(current->getRightChild())) + 1;
    }
    return 0;
}
template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    int size = 0;
    
    size += calculateSize(this->root);
    
    return size;
}
template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinaryTreeNode<Type>* current)
{
    if(current != nullptr)
    {
        return calculateSize(current->getLeftChild()) + calculateSize(current->getRightChild()) + 1;
    }
    return 0;
}
template <class Type>
bool BinarySearchTree<Type> :: isComplete()
{
    int index = 0;
    int size = getSize();
    
    return isComplete(this->root, index, size);
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete(BinaryTreeNode<Type>*startNode, int index, int size)
{
    if(startNode == nullptr)
    {
        return true;
    }
    if(index >= size)
    {
        return false;
    }
    return (isComplete(startNode->getLeftChild(), 2 * index + 1, size) && isComplete(startNode->getRightChild(), 2 * index + 2, size));
}
template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
    return isBalanced(this->root);
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinaryTreeNode<Type>*current)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if(current == nullptr)
    {
        return true;
    }
    
    leftHeight = calculateHeight(current->getLeftChild());
    rightHeight = calculateHeight(current->getRightChild());
    
    int heightDifference = abs(leftHeight - rightHeight);
    bool leftBalanced = isBalanced(current->getLeftChild());
    bool rightBalanced = isBalanced(current->getRightChild());
    
    if(heightDifference <= 1 && leftBalanced && rightBalanced)
    {
        return true;
    }
    
    return false;
    
}
template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal
{
    
}
template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal
{
    
}
template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    
}
template <class Type>
void BinarySearchTree<Type> :: insert(Type item)
{
    
}
template <class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinaryTreeNode<Type> * current = this->root;
    if(current == nullptr)
    {
        return false;
    }
    else
    {
        while(current != nullptr)
        {
            if(itemToFind == current->getData())
            {
                return true;
            }
            else if(itemToFind < current ->getData())
            {
                current = current->getLeftNode();
            }
            else
            {
                current = current->getRightNode();
            }
        }
    }
    return false;
}
template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if(this->root == nullptr)
    {
        cout << "Empty tree removal is not possible" << endl;
    }
    else
    {
        BinaryTreeNode<Type>* current =this->root;
        BinaryTreeNode<Type>* previous = nullptr;
        Bool hasBeenFound = false;
        
        while(current != nullptr && !hasBeenFound)
        {
            if(current->getData()  == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if(getRidOfMe < current->getData())
                {
                    current = current->getLeftNode();
                }
                else
                {
                    current = current->getRightNode();
                }
            }
        }
        
        if(current == nullptr)
        {
            cerr << "Item not found, removal unsuccessful" << endl;
        }
        else if(hasBeenFound)
        {
            if(current== this->root)
            {
                removeNode(this->root);
            }
            else if(getRidOfMe < previous->getData())
            {
                removeNode(previous->getLeftNode());
            }
            else
            {
                removeNode(previous->getRightNode());
            }
        }
    }
}
template <class Type>
void BinarySearchTree<Type>:: removeNode(BinaryTreeNode <Type> * removeMe)
{
    BinaryTreeNode<Type>* current;
    BinaryTreeNode<Type>* previous;
    BinaryTreeNode<Type>* temp;
    
    previous = removeMe->getRootNode();
    
    //Node is a leaf - has no kiddos
    if(removeMe->getRightNode() == nullptr && removeMe->getLeftNode() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
        
        if(previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if(previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setRightNode(removeMe);
        }
        
        delete temp;
    }
    else if(removeMe->getRightNode() == nullptr)
    {
        temp = removeMe;
        removeMe =removeMe->getLeftNode();
    }
}
#endif /* BinarySearchTree_h */
