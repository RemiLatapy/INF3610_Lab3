///////////////////////////////////////////////////////////////////////////////
//
//	main.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include <systemc.h>
#include "Bubble.h"
#include "Reader.h"
#include "Writer.h"
#include "DataRAM.h"

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

	// Components
	Bubble bubble("mod_bubble");
	Reader reader("chan_reader");
	Writer writer("chan_writer");
	DataRAM dataRAM("mod_dataRam", FILE, RAMSIZE, true);

	// Connexions
	bubble.readPort(reader);
	bubble.writePort(writer);
	writer.dataPortRAM(dataRAM);
	reader.dataPortRAM(dataRAM);

	// Démarrage de l'application
	if (!m_bError)
	{
		cout << "Démarrage de la simulation." << endl;
		sc_start(-1, sc_core::sc_time_unit(sim_units));
		cout << endl << "Simulation s'est terminée à " << sc_time_stamp() << endl;
	}
	// Fin du programme
	return 0;
}
