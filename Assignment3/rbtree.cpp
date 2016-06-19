//
// Created by Leonard on 2016/6/7.
//
//

#include "rbtree.h"
#include "stockitem.h"

//#include "stockitem.h"
//#include "stocksystem.h"



// recursive helper function for deep copy
// creates a new node based on sourcenode's contents, links back to parentnode,
//   and recurses to create left and right children
template <typename T>
Node<T>* RBTree<T>::CopyTree(Node<T>* sourcenode, Node<T>* parentnode){
    if (sourcenode == NULL){
        return NULL;
    }

    Node<T>* newNode = new Node<T>(sourcenode->data);
    newNode->p = parentnode;
    newNode->is_black = sourcenode->is_black;
    if(parentnode != NULL){
        if(parentnode->data < newNode->data){
            parentnode->right = newNode;
        }
        else{
            parentnode->left = newNode;
        }
    }
    newNode->left = CopyTree(sourcenode->left, newNode);
    newNode->right = CopyTree(sourcenode->right, newNode);
    size++;
    return newNode;
}

// recursive helper function for tree deletion
// deallocates nodes in post-order
template <typename T>
void RBTree<T>::RemoveAll(Node<T> *node) {
    if(node != NULL){
        if(node->left != NULL)
            RemoveAll(node->left);
        if(node->right != NULL)
            RemoveAll(node->right);
    }
    else return;
    root = NULL;
}

// Tree fix, performed after removal of a black node
// Note that the parameter x may be NULL
template <typename T>
void RBTree<T>::RBRemoveFixUp(Node<T> *x, Node<T> *xparent, bool xisleftchild) {
    while(((x != NULL) && (x != root) && (x->is_black)) || (x == NULL && x != root)){
        if(xisleftchild){
            Node<T>* sibling = xparent->right;
            if(!sibling->is_black){
                sibling->is_black = true;
                xparent->is_black = false;
                RotateLeft(xparent);
                sibling = xparent->right;
            }

            if((sibling->left != NULL && sibling->right != NULL && sibling->left->is_black && sibling->right->is_black)
               || (sibling->left == NULL && sibling->right != NULL && sibling->right->is_black) ||
                    (sibling->left != NULL && sibling->right == NULL && sibling->left->is_black) ||
                    (sibling->left == NULL && sibling->right == NULL)){
                sibling->is_black = false;
                x = xparent;
            }
            else{
                if(sibling->right == NULL || ((sibling->right != NULL) && (sibling->right->is_black))){
                    sibling->left->is_black = true;
                    sibling->is_black = false;
                    RotateRight(sibling);
                    sibling = xparent->right;
                }
                sibling->is_black = xparent->is_black;
                xparent->is_black = true;
                sibling->right->is_black = true;
                RotateLeft(xparent);
                x = root;
            }
        }
        else{
            Node<T>* sibling = xparent->left;
            if(!sibling->is_black){
                sibling->is_black = true;
                xparent->is_black = false;
                RotateRight(xparent);
                sibling = xparent->left;
            }

            if((sibling->left != NULL && sibling->right != NULL && sibling->left->is_black && sibling->right->is_black)
               || (sibling->left == NULL && sibling->right != NULL && sibling->right->is_black) ||
               (sibling->left != NULL && sibling->right == NULL && sibling->left->is_black) ||
               (sibling->left == NULL && sibling->right == NULL)){
                sibling->is_black = false;
                x = xparent;
            }
            else{
                if((sibling->left == NULL) || ((sibling->left != NULL) && (sibling->left->is_black))){
                    sibling->right->is_black = true;
                    sibling->is_black = false;
                    RotateLeft(sibling);
                    sibling = xparent->left;
                }
                sibling->is_black = xparent->is_black;
                xparent->is_black = true;
                sibling->left->is_black = true;
                RotateRight(xparent);
                x = root;
            }
        }
    }
    if(x != NULL){
        x->is_black = true;
    }
}

// Calculates the height of the tree
// Requires a traversal of the tree, O(n)
template <typename T>
int RBTree<T>::ComputeHeight(Node<T> *node) const {
    if(node == NULL){
        return 0;
    }
    else{
        return 1 + std::max(ComputeHeight(node->left),ComputeHeight(node->right));
    }
}

// default constructor
template <typename T>
RBTree<T>::RBTree() {
    root = NULL;
    size = 0;
}

// copy constructor, performs deep copy of parameter
template <typename T>
RBTree<T>::RBTree(const RBTree<T> &rbtree) {
    size = 0;
    root = CopyTree(rbtree.root,NULL);
}

// destructor
// Must deallocate memory associated with all nodes in tree
template <typename T>
RBTree<T>::~RBTree() {
    RemoveAll();
}

// overloaded assignment operator
template <typename T>
RBTree<T> &RBTree<T>::operator=(const RBTree<T> &rbtree) {
    if (this != &rbtree){
        RemoveAll();
        root = CopyTree(rbtree.root,NULL);
    }
    return *this;
}

// Calls BSTInsert and then performs any necessary tree fixing.
// If item already exists, do not insert and return false.
// Otherwise, insert, increment size, and return true.
template <typename T>
bool RBTree<T>::Insert(T item) {
    if(Find(item)){
        return false;
    }
    Node<T>* node = BSTInsert(item);

    node->is_black = false;

    while((node->p != NULL) && !(node->p->is_black)){
        if( node->p == node->p->p->left ){
            Node<T>* uncle = node->p->p->right;
            if(uncle != NULL){
                if(!(uncle->is_black)){
                    node->p->is_black = true;
                    uncle->is_black = true;
                    node->p->p->is_black = false;
                    node = node->p->p;
                }
            }
            else if(uncle == NULL || uncle->is_black){
                if(node == node->p->right){
                    node = node->p;
                    RotateLeft(node);
                }
                node->p->is_black = true;
                node->p->p->is_black = false;
                RotateRight(node->p->p);
            }
        }
        else{
            Node<T>* uncle = node->p->p->left;
            if(uncle != NULL){
                if(!uncle->is_black){
                    node->p->is_black = true;
                    uncle->is_black = true;
                    node->p->p->is_black = false;
                    node = node->p->p;
                }
            }
            else if(uncle == NULL || uncle->is_black){
                if(node == node->p->left){
                    node = node->p;
                    RotateRight(node);
                }
                node->p->is_black = true;
                node->p->p->is_black = false;
                RotateLeft(node->p->p);
            }
        }
    }
    root->is_black = true;
    size++;
    return true;
}

// Removal of an item from the tree.
// Must deallocate deleted node after RBDeleteFixUp returns
template <typename T>
bool RBTree<T>::Remove(T item) {
    Node<T>* target = Find(item);
    if (target == NULL){
        return false;
    }

    Node<T>* pre;

    if((target->left == NULL) || (target->right == NULL)){
        pre = target;
    }
    else{
        pre = Predecessor(target);
    }

    Node<T>* child;

    if(pre->left != NULL){
        child = pre->left;
    }
    else{
        child = pre->right;
        if(child != NULL){
            child->p = pre->p;
        }
    }

    if(pre->p == NULL){
        root = child;
    }
    else{
        if(pre == pre->p->left){
            pre->p->left = child;
        }
        else{
            pre->p->right = child;
        }
    }

    if(pre != target){
        target->data = pre->data;
    }

    if((pre->is_black) && (pre->p != NULL)){
        if(child == pre->p->left)
            RBRemoveFixUp(child,pre->p,true);
        else
            RBRemoveFixUp(child,pre->p,false);
    }

    delete pre;
    size--;
    return true;
}

// deletes all nodes in the tree. Calls recursive helper function.
template <typename T>
void RBTree<T>::RemoveAll() {
    RemoveAll(root);
}

// returns the number of items in the tree
template <typename T>
int RBTree<T>::Size() const {
    return size;
}

// returns the height of the tree, from root to deepest null child. Calls recursive helper function.
// Note that an empty tree should have a height of 0, and a tree with only one node will have a height of 1.
template <typename T>
int RBTree<T>::Height() const {
    return ComputeHeight(root);
}

// template class RBTree<StockItem>;
template class RBTree<int>;















































