#include <cstdio>
#include <cstring>

int Gcd(int a, int b) {
	while (a % b != 0) {
		int m = a % b;
		a = b;
		b = m;
	}
	return b;
}

struct Frac {
	int br, im;
	Frac(int _br, int _im) : br(_br), im(_im) {}
	void Shorten() {
		int gcd = Gcd(br, im);
		br /= gcd; im /= gcd;
	}
};

const int NUM_MAX = 99;

int main() {
	for (int im = 10; im <= NUM_MAX; im++) {
		int br = 10;
		for (; br < im; br++) {
			int desBr = br / 10, jedBr = br % 10, desIm = im / 10, jedIm = im % 10;
			Frac f(br, im);
			f.Shorten();
			if ((f.br == desBr) && (f.im == desIm) && (jedBr == jedIm) && (jedBr != 0) && (desBr != 0))
				printf("Pre: %d %d Posle: %d / %d \n", br, im, f.br, f.im);
			if ((f.br == jedBr) && (f.im == desIm) && (desBr == jedIm))
				printf("Pre: %d %d Posle: %d / %d \n", br, im, f.br, f.im);
			if ((f.br == jedBr) && (f.im == jedIm) && (desBr == desIm))
				printf("Pre: %d %d Posle: %d / %d \n", br, im, f.br, f.im);
			if ((f.br == desBr) && (f.im == jedIm) && (jedBr == desIm))
				printf("Pre: %d %d Posle: %d / %d \n", br, im, f.br, f.im);


		}
	}
	return 0;
}