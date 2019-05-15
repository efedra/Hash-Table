#pragma once
#include <iostream>
#include<vector>
#include<unordered_set>
#include<list>
#include<ostream>
#include <random>
#include<typeinfo>
#include<typeindex>
#include<algorithm>
#include <cmath>


template <typename T>
struct my_hash
{
    size_t operator()(T key) const
    {

        return  2000 * abs(fmod(0.618033 * key,1));
    }
};

template<typename T,typename Hash = std::hash<T>>
class HashTable
{
    int table_size = 2000;
	std::vector<std::list<T>> hashT = std::vector<std::list<T>>(table_size);
	Hash h;

public:
	HashTable(int sz,Hash hh) : table_size(sz),hashT(sz), h(hh)
	{
	
	}

    HashTable() = default;


    //Find elem
	bool find( const T elem)
	{
		int ind = h(elem);
		for (auto x : hashT[ind])
		{
			if (x == elem) return true;
		}
		return false;
	}
	//Add elem
	void add( const T  & elem ) 
	{
		int ind = h(elem);
		if (!find(elem))
		{
			hashT[ind].emplace_back(elem);
		}
	}

	//Delete elem
	void erase (const T & elem )
	{
			int ind = h(elem);
			hashT[ind].remove(elem);
	}

	//вывод в поток
	friend std::ostream& operator<<(std::ostream& os , HashTable<T,Hash> & ht)
	{
		for ( int i = 0 ; i<ht.table_size;i++)
		{
			for (auto y : ht.hashT[i])
			{
				os<<"Ind: " << i << " Hash:" <<y << std::endl;
			}

		}
		return os;
	}


};
