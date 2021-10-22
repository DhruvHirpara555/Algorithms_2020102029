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

void resize(std::vector<double> &a, int old, int nnew) {
    a.resize(nnew);
    for (int i = old; i < nnew; i++) {
        a[i] = 0;
    }
}

std::vector<double> multiply(std::vector<double> &a, std::vector<double> &b) {
    int n = 1;
    while(a.size() + b.size() > n)
    {
        n= n<<1;
    }
    resize(a, a.size(), n);
    resize(b, b.size(), n);
    std::vector<com> val_a(n), val_b(n), val_c(n);
    for (int i = 0; i < n; i++) {
        val_a[i] = a[i];
        val_b[i] = b[i];
    }
    FFT(val_a, 1);
    FFT(val_b, 1);
    for (int i = 0; i < n; i++) {
        val_c[i] = val_a[i] * val_b[i];
    }
    FFT(val_c, -1);
    std::vector<double> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = val_c[i].real() / n;
    }


}


