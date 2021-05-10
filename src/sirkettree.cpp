
#include "sirkettree.hpp"
#include <iostream>
#include <string>

using namespace std;
sirketTree::sirketTree(){
	root=NULL;
	
}

sirketNode* sirketTree::newNode(sirketNode* sirket){
	sirketNode* node=new sirketNode();
	node->sag=NULL;
	node->sol=NULL;
	return node;
}
int sirketTree::enBuyukGetir(sirketNode* sirket){
	int enBuyuk;
	if(sirket==NULL){
		return 1;
	}
	else{
		sirketNode* temp=sirket;
		enBuyuk=sirket->calisanSayisi;
		
		while(temp->sag!=NULL){
		temp=temp->sag;
		enBuyuk=temp->calisanSayisi;	
		}
	}
	
	
	return enBuyuk;
}
sirketNode* sirketTree::sirketBul(sirketNode* sirket,string isim,int veri){
	if(sirket == NULL) return sirket;
			if(sirket->sirketIsmi==isim) return sirket;
			else if(veri <= sirket->calisanSayisi|| veri>=sirket->calisanSayisi){
				if(sirketAra(sirket->sol,isim,veri))
					return sirketBul(sirket->sol,isim,veri);
				else
					return sirketBul(sirket->sag,isim,veri);
			}
	
}


bool sirketTree::sirketAra(sirketNode* sirket,string isim,int veri){
	if(sirket == NULL) return false;
			if(sirket->sirketIsmi==isim) return true;
			else if(veri <= sirket->calisanSayisi|| veri>=sirket->calisanSayisi){
				if(sirketAra(sirket->sol,isim,veri))
					return sirketAra(sirket->sol,isim,veri);
				else
					return sirketAra(sirket->sag,isim,veri);
			}
						
}

	
 sirketNode* sirketTree::sirketGetir(sirketNode* sirket,string isim){
		sirketNode* temp;
		int sayac=0;
		while(sayac<enBuyukGetir(sirket)+1){
			if(sirketBul(sirket,isim,sayac)->sirketIsmi==isim)
			temp=sirketBul(sirket,isim,sayac);
			sayac++;
		}
		return temp;
		
	}
	
		
int sirketTree::sirketYukseklik(sirketNode* sirket){
	if(sirket == NULL) return -1; 
	return 1+max(sirketYukseklik(sirket->sol),sirketYukseklik(sirket->sag));
}



bool sirketTree::sirketVarMi(sirketNode* sirket,string isim){
	int sayac=0;
	bool deger=true;
	while(!sirketAra(sirket,isim,sayac)){
		
		sayac++;
		if(sayac>enBuyukGetir(sirket)+1){
			
			deger=false;
			break;
		}
	}
	return deger;	
}

sirketNode* sirketTree::rrRotation(sirketNode* sirket){
	sirketNode* t;
    t = sirket->sag;
    sirket->sag = t->sol;
    t->sol = sirket;
    //cout<<"Right-Right Rotation";
    return t;
}
sirketNode* sirketTree::llRotation(sirketNode* sirket){
	sirketNode* t;
    t = sirket->sol;
    sirket->sol = t->sag;
    t->sag = sirket;
    //cout<<"Left-Left Rotation";
    return t;
}
sirketNode* sirketTree::lrRotation(sirketNode* sirket){
	sirketNode *t;
    t = sirket->sol;
    sirket->sol = rrRotation(t);
    //cout<<"Left-Right Rotation";
    return llRotation(sirket);
}
sirketNode* sirketTree::rlRotation(sirketNode* sirket){
	sirketNode *t;
    t = sirket->sag;
    sirket->sag = llRotation(t);
    //cout<<"Right-Left Rotation";
    return rrRotation(sirket);
}


sirketNode* sirketTree::sirketEkle(sirketNode* sirket,string isim,int veri){
	
	if(sirket == NULL){
		sirket = newNode(sirket);
		sirket->sirketIsmi=isim;
		sirket->calisanSayisi=veri;
				
	}
	else if(veri <= sirket->calisanSayisi){  
				sirket->sol = sirketEkle(sirket->sol,isim,veri);
				
				
				
		if(sirketYukseklik(sirket->sol) - sirketYukseklik(sirket->sag) == 2){
			// Sol Sol Durumu 
			if(veri <= sirket->sol->calisanSayisi)
				//sirket = solCocukIleDegistir(sirket); 
				sirket=llRotation(sirket);
			else{ //Sol Sağ Durumu
				//sirket->sol = sagCocukIleDegistir(sirket->sol); 
				//sirket = solCocukIleDegistir(sirket);
				sirket=lrRotation(sirket);
			}
		}
	}
	else if(veri > sirket->calisanSayisi){
		sirket->sag = sirketEkle(sirket->sag,isim,veri);
				
				
		if(sirketYukseklik(sirket->sag) - sirketYukseklik(sirket->sol) == 2){
			// Sağ Sağ Durumu
			if(veri > sirket->sag->calisanSayisi)
				sirket = rrRotation(sirket);
			else{// Sağ Sol Durumu 
				//sirket->sag = solCocukIleDegistir(sirket->sag); 
				sirket = rlRotation(sirket); 
			}
		}
	}
		
			
	//Yüksekliği güncelle		
	sirket->yukseklik = sirketYukseklik(sirket);	
	return sirket;		
	
}

sirketNode* sirketTree::calisanEkle(sirketNode* sirket,string calisanIsim,string sirketIsim,int yil){
	
	sirketNode* eklenecekSirket=new sirketNode;
	eklenecekSirket=sirketGetir(root,sirketIsim);
	eklenecekSirket->calisan->root=eklenecekSirket->calisan->Ekle(eklenecekSirket->calisan->root,yil,calisanIsim);
	eklenecekSirket->calisanSayisi++;
								
}


void sirketTree::postorder(sirketNode* sirket) 
{ 
    if (sirket!=NULL) 
   { postorder(sirket->sol); 
    postorder(sirket->sag); 
    cout <<sirket->sirketIsmi<<endl;
	
	sirket->calisan->postorder(sirket->calisan->root);
	cout<<endl;
	
  } 
}


