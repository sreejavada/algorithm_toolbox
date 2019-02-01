#include <iostream>
#include <vector>
#include <string>
#include <limits>

// comments verbose format
//#define VERBOSE 1

#ifdef VERBOSE 
#define PRINT_VERBOSE(...) cout __VA_ARGS__
#else
#define PRINT_VERBOSE(...)
#endif

using namespace std;

int min(int a, int b, int c) {
	if (a < b) {
		if (a < c)
			return a;
		else
			return c;
	}
	else {
		if (b < c)
			return b;
		else
			return c;
	}
}

int edit_distance(const string &str1, const string &str2) {
	//write your code here
	vector< vector<int>> scores(str1.size()+1);
	bool diff;
	vector<int> temp_vector(str2.size() + 1);
	for (size_t i = 0; i < str1.size() + 1; i++) {
		scores[i] = vector<int>(str2.size()+1, numeric_limits<int>::max());
		/*for (size_t j = 0; j < str2.size() + 1; j++) {
			temp_vector[j] = numeric_limits<int>::max();
		}
		scores.push_back(temp_vector);*/
	}

	for (size_t i = 0; i < str1.size() + 1; i++)
		scores[i][0] = i;
	for (size_t i = 0; i < str2.size() + 1; i++)
		scores[0][i] = i;
	
	for (size_t i = 1; i < str1.size() + 1; i++) {
		for (size_t j = 1; j < str2.size() + 1; j++) {
			if (str1[i-1] == str2[j-1])
				diff = 0;
			else
				diff = 1;
			PRINT_VERBOSE(<< "i:" << i << "j:" << j << endl);
			scores[i][j] = min(scores[i - 1][j - 1] + diff, scores[i - 1][j] + 1, scores[i][j - 1] + 1);
		}
	}
	for (size_t i = 0; i < str1.size() + 1; i++) {
		for (size_t j = 0; j < str2.size() + 1; j++) {
			PRINT_VERBOSE(<< scores[i][j] << " ");
		}
		PRINT_VERBOSE(<< endl);
	}

	return scores[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
