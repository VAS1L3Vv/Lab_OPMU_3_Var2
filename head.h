#pragma once
#define _USE_MATH_DEFINES
#include <vector>
using namespace std;
void create_const(vector<float>& CNST, int i);
void create_sin(vector <float>&, int);
void create_impulse(vector <float>&);
void create_pila(vector <float>&);

void write_ToFile(vector <float>&, int);
void write_ToArray(vector <float>&, float&);
bool write_adc(std::vector<float> data, double freq_sampling);
void add_element(vector <float>&, vector <float>& old_data);

struct ADCFILEHEADER
{
	double dt;
	unsigned long h;
	unsigned long fN;
	float Am;
	unsigned long flags;
	char reserv[8];
};
typedef struct ADCFILEHEADER* LPADCFILEHEADER;
#define ADCF_DATA_INTEGER 0x00000000
#define ADCF_DATA_FLOAT 0x00000001
#define ADCF_TYPE_REAL 0x00000000 
#define ADCF_TYPE_COMPLEX 0x00000002

inline vector<float> const_sig;
inline vector<float> impulse;
inline vector<float> SIN;
inline vector<float> saw;
inline vector<float> DATA;