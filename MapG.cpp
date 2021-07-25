#include "MapG.h"
#include<vector>
using namespace std;


MapG::MapG(){
	sizen=0;
	cols_ins=0;
	cols_at=0;
}

MapG::~MapG(){
}
unsigned long MapG::func_hash(string k){
	unsigned long sum=0;
    int z = 31;    
    for (char c : k) 
        sum = sum * z + int(c);    
    return sum%hash_size;
}
void MapG::rehashing(){
	hash_size=hash_size*2;
	vector<pair<string,int>> hash_temp=hash_table;
	hash_table.clear();
	hash_table.resize(hash_size);
	for(int i=0; i<hash_size/2;i++){
		if(!(hash_temp[i].first=="AVAILABLE" || (hash_temp[i].first.size()==0 && hash_temp[i].second==0))){
			int hashPos=func_hash(hash_temp[i].first);
			hash_table[hashPos]=hash_temp[i];
		}			
	}
}
void MapG::insert(pair<string,int> par){
	if(sizen==hash_size/2){
		rehashing();
	}
	int hashPos=func_hash(par.first); //valor de posicion a guardar 
	int tempPos=hashPos;
	for(int i= 0;i<hash_size;i++){
		if(hash_table.at(tempPos).first=="AVAILABLE" || (hash_table[tempPos].first.size()==0 && hash_table[tempPos].second==0)){
				hash_table[tempPos]=make_pair(par.first,par.second);
				sizen++;
				break;
		}
		if(par.first.compare(hash_table[tempPos].first)==0){
			cols_ins++;
			hash_table[tempPos].second=par.second;
			return;			
		}
		cols_ins++;
		tempPos=(tempPos+1)%hash_size;
	}
	return;
}

void MapG::erase(string k){
	int hashPos=func_hash(k);
	int tempPos=hashPos;
	for(int i=0;i<hash_size;i++){
		if(k.compare(hash_table[tempPos].first)==0){
			hash_table[tempPos].first="AVAILABLE";
			sizen--;
		}
		tempPos=(tempPos+1)%hash_size;
	}
}
int MapG::at(string k){
	int hashPos=func_hash(k);
	for(int i=0;i<hash_size;i++){
		if(hash_table[hashPos].first.size()==0 && hash_table[hashPos].second==0)
			return INT_MAX; //no se encontro el valor con esa llave
		else if(hash_table[hashPos].first==k){
			return hash_table[hashPos].second;
		}
		else{
			hashPos=(hashPos+1)%hash_size;
			cols_at++;
		}		
	}
	return INT_MAX; //no se encontro valor con esa llave
}
int MapG::size(){
	return sizen;
}

bool MapG::empty(){
	if(!sizen)
		return true;
	return false;
}	


int MapG::getCols_ins(){
	return cols_ins;
}

int MapG::getCols_at(){
	return cols_at;
}
