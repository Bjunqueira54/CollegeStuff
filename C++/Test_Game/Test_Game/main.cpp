#include "includes.h"
#include "Interface.h"

int main(int argc, char** argv)
{
	Interface *interface = new Interface();

	interface->run();

	delete interface;

	return 0;
}