// lab_tables

#include <iostream>
#include"Polinoms.h"
#include "UnorderedTables.h"
#include "OrderedTables.h"
#include "AVLTreeTable.h"
#include "Hash_Table.h"
#include "Unordered_Tables_List.h"

template<typename T>
void help(T* table)
{
	bool fl = true;
	while (fl)
	{
		cout << "1. Insert polynom into a table\n";
		cout << "2. Search polynom in a table\n";
		cout << "3. Delete polynom from a table\n";
		cout << "4. Operations with polynoms (you need have 2 polynoms)\n";
		cout << "5. Exit\n";

		int count;
		cin >> count;

		if (count == 5) fl=false;

		switch (count)
		{
		default:
			break;

		case 1:
		{
			string n, p;
			cout << "Polynom and its name: ";
			cin >> p, n;

			Polynom pol1(p);
			table->Insert(n, pol1);
			cout << "\n";
			break;
		}

		case 2:
		{
			string n;
			cout << "Name of polynom: ";
			cin >> n;
			auto t = table->Search(n);
			if (t == nullptr) cout << "Not found this polynom\n";
			else 
			{
				(*(t)).Print();
				cout << "\n";
			}
			break;
		}

		case 3:
		{
			string n;
			cout << "Name of polynom: ";
			cin >> n;
			table->Delete(n);
			cout << "Done!\n";
			break;
		}

		case 4:
		{
			string n1, n2;
			cout << "Names of polynoms: ";
			cin >> n1, n2;
			double x, y, z, c;
			cout << "Const: ";
			cin >> c;
			cout << "Point(x, y, z): ";
			cin >> x;
			cin >> y;
			cin >> z;

			auto p1 = table->Search(n1);
			auto p2 = table->Search(n2);
			if (p1 == nullptr or p2 == nullptr)
				cout << "not found\n";
			else
			{
				Polynom pol1 = (*p1);
				Polynom pol2 = (*p2);
				
				Polynom p3 = pol1 + pol2;
				cout << "("; pol1.Print(); cout << ") + ("; pol2.Print(); cout << ") = "; p3.Print();
				cout << "\n";

				Polynom p4 = pol1 - pol2;
				cout << "("; pol1.Print(); cout << ") - ("; pol2.Print(); cout << ") = "; p4.Print();
				cout << "\n";

				Polynom p5 = pol1 * c;
				Polynom p6 = pol2 * c;
				cout << "("; pol1.Print(); cout << ") * " << c << " = "; p5.Print();
				cout << "\n";
				cout << "("; pol2.Print(); cout << ") * " << c << " = "; p6.Print();
				cout << "\n";

				Polynom p7 = pol1 * pol2;
				cout << "("; pol1.Print(); cout << ") * ("; pol2.Print(); cout << ") = "; p7.Print();
				cout << "\n";

				double a1 = pol1.value_pol(x, y, z);
				double a2 = pol2.value_pol(x, y, z);
				pol1.Print(); cout << "(" << x << ", " << y << ", " << z << ") = " << a1 << "\n";
				pol2.Print(); cout << "(" << x << ", " << y << ", " << z << ") = " << a2 << "\n\n";
			}
			break;
		}

		}
	}
}

void main()
{
	UnorderedTables<string, Polynom> un_tab;
	cout << "Hello! Type of Tables: \n\n";
	cout << "1) Unordered Table (on vector)\n";
	help(&un_tab);

	Unordered_Tables_List<string, Polynom> un_list_tab;
	cout << "2) Unordered Table (on list)\n";
	help(&un_list_tab);

	OrderedTables<string, Polynom> or_tab;
	cout << "\n3) Ordered Table (on vector)\n";
	help(&or_tab);

	AVL_Tree avl_tab;
	cout << "\n4) AVL Tree\n";
	help(&avl_tab);

	Hash_Table<string, Polynom> hash_table;
	cout << "\n5) Hash Table\n";
	help(&hash_table);
}