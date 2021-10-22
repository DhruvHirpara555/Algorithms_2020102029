#include<iostream>
#include<complex>
#include<math.h>
#include<vector>

#define PI 3.14159265358979323


using com = std::complex<double>;

void FFT(std::vector<com> &a,int sign) {
    int n = a.size();
    if (n == 1) return;
    std::vector<com> a0(n / 2), a1(n / 2);
    for (int i = 0; i < n / 2; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    FFT(a0, sign);
    FFT(a1, sign);
    com w(1, 0);
    com wn(cos(2 * PI / n), sign * sin(2 * PI / n));
    for (int i = 0; i < n / 2; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        w = w * wn;
    }
}




