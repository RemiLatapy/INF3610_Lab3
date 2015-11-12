///////////////////////////////////////////////////////////////////////////////
//
//	Bubble.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include "Bubble.h"


///////////////////////////////////////////////////////////////////////////////
//
//	Constructeur
//
///////////////////////////////////////////////////////////////////////////////
Bubble::Bubble( sc_module_name name )
:sc_module(name)
{
	/*
	
	À compléter
	
	*/
	SC_THREAD(thread);
}


///////////////////////////////////////////////////////////////////////////////
//
//	Destructeur
//
///////////////////////////////////////////////////////////////////////////////
Bubble::~Bubble()
{
	/*
	
	À compléter
	
	*/
}


///////////////////////////////////////////////////////////////////////////////
//
//	thread
//
///////////////////////////////////////////////////////////////////////////////
void Bubble::thread(void)
{
	while (1)
	{
		int addr = 0;
		address->write(addr);
		requestRead->write(true);
		do 
		{
			wait(clk->posedge_event());
		} while (!ack->read());

		unsigned int numVal = data->read();
		valueTab = new unsigned int[numVal];
		requestRead->write(false);

		do 
		{
			wait(clk->posedge_event());
		} while (ack->read());
		
		//reading all values
		addr += 4;
		for (unsigned int i = 0; i < numVal; i++)
		{
			address->write(addr);
			requestRead->write(true);
			do
			{
				wait(clk->posedge_event());
			} while (!ack->read());

			valueTab [i]= data->read();
			requestRead->write(false);

			do
			{
				wait(clk->posedge_event());
			} while (ack->read());
			addr += 4;
		}

		bubbleSort(valueTab, numVal);
		addr = 4;
		//writing all values
		for (unsigned int i = 0; i < numVal; i++)
		{
			address->write(addr);
			data->write(valueTab[i]);
			requestWrite->write(true);
			do
			{
				wait(clk->posedge_event());
			} while (!ack->read());

			requestWrite.write(false);
			do
			{
				wait(clk->posedge_event());
			} while (ack->read());

			addr += 4;
		}

		sc_stop();
	}
}


///////////////////////////////////////////////////////////////////////////////
//
//	bubbleSort
//
///////////////////////////////////////////////////////////////////////////////
void Bubble::bubbleSort(unsigned int *ptr, int counter)
{
	// Variable
	unsigned int tmp = 0;
	
	for (int i = 1; i < counter; ++i){
		for (int j = 0; j < counter - i; ++j){
			if (ptr[j] > ptr[j + 1]){
				// Changing position
				tmp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = tmp;
			}
	
		}
	}
	// Display
	for (int i = 0; i < counter; i++)
		cout << ptr[i] << endl;
}
