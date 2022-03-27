#include "head.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

void write_ToFile(vector <float>& numbers, int N)
{
	ofstream write;
	write.open("H:\\Desktop\\101.txt");
	for (int i = 0; i <= (N - 1); i++)
	{
		write << numbers[i] << endl;
	}
	write.close();
}

void write_ToArray(vector <float>& a, float& St)
{
	a.push_back(St);
}

void add_element(vector <float>& new_data, vector <float>& old_data)
{
	for (int i = 0; i < 64; ++i)
	{
		new_data.push_back(old_data.at(i));
		cout << new_data.back() << endl;
	}
}

bool write_adc(std::vector<float> data, double freq_sampling)
{
	ADCFILEHEADER head;
	head.Am = 1.0;
	head.h = 32;
	head.dt = 1.0 / freq_sampling;
	head.fN = data.size();
	head.flags = ADCF_DATA_FLOAT;
	const char* FName = "H:\\Desktop\\101.adc";
	float im = 0.0;
	ofstream out(FName, ios::binary);
	out.write((char*)& head, sizeof(head));
	for (int i = 0; i < data.size(); ++i)
	{
		out.write((char*)& data[i], sizeof(data[i]));
	}
	out.close();
	return true;
}

void create_sin(vector <float> &SIN, int i)
{
	double freq_sampling = 48000.0;
	double freq_Hz = 1200.0;
	float A = sin(float(2 * M_PI * i * freq_Hz / freq_sampling));
	write_ToArray(SIN, A);
}

void create_const(vector<float>& CNST, int i)
{
	float A = 1.02;
	write_ToArray(CNST, A);
}

void create_impulse(vector <float>& IMP)
	{
		static int t = 0;
		int T = 2.0;
		float A;
		if ((t + 1) % 3 == 0)
		{
			A = 0;
			write_ToArray(IMP, A);
		}
		else
		{
			A = 1.02; write_ToArray(IMP, A);
		}
		++t;
	}

void create_pila(vector <float>& SAW)
{
	static int t = 0.0;
	static int T = 3.0;
	if (t % T == 0 && t != 0) t = 0;
	float A = tan(0.471615567862328) * t;
	write_ToArray(saw, A);
	t++;
}