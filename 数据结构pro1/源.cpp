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

//Dalaoд��cmp����
struct Compare
{
	bool operator()(const stack<int> &A, const stack<int> &B) const
	{
		return A.top() < B.top();
	}
};
//ջ
set < stack<int> ,Compare> mySet;

//���Һ������鿴i�ڲ���ջ��
bool Find(int i);
//���뺯������һ��������ջ��
void Insert(int i);
int main()
{
	//���벿��
	queue <int> num;
	int temp = 0;
	while (cin >> temp)
	{
		num.push(temp);
	}

	int n = num.size();

	//��1�ų���ʼ
	int i = 1;
	while(i<=n)
	{
		//�����ǰ�ĵ�һ������������Ѱ�ҵ�i��ֱ�����
		if (!num.empty()|| num.front() == i)
		{
			num.pop();
			cout << i << endl;
			++i;
			continue;
		}
		//������ջ����i������ҵ������
		if (Find(i))
		{
			cout << i << endl;
			++i;
			continue;
		}
		//�����еĵ�һ��Ԫ�ز��뵽ջ��
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