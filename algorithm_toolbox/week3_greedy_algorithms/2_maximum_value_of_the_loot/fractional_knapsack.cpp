#include <iostream>
#include <vector>

using std::vector;
using namespace std;

void merge(vector<double>& per_unit_value, vector<int>& weights, int start, int mid, int end) {
	//std::cout << __func__ << std::endl;
	//std::cout << "start: " << start << std::endl;
	//std::cout << "mid: " << mid << std::endl;
	//std::cout << "end: " << end << std::endl;

	std::vector<double> dummy_per_unit_value(end - start + 1);
	std::vector<int> dummy_weights(end - start + 1);

	int i = start, j = mid + 1;
	int k = 0;
	while (i < mid + 1 && j < end + 1) {
		//std::cout << i << " " << j << std::endl;
		if (per_unit_value[i] > per_unit_value[j]) {
			//cout << "1st array value is greater";
			dummy_per_unit_value[k] = per_unit_value[i];
			dummy_weights[k] = weights[i];
			i++;
			k++;
		} else {
			//cout << "2nd array value is greater";
			dummy_per_unit_value[k] = per_unit_value[j];
			dummy_weights[k] = weights[j];
			j++;
			k++;
		}
	}
	//std::cout << "1st loop done" << endl;
	while(i <  mid+1){
		//std::cout << i << endl;
		dummy_per_unit_value[k] = per_unit_value[i];
		dummy_weights[k] = weights[i];
		i++;
		k++;
	}
	//std::cout << "i loop done" << endl;
	while (j < end + 1) {
		//std::cout << j << endl;
		dummy_per_unit_value[k] = per_unit_value[j];
		dummy_weights[k] = weights[j];
		j++;
		k++;
	}
	//std::cout << "j loop done" << endl;
	for (i = 0; i < (end - start + 1); i++) {
		per_unit_value[start+i] = dummy_per_unit_value[i];
		weights[start + i] = dummy_weights[i];
	}
	//std::cout << "copying loop done" << endl;
}

void merge_sort(vector<double>& per_unit_value, vector<int>& weights, int start, int end) {
	//std::cout << __func__ << std::endl;
	//std::cout << "start: " << start << std::endl;
	//std::cout << "end: " << end << std::endl;

	int mid = 0;
	if (end > start) {
		mid = (end - start) / 2;
		merge_sort(per_unit_value, weights, start, start + mid);
		merge_sort(per_unit_value, weights, start + mid + 1, end);
		merge(per_unit_value, weights, start, start + mid, end);
	}
}


int minimum(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
	
}


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
	int n = weights.size();
	int a = 0;
	int i=0;
	vector<double> value_per_unit(n);
	// write your code here
	for (i = 0; i < n; i++) {
		value_per_unit[i] = double(values[i]) / double(weights[i]);
	}
	//sort weights and value_per_unit as per value_per_unit
	merge_sort(value_per_unit, weights,0,n-1);

	//algorithm
	for (i = 0; i < n; i++) {
		a = minimum(weights[i], capacity);
		if (a > 0) {
			value += double(value_per_unit[i] * a);
			capacity = capacity - a;
			weights[i] = weights[i] - a;
		}
	}
	return value;
}

int main() {
	int n;
	int capacity;
	//vector<double> array_to_be_sorted(10);
	//vector<int> indices(10);
	//for (int i = 0; i < 10; i++) {
	//	array_to_be_sorted[i] = i;
	//	indices[i] = i;
	//}
	//merge_sort(array_to_be_sorted, indices, 0, 9);
	//for (int i = 0; i < 10; i++) {
	//	std:: cout << array_to_be_sorted[i] << " ";
	//}
	//std::cout << "\n";
	//for (int i = 0; i < 10; i++) {
	//	std::cout << indices[i] << " ";
	//}

	//return 0;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	//std::cout << "optima_value " << optimal_value << std::endl;
	return 0;
}