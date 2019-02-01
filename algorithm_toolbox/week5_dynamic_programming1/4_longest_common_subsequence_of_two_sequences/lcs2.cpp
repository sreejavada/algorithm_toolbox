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

int lcs2(vector<int> &a, vector<int> &b) {
	vector<int> c(1, 1);
	vector<vector<int>> scores(a.size() + 1);
	bool diff;
	for (size_t i = 0; i < a.size() + 1; i++) {
		scores[i] = vector<int>(b.size() + 1, 0);
	}

	//for (size_t i = 0; i < a.size() + 1; i++)
	//	scores[i][0] = i;

	//for (size_t i = 0; i < b.size() + 1; i++)
	//	scores[0][i] = i;

	for (size_t i = 1; i < a.size() + 1; i++) {
		for (size_t j = 1; j < b.size() + 1; j++) {
			if (a[i - 1] == b[j - 1])
				diff = 1;
			else
				diff = 0;
			PRINT_VERBOSE(<< "i:" << i << "j:" << j << endl);
			scores[i][j] = max(max(scores[i - 1][j - 1] + diff, scores[i - 1][j]), scores[i][j - 1]);
		}
	}

	/*for (size_t i = 0; i < a.size() + 1; i++) {
		for (size_t j = 0; j < b.size() + 1; j++) {
			PRINT_VERBOSE(<< scores[i][j] << " ");
		}
		PRINT_VERBOSE(<< endl);
	}*/
	//write your code here
	return scores[a.size()][b.size()];
	return min(min(a.size(), b.size()), c.size());
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
