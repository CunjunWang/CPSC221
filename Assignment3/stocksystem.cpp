//
// Created by Leonard on 2016/6/7.
//

#include "stocksystem.h"
#include "rbtree.cpp"


StockSystem::StockSystem() {
    records = RBTree<StockItem>();
    balance = 100000;
}

double StockSystem::GetBalance() {
    return balance;
}

bool StockSystem::StockNewItem(StockItem item) {
    if(records.Contains(item)){
        return false;
    }
    records.Insert(item);
    return true;
}

bool StockSystem::EditStockItemDescription(int itemsku, string desc) {
    StockItem* item = records.Retrieve(StockItem(itemsku,"",0.0));
    if(item == NULL){
        return false;
    }
    else{
        item->SetDescription(desc);
        return true;
    }
}

bool StockSystem::EditStockItemPrice(int itemsku, double retailprice) {
    if(retailprice < 0){
        return false;
    }
    else{
        StockItem* item = records.Retrieve(StockItem(itemsku,"",0.0));
        if(item == NULL){
            return false;
        }
        else{
            item->SetPrice(retailprice);
            return true;
        }
    }
}

bool StockSystem::Restock(int itemsku, int quantity, double unitprice) {
    StockItem* item = records.Retrieve(StockItem(itemsku,"",0.0));
    if(item == NULL){
        return false;
    }

    int stock = item->GetStock();
    if(quantity < 0 || unitprice < 0){
        return false;
    }
    if(stock + quantity <= 1000){
        if(balance < quantity * unitprice){
            return false;
        }
        item->SetStock(stock+quantity);
        balance = balance - quantity * unitprice;
        return true;
    }
    else{
        int buyQuantity = 1000 - stock;
        if(balance < buyQuantity * unitprice){
            return false;
        }
        item->SetStock(1000);
        balance = balance - buyQuantity * unitprice;
        return true;
    }
}

bool StockSystem::Sell(int itemsku, int quantity) {
    StockItem* item = records.Retrieve(StockItem(itemsku,"",0.0));
    if(item == NULL){
        return false;
    }

    int stock = item->GetStock();
    int price = item->GetPrice();
    if(stock <= 0 || quantity < 0){
        return false;
    }

    if(stock <= quantity){
        int sellQuality = stock;
        item->SetStock(0);
        balance = balance + sellQuality * price;
        return true;
    }
    else{
        item->SetStock(stock-quantity);
        balance = balance + quantity * price;
        return true;
    }
}

template class RBTree<StockItem>;













