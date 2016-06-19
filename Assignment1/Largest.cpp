#include <iostream>
using namespace std;

double arrayMax(double arr[], int sz, int start)
{
    if(start >= sz-1)
        return arr[start];
    else {
        double largest = arr[start];
        double largest0 = arrayMax(arr,sz,start+1);
        if(largest > largest0){
            return largest;
        }
        else{
            return largest0;
        }
     }
}

int main(){

    double arr1[] = {10,101,2,53,11,15,62,7,81,19};

    double largest = arrayMax(arr1,10,4);

    cout << largest << endl;

    return 0;

}
