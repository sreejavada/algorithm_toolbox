#include <iostream>
#include <vector>

using namespace std;
// comments verbose format
//#define VERBOSE 1

#ifdef VERBOSE 
#define PRINT_VERBOSE(...) cout __VA_ARGS__
#else
#define PRINT_VERBOSE(...)
#endif

using std::vector;

long long merge_sort_inversions(vector<int> &array_to_be_sorted, vector<int> &b, size_t start, size_t mid, size_t end) {
	PRINT_VERBOSE(<< __func__ << std::endl);
	for (size_t i = start; i < end; i++) {
		PRINT_VERBOSE(<< array_to_be_sorted[i] << " ");
	}
	PRINT_VERBOSE(<< "array ends" << endl);
	std::vector<int> dummy_per_unit_value(end - start);

	size_t i = start, j = mid;
	long long inversions = 0;
	int k = 0;
	while (i < mid && j < end) {
		
		if (array_to_be_sorted[i] > array_to_be_sorted[j]) {
			inversions = inversions + (end - j);
			PRINT_VERBOSE(<< "inversions: " << inversions << endl);
			dummy_per_unit_value[k] = array_to_be_sorted[i];
			i++;
			k++;
		}
		else {
			dummy_per_unit_value[k] = array_to_be_sorted[j];
			j++;
			k++;
		}
	}

	while (i < mid) {
		dummy_per_unit_value[k] = array_to_be_sorted[i];
		i++;
		k++;
	}
	PRINT_VERBOSE(<< "i loop done" << endl);
	while (j < end) {
		dummy_per_unit_value[k] = array_to_be_sorted[j];
		j++;
		k++;
	}
	for (i = 0; i < (end - start); i++) {
		array_to_be_sorted[start + i] = dummy_per_unit_value[i];
	}
	return inversions;
}


long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
	for (size_t i = left; i < right; i++) {
		PRINT_VERBOSE(<< a[i] << " ");
	}
	PRINT_VERBOSE(<< "array ends main func" << endl);
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  PRINT_VERBOSE(<< "number of inversions left: " << number_of_inversions << endl);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  PRINT_VERBOSE(<< "number of inversions right: " << number_of_inversions << endl);
  //write your code here
  number_of_inversions += merge_sort_inversions(a, b, left, ave, right);

  PRINT_VERBOSE(<< "number of inversions total: " << number_of_inversions << endl);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
  for (size_t i = 0; i < a.size(); i++) {
	  PRINT_VERBOSE(<< a[i] << " ");
  }
  PRINT_VERBOSE(<< endl);
}
