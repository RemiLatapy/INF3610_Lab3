#include "Writer.h"

Writer::Writer(sc_module_name name)
:sc_channel(name)
{
	/*

	� compl�ter

	*/
}


Writer::~Writer()
{
}

void Writer::Write(unsigned int offset, unsigned int data)  {
	dataPortRAM->Write(offset, data);
}