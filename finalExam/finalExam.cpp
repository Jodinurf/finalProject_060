#include <iostream>
using namespace std;
class bidangDatar {
private:
	int x, y;
public:
	bidangDatar() {
		x = 0;
		y = 0;
	}
	virtual void input() {}
	virtual float Luas(int a) { return 0; }
	virtual float Keliling(int a) { return 0; }
	virtual void cekUkuran() { return; }
	void setX(int a) {
		this->x = a;
	}
	int getX() {
		return x;
	}
	void setY(int b) {
		this->y = b;
	}
	int getY() {
		return y;
	}
};
class Lingkaran :public bidangDatar {
public:
	void input() {
		cout << "Masukkan jejari: ";
		int r;
		cin >> r;
		setX(r);
	}

	float Luas(int r) {
		return 3.14 * r * r;
	}

	float Keliling(int r) {
		return 2 * 3.14 * r;
		
	}

	void cekUkuran() {
		float keliling(getX());
		if (keliling > 40)
		{
			cout << "Ukuran Lingkaran adalah besar" << endl;
		}
		else if (keliling < 20) {
			cout << "Ukuran Lingkaran adalah sedang" << endl;
		}
		else if (keliling < 10) {
			cout << "Ukuran Lingkaran adalah kecil" << endl;
		}
	}

};

class Persegipanjang :public bidangDatar {
	void input() {
		cout << "Masukkan Panjang: ";
		int p;
		cin >> p;
		setX(p);

		cout << "Masukkan Lebar : ";
		int l;
		cin >> l;
		setY(l);
	}

	float Luas(int p) {
		return p * getY();
	}

	float Keliling(int p) {
		return 2 * (p + getY());
	}

	void cekUkuran() {
		float keliling(getX());
		if (keliling > 40)
		{
			cout << "Ukuran Persegipanjang adalah besar" << endl;
		}
		else if (keliling < 20  and keliling > 10) {
			cout << "Ukuran Persegipanjang adalah sedang" << endl;
		}
		else if (keliling < 10) {
			cout << "Ukuran Persegipanjang adalah kecil" << endl;
		}
	}
};
int main() {
	bidangDatar* a;
	char ch;
	do {
		cout << "Lingkaran dibuat" << endl;
		a = new Lingkaran();
		a->input();
		int r = a->getX();
		cout << "Luas Lingkaran = " << a->Luas(r) << endl;
		cout << "Keliling Lingkaran = " << a->Keliling(r) << endl;
		a->cekUkuran();

		cout << "\nPersegipanjang dibuat" << endl;
		a = new Persegipanjang();
		a->input();
		int p = a->getX();

		cout << "Luas Persegipanjang = " << a->Luas(p) << endl;
		cout << "Keliling Persegipanjang = " << a->Keliling(p) << endl;
		a->cekUkuran();
		cout << "\nApakah anda ingin mengulang program? Y/N ";
		cin >> ch;
	} while ((ch == 'Y') || (ch == 'y'));

	delete a;
	return 0;
}