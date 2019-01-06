#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;
using std::vector;

// comments verbose format
//#define VERBOSE 1

#ifdef VERBOSE 
#define PRINT_VERBOSE(...) cout __VA_ARGS__
#else
#define PRINT_VERBOSE(...)
#endif

struct Segment {
	int start, end;
};

void copy(Segment& src, Segment& dest) {
	Segment dummy = src;
	src = dest;
	dest = dummy;
}

void merge(vector<Segment>& array_to_be_sorted, int start, int mid, int end) {
	PRINT_VERBOSE(<< __func__ << std::endl);
	PRINT_VERBOSE(<< "start: " << start << std::endl);
	PRINT_VERBOSE(<< "mid: " << mid << std::endl);
	PRINT_VERBOSE(<< "end: " << end << std::endl);

	std::vector<Segment> dummy_per_unit_value(end - start + 1);

	int i = start, j = mid + 1;
	int k = 0;
	while (i < mid + 1 && j < end + 1) {
		PRINT_VERBOSE(<< i << " " << j << std::endl);
		if (array_to_be_sorted[i].end < array_to_be_sorted[j].end) {
			PRINT_VERBOSE(<< "1st array value is greater");
			copy(dummy_per_unit_value[k], array_to_be_sorted[i]);
			/*dummy_per_unit_value[k].end = array_to_be_sorted[i].end;
			dummy_per_unit_value[k].start = array_to_be_sorted[i].start*/;
			i++;
			k++;
		}
		else {
			PRINT_VERBOSE(<< "2nd array value is greater");
			copy(dummy_per_unit_value[k], array_to_be_sorted[j]);/*
			dummy_per_unit_value[k].end = array_to_be_sorted[j].end;
			dummy_per_unit_value[k].start = array_to_be_sorted[j].start;*/
			j++;
			k++;
		}
	}
	PRINT_VERBOSE(<< "1st loop done" << endl);
	while (i < mid + 1) {
		PRINT_VERBOSE(<< i << endl);
		copy(dummy_per_unit_value[k], array_to_be_sorted[i]);
		//dummy_per_unit_value[k].end = array_to_be_sorted[i].end;
		//dummy_per_unit_value[k].start = array_to_be_sorted[i].start;
		i++;
		k++;
	}
	PRINT_VERBOSE(<< "i loop done" << endl);
	while (j < end + 1) {
		PRINT_VERBOSE(<< j << endl);
		copy(dummy_per_unit_value[k], array_to_be_sorted[j]);/*
		dummy_per_unit_value[k].end = array_to_be_sorted[j].end;
		dummy_per_unit_value[k].start = array_to_be_sorted[j].start;*/
		j++;
		k++;
	}
	PRINT_VERBOSE(<< "j loop done" << endl);
	for (i = 0; i < (end - start + 1); i++) {
		copy(array_to_be_sorted[start + i], dummy_per_unit_value[i]);
		//array_to_be_sorted[j].end= dummy_per_unit_value[k].end;
		//array_to_be_sorted[j].start=dummy_per_unit_value[k].start;
	}
	PRINT_VERBOSE(<< "copying loop done" << endl);
}

void merge_sort(vector<Segment>& array_to_be_sorted, int start, int end) {
	PRINT_VERBOSE(<< __func__ << std::endl);
	PRINT_VERBOSE(<< "start: " << start << std::endl);
	PRINT_VERBOSE(<< "end: " << end << std::endl);

	int mid = 0;
	if (end > start) {
		mid = (end - start) / 2;
		merge_sort(array_to_be_sorted, start, start + mid);
		merge_sort(array_to_be_sorted, start + mid + 1, end);
		merge(array_to_be_sorted, start, start + mid, end);
	}
}

vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
	size_t i = 0;
	int key=0;
	//write your code here

	//sort here
	merge_sort(segments, 0, segments.size() - 1);

	//greddy algo here
	while (i < segments.size()) {
		key = segments[i].end;
		i = i + 1;
		while (i<segments.size() && key >= segments[i].start)
			i = i + 1;
		points.push_back(key);
	}

	/*for (size_t i = 0; i < segments.size(); ++i) {
		points.push_back(segments[i].start);
		points.push_back(segments[i].end);
	}*/
	return points;
}

int main() {
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
}
