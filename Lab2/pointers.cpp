#include <iostream>
using namespace std;

int main() {
  int* p1;
  int* p2;
  int x = 5;
  int y = 15;

  p1 = &x; 	 	// x contains 5; y 15; p1 0x28ff14; p2 0x28ff60

  p2 = &y;	 	// x contains 5; y 15; p1 0x28ff14; p2 0x28ff10
 
  *p1 = 6; 		// x contains 6; y 15; p1 0x28ff14; p2 0x28ff10

  *p1 = *p2;	// x 15; y 15; p1 0x28ff14; p2 0x28ff10

  p2 = p1; 		// x 15; y 15; p1 0x28ff14; p2 0x28ff14

  *p1 = *p2+10; // x 25; y 15; p1 0x28ff14; p2 0x28ff14

  return 0;
}
