#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <cstdio>

using namespace std;

int changeChar(char c)
{
	switch (c)
	{
	case '0': return 0;
	case '1': return 1;
	case 'A':
	case 'B':
	case 'C':
	case '2': return 2;
	case 'D':
	case 'E':
	case 'F':
	case '3': return 3;
	case 'G':
	case 'H':
	case 'I':
	case '4': return 4;
	case 'J':
	case 'K':
	case 'L':
	case '5': return 5;
	case 'M':
	case 'N':
	case 'O':
	case '6': return 6;
	case 'P':
	case 'R':
	case 'S':
	case '7': return 7;
	case 'T':
	case 'U':
	case 'V':
	case '8': return 8;
	case 'W':
	case 'X':
	case 'Y':
	case '9': return 9;
	default: return -1;
	}
}

typedef unsigned int TelNumberType;
typedef unsigned int CountType;
typedef map<TelNumberType, CountType> TelNumberContainer;

void telNumber2Str(TelNumberType num, string &str)
{
	str.assign(8, '0');
	string::reverse_iterator si = str.rbegin();
	for (int i = 7; i > 0; --i)
	{
		*si++ = int(num % 10) + '0';
		num /= 10;
		if (i == 4)
		{
			*si++ = '-';
		}
	}
}

int main()
{
	int count;
	cin >> count;

	TelNumberContainer telNumberCount;

	string telStr;
	TelNumberType telNumber;
	for (int i = 0; i < count; ++i)
	{
		cin >> telStr;
		telNumber = 0;
		for (string::iterator si = telStr.begin(); si != telStr.end(); ++si)
		{
			int num = changeChar(*si);
			if (num >= 0)
			{
				telNumber *= 10;
				telNumber += num;
			}
		}
		if (telNumberCount.find(telNumber) == telNumberCount.end())
		{
			telNumberCount.insert(make_pair(telNumber, 1));
		}
		else
		{
			telNumberCount[telNumber]++;
		}
	}

	bool noDuplicates = true;
	for (TelNumberContainer::iterator ti = telNumberCount.begin(); ti != telNumberCount.end(); ++ti)
	{
		if (ti->second > 1)
		{
			noDuplicates = false;
			telNumber2Str(ti->first, telStr);
			printf("%s %d\n", telStr.c_str(), ti->second);
		}
	}

	if (noDuplicates)
	{
		cout << "No duplicates." << endl;
	}
	return 0;
}
