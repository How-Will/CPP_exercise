#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vi{1, 3, 5, 7, 8, 9};

	auto iter = vi.begin();
	while (iter != vi.end()) {
		if (*iter % 2) {
			iter = vi.insert(iter, *iter);	//插入到迭代器之前的位置
			iter += 2;
		}
		else
			++iter;
	}

	for (auto i : vi)
		cout << i << " ";
	cout << endl;

	return 0;
}