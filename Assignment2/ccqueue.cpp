//
// Created by Leonard on 2016/5/26.
//


#include "ccqueue.h"
#include "linkedlist.cpp"

CCQueue::CCQueue() {
    tickets = LinkedList<Ticket>();
    maxticketid = 0;
}

bool CCQueue::Add(string customer, string complaint) {
    if(customer != "" && complaint != ""){
        Ticket toAdd = Ticket(1+maxticketid,customer,complaint);
        tickets.InsertBack(toAdd);
        maxticketid++;
        return true;
    }
    return false;
}

Ticket CCQueue::Service() {
    if(tickets.IsEmpty()){
        throw std::out_of_range("List is empty!");
    }
    else{
        Ticket toReturn = tickets.ElementAt(0);
        tickets.RemoveAt(0);
        return toReturn;
    }
}

bool CCQueue::MoveUp(int index) {
    if(index <= 0 || index > tickets.Size()-1) {
        return false;
    }
    else{
        Ticket toMove = tickets.ElementAt(index);
        tickets.RemoveAt(index);
        tickets.InsertAt(toMove,index-1);
        return true;
    }
}

bool CCQueue::MoveDown(int index) {
    if(index < 0 || index >= tickets.Size()-1) {
        return false;
    }
    else{
        Ticket toMove = tickets.ElementAt(index);
        tickets.RemoveAt(index);
        tickets.InsertAt(toMove,index+1);
        return true;
    }
}

int CCQueue::Size() const {
    return tickets.Size();
}

template class LinkedList<Ticket>;











