#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using namespace std;

// comments verbose format
//#define VERBOSE 1

#ifdef VERBOSE 
#define PRINT_VERBOSE(...) cout __VA_ARGS__
#else
#define PRINT_VERBOSE(...)
#endif
struct pair_m
{
	int m1;
	int m2;
};

void three_way_swap(vector<int> &a, int index1, int index2, int index3) {
	PRINT_VERBOSE(<< "3 WAY SWAP" << a[index1] << " " << a[index2] << " " << a[index3] << " " << endl);
	int dummy = a[index1];
	a[index1] = a[index3];
	a[index3] = a[index2];
	a[index2] = dummy;
}

pair_m partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int m1 = l;
  int m2 = l;
  pair_m m;
  for (int i = l + 1; i <= r; i++) {
	  PRINT_VERBOSE(<< "i:" << i << endl);
	  for (size_t j = l; j < r+1; ++j) {
		  PRINT_VERBOSE(<< a[j] << ' ');
	  }
	  PRINT_VERBOSE(<< endl);
	  if (a[i] == x) {
		  swap(a[i], a[m2 + 1]);
		  m2++;
	}
    if (a[i] < x) {
		three_way_swap(a, i, m1 + 1, m2 + 1);
		m1++;
		m2++;
    }
  }
  swap(a[l], a[m1]);
  m.m1 = m1;
  m.m2 = m2;
  return m;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pair_m m = partition2(a, l, r);

  randomized_quick_sort(a, l, m.m1 - 1);
  randomized_quick_sort(a, m.m2 + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
