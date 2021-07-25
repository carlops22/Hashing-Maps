#include "MapB.h"
#include "MapG.h"
#include "MapDH.h"
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
	srand(time(NULL));
	MapB badhash;
	MapG goodhash;
	MapDH doublehash;
	int colsB_ins,colsG_ins,colsDH_ins,colsB_at,colsG_at,colsDH_at;
	cout<<"n;colsB_ins;colsG_ins;colsDH_ins;";
	cout<<"colsB_at;"<<"colsG_at;"<<"colsDH_at"<<endl;	
	int rep=20;

	for(int N=1000;N<=10000;N+=1000){
		colsB_ins=0,colsG_ins=0,colsDH_ins=0,colsB_at=0,colsG_at=0,colsDH_at=0;

			vector<int> values(N);
			vector<string> keys(N);
			int stringSize;
			MapB badhash;
			MapG goodhash;
			MapDH doublehash;

			for(int i=0 ; i<N ; ++i)
				values[i] = rand()%101+1;
			
			for(int i=0 ; i<N ; ++i){
				stringSize = 5 + rand()%10;
				while(stringSize--)
					keys[i] += (char)('a'+rand()%('z' - 'a' +1));	
			}
		

			for(int i=0 ; i<N ; ++i)
				badhash.insert(make_pair(keys[i], values[i]));
			colsB_ins=badhash.getCols_ins();

			for(int i=0 ; i<N ; ++i)
				goodhash.insert(make_pair(keys[i], values[i]));
			colsG_ins=goodhash.getCols_ins();


			for(int i=0 ; i<N ; ++i)
				doublehash.insert(make_pair(keys[i], values[i]));
			colsDH_ins=doublehash.getCols_ins();
		

			for(int i=0 ; i<N ; ++i)
				badhash.at(keys[rand()%N]);
		
			colsB_at=badhash.getCols_at();
			for(int i=0 ; i<N ; ++i)
				goodhash.at(keys[rand()%N]);
		
			colsG_at=goodhash.getCols_at();
			for(int i=0 ; i<N ; ++i)
				doublehash.at(keys[rand()%N]);
	
			colsDH_at=doublehash.getCols_at();

		cout<<N<<";"<<colsB_ins<<";"<<colsG_ins<<";"<<colsDH_ins<<";"<<colsB_at<<";"<<colsG_at<<";"<<colsDH_at<<endl;
	}	
	return 0;
}