#include <iostream>
#include <vector>
#include <limits>

// comments verbose format
//#define VERBOSE 1

#ifdef VERBOSE 
#define PRINT_VERBOSE(...) cout __VA_ARGS__
#else
#define PRINT_VERBOSE(...)
#endif

using std::vector;
using namespace std;

int min(int a, int b, int c) {
	if (a < b) {
		if (a < c)
			return a;
		else
			return c;
	} else {
		if (b < c)
			return b;
		else
			return c;
	}
}

int get_change(int m) {
	int money_iterator=1;
	int tmp_1, tmp_3, tmp_4;
	int int_max= std::numeric_limits<int>::max();
	// for 1, 3, 4 
	vector<int> no_of_coins(m+1);
	no_of_coins[0] = 0;
	while (money_iterator <= m)  {
		PRINT_VERBOSE(<< money_iterator << endl);
		tmp_1 = int_max;
		tmp_3 = int_max;
		tmp_4 = int_max;
		if (money_iterator >= 1) {
			tmp_1 = no_of_coins[money_iterator - 1] + 1;
		}
		if (money_iterator >= 3) {
			tmp_3 = no_of_coins[money_iterator - 3] + 1;
		}
		if (money_iterator >= 4) {
			tmp_4 = no_of_coins[money_iterator - 4] + 1;
		}
		PRINT_VERBOSE(<< tmp_1 <<" " << tmp_3 << " " << tmp_4 << " " << endl);
		no_of_coins[money_iterator] = min(tmp_1, tmp_3, tmp_4);
		money_iterator++;
	}
  //write your code here
  return no_of_coins[m];
}

int main() {
  int m;
  std::cin >> m;
  //std::cout << min(1, 2, 3);
  //std::cout << min(2, 3,1);
  //std::cout << min(3,2,1);
  //std::cout << min(1, 1, 3);
  //std::cout << min(1, 2, 2);
  //std::cout << min(1, 3, 3);
  //std::cout << min(1, 1, 1);
  //std::cout << min(1, 2, 1);
	 // return 0;
  std::cout << get_change(m) << '\n';
  return 0;
}
