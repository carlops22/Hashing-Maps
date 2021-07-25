#ifndef MAPB_H
#define MAPB_H

#include "ADTMap.h"
#include<vector>
#include <bits/stdc++.h>
using namespace std;


class MapB: public ADTMap{
	private:
		int N=100;
		int hash_size=N/2;	
		vector<pair<string,int>> hash_table=vector<pair<string,int>>(hash_size);
		int func_hash(string);
		int sizen;	
		int cols_ins;
		int cols_at;
		void rehashing();		
	
	public:
		MapB();
		~MapB();
		void insert(pair<string,int>);
		void erase(string);
		int at(string);
		int size();
		bool empty();
		int getCols_ins();
		int getCols_at();
};

#endif