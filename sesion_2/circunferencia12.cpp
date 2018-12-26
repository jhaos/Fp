#include <iostream>
#include <cmath>

using namespace std;

const double PI = 6 * asin(0.5);
const int DOS = 2;
int main(){

	double radio;
	double longitud;
	double area;

	cout << "Indique la longitud del radio de la circunferencia: ";
	cin >> radio;

	area = PI * radio*radio;
	longitud = DOS * PI * radio;

	cout << "El area del circulo es: " << area << endl;
	cout << "La longitud del circulo es: " << longitud << endl;
}