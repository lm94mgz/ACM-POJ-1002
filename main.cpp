#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <cstdio>

using namespace std;

bool changeChar(string::iterator &c)
{
	switch (*c)
	{
	case '0': *c = '0'; return true;
	case '1': *c = '1'; return true;
	case 'A':
	case 'B':
	case 'C':
	case '2': *c = '2'; return true;
	case 'D':
	case 'E':
	case 'F':
	case '3': *c = '3'; return true;
	case 'G':
	case 'H':
	case 'I':
	case '4': *c = '4'; return true;
	case 'J':
	case 'K':
	case 'L':
	case '5': *c = '5'; return true;
	case 'M':
	case 'N':
	case 'O':
	case '6': *c = '6'; return true;
	case 'P':
	case 'R':
	case 'S':
	case '7': *c = '7'; return true;
	case 'T':
	case 'U':
	case 'V':
	case '8': *c = '8'; return true;
	case 'W':
	case 'X':
	case 'Y':
	case '9': *c = '9'; return true;
	default: return false;
	}
}

struct node 
{
private:
	typedef map<char, node> SubNodeType;

	SubNodeType subNodes;
	int count;

public:
	node() :count(0), subNodes() { }

	node* inputNode(char key)
	{
		SubNodeType::iterator si = subNodes.find(key);
		if (si == subNodes.end())
		{
			subNodes.insert(make_pair(key, node()));
			si = subNodes.find(key);
		}
		return &si->second;
	}

	void inputLeaf()
	{
		count++;
	}

	bool output(string &str, string::iterator &iter)
	{
		if (count > 1)
		{
			*iter = '\0';
			printf("%s %d\n", str.c_str(), count);
			return true;
		}

		bool result = false;
		for (SubNodeType::iterator si = subNodes.begin(); si != subNodes.end(); ++si)
		{
			*iter++ = si->first;
			if (si->second.output(str, iter))
			{
				result = true;
			}
			iter--;
		}
		return result;
	}
};


int main()
{
	int count;
	cin >> count;

	node root;
	string tel_str;
	for (int i = 0; i < count; ++i)
	{
		cin >> tel_str;

		int num = 0;
		node *next = &root;

		for (string::iterator word = tel_str.begin(); word != tel_str.end(); ++word)
		{
			if (changeChar(word))
			{
				next = next->inputNode(*word);
				if (++num == 3)
				{
					next = next->inputNode('-');
				}
			}
		}
		next->inputLeaf();
	}

	tel_str.assign(9, '\0');
	string::iterator si = tel_str.begin();
	if (!root.output(tel_str, si))
	{
		cout << "No duplicates." << endl;
	}
	return 0;
}
