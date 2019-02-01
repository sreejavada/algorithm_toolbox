#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <ctime>

// comments verbose format
#define VERBOSE 1

#ifdef VERBOSE 
#define PRINT_VERBOSE(...) cout __VA_ARGS__
#else
#define PRINT_VERBOSE(...)
#endif

using std::vector;
using namespace std;


vector<int> optimal_sequence(int n) {
	vector<int> count_operations(n+1, numeric_limits<int>::max());
	vector<int> sequence;
	
	int level = 1;
	bool BREAK_FLAG = 0;
	vector<int> stack;
	
	stack.push_back(1);

	int tmp;
	count_operations[0] = 0;
	count_operations[1] = 0;

	//vector<int> stack_tmp;
	//int iterator = 2;
	//while (iterator <= n) {
	//	//copy stack to a tmp
	//	stack_tmp.assign(stack.begin(), stack.end());
	//	stack.clear();
	//	for (size_t i = 0; i < stack_tmp.size(); i++) {
	//			count_operations[stack_tmp[i]] = min(level, count_operations[stack_tmp[i]]);
	//			if (stack_tmp[i] == n) {
	//				PRINT_VERBOSE(<< "breakin" << endl);
	//				BREAK_FLAG = 1;
	//				break;
	//			}
	//			if (stack_tmp[i] * 2 <= n)
	//				stack.push_back(stack_tmp[i] * 2);
	//			if (stack_tmp[i] * 3 <= n)
	//				stack.push_back(stack_tmp[i] * 3);
	//			if ((stack_tmp[i] + 1) <= n)
	//				stack.push_back(stack_tmp[i] + 1);
	//	}
	//	if (BREAK_FLAG == 1)
	//		break;
	//	level++;
	//	iterator++;
	//}


	//loop untill stack is empty
	clock_t begin = clock();
	while (stack.size() != 0) {
		tmp = stack[0];
		PRINT_VERBOSE(<< "tmp:" << tmp << endl);
		stack.erase(stack.begin());
		if ((tmp == n) || (tmp + 1 == n) || (tmp * 2 == n) || (tmp * 3 == n))
			BREAK_FLAG = 1;
		if ((tmp + 1 <= n) && (level < count_operations[tmp + 1])) {
			stack.push_back(tmp + 1);
			count_operations[tmp + 1] = level;
		}
		if ((tmp * 2 <= n) && (level < count_operations[tmp * 2])){
			stack.push_back(tmp * 2);
			count_operations[tmp * 2] = level;
		}
		if ((tmp * 3 <= n) && (level < count_operations[tmp * 3])){
			stack.push_back(tmp * 3);
			count_operations[tmp * 3] = level;
		}
		level++;
		if (BREAK_FLAG == 1)
			break;
	}


	PRINT_VERBOSE(<< count_operations[n]);
	PRINT_VERBOSE(<< endl);

	clock_t end = clock();
	cout << "1: " << (double(end - begin) / CLOCKS_PER_SEC) << endl;
	
	//get sequence -- backtrace
	int i = n;
	vector<int> tmp_ints(3);
	int index;
	
	sequence.push_back(n);
	while (i != 1) {
		tmp_ints[0] = count_operations[i - 1];
		if (i % 2 == 0)
			tmp_ints[1] = count_operations[i / 2];
		else
			tmp_ints[1] = numeric_limits<int>::max();
		if (i % 3 == 0)
			tmp_ints[2] = count_operations[i / 3];
		else
			tmp_ints[2] = numeric_limits<int>::max();
		index = std::min_element(tmp_ints.begin(), tmp_ints.end()) - tmp_ints.begin();
		switch (index)
		{
		case 0: i = i - 1;
				break;
		case 1:	i = i / 2;
				break;
		case 2:	i = i / 3;
				break;
		default:
			break;
		}

		sequence.push_back(i);
	}
	clock_t end2 = clock();
	cout << "2: " << (double(end2 - end) / CLOCKS_PER_SEC) << endl;
	reverse(sequence.begin(), sequence.end());
	return sequence;
}
vector<int> dynamic_sequence(int n) {
	vector<int> a(n + 1);
	vector<int> predecessor(n + 1);

	for (int i = 2; i <= n; i++) {
		a[i] = a[i - 1] + 1;
		predecessor[i] = i - 1;
		if (i % 3 == 0) {
			if (a[i / 3] < a[i]) {
				a[i] = a[i / 3] + 1;
				predecessor[i] = i / 3;
			}
		}
		if (i % 2 == 0) {
			if (a[i / 2] < a[i]) {
				a[i] = a[i / 2] + 1;
				predecessor[i] = i / 2;
			}
		}
	}

	vector<int> sequence;

	for (int i = n; i != 0; i = predecessor[i]) {
		sequence.push_back(i);
	}
	reverse(sequence.begin(), sequence.end());
	return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);

//  vector<int> sequence = dynamic_sequence(n);

  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }

}
