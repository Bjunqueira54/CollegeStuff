#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main(int argc, char** argv)
{
	HMODULE hDll = LoadLibraryEx("GothicTestDll.dll", NULL, NULL);

	if (hDll == NULL)
		return -1;

	void(*SayHello)() = (void(*)()) GetProcAddress(hDll, "SayHello");
	int(*GiveRandom)() = (int(*)()) GetProcAddress(hDll, "GiveRandom");
	void(*SayGoodbye)() = (void(*)()) GetProcAddress(hDll, "SayGoodBye");

	if (SayHello == NULL || GiveRandom == NULL || SayGoodbye == NULL)
		return -1;

	SayHello();
	for (int i = 0; i < 10; i++)
		printf("%i\n", GiveRandom());
	SayGoodbye();

	getch();

	return 0;
}