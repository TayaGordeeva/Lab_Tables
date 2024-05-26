#pragma once
#include "Polinoms.h"
#include <list>

using namespace std;

template<typename TKey, typename TValue> class Unordered_Tables_List
{
private:
	list<Pair<TKey, TValue>> values{};
public:
	TValue* Search(TKey key) 
	{
		for (auto& i : values) 
			if (i.Key == key)
				return &i.Value;
		return nullptr;
	}

	void Insert(TKey key, TValue value) 
	{
		if (Search(key)) return;
		values.push_back({ key, value });
	}

	void Delete(TKey key) 
	{
		for (auto j = values.begin(); j != values.end(); j++)
		{
			if (j->Key == key)
			{
				values.erase(j);
				return;
			}
		}
	}
	friend ostream& operator<<(ostream& os, Unordered_Tables_List& table)
	{
		for (auto& i : table.values) {
			cout << i.TKey << " = " << i.TValue << endl;
		}
		return os;
	}
};

