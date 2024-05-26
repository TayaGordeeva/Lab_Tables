#pragma once
#include "Polinoms.h"

using namespace std;

class AVL_Tree
{
	private:
		struct TreeNode
	{
		string key;
		Polynom p;
		TreeNode* left, * right;
		int height;

		TreeNode(const string& key, Polynom& p) : key(key), p(p), left(nullptr), right(nullptr), height(1) {}
	};
	

		TreeNode* root;

		string Key(TreeNode* n)
		{
			return n->key;
		}

		int Height(TreeNode* n)
	{
		if (n == nullptr) return 0;
		else return n->height;
	}

		int Balance(TreeNode* n)
	{
		if (n == nullptr) return 0;
		else return (Height(n->left) - Height(n->right));
	}

		TreeNode *Left(TreeNode* l)
	{
		TreeNode* l1 = l->right;
		TreeNode* t = l1->left;

		l1->left = l;
		l->right = t;

		l->height = max(Height(l->left), Height(l->right)) + 1;
		l1->height = max(Height(l1->left), Height(l1->right)) + 1;

		return l1;
	}

		TreeNode* Right(TreeNode* r)
	{
		TreeNode* r1 = r->left;
		TreeNode* t = r1->right;

		r1->right = r;
		r->left = t;

		r->height = max(Height(r->left), Height(r->right)) + 1;
		r1->height = max(Height(r1->left), Height(r1->right)) + 1;

		return r1;
	}

		TreeNode* MinNode(TreeNode* n)
	{
		TreeNode* t = n;
		while (t->left != nullptr)
			t = t->left;

		return t;
	}

		TreeNode* Search_Tree(TreeNode* n, const string& key)
	{
		while ((n != nullptr) and (key != n->key))
			if (key < n->key) n = n->left;
			else n = n->right;

		return n;
	}

		TreeNode* Insert_Tree(TreeNode* n, const string& key, Polynom p)
	{
		if (!n) return new TreeNode(key, p);

		if (key < n->key)
			n->left = Insert_Tree(n->left, key, p);
		else if (key > n->key)
			n->right = Insert_Tree(n->right, key, p);
		else
			n->p = p;

		n->height = max(Height(n->left), Height(n->right)) + 1;
		int bal = Balance(n);

		if ((bal > 1) and (key < (n->left)->key))
			return Right(n);

		if ((bal < -1) and (key > (n->right)->key))
			return Left(n);

		if ((bal > 1) and (key > (n->left)->key))
		{
			n->left = Left(n->left);
			return Right(n);
		}

		if ((bal < -1) and (key < (n->right)->key))
		{
			n->right = Right(n->right);
			return Left(n);
		}
		return n;
	}

		TreeNode* Delete_Tree(TreeNode* n, const string& key)
	{
		if (!n) return n;

		if (key < n->key)
			n->left = Delete_Tree(n->left, key);
		else if (key > n->key)
			n->right = Delete_Tree(n->right, key);
		else
		{
			if ((!n->left) or (!n->right))
			{
				TreeNode* t = n->left ? n->left : n->right;
				if (!t)
				{
					t = n;
					n = nullptr;
				}
				else
					*n = *t;
				delete t;
			}
			else
			{
				TreeNode* t = MinNode(n->right);
				n->key = t->key;
				n->p = t->p;
				n->right = Delete_Tree(n->right, t->key);
			}
		}

		if (!n) return n;

		n->height = max(Height(n->left), Height(n->right)) + 1;
		int bal = Balance(n);

		if ((bal > 1) and (Balance(n->left)>=0))
			return Right(n);

		if ((bal < -1) and (Balance(n->right) <= 0))
			return Left(n);

		if ((bal > 1) and (Balance(n->left) >= 0))
		{
			n->left = Left(n->left);
			return Right(n);
		}

		if ((bal < -1) and (Balance(n->right) > 0))
		{
			n->right = Right(n->right);
			return Left(n);
		}
		return n;
	}

		void Print_Tree(TreeNode* n)
	{
		if (n != nullptr)
		{
			Print_Tree(n->left);
			cout << n->key << ": ";
			n->p.Print();
			cout << "\n";
			Print_Tree(n->right);
		}
		else cout << "not found\n";
	}

	public:
		AVL_Tree(): root(nullptr) {}

		Polynom *Search(const string& key)
		{
			if (root != nullptr)
			{
				TreeNode* n = Search_Tree(root, key);
				if (n != nullptr)
					return &n->p;
				else
					return nullptr;
			}
			else return nullptr;
		}

		void Insert(const string& key, Polynom& p)
		{
			root = Insert_Tree(root, key, p);
		}

		void Delete_1(TreeNode* n)
		{
			if (n == nullptr) return;

			Delete_1(n->left);
			Delete_1(n->right);
			delete n;
		}
		
		void Delete(string key)
		{
			TreeNode* n = Search_Tree(root, key);
			if (n == nullptr) return;

			Delete_1(n->left);
			Delete_1(n->right);
			root->key = "";
			
		}
		
		~AVL_Tree()
		{
			Delete_1(root);
		}

		void Print()
		{
			Print_Tree(root);
		}
};

