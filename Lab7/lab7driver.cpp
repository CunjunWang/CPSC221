#include "hashtable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


void usage(char* argv[]) {
	cerr << "Usage: " << argv[0] << " scheme numberOfKeys sizeOfTable" << endl;
	exit(-1);
}

int main(int argc, char *argv[]) {
	int n, m;
	srand(time(0));

	if (argc == 1) {
		cout << "Running your test code..." << endl;
		/* ADD YOUR TEST CODE HERE */
		cout << "With 1000 keys and size 10007: " << endl;
		Hashtable H1(10007);
		for(int i=0; i<1000; i++){
			H1.linsert(rand()+1);
		}
		H1.printStats();
		Hashtable H2(10007);
		for(int i=0; i<1000; i++){
			H2.qinsert(rand()+1);
		}
		H2.printStats();
		Hashtable H3(10007);
		for(int i=0; i<1000; i++){
			H3.dinsert(rand()+1);
		}
		H3.printStats();

		cout << "With 2000 keys and size 10007: " << endl;
		Hashtable H4(10007);
		for(int i=0; i<2000; i++){
			H4.linsert(rand()+1);
		}
		H4.printStats();
		Hashtable H5(10007);
		for(int i=0; i<2000; i++){
			H5.qinsert(rand()+1);
		}
		H5.printStats();
		Hashtable H6(10007);
		for(int i=0; i<2000; i++){
			H6.dinsert(rand()+1);
		}
		H6.printStats();

		cout << "With 3000 keys and size 10007: " << endl;
		Hashtable H7(10007);
		for(int i=0; i<3000; i++){
			H7.linsert(rand()+1);
		}
		H7.printStats();
		Hashtable H8(10007);
		for(int i=0; i<3000; i++){
			H8.qinsert(rand()+1);
		}
		H8.printStats();
		Hashtable H9(10007);
		for(int i=0; i<3000; i++){
			H9.dinsert(rand()+1);
		}
		H9.printStats();

		cout << "With 5000 keys and size 10007: " << endl;
		Hashtable H10(10007);
		for(int i=0; i<5000; i++){
			H10.linsert(rand()+1);
		}
		H10.printStats();
		Hashtable H11(10007);
		for(int i=0; i<5000; i++){
			H11.qinsert(rand()+1);
		}
		H11.printStats();
		Hashtable H12(10007);
		for(int i=0; i<5000; i++){
			H12.dinsert(rand()+1);
		}
		H12.printStats();

		cout << "With 7000 keys and size 10007: " << endl;
		Hashtable H13(10007);
		for(int i=0; i<7000; i++){
			H13.linsert(rand()+1);
		}
		H13.printStats();
		Hashtable H14(10007);
		for(int i=0; i<7000; i++){
			H14.qinsert(rand()+1);
		}
		H14.printStats();
		Hashtable H15(10007);
		for(int i=0; i<7000; i++){
			H15.dinsert(rand()+1);
		}
		H15.printStats();

		cout << "With 10000 keys and size 10007: " << endl;
		Hashtable H16(10007);
		for(int i=0; i<10000; i++){
			H16.linsert(rand()+1);
		}
		H16.printStats();
		Hashtable H17(10007);
		for(int i=0; i<10000; i++){
			H17.qinsert(rand()+1);
		}
		H17.printStats();
		Hashtable H18(10007);
		for(int i=0; i<10000; i++){
			H18.dinsert(rand()+1);
		}
		H18.printStats();

		cout << "With 1000 keys and size 99991: " << endl;
		Hashtable H19(99991);
		for(int i=0; i<1000; i++){
			H19.linsert(rand()+1);
		}
		H19.printStats();
		Hashtable H20(99991);
		for(int i=0; i<1000; i++){
			H20.qinsert(rand()+1);
		}
		H20.printStats();
		Hashtable H21(99991);
		for(int i=0; i<1000; i++){
			H21.dinsert(rand()+1);
		}
		H21.printStats();

		cout << "With 10000 keys and size 99991: " << endl;
		Hashtable H22(99991);
		for(int i=0; i<10000; i++){
			H22.linsert(rand()+1);
		}
		H22.printStats();
		Hashtable H23(99991);
		for(int i=0; i<10000; i++){
			H23.qinsert(rand()+1);
		}
		H23.printStats();
		Hashtable H24(99991);
		for(int i=0; i<10000; i++){
			H24.dinsert(rand()+1);
		}
		H24.printStats();

		cout << "With 50000 keys and size 99991: " << endl;
		Hashtable H25(99991);
		for(int i=0; i<50000; i++){
			H25.linsert(rand()+1);
		}
		H25.printStats();
		Hashtable H26(99991);
		for(int i=0; i<50000; i++){
			H26.qinsert(rand()+1);
		}
		H26.printStats();
		Hashtable H27(99991);
		for(int i=0; i<50000; i++){
			H27.dinsert(rand()+1);
		}
		H27.printStats();

		cout << "With 70000 keys and size 99991: " << endl;
		Hashtable H28(99991);
		for(int i=0; i<70000; i++){
			H28.linsert(rand()+1);
		}
		H28.printStats();
		Hashtable H29(99991);
		for(int i=0; i<70000; i++){
			H29.qinsert(rand()+1);
		}
		H29.printStats();
		Hashtable H30(99991);
		for(int i=0; i<70000; i++){
			H30.dinsert(rand()+1);
		}
		H30.printStats();


#ifdef _WIN32
    system("pause");
#endif
		return 0;
	}
	
	if (argc != 4) {
		usage(argv);
	}
	n = atoi(argv[2]);
	m = atoi(argv[3]);
	Hashtable H(m);
	
	switch(argv[1][0]) {
	case 'l':
		for (int i=0; i<n; ++i) {
			H.linsert(rand() + 1);
		}
		//    H.print();
		cout << "Linear: ";  
		H.printStats();
		break;
	case 'q':
		for (int i=0; i<n; ++i) {
			H.qinsert(rand() + 1);
		}
		//    H.print();
		cout << "Quadratic: ";
		H.printStats();
		break;
	case 'd':
		for (int i=0; i<n; ++i) {
			H.dinsert(rand() + 1);
		}
		//    H.print();
		cout << "Double Hashing: "; 
		H.printStats();
		break;
	default:
		usage(argv);
	}
#ifdef _WIN32
  system("pause");
#endif
}

