#include <iostream>

int get_change(int m) {
	//write your code here
	int coins[3] = { 10,5,1 };
	int a = 0, n=0;
	for (int i = 0; i < 3; i++) {
		a = m / coins[i];
		if (a > 0) {
			m = m - a * (coins[i]);
			n = n + a;
		}
	}
	return n;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
