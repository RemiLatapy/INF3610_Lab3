///////////////////////////////////////////////////////////////////////////////
//
//	Bubble.h
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <systemc.h>
#include <stdio.h>
#include "InterfaceRead.h"
#include "InterfaceWrite.h"


///////////////////////////////////////////////////////////////////////////////
//
//	Class Bubble
//
///////////////////////////////////////////////////////////////////////////////
class Bubble : public sc_module
{
public:
	// Ports    
	sc_port<InterfaceRead> readPort;							// Port pour le module lecteur
	sc_port<InterfaceWrite>	writePort;							// Port pour le module écrivain

	// Constructor
	Bubble(sc_module_name name);

	// Destructor
	~Bubble();

private:
	unsigned int *valueTab;

	// Process SystemC
	SC_HAS_PROCESS(Bubble);

	void thread(void);
	void bubbleSort(unsigned int *ptr, int counter);
};

