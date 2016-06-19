// File:        a1simpledriver.cpp
// Author:      (your name here) / Geoffrey Tien
// Date:        2016-05021
// Description: Basic test driver for CPSC 221 assignment #2
//              This file tests some functions of the CCQueue and LinkedList classes of assignment #2.
//              Note that only functions which are called will be compiled, therefore you must
//                ensure that every function in your classes is called at least once.
//              Not all special cases have been tested; you will be responsible for adding
//                your own test code and function calls to this file in order to thoroughly
//                test all general and boundary cases for your functions.
//              In general, please ensure that you test:
//               1. invalid parameter(s)
//               2. valid parameter(s), boundary case
//               3. valid parameter(s), general case

#include <cstdlib>
#include <iostream>
#include "ccqueue.h"


using namespace std;


// forward function declarations
void LLTest();
void CCQTest();

// program entry point
int main()
{
  cout << "Entering LinkedList test function... " << endl;
  LLTest();
  cout << "... LinkedList test function complete!\n" << endl;

  cout << "Entering CCQueue test function... " << endl;
  CCQTest();
  cout << "... CCQueue test function complete!\n" << endl;

#ifdef _WIN32
  system("pause");
#endif
  return 0;
}

void LLTest()
{
  // default constructor, InsertFront, InsertBack, ElementAt
  LinkedList<int> lla;
  lla.InsertFront(5);
  lla.InsertBack(10);
  cout << "lla contains " << lla.ElementAt(0) << " at index 0." << endl;

  // add
//  cout << "lla contains " << lla.ElementAt(1) << " at index 1." << endl;
//  lla.InsertBack(15);
//  lla.InsertAt(13,1);
//  lla.InsertAt(17,4);
//  cout << "lla contains " << lla.ElementAt(1) << " at index 1." << endl;
//  cout << "lla contains " << lla.ElementAt(2) << " at index 2." << endl;
//  cout << "lla contains " << lla.ElementAt(3) << " at index 3." << endl;
//  cout << "lla contains " << lla.ElementAt(4) << " at index 4." << endl;


  // copy constructor, InsertAt, RemoveAt (with exception)
  LinkedList<int> llb(lla);
//  llb.InsertAt(1,1);
  llb.InsertAt(7, 1);

  // add
//  cout << "llb contains " << llb.ElementAt(1) << " at index 1." << endl;
//  cout << "llb contains " << llb.ElementAt(2) << " at index 2." << endl;
//
//  LinkedList<int> lld;
//  try{
//    lld.RemoveAt(0);
//  }
//  catch (exception e){
//    cout << "Catch Exception!" << e.what() << endl;
//  }
//  lld.InsertFront(1);
//  cout << "lld contains " << lld.ElementAt(0) << " at index 0." << endl;
//  lld.RemoveAt(0);
//  cout << "lld is " << lld.Size() << " long." << endl;
//  lld.InsertFront(2);
//  lld.InsertFront(3);
//  lld.InsertFront(4);
//  cout << "lld contains " << lld.ElementAt(0) << " at index 0." << endl;
//  lld.RemoveAt(2);
//  cout << "lld is " << lld.Size() << " long." << endl;
//  cout << "lld contains " << lld.ElementAt(1) << " at index 1." << endl;

  try
  {
    int temp = llb.RemoveAt(12345);
    cout << temp << endl;
  }
  catch (exception e)
  {
    cout << "Exception in RemoveAt(): " << e.what() << endl;
  }

  // assignment operator, IsEmpty, Size, RemoveDuplicates, Contains
  LinkedList<int> llc;
  if (llc.IsEmpty())
    cout << "llc is empty." << endl;
  else
    cout << "llc is not empty." << endl;
  llc = lla;
  llc.InsertBack(13);
  llc.InsertBack(13);
  llc.InsertBack(13);
  cout << "llc contains " << llc.Size() << " items." << endl;
  llc.RemoveDuplicates();
  // cout << "llc contains " << llc.Size() << " items." << endl;
  if (llc.Contains(10))
    cout << "10 found in llc." << endl;
  else
    cout << "10 not found in llc." << endl;
  if (llc.Contains(13))
    cout << "13 found in llc." << endl;
  else
    cout << "13 not found in llc." << endl;
  llb.Append(lla);
  cout << "lla contains " << lla.Size() << " items, "
       << "llb contains " << llb.Size() << " items." << endl;
}

void CCQTest()
{
  CCQueue ccq;
  ccq.Add("Alrikr", "Video card smoked");
  ccq.Add("Bjornstjerne", "Cable is wrong colour, computer not colour coordinated. Worst day ever");
  ccq.Add("Cyprianus", "Still lost game after consuming energy drink");
  ccq.Add("Dietrich", "Order not received");
  ccq.Add("Elisaeus", "Box says 1TB, only 931GB formatted");
  cout << "Size of ticket queue: " << ccq.Size() << endl;
  //cout << ccq.PrintStatus() << endl;
  ccq.Service();
  //cout << ccq.PrintStatus() << endl;
//  cout << "Size of ticket queue: " << ccq.Size() << endl;
//  ccq.Service();
//  cout << "Size of ticket queue: " << ccq.Size() << endl;
//  ccq.Service();
//  cout << "Size of ticket queue: " << ccq.Size() << endl;
  ccq.MoveUp(3);
  //cout << ccq.PrintStatus() << endl;
  ccq.MoveUp(2);
  //cout << ccq.PrintStatus() << endl;
  ccq.MoveDown(2);
  cout << ccq.PrintStatus() << endl;

  ccq.MoveDown(2);
  cout << ccq.PrintStatus() << endl;

  ccq.MoveDown(2);
  cout << ccq.PrintStatus() << endl;
}

//template class LinkedList<int>;