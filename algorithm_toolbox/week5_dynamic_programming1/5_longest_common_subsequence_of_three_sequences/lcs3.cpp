#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;
//#define VERBOSE 1

#ifdef VERBOSE 
#define PRINT_VERBOSE(...) cout __VA_ARGS__
#else
#define PRINT_VERBOSE(...)
#endif

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {

	vector<vector<int>> temp(b.size() + 1);
	vector<vector< vector<int> > > scores(a.size() + 1);
	bool diff;
	for (size_t i = 0; i < b.size() + 1; i++) {
		temp[i] = vector<int>(c.size() + 1, 0);
	}

	for (size_t i = 0; i < a.size() + 1; i++) {
		scores[i] = temp;
	}

	//for (size_t i = 0; i < a.size() + 1; i++)
	//	scores[i][0] = i;

	//for (size_t i = 0; i < b.size() + 1; i++)
	//	scores[0][i] = i;
	vector<int> tmp_to_get_max(7);
	vector<int>::const_iterator it;
	for (size_t i = 1; i < a.size() + 1; i++) {
		for (size_t j = 1; j < b.size() + 1; j++) {
			for (size_t k = 1; k < c.size() + 1; k++) {
				if ((a[i - 1] == b[j - 1]) &&(b[j-1] == c[k-1]))
					diff = 1;
				else
					diff = 0;
				PRINT_VERBOSE(<< "i:" << i << "j:" << j << endl);
				tmp_to_get_max[0] = scores[i - 1][j - 1][k - 1] + diff;
				tmp_to_get_max[1] = scores[i - 1][j][k];
				tmp_to_get_max[2] = scores[i - 1][j-1][k];
				tmp_to_get_max[3] = scores[i - 1][j][k-1];
				tmp_to_get_max[4] = scores[i][j-1][k];
				tmp_to_get_max[5] = scores[i][j-1][k-1];
				tmp_to_get_max[6] = scores[i][j][k-1];
				it = max_element(tmp_to_get_max.begin(), tmp_to_get_max.end());
				scores[i][j][k] = *it;
			}
		}
	}

	/*for (size_t i = 0; i < a.size() + 1; i++) {
		for (size_t j = 0; j < b.size() + 1; j++) {
			PRINT_VERBOSE(<< scores[i][j] << " ");
		}
		PRINT_VERBOSE(<< endl);
	}*/
	//write your code here
	return scores[a.size()][b.size()][c.size()];
	return min(min(a.size(), b.size()), c.size());
}
int main() {
	size_t an;
	std::cin >> an;
	vector<int> a(an);
	for (size_t i = 0; i < an; i++) {
		std::cin >> a[i];
	}
	size_t bn;
	std::cin >> bn;
	vector<int> b(bn);
	for (size_t i = 0; i < bn; i++) {
		std::cin >> b[i];
	}
	size_t cn;
	std::cin >> cn;
	vector<int> c(cn);
	for (size_t i = 0; i < cn; i++) {
		std::cin >> c[i];
	}
	std::cout << lcs3(a, b, c) << std::endl;
}