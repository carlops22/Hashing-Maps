#ifndef MAPG_H
#define MAPG_H

#include "ADTMap.h"
#include<vector>
#include <bits/stdc++.h>
using namespace std;


class MapG: public ADTMap{
	private:
		int N=100;
		int hash_size=N/2;	
		vector<pair<string,int>> hash_table=vector<pair<string,int>>(hash_size); //inicializa el vector con tamaño N/2
		
		unsigned long func_hash(string);
		int sizen;	
		int cols_ins;
		int cols_at;
		void rehashing();	
	public:
		MapG();
		~MapG();
		void insert(pair<string,int>);
		void erase(string);
		int at(string);
		int size();
		bool empty();
		int getCols_ins();
		int getCols_at();
};

#endif