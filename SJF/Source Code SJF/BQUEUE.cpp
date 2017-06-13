
#include <iostream>
#include "BQUEUE.h" 
#include <iomanip>
#include <string>
#include <climits>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: BQUEUE()
//Precondition: N/A
//Postcondition: back set to 0.
//Description: Default constructor.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
BQUEUE::BQUEUE()
{
	back = NULL;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~BQUEUE()
//Precondition: BQUEUE needs to exist, be constructed.
//Postcondition: Deallocates memory.
//Description: Memory is given back (deallocated), prevents leakage.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
BQUEUE::~BQUEUE()			
{
	while (back != 0)					
	{
		Dequeue();
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Enqueue(int num)
//Precondition: Needs a queue to be defined, consturcted.
//Postcondition:  Adds new element to the back of a queue.
//Description: Inserts a new element at the end of a queue.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BQUEUE::Enqueue(string process, int AT , int CPU, int IO)
{
	if (back==0)
	{
		back = new bqnode;
		back->proc = process;
		back->AT = AT;
		back->CPU = CPU;
		back->IO = IO;
		back->next = back;
		back->prev = back;  
	}
	else
	{
		bqnode *f = back->next;
		back->next = new bqnode;
		back->next->next = f;
		back->next->prev = back;
		f->prev = back->next;
		back = back->next;
		back->proc = process;
		back->AT = AT;
		back->CPU = CPU;
		back->IO = IO;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Dequeue()
//Precondition: needs to be construded, defined queue.
//Postcondition: Element removed from a front of a queue.
//Description: Removes the element at the front of a queue.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BQUEUE::Dequeue()
{
if(back == 0)
{
	cout << "Can't remove more as Queue is EMPTY!!" << endl;

}

else if(back == back->next)
{ 
	back = 0;
	cout << "QUEUE'S LAST ELEMENT WAS DELETED!!!" << endl << endl;
}
else
{
	bqnode*f = back->next;
	f->next->prev = back;
	back->next = f->next;
	f->prev = f->next = 0;
	delete f;
}
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Print()
//Precondition: queue need to be defiened before hand.
//Postcondition: displays items in a queue.
//Description: prints out a queue.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void BQUEUE::Print()
{
	if(back == 0)
	{
		cout << "EMPTY QUEUE" <<endl;
	}
	else
	{
		bqnode *f = back->next;		//pointer to front 
		
		do
		{
			cout << left << setw(15) << f->proc
				<< setw(15) << left << f->AT
				<< setw(30) << left << f->CPU
				<< setw(10) << left << f->IO << endl;

			f = f->next;
		} while (f != back->next);
		cout << endl << endl;

		f=0;
		delete f;
	}
}


void BQUEUE::Print(int timer)
{

	if (back == 0)
	{
		cout << "EMPTY QUEUE" << endl;
	}
	else 
	{
		bqnode *m = back->next;
		bqnode *n = m->next;

		cout << left << "Ready Queue:  " << endl << "At time: " << timer << endl;

		while (n != back)			//chceks all DLL
		{
			while (m->proc == n->proc && n != back)					// if same Procces change to next node
			{
				n = n->next;
			}
			if (m->AT <= timer)
			{
				cout << left << setw(16) << "Ready Process:  " << left << m->proc << endl
					<< setw(16) << left << "CPU Burst: " << left << m->CPU << endl
					<< setw(16) << left << "I/O:  " << left << m->IO << endl << endl;

				m = n;
			}
			else 
			{
				m = n;
			}
		}
	}
}



void BQUEUE::run(int timer)
{
	//bqnode *f = back->next;					//pointer to front 

	if (back == NULL)	
	{
		return;
	}

	bqnode *x = Search(timer);

	if (x == 0)
	{
		timer++;
		run(timer);
	}


	if (back == NULL)
	{
		return;
	}

	// CONTEXT SWITCH
	Print(timer);

	cout << left << setw(15) << "Executing:  " << x->proc << endl
		<< setw(15) << left << "From: " << timer << endl
		<< setw(15) << left << "To:  " << timer + x->CPU << endl << endl;

	
	


	timer = timer + x->CPU;


	if (x->proc == x->next->proc)
	{
		x->next->AT = timer + x->IO;			//needs conditon to update
	}
	Out(x);								//needs to deque only specified node not at begging.
	
	if (back != NULL)
	{
		run(timer);
	}


}
void BQUEUE::Out(bqnode * ptr)
{
	if (ptr == back->next)
	{
		Dequeue();
	}
	else if (ptr == back)
	{
		back->next->prev = back->prev;
		back = back->prev;
		back->next = ptr->next;
	}
	else
	{
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		delete ptr;
	}
}


bqnode * BQUEUE::Search(int timer)			//searches for process that can be used
{
	bqnode *m = back->next;
	bqnode *n = m->next;
		
	while (n != back->next)			//chceks all DLL
	{
		while (m->proc == n->proc && n != back)					// if same Procces change to next node
		{
			n = n->next;
		}
	
		if (m->CPU > n->CPU && n->AT <= timer )  
		{
			m = n;
		}
		else if (n->CPU > m->CPU && m->AT <= timer)
		{
			n = n->next;
		}						
		else if (n->CPU == m->CPU && m->AT <= timer && n->AT <= timer)
		{
			if (m->AT < n->AT)
			{
				n = n->next;
			}
			else if (m->AT > n->AT)
			{
				m = n;
			}
			else
			{
				n = n->next;
			}
		}
		else
		{
			n = n->next;
		}
	}

	if (n->CPU == m->CPU && m->AT <= timer && n->AT <= timer)
	{
		if (m->AT <= n->AT)
		{
			return m;
		}
		else
		{
			return n;
		}
	}
	else if (m->CPU < n->CPU && m->AT <= timer)  //error here due to at <=
	{
		return m;
	}
	else if (n->AT <= timer && m->CPU == n->CPU && m->AT > n->AT)
	{
		return n;
	}
	else
	{
		if (n->AT > timer)
		{
			return m;
		}
		else if (m->AT <= timer )
		{
			return n;
		}
		else
		{
			return 0;
		}
	}


}
