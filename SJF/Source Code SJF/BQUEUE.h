#include <iostream>

using namespace std;

#ifndef BQUEUE_H
#define BQUEUE_H

class bqnode
{
public:

	string proc;
	int CPU;
	int IO;
	int AT;						//data type input inside a node
	bqnode *prev, *next;			//two pointers
};

class BQUEUE
{
public:
	BQUEUE();					//const
	~BQUEUE();					//destructor
	BQUEUE(const BQUEUE &);		//copy const
	void Enqueue(string, int, int, int);			//adds to end of the list
	void Dequeue();				//removes form beginning of the list
	void Print();				//prints content
	void Print(int);				//prints content
	void run(int);
	bqnode * Search(int);
	void Out(bqnode *);

private:
	bqnode *front, *back;		// no need for front pointer?? as its equal to back->next due to circular Q.
};

#endif