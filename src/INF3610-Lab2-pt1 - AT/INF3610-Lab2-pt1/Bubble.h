///////////////////////////////////////////////////////////////////////////////
//
//	Bubble.h
//
///////////////////////////////////////////////////////////////////////////////
#ifndef _BUBBLE_H_
#define _BUBBLE_H_

#include <systemc.h>
#include <stdio.h>


///////////////////////////////////////////////////////////////////////////////
//
//	Class Bubble
//
///////////////////////////////////////////////////////////////////////////////
class Bubble : public sc_module /* À compléter */
{
	public: 
		// Ports
		sc_in_clk clk;
		sc_out<unsigned int> address;
		sc_inout<unsigned int> data;
		sc_out<bool> requestRead;
		sc_out<bool> requestWrite;
		sc_in<bool> ack;

	
		// Constructor
		Bubble( sc_module_name name );
		
		// Destructor
		~Bubble();
		
	private:
		/*
		
		À compléter
		
		*/

		SC_HAS_PROCESS(Bubble);
		unsigned int *valueTab;
		void thread(void);
		void bubbleSort(unsigned int *ptr, int counter);
};

#endif
