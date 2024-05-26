#pragma once
#include "Polinoms.h"

using namespace std;

template <typename TKey, typename TValue> class OrderedTables
{
private:
	vector<Pair<TKey, TValue>> values{};
public:
	TValue* Search(TKey key)
	{
		int left = 0;
		int right = values.size() - 1;
		while ((left <= right) and (left >= 0))
		{
			int median = (left + right) / 2;

			if (values[median].Key > key)
				right = median - 1;

			else if (values[median].Key < key)
				left = median + 1;

			else if (values[median].Key == key)
				return (&(values[median].Value));
		}
		return nullptr;
	}

	void Insert(TKey key, TValue val)
	{
		int median = -1;
		int left = 0;
		int right = values.size() - 1;
		while ((left <= right) and (left >= 0))
		{
			int median = (left + right) / 2;

			if (values[median].Key > key)
				right = median - 1;

			else if (values[median].Key < key)
				left = median + 1;

			else if (values[median].Key == key)
				return;
		}

		Pair<TKey, TValue> tmp = { key, val };
		if (median == -1)
			values.push_back(tmp);
		else 
			if (values[median].Key > key)
				values.insert(values.begin() + median, tmp);
			else
				values.insert(values.begin() + median + 1, tmp);
	}

	void Delete(TKey key)
	{
		int left = 0;
		int right = values.size() - 1;
		while ((left <= right) and (left >= 0))
		{
			int median = (left + right) / 2;

			if (values[median].Key > key)
				right = median - 1;

			else if (values[median].Key < key)
				left = median + 1;

			else if (values[median].Key == key)
			{
				values.erase(values.begin() + median);
				return;
			}
		}
		return;
	}

	friend ostream& operator<<(ostream& os, OrderedTables& table)
	{
		for (auto& i : table.values) {
			cout << i.TKey << " = " << i.TValue << endl;
		}
		return os;
	}
};

