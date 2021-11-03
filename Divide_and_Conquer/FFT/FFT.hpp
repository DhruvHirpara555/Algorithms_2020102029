#if !defined(MACRO_FFT_H)
#define MACRO

#include<iostream>
#include<complex>
#include<math.h>
#include<vector>

#define PI 3.14159265358979323


using com = std::complex<double>;

void FFThelp(std::vector<com> &a,int sign);
std::vector<com> FFT(std::vector<com> a,int sign);


#endif // MACRO
