#include "lab9.h"
#include <iostream>
using namespace std;

void FindA(double x[], double y[], int n, double ans[], int m) {
		double** X = NewMatrix(n, m + 1);
		for(int i = 0; i < n; i++) {
				for(int j = 0; j < m + 1; j++) {
						if(j == 0) {
								X[i][j] = 1;
						} else {
								X[i][j] = X[i][j - 1] * x[i];
						}
				}
		}
		//PrintMatrix(X, n, m + 1);
		//cout << endl;
		double** N = NewMatrix(m + 1, m + 1);
		double* C = new double[m + 1];
		MakeN(N, X, n, m + 1);
		MakeC(C, y, X, n, m + 1);
		//PrintMatrix(N, m + 1, m + 1);
		//cout << endl;
		//for(int i = 0; i < m + 1; i++) {
		//		cout.precision(6);
		//		cout.width(7);
		//		cout << C[i] << endl;
		//}

		double* Y = new double[m + 1];
		double* Ans = new double[m + 1];
		double** L = NewMatrix(m + 1, m + 1);
		double** Lt = NewMatrix(m + 1, m + 1);
		FillZero(L, m + 1);
		FillZero(Lt, m + 1);

		MakeL(N, L, Lt, m + 1);

		LUStraight(L, m + 1, C, Y);

		Reverse(Lt, m + 1, Y, Ans);

		//cout << endl << "Answers" << endl;
		for(int i = 0; i < m + 1; i++) {
				cout.precision(6);
				//cout.width(7);
				if(i != m) cout << "(" << Ans[i] << ")X^" << i << " + ";
				else cout << "(" << Ans[i] << ")X^" << i << " ";
		}
		cout << endl << endl;
		//Gaus(N, m + 1, C);
}
