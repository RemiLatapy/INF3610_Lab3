///////////////////////////////////////////////////////////////////////////////
//
//	main.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include <systemc.h>
#include "Bubble.h"
#include "Reader.h"
#include "DataRAM.h"
#include "Writer.h"

#define RAMSIZE 0x400
#define RAMSIZE 0x400
#define FILE "chiffre.hex"

// Global variables
bool m_bError = false;

///////////////////////////////////////////////////////////////////////////////
//
//	Main
//
///////////////////////////////////////////////////////////////////////////////
int sc_main(int arg_count, char **arg_value)
{
	// Variables
	int sim_units = 2; //SC_NS 
	
	/*
	
	À compléter
	
	*/
	sc_clock clock("clock", 1, SC_SEC);
	sc_signal<bool, SC_MANY_WRITERS> fileAck;
	sc_signal<unsigned int> fileAddr;
	sc_signal<bool> fileReq1;
	sc_signal<bool> filReq2;
	sc_signal<unsigned int, SC_MANY_WRITERS> Datasig;

	Bubble bubble("mod_Bubble");
	Reader reader("chan_Reader");
	Writer writer("chan_Writer");
	DataRAM dataRAM("mod_dataRam", FILE, RAMSIZE, true);

	bubble.clk(clock);
	bubble.ack(fileAck);
	bubble.address(fileAddr);
	bubble.data(Datasig);
	bubble.requestRead(fileReq1);
	bubble.requestWrite(filReq2);

	reader.ack(fileAck);
	reader.dataPortRAM(dataRAM);
	reader.address(fileAddr);
	reader.data(Datasig);
	reader.request(fileReq1);
	reader.clk(clock);

	writer.ack(fileAck);
	writer.dataPortRAM(dataRAM);
	writer.address(fileAddr);
	writer.data(Datasig);
	writer.request(filReq2);
	writer.clk(clock);
	// Démarrage de l'application
	if (!m_bError)
	{
		cout << "Démarrage de la simulation." << endl;
		sc_start( -1, sc_core::sc_time_unit(sim_units) );
		cout << endl << "Simulation s'est terminée à " << sc_time_stamp();
	}
	// Fin du programme
	return 0;
}
