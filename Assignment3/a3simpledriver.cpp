// File:        a3simpledriver.cpp
// Author:      Geoffrey Tien
// Date:        2016-06-05
// Description: Test driver for RBTree and StockSystem classes
//              Only basic cases for RBTree are tested. You are responsible
//              for adding your own code to thoroughly test your RBTree class.
//              See PDF specification for tips for testing your tree structure using
//              pre-order traversal.

#include <iostream>
#include <cstdlib>
#include <string>

#include "rbtree.h"
#include "stockitem.h"
#include "stocksystem.h"

using namespace std;

// forward declarations

void PrintMenu();
void RBTreeTest();

// program entry point
int main()
{
  RBTreeTest();

  int choice = 0;
  string inputchoice;
  int asku;
  string inputasku;
  string adesc;
  double aprice;
  string inputaprice;
  int amount;
  string inputamt;
  string ctlg = "";

  StockSystem mystore;

  while (choice != 8)
  {
    PrintMenu();
    // get the menu choice from standard input
    getline(cin, inputchoice);
    choice = atoi(inputchoice.c_str());

    switch (choice)
    {
      case 1: // Print balance
        cout << "Funds: $" << mystore.GetBalance() << endl << endl;
        break;
      case 2: // Print catalogue
        ctlg = mystore.GetCatalogue();
        cout << ctlg << endl;
        break;
      case 3: // Add SKU
        cout << "Enter a numeric SKU (will be converted to 5 digits): ";
        getline(cin, inputasku);
        asku = atoi(inputasku.c_str());
        cout << "Enter item description: ";
        getline(cin, adesc);
        cout << "Enter a retail price: $";
        getline(cin, inputaprice);
        aprice = atof(inputaprice.c_str());
        if (mystore.StockNewItem(StockItem(asku, adesc, aprice)))
          cout << "Successfully added item to catalogue." << endl;
        else
          cout << "Item not added to catalogue." << endl;
        break;
      case 4: // Edit item description
        cout << "Enter a numeric SKU to edit: ";
        getline(cin, inputasku);
        asku = atoi(inputasku.c_str());
        cout << "Enter item description: ";
        getline(cin, adesc);
        if (mystore.EditStockItemDescription(asku, adesc))
          cout << "Item successfully updated." << endl;
        else
          cout << "Item not updated." << endl;
        break;
      case 5: // Edit item price
        cout << "Enter a numeric SKU to edit: ";
        getline(cin, inputasku);
        asku = atoi(inputasku.c_str());
        cout << "Enter a retail price: $";
        getline(cin, inputaprice);
        aprice = atof(inputaprice.c_str());
        if (mystore.EditStockItemPrice(asku, aprice))
          cout << "Item successfully updated." << endl;
        else
          cout << "Item not updated." << endl;
        break;
      case 6: // Restock an item
        cout << "Enter a numeric SKU to purchase: ";
        getline(cin, inputasku);
        asku = atoi(inputasku.c_str());
        cout << "Enter a quantity to purchase: ";
        getline(cin, inputamt);
        amount = atoi(inputamt.c_str());
        cout << "Enter the per-unit purchase price: $";
        getline(cin, inputaprice);
        aprice = atof(inputaprice.c_str());
        if (mystore.Restock(asku, amount, aprice))
          cout << "Item successfully restocked." << endl;
        else
          cout << "Item not restocked." << endl;
        break;
      case 7: // Sell an item
        cout << "Enter the SKU of item to sell: ";
        getline(cin, inputasku);
        asku = atoi(inputasku.c_str());
        cout << "Enter a quantity to sell: ";
        getline(cin, inputamt);
        amount = atoi(inputamt.c_str());
        if (mystore.Sell(asku, amount))
          cout << "Transaction complete. Have a nice day." << endl;
        else
          cout << "Item is out of stock. Sorry!" << endl;
        break;
      case 8: // Quit
        // no need to do anything, will cause while loop to break
        break;
      default:
        cout << "Invalid choice." << endl;
        break;
    }
  }

  return 0;
}

void PrintMenu()
{
  cout << "****************************************************\n"
       << "* Please select an option:                         *\n"
       << "* 1. Print balance             6. Restock an item  *\n"
       << "* 2. Print catalogue           7. Sell an item     *\n"
       << "* 3. Add a new SKU                                 *\n"
       << "* 4. Edit item description                         *\n"
       << "* 5. Edit item price           8. Quit             *\n"
       << "****************************************************\n" << endl;
  cout << "Enter your choice: ";
}

void RBTreeTest()
{
  RBTree<int> tree1;

  tree1.Insert(1);
  cout << "Tree contains " << tree1.Size() << " entries." << endl;
  cout << "Tree height: " << tree1.Height() << endl;
  Node<int>* node1 = tree1.Get(1);
  cout << node1->is_black << endl;

  tree1.Insert(3);
  cout << "Tree contains " << tree1.Size() << " entries." << endl;
  cout << "Tree height: " << tree1.Height() << endl;
  Node<int>* node2 = tree1.Get(3);
  cout << node2->is_black << endl;

  tree1.Insert(2); // should cause 2 rotations to occur
  cout << "Tree contains " << tree1.Size() << " entries." << endl;
  cout << "Tree height: " << tree1.Height() << endl;
  Node<int>* node3 = tree1.Get(2);
  Node<int>* node4 = tree1.Get(1);
  Node<int>* node5 = tree1.Get(3);
  cout << node3->is_black << endl;
  cout << node4->is_black << endl;
  cout << node5->is_black << endl;

  tree1.Insert(4);
  cout << "Tree contains " << tree1.Size() << " entries." << endl;
  cout << "Tree height: " << tree1.Height() << endl;
  Node<int>* node6 = tree1.Get(2);
  Node<int>* node7 = tree1.Get(1);
  Node<int>* node8 = tree1.Get(3);
  Node<int>* node9 = tree1.Get(4);
  cout << node6->is_black << endl;
  cout << node7->is_black << endl;
  cout << node8->is_black << endl;
  cout << node9->is_black << endl;


  tree1.Remove(4);
  cout << "Tree contains " << tree1.Size() << " entries." << endl;
  cout << "Tree height: " << tree1.Height() << endl;
  Node<int>* node10 = tree1.Get(2);
  Node<int>* node11 = tree1.Get(1);
  Node<int>* node12 = tree1.Get(3);
  cout << node10->is_black << endl;
  cout << node11->is_black << endl;
  cout << node12->is_black << endl;

  tree1.Remove(2);
  cout << "Tree contains " << tree1.Size() << " entries." << endl;
  cout << "Tree height: " << tree1.Height() << endl;
  Node<int>* node13 = tree1.Get(1);
  Node<int>* node14 = tree1.Get(3);
  cout << node13->is_black << endl;
  cout << node14->is_black << endl;

//  tree1.Remove(1);
//  cout << "Tree contains " << tree1.Size() << " entries." << endl;
//  cout << "Tree height: " << tree1.Height() << endl;
  tree1.Remove(3);
  cout << "Tree contains " << tree1.Size() << " entries." << endl;
  cout << "Tree height: " << tree1.Height() << endl;

  RBTree<int> tree2(tree1);
  cout << "Tree contains " << tree2.Size() << " entries." << endl;
  cout << "Tree height: " << tree2.Height() << endl;

  RBTree<int> tree3;
  tree3.Insert(5);
  tree3 = tree2;
  cout << tree3.Contains(5) << endl;
  cout << tree3.Contains(1) << endl;



}