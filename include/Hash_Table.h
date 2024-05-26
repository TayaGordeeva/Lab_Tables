#pragma once
#include "Polinoms.h"
#include <list>

using namespace std;

template <typename TKey, typename TValue> class Hash_Table
{
	private:
		int m;
		vector<list<Pair<TKey, TValue>>> values{};
	public:
		int hash_func(const string& key)
		{
			int s = 0;
			for (char i : key)
				s += static_cast<int>(i);
			return s%m;
		}

		Hash_Table() { m = 100; values.resize(m); }

		Hash_Table(int n) { m = n; values.resize(m); }

		Polynom* Search(TKey& key)
		{
			int t = hash_func(key) ;
			for (auto& i : values[t])
				if (i.Key == key)
					return &i.Value;
			return nullptr;
		}

		void Insert(TKey key, TValue val)
		{
			if (Search(key)) return;

			int i = hash_func(key);
			values[i].push_back({ key, val });
		}

		void Delete(TKey key)
		{
			int t = 0;
			int h = hash_func(key);
			for (auto i = values[h].begin(); i != values[h].end(); i++)
			{
				if (i->Key == key)
				{
					values[h].erase(i);
					return;
				}			
			}
		}

		friend ostream& operator<<(ostream& os, Hash_Table& v)
		{
			int t = 0;
			while (t < v.m) {
				for (auto& i : v.values[t]) {
					if (i.TKey != "")
						cout << i.TKey << " = " << i.TValue << endl;
				}
				t++;
			}
			return os;
		}
};

