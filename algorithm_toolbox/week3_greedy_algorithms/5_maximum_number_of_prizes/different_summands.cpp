#include <iostream>
#include <vector>

using std::vector;

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}
vector<int> optimal_summands(int n) {
	vector<int> summands;
	int i = 1;
	int prize = 0;
	//write your code here
	while (n > 0) {
		prize = i;
		if (i > n) {
			prize = summands[summands.size()-1] + n;
			summands.pop_back();
			summands.push_back(prize);
			n = 0;
		}
		else {
			summands.push_back(prize);
			i = i + 1;
			n = n - prize;
		}
	}
	return summands;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> summands = optimal_summands(n);
	std::cout << summands.size() << '\n';
	for (size_t i = 0; i < summands.size(); ++i) {
		std::cout << summands[i] << ' ';
	}
}
