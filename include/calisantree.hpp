#ifndef CALISANTREE_HPP
#define CALISANTREE_HPP

#include "calisannode.hpp"
#include <iostream>



using namespace std;

class calisanTree {
	
	
	public:
	calisanNode* root;
	
	calisanNode* Ekle(calisanNode* calisan,int yil,string isim);
	calisanNode* solCocukIleDegistir(calisanNode* calisan);
	calisanNode* sagCocukIleDegistir(calisanNode* calisan);
	int Yukseklik(calisanNode* calisan);
	void postorder(calisanNode* calisan);
	
	
};
#endif