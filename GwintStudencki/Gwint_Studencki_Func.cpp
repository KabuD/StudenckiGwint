#include "Gwint_Studencki_Header.h"

bool czyBylaWylosowana(int iLiczba, int tab[], int ile)
{
	if (ile <= 0)
		return false;

	int i = 0;
	do
	{
		if (tab[i] == iLiczba)
			return true;

		i++;
	} while (i < ile);

	return false;
}
int wylosuj()
{
	return(rand() % 10) + 1;
}