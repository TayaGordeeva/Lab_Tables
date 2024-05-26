#pragma once
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename K, typename V> struct Pair {
	K Key;
	V Value;

	friend auto operator<(const Pair& a, const Pair& b)
	{
		return a.V< b.V;
	}
	friend auto operator<=(const Pair& a, const Pair& b)
	{
		return a.V <= b.V;
	}
	friend auto operator>(const Pair& a, const Pair& b)
	{
		return a.V > b.V;
	}
	friend auto operator>=(const Pair& a, const Pair& b)
	{
		return a.V <= b.V;
	}
	friend bool operator==(const Pair& a, const Pair& b)
	{
		if ((a.V == b.V) && (a.K == b.K))
			return(true);
		else
			return(false);
	}
	friend bool operator!=(const Pair& a, const Pair& b)
	{
		if ((a.V < b.V) && (a.K == b.K))
			return(false);
		else
			return(true);
	}
};

struct Monom
{
	int value;//значение степеней
	int coeff;//коэффициент
	Monom* pNext;//индекс следующего звена

	Monom(int v, int c) : value(v), coeff(c), pNext(nullptr) {}
};

class Iterator {
private:
	Monom* f;
public:
	Iterator(Monom* f = nullptr) : f(f) {}

	Monom& operator*()
	{
		return *f;
	};

	Iterator& operator++()
	{
		if (f) f = f->pNext;
		return *this;
	};

	bool operator!=(const Iterator& p)
	{
		return f != p.f;
	};
};

class Polynom {
private:
	Monom* pFirst;
public:
	Polynom() : pFirst(nullptr) {};

	Polynom(string polynom);

	~Polynom()
	{
		pFirst = nullptr;
	};

	void AddMonom(int coef, int deg);

	Polynom operator+(const Polynom& p) const;

	Polynom operator-(const Polynom& p) const;

	Polynom operator*(const Polynom& p) const;

	Polynom operator*(double c) const;

	double value_pol(double x1, double y1, double z1) const;

	bool operator ==(const Polynom& p) const;


	Iterator begin();

	Iterator end();

	void Print();
};

