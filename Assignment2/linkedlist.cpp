//
// Created by Leonard on 2016/5/26.
//

#include "linkedlist.h"
#include "ticket.h"
#include <iostream>
using namespace std;

template <typename T>
void LinkedList<T>::CopyList(const LinkedList& ll){
    front = NULL;
    back = NULL;
    size = 0;
    if(this != &ll){
        // DeleteList();
        Node<T>* iterator = ll.front;
        while(iterator != NULL){
            InsertBack(iterator->data);
            iterator = iterator->next;
        }
    }
}

template <typename T>
void LinkedList<T>::DeleteList(){
    if(!IsEmpty()){
        for(int i=0; i < size; i++){
            Node<T>* temp = front->next;
            delete front;
            front = temp;
            size--;
        }
    }
}

template <typename T>
LinkedList<T>::LinkedList() {
    size = 0;
    front = NULL;
    back = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &ll) {
    CopyList(ll);
}

template <typename T>
LinkedList<T>::~LinkedList() {
    DeleteList();
}

template <typename T>
void LinkedList<T>::InsertFront(T item) {

    Node<T>* toInsert = new Node<T>(item);

    if(IsEmpty()){
        front = toInsert;
        back = toInsert;
    }
    else{
        front->prev = toInsert;
        toInsert->next = front;
        front = toInsert;
    }
    size++;
}

template <typename T>
void LinkedList<T>::InsertBack(T item) {
    Node<T>* toInsert = new Node<T>(item);

    if(IsEmpty()){
        front = toInsert;
        back = toInsert;
    }
    else{
        back->next = toInsert;
        toInsert->prev = back;
        back = toInsert;
    }
    size++;

}

template <typename T>
void LinkedList<T>::InsertAt(T item, int p){

    Node<T>* toInsert = NULL;

    if(p < 0 || p > size){
        throw std::out_of_range("Invalid Index!");
    }else{
        if(p==0){
            InsertFront(item);
        }
        else if(p==size){
            InsertBack(item);
        }
        else{
            Node<T>* temp = front;
            while(p > 1){
                temp = temp->next;
                p--;
            }
            toInsert = new Node<T>(item);
            toInsert->next = temp->next;
            toInsert->prev = temp;
            toInsert->next->prev = temp;
            temp->next = toInsert;
            size++;
        }
    }
}

template <typename T>
T LinkedList<T>::RemoveAt(int p) {
    Node<T>* toReturn = NULL;
    if(IsEmpty()){
        throw std::out_of_range("Empty List!");
    }
    else if (p < 0 || p > size-1) {
        throw std::out_of_range("Invalid index!");
    }
    else if(size==1){
        toReturn = front;
        front = NULL;
        back = NULL;
        size--;
        return toReturn->data;
    }
    else if(p==0){
        toReturn = front;
        front = front->next;
        front->prev = NULL;
        size--;
        return toReturn->data;
    }
    else if(p==size-1){
        toReturn = back;
        back = back->prev;
        back->next = NULL;
        size--;
        return toReturn->data;
    }
    else{
        Node<T>* temp = front;
        while(p > 1){
            temp = temp->next;
            p--;
        }
        toReturn = temp->next;
        temp->next = temp->next->next;
        toReturn->next->prev = toReturn->prev;
        size--;
        return toReturn->data;
    }
}

template <typename T>
void LinkedList<T>::Append(const LinkedList &ll) {
    int back_size = ll.Size();
    back->next = ll.front;
    ll.front->prev = back;
    back = ll.back;
    size = size + back_size;
}

template <typename T>
void LinkedList<T>::RemoveDuplicates() {
    Node<T>* current = back;
    while(current != NULL && current->prev != NULL){
        Node<T>* curr = current;
        while(curr->prev != NULL){
            if(curr->prev->data == current->data){
                curr->prev->prev->next = curr;
                curr->prev = curr->prev->prev;
                size--;
            }
            else{
                curr = curr->prev;
            }
        }
        current = current->prev;
    }
}

template <typename T>
int LinkedList<T>::Size() const {
    return size;
}

template <typename T>
bool LinkedList<T>::IsEmpty() const {
    return size==0;
}

template <typename T>
bool LinkedList<T>::Contains(T item) const {
    Node<T>* compare = front;
    while(compare != NULL){
        if(compare->data == item){
            return true;
        }
        compare = compare->next;
    }
    return false;
}

template <typename T>
T LinkedList<T>::ElementAt(int p) const {
    if(p < 0 || p > size-1){
        throw std::out_of_range("Invalid Index!");
    }
    else{
        Node<T>* temp = front;
        while(p != 0){
            temp = temp->next;
            p--;
        }
        return temp->data;
    }
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &ll){
    if (this != &ll){
        DeleteList();
        Node<T>* itr = ll.front;
        while(itr != NULL){
            InsertBack(itr->data);
            itr = itr->next;
        }
    }
    return *this;
}


template class LinkedList<int>;




