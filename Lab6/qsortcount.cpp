#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int * x;
int comps = 0;

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
//	cout << "a is " << a << endl;
//	cout << "b is " << b << endl;
//	cout << "pivot is " << p << endl;
//	cout << "x[a] is " << x[a] << endl;
//	cout << "x[b] is " << x[b] << endl;
//	cout << "x[p] is " << x[p] << endl;
	swap(x[a], x[p]);
//	cout << "x[a] is " << x[a] << " after swap" << endl;
//	cout << "x[b] is " << x[b] << " after swap" << endl;
//	cout << "x[p] is " << x[p] << " after swap" << endl;
	int m = a;
	// cout << "m is " << m << endl;
	int i;

	// in-place partition:
	for (i = a+1; i <= b; i++) {
//		cout << "i is " << i << endl;
//		cout << "x[i] is " << x[i] << endl;
		if (x[i] < x[a]) {

			swap(x[++m], x[i]);
		}
		comps++;
		// cout << "x[i] is " << x[i] << " after partition" << endl;
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
	// cout << "comps is " << comps << endl;
}

int qc(int n){
	if(n <= 1){
		return 0;
	}
	else{
		int p = randint(0,n);
		return n-1 + qc(p) + qc(n-1-p);
	}
}

//#define NN 1000
#define NN 10000

int main(int argc, char *argv[]) {
	srand(time(0));

	// change the following code
	x = new int[NN];
	for (int i=0; i<NN; ++i) {
		x[i] = rand() % NN;
	}
	
	quicksort(0, NN-1);
	for (int i=0; i<NN; ++i) {
		cout << x[i] << " ";
	}
	cout << endl;

	cout << comps << endl;
	cout << qc(NN) << endl;

	delete[] x;
	return 0;
}

