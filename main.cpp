#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "head.h"
using namespace std;
int main()
{
	cout << "Generated signal. Check the file.\n";
	double freq_sampling = 48000.0;
	for (int i = 0; i < 64; ++i)
	{

		create_sin(SIN, i);
		create_const(const_sig, i);
		create_impulse(impulse);
		create_pila(saw);
	}
	add_element(DATA, const_sig);
	add_element(DATA, impulse);
	add_element(DATA, SIN);
	add_element(DATA, saw);
	write_adc(DATA, freq_sampling);

}
