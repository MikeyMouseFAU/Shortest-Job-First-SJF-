#include <iostream>
#include "BQUEUE.h"
#include <climits>

using namespace std;

int main()
{
	int x = INT_MAX;
	int timer = 0;
	BQUEUE  P;

	P.Enqueue("P1", 0, 18, 41);			//adds to queue
	P.Enqueue("P1", x, 16, 52);			//adds to queue
	P.Enqueue("P1", x, 19, 31);			//adds to queue
	P.Enqueue("P1", x, 14, 33);			//adds to queue
	P.Enqueue("P1", x, 17, 43);			//adds to queue
	P.Enqueue("P1", x, 19, 66);			//adds to queue
	P.Enqueue("P1", x, 14, 39);			//adds to queue
	P.Enqueue("P1", x, 17, 0);			//adds to queue
	
	P.Enqueue("P2", 0, 8, 32);			//adds to queue	
	P.Enqueue("P2", x, 7, 42);			//adds to queue
	P.Enqueue("P2", x, 6, 27);			//adds to queue
	P.Enqueue("P2", x, 17, 41);			//adds to queue
	P.Enqueue("P2", x, 7, 33);			//adds to queue
	P.Enqueue("P2", x, 11, 43);			//adds to queue
	P.Enqueue("P2", x, 12, 32);			//adds to queue
	P.Enqueue("P2", x, 14, 0);			//adds to queue

	P.Enqueue("P3", 0, 6, 51);			//adds to queue	
	P.Enqueue("P3", x, 5, 53);			//adds to queue	
	P.Enqueue("P3", x, 6, 46);			//adds to queue	
	P.Enqueue("P3", x, 9, 32);			//adds to queue	
	P.Enqueue("P3", x, 11, 52);			//adds to queue	
	P.Enqueue("P3", x, 4, 61);			//adds to queue	
	P.Enqueue("P3", x, 8, 0);			//adds to queue	
	
	P.Enqueue("P4", 0, 25, 35);
	P.Enqueue("P4", x, 19, 41);
	P.Enqueue("P4", x, 21, 45);
	P.Enqueue("P4", x, 18, 51);
	P.Enqueue("P4", x, 12, 61);
	P.Enqueue("P4", x, 24, 54);
	P.Enqueue("P4", x, 23, 61);
	P.Enqueue("P4", x, 21, 0);

	P.Enqueue("P5", 0, 15, 61);
	P.Enqueue("P5", x, 16, 52);
	P.Enqueue("P5", x, 15, 71);
	P.Enqueue("P5", x, 13, 41);
	P.Enqueue("P5", x, 15, 62);
	P.Enqueue("P5", x, 14, 31);
	P.Enqueue("P5", x, 14, 41);
	P.Enqueue("P5", x, 13, 32);
	P.Enqueue("P5", x, 15, 0);

	P.Enqueue("P6", 0, 6, 25);
	P.Enqueue("P6", x, 5, 31); 
	P.Enqueue("P6", x, 6, 32); 
	P.Enqueue("P6", x, 5, 41);
	P.Enqueue("P6", x, 4, 81);
	P.Enqueue("P6", x, 8, 39); 
	P.Enqueue("P6", x, 11, 42);
	P.Enqueue("P6", x, 5, 0);

	P.Enqueue("P7", 0, 16, 38);
	P.Enqueue("P7", x, 17, 41);
	P.Enqueue("P7", x, 15, 29); 
	P.Enqueue("P7", x, 14, 26); 
	P.Enqueue("P7", x, 9, 32);
	P.Enqueue("P7", x, 5, 34); 
	P.Enqueue("P7", x, 8, 26);
	P.Enqueue("P7", x, 6, 39);
	P.Enqueue("P7", x, 5, 0);
	
	P.Enqueue("P8", 0, 5, 52);
	P.Enqueue("P8", x, 4, 42);
	P.Enqueue("P8", x, 6, 31);
	P.Enqueue("P8", x, 7, 21);
	P.Enqueue("P8", x, 4, 43);
	P.Enqueue("P8", x, 5, 31);
	P.Enqueue("P8", x, 7, 32);
	P.Enqueue("P8", x, 6, 32); 
	P.Enqueue("P8", x, 7, 41);
	P.Enqueue("P8", x, 4, 0);

	P.Enqueue("P9", 0, 11, 37);	P.Enqueue("P9", x, 12, 41);	P.Enqueue("P9", x, 6, 41);	P.Enqueue("P9", x, 4, 48);	P.Enqueue("P9", x, 6, 41); 	P.Enqueue("P9", x, 5, 29);	P.Enqueue("P9", x, 4, 26);	P.Enqueue("P9", x, 5, 31);	P.Enqueue("P9", x, 3, 0);

	//P.Print();				//prints queue

	P.run(timer);
	
	cout << "Execution has been Finised" << endl;
	
	cout << "Press a key to close program";
	cin.get();


	return 0;
  }