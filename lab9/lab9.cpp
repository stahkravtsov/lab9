#include <iostream>
#include "lab9.h"

int main() {
		double x[6] = { 0.41, 0.46, 0.52, 0.61, 0.66, 0.73 },
				y[6] = { 2.73, 2.31, 1.97, 1.76, 1.53, 1.31 }, ans[6];
		std::cout<<"LINERAL"<<std::endl;
		FindA(x, y, 6, ans, 1);
		std::cout << std::endl <<"SQARE"<<std::endl;
		FindA(x, y, 6, ans, 2);
		std::cout << std::endl <<"CUBIC"<<std::endl;
		FindA(x, y, 6, ans, 3);
		return 0;

}