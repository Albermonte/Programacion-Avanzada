#include <iostream>
#include "CPolinomio.h"
#include "MemoryManager.h"

int main()
{
	{
		CPolinomio P, Q, R, S, T, U, V, W, X, Y, Z, N;
		CMonomio m1, m2(2, 2), m3(3, 3), m4(4, 4);

		P << m1 << m2 << -m4 << m3;
		Q << m4 << m1 << m2 << -m3;
		R << m3 << m4 << -m2;
		S << m2 << m3 << m4 << -m2;
		T << -m2 << -m3 << -m4 << m3;
		U << m2 << m3 << m4 << -m4;
		V << m2 << m3 << m4 << -m2 << -m3 << -m4;
		W << m2 << m3 << -m2 << -m3;
		X << m2 << -m2;
		Y << m2 << m3 << m4 << m2;
		Z << -m2 << -m3 << -m4 << -m3; N << m2 << m3 << m4 << m4;

		cout << "P = " << P << endl
			<< "Q = " << Q << endl
			<< "R = " << R << endl
			<< "S = " << S << endl
			<< "T = " << T << endl
			<< "U = " << U << endl
			<< "V = " << V << endl
			<< "W = " << W << endl
			<< "X = " << X << endl
			<< "Y = " << Y << endl
			<< "Z = " << Z << endl
			<< "N = " << N << endl << endl << endl;

		CPolinomio A(P), B;
		CPolinomio C(2.5, 1), D(2.5, 5);
		CPolinomio E(m4);
		B = Q;
		P = P;
		vector<CMonomio> monomios;
		monomios.push_back(m4);
		monomios.push_back(m3);
		monomios.push_back(m2);
		CPolinomio F(monomios);
		CMonomio monomio1(3, 2), monomio2(-2, 1);
		vector<CMonomio> monomios2;
		monomios2.push_back(monomio1);
		monomios2.push_back(monomio2);
		CPolinomio G(monomios2);

		cout << "CPolinomio A = P (constructor copia)\nA = " << A << endl
			<< "B = Q (operador de asignacion)\n B = " << B << endl
			<< "P = P (evitar auto-asignacion)\n P: " << P << endl
			<< "Probando el constructor con un coef. y un exp. " << endl << C << endl << D << endl
			<< "Probando el constructor con un monomio\n E = " << E << endl
			<< "Obteniendo el grado del polinomio.\n El grado de U es: " << U.MayorGrado() << endl
			<< "Probando el constructor con vector<CMonomio>\n F = " << F << endl
			<< "Probando el operador >\n P = -4x^4 +3x^3 +2x^2\n U = +3x^3 +2x^2" << endl
			<< "P " << (P > U ? "es de mayor grado que" : "es de menor grado que") << " U" << endl
			<< "Probando el operador ==\n P = -4x^4 +3x^3 +2x^2\n Q = +4x^4 - 3x^3 + 2x^2" << endl
			<< "P " << (P == Q ? "es de mismo grado que" : "es de distinto grado que") << " Q" << endl
			<< "Probando el operador - unario\n Q = +4x^4 - 3x^3 + 2x^2\n -Q = " << -Q << endl
			<< "Probando el operador +\n N = +8x^4 +3x^3 +2x^2\n U = +3x^3 +2x^2\n N + U: " << N + U << endl
			<< "Probando los operadores - y +=\n R = +4x^4 +3x^3 -2x^2\n S = +4x^4 + 3x^3\n R - S: " << R - S << endl
			<< "R += S: " << (R += S) << endl
			<< "Probando el operador -=\n N = +8x^4 +3x^3 +2x^2\n Y = +4x^4 + 3x^3 + 4x^2\n N -= Y: " << (N -= Y) << endl
			<< "Probando el operador []\n Polinomio P: -4x^4 +3x^3 +2x^2\n Coeficiente de P[4]: " << P[4] << endl
			<< "Probando el operador ()\n Polinomio G : +3x ^ 2 - 2x\n G(0.5) = " << G(0.5) << endl
			<< "Probando el operador *\n Q = +4x^4 -3x^3 +2x^2\n S = +4x^4 +3x^3\n Q * S: " << Q * S << endl
			<< "Probando el operador *=\n P = -4x^4 +3x^3 +2x^2\n Q = +4x^4 - 3x^3 + 2x^2\n P *= Q: " << (P *= Q) << endl;

	}
	MemoryManager::dumpMemoryLeaks();
	return 0;
}
