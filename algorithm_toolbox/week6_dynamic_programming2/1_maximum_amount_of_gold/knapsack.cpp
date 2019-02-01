#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

//#define VERBOSE 1

#ifdef VERBOSE 
#define PRINT_VERBOSE(...) cout __VA_ARGS__
#else
#define PRINT_VERBOSE(...)
#endif

using namespace std;
using std::vector;

//int optimal_weight(int W, vector<int> &w) {
//  //write your code here
//	if (W <= 0)
//		return 0;
//	vector<int>::const_iterator it;
//	it = min_element(w.begin(), w.end());
//	if (W < *it)
//		return 0;
//
//	vector<int> F(W+1, 0);
//	vector<int> dup_w;
//	
//	int tmp_max = numeric_limits<int>::min();
//	sort(w.begin(), w.end());
//	for (int tmp_w = 1; tmp_w < W+1; tmp_w++) {
//		PRINT_VERBOSE(<< "tmp_w:" << tmp_w << endl);
//		tmp_max = numeric_limits<int>::min();
//		//intialize w to dup_w
//		copy(w.begin(), w.end(), back_inserter(dup_w));
//		//for (size_t i = 0; i < dup_w.size(); ++i) {
//		while(dup_w.size() != 0){
//			PRINT_VERBOSE(<< "IAM HER" << dup_w[0] <<endl);
//			if (dup_w[0] <= tmp_w) {
//				tmp_max = max(tmp_max, F[tmp_w - dup_w[0]] + dup_w[0]);
//				dup_w.erase(dup_w.begin() + 0);
//			}
//			else
//				break;
//		}
//		dup_w.clear();
//		PRINT_VERBOSE(<< "assiging value: " << tmp_max << endl);
//		F[tmp_w] = tmp_max;
//	}
//	for (int tmp_w = 1; tmp_w < W + 1; tmp_w++) {
//		PRINT_VERBOSE(<< tmp_w << " " << F[tmp_w] << endl);
//	}
//	return F[W];
//}

int optimal_weight(int W, vector<int> &w) {
	vector<vector<int> > scores(w.size() + 1);
	bool diff;
	for (size_t i = 0; i < w.size()+1; i++) {
		scores[i] = vector<int>(W + 1, 0);
	}

	for (size_t i = 1; i < w.size() + 1; i++) {
		for (size_t j = 1; j < W + 1; j++) {
			scores[i][j] = scores[i - 1][j];
			if (w[i-1] <= j) {
				scores[i][j] = max(scores[i][j], scores[i - 1][j - w[i - 1]] + w[i - 1]);
			}
		}
	}
	for (size_t i = 1; i < w.size() + 1; i++) {
		for (size_t j = 1; j < W + 1; j++) {
			PRINT_VERBOSE(<< scores[i][j] << " ");
		}
		PRINT_VERBOSE(<< endl);
	}
	return scores[w.size()][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
