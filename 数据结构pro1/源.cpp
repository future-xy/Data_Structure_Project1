#include<iostream>
#include<set>
#include<queue>
#include<stack>

using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::stack;
using std::queue;

//Dalao写的cmp函数
struct Compare
{
	bool operator()(const stack<int> &A, const stack<int> &B) const
	{
		return A.top() < B.top();
	}
};
//栈
set < stack<int> ,Compare> mySet;

//查找函数，查看i在不在栈中
bool Find(int i);
//插入函数，将一个数插入栈中
void Insert(int i);
int main()
{
	//输入部分
	queue <int> num;
	int temp = 0;
	while (cin >> temp)
	{
		num.push(temp);
	}

	int n = num.size();

	//从1号车开始
	int i = 1;
	while(i<=n)
	{
		//如果当前的第一个车就是正在寻找的i，直接输出
		if (!num.empty()|| num.front() == i)
		{
			num.pop();
			cout << i << endl;
			++i;
			continue;
		}
		//尝试在栈中找i，如果找到则输出
		if (Find(i))
		{
			cout << i << endl;
			++i;
			continue;
		}
		//将队列的第一个元素插入到栈中
		int temp = num.front();
		num.pop();
		Insert(temp);
		
	}

	return 0;
}
bool Find(int i)
{
	stack <int> temp;
	temp.push(i);
	auto item = mySet.lower_bound(temp);
	if (item==mySet.end() || item->top() != i)
	{
		return false;
	}
	else
	{
		temp = (*item);
		temp.pop();
		mySet.erase(item);
		mySet.insert(temp);
		return true;
	}
}

void Insert(int i)
{
	stack <int> temp;
	temp.push(i);
	auto item = mySet.upper_bound(temp);
	if (item == mySet.end())
	{
		mySet.insert(temp);
	}
	else
	{
		stack <int> temp = (*item);
		temp.push(i);
		mySet.erase(item);
		mySet.insert(temp);
	}
}