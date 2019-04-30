//
//  AVLTree.h
//  DataStructures
//
//  Created by James, Emily on 4/30/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

#include "BinarySearchTree.hpp"

template <class Type>
class AVLTree :public BinarySearchTree<Type>
{
private:
    
    BinaryTreeNode<Type> * leftRotation (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightRotation (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * leftRightRotation (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightLeftRotation (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * balanceSubTree (BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * insertNode (BinaryTreeNode<Type> * parent, Type value);
    BinaryTreeNode<Type> * removeNode (BinaryTreeNode<Type> * parent, Type value);
    
    int heightDifference(BinaryTreeNode<Type>* parent);
    
public:
    
    AVLTree();
    void insert(Type itemToInsert);
    void remove(Type value);
    
};

template <class Type>
AVLTree<Type> :: AVLTree() : BinarySearchTree<Type>()
{
    this->root = nullptr;
}
template <class Type>
void AVLTree<Type>::insert (type item)
{
    insertNode(this->getRoot(), item);
    
}

template <class Type>
void AVLTree<Type>:: remove(Type item)
{
    removeNode(this->getRoot(),item);
}

template <class Type>
BinaryTreeNode<Type>* AVLTree<Type> :: insertNode(BinaryTreeNode<Type>* parent, Type inserted)
{
    if(parent == nullptr)
    {
        parent = new BinaryTreeNode<Type>(inerted);
        
        if(this->getRoot()== nullptr)
        {
            this->setRoot(parent)
        }
        
        return parent;
    }
    else if(inserted < parent -> getNodeData())
    {
        parent->setLeftChild(insertNode(parent->getLeftChild(), inserted));
        parent = balanceSubTree(parent);
    }
    else if(inserted > parent -> getNodeData())
    {
        parent->setRightChild(insertNode(parent->getRightChild(), inserted));
        parent = balanceSubTree(parent);
    }
    return parent;
}


#endif /* AVLTree_h */
