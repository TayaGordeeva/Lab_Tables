#pragma once
#include "Polinoms.h"

using namespace std;

template <typename TKey, typename TValue> class UnorderedTables
{
private:
	vector<Pair<TKey, TValue>> values{};
public:
	TValue* Search(TKey key)
	{
		for (auto& i:values)
			if (i.Key == key)
				return &i.Value;
		return nullptr;
	}

	void Insert(TKey key, TValue val)
	{
		if (Search(key)) return;
		values.push_back({key, val});
	}

	void Delete(TKey key)
	{
		int i = 0;
		for (auto& j:values)
		{
			if (j.Key == key)
			{
				values.erase(values.begin() + i);
				break;
			}
			i++;
		}
		return;
	}

	friend ostream& operator<<(ostream& os, UnorderedTables& table)
	{
		for (auto& i : table.values) {
			cout << i.TKey << " = " << i.TValue << endl;
		}
		return os;
	}

};

