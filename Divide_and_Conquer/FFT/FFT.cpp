
#include "FFT.hpp"

// give input with size of the form 2^n

void FFThelp(std::vector<com> &a,int sign) {
    int n = a.size();
    if (n == 1) return;
    std::vector<com> a0(n / 2), a1(n / 2); // a0 and a1 are the two halves of a vector such that a0 contains the even indexed elements and a1 contains the odd indexed elements
    for (int i = 0; i < n / 2; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    FFThelp(a0, sign);
    FFThelp(a1, sign);
    com w(1, 0); // w is the complex number with real part 1 and imaginary part 0
    com wn(cos(2 * PI / n), sign * sin(2 * PI / n)); // wn is the complex number with real part cos(2*pi/n) and imaginary part sign*sin(2*pi/n) (nth root of unity)

    // Evaluating the butterfly operation

    // a[i] = a0[i] + (wn^i)*a1[i];
    // a[i + n/2] = a0[i] - (wn^i)a1[i];

    for (int i = 0; i < n / 2; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        w = w * wn;
    }
}
// we can use the same function for FFT and IFFT
// IFFT is just a FFT with sign = -1 and multiply by 1/n
std::vector<com> FFT(std::vector<com> a,int sign) {
    FFThelp(a, sign);
    com i = com(0, 1);
    if(sign == -1) {
        for (int i = 0; i < a.size(); i++) {
            a[i] = (a[i].real()/a.size() + a[i].imag()/a.size()*i);
        }
    }
    return a;
}





