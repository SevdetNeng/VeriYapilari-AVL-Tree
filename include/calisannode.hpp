#ifndef calisannode_HPP
#define calisannode_HPP
#include <iostream>
#include <string>





using namespace std;

class calisanNode{
	public:
	
	string isim;
	int calisanYil;
	int yukseklik;
	calisanNode* sag=NULL;
	calisanNode* sol=NULL;
	
	calisanNode(){
		sag=NULL;
		sol=NULL;
		calisanYil=0;
		yukseklik=1;
		
	}
		
	
};
#endif