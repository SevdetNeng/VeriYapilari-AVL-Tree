#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "sirketnode.hpp"
#include "calisantree.hpp"
#include <iostream>
using namespace std;
class sirketTree {
	public:
	sirketNode* root=new sirketNode();
	sirketTree();
	
	sirketNode* sirketEkle(sirketNode* sirket,string sirketIsmi,int veri);	
	sirketNode* sirketGetir(sirketNode* sirket,string isim);	
	int sirketYukseklik(sirketNode* sirket);
	bool sirketAra(sirketNode* sirket,string isim,int veri);
	bool sirketVarMi(sirketNode* sirket,string isim);
	sirketNode* rrRotation(sirketNode* sirket);
	sirketNode* llRotation(sirketNode* sirket);
	sirketNode* rlRotation(sirketNode* sirket);
	sirketNode* lrRotation(sirketNode* sirket);
	int enBuyukGetir(sirketNode* sirket);
	sirketNode* sirketBul(sirketNode* sirket,string isim,int veri);
	sirketNode* calisanEkle(sirketNode* sirket,string calisanIsim,string sirketIsim,int yil);
	void postorder(sirketNode* sirket);
	sirketNode* newNode(sirketNode* sirket);
	
};
#endif
