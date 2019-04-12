//
//  Tree.hpp
//  DataStructures
//
//  Created by James, Emily on 4/12/19.
//  Copyright © 2019 CTEC. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include "../Nodes/BinaryTreeNode.hpp"

template <class Type>
class Tree
{
protected:
    BinaryTreeNode<Type> * root;
    
public:
    virtual int getSize() = 0;
    virtual int geHeight() = 0;
    virtual bool isComplete() = 0;
    virtual bool isBalanced() = 0;
    
    virtual void insert(Type data) = 0;
    virtual bool contains(Type data) = 0;
    virtual void remove(Type data) = 0;
    
    virtual void inOrderTraversal() = 0;
    virtual void preOrderTraversal() = 0;
    virtual void postOrderTraversal() = 0
};
#endif /* Tree_h */
