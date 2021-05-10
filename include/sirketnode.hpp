#ifndef sirketnode_HPP
#define sirketnode_HPP
#include "calisantree.hpp"
#include <iostream>
#include <string>

using namespace std;
class sirketNode{
	public:
	sirketNode* sag=NULL;
	sirketNode* sol=NULL;
	string sirketIsmi=" ";
	int calisanSayisi;
	int yukseklik;
	calisanTree* calisan=new calisanTree;
	
	sirketNode(){
		sag=NULL;
		sol=NULL;
		
		calisanSayisi=0;
		yukseklik=1;
	}
};


#endif