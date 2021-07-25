#include "MapB.h"
using namespace std;

MapB::MapB(){
	sizen=0;
	cols_ins=0;
	cols_at=0;
}

MapB::~MapB(){
}
int MapB::func_hash(string k){
    char ch[k.size()+1];
    strcpy(ch,k.c_str());
    int i, sum;
    for (sum=0, i=0; i < k.length(); i++)
		sum += ch[i];
    return sum % hash_size;
}
void MapB::rehashing(){
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
void MapB::insert(pair<string,int> par){
	if(sizen==hash_size/2){
		rehashing();
	}
	int hashPos=func_hash(par.first); //valor de posicion a guardar 
	int tempPos=hashPos;
	
	for(int i= 0;i<hash_size;i++){

		if(hash_table[tempPos].first=="AVAILABLE" || (hash_table[tempPos].first.size()==0 && hash_table[tempPos].second==0)){
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

void MapB::erase(string k){
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
int MapB::at(string k){
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
int MapB::size(){
	return sizen;
}

bool MapB::empty(){
	if(!sizen)
		return true;
	return false;
}	


int MapB::getCols_ins(){
	return cols_ins;
}

int MapB::getCols_at(){
	return cols_at;
}
