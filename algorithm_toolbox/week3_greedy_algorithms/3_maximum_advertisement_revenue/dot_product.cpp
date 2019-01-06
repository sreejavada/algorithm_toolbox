#include <algorithm>
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

void merge(vector<int>& array_to_be_sorted, int start, int mid, int end) {
	PRINT_VERBOSE(<< __func__ << std::endl);
	PRINT_VERBOSE(<< "start: " << start << std::endl);
	PRINT_VERBOSE(<< "mid: " << mid << std::endl);
	PRINT_VERBOSE(<< "end: " << end << std::endl);

	std::vector<int> dummy_per_unit_value(end - start + 1);

	int i = start, j = mid + 1;
	int k = 0;
	while (i < mid + 1 && j < end + 1) {
		PRINT_VERBOSE(<< i << " " << j << std::endl);
		if (array_to_be_sorted[i] > array_to_be_sorted[j]) {
			PRINT_VERBOSE(<< "1st array value is greater");
			dummy_per_unit_value[k] = array_to_be_sorted[i];
			i++;
			k++;
		}
		else {
			PRINT_VERBOSE(<< "2nd array value is greater");
			dummy_per_unit_value[k] = array_to_be_sorted[j];
			j++;
			k++;
		}
	}
	PRINT_VERBOSE(<< "1st loop done" << endl);
	while (i < mid + 1) {
		PRINT_VERBOSE(<< i << endl);
		dummy_per_unit_value[k] = array_to_be_sorted[i];
		i++;
		k++;
	}
	PRINT_VERBOSE(<< "i loop done" << endl);
	while (j < end + 1) {
		PRINT_VERBOSE(<< j << endl);
		dummy_per_unit_value[k] = array_to_be_sorted[j];
		j++;
		k++;
	}
	PRINT_VERBOSE(<< "j loop done" << endl);
	for (i = 0; i < (end - start + 1); i++) {
		array_to_be_sorted[start + i] = dummy_per_unit_value[i];
	}
	PRINT_VERBOSE(<< "copying loop done" << endl);
}

void merge_sort(vector<int>& array_to_be_sorted, int start, int end) {
	PRINT_VERBOSE(<< __func__ << std::endl);
	PRINT_VERBOSE(<<"start: " << start << std::endl);
	PRINT_VERBOSE(<< "end: " << end << std::endl);

	int mid = 0;
	if (end > start) {
		mid = (end - start) / 2;
		merge_sort(array_to_be_sorted, start, start + mid);
		merge_sort(array_to_be_sorted, start + mid + 1, end);
		merge(array_to_be_sorted, start, start + mid, end);
	}
}

long long max_dot_product(vector<int> a, vector<int> b) {
	// write your code here
	long long result = 0;
	merge_sort(a, 0, a.size() - 1);
	merge_sort(b, 0, b.size() - 1);
	for (size_t i = 0; i < a.size(); i++) {
		result += ((long long)a[i]) * b[i];
	}
	return result;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n), b(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (size_t i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	PRINT_VERBOSE(<< "printing here");
	std::cout << max_dot_product(a, b) << std::endl;
}