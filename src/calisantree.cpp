#include "calisantree.hpp"
#include <iostream>
#include <string>


using namespace std;




int calisanTree::Yukseklik(calisanNode* calisan){
	if(calisan == NULL) return -1; // Ortada düğüm yoksa yükseklik anlamsızdır. Kodun çalışması adına -1 verilmektedir.
			return 1+max(Yukseklik(calisan->sol),Yukseklik(calisan->sag));
}

calisanNode* calisanTree::solCocukIleDegistir(calisanNode* calisan){
	calisanNode* tmp = calisan->sol; 
			calisan->sol = tmp->sag; 		  
			tmp->sag = calisan; 
		  
			// Yükseklikleri Güncelle 
			calisan->yukseklik = Yukseklik(calisan); 
			tmp->yukseklik = max(Yukseklik(tmp->sol),calisan->yukseklik)+1;
			
			return tmp;
	
}

calisanNode* calisanTree::sagCocukIleDegistir(calisanNode* calisan){
	calisanNode* tmp = calisan->sag; 
			calisan->sag = tmp->sol;
			tmp->sol = calisan;
		  
			// Yükseklikleri Güncelle 
			calisan->yukseklik = Yukseklik(calisan); 
			tmp->yukseklik = max(Yukseklik(tmp->sag),calisan->yukseklik)+1;

			return tmp;
}





calisanNode* calisanTree::Ekle(calisanNode* calisan,int yil,string isim){
		if(calisan == NULL){
				calisan = new calisanNode;
				calisan->calisanYil=yil;
				calisan->isim=isim;

				
			}
			else if(yil >= calisan->calisanYil){
				calisan->sol = Ekle(calisan->sol,yil,isim);
				
				if(Yukseklik(calisan->sol) - Yukseklik(calisan->sag) == 2){
					// Sol Sol Durumu 
					if(yil >= calisan->sol->calisanYil)
						calisan = solCocukIleDegistir(calisan); 
					else{ //Sol Sağ Durumu
						calisan->sol = sagCocukIleDegistir(calisan->sol); 
						calisan = solCocukIleDegistir(calisan);
					}
				}
			}
			else if(yil < calisan->calisanYil){
				calisan->sag = Ekle(calisan->sag,yil,isim);
				
				if(Yukseklik(calisan->sag) - Yukseklik(calisan->sol) == 2){
					// Sağ Sağ Durumu
					if(yil < calisan->sag->calisanYil)
						calisan = sagCocukIleDegistir(calisan);
					else{// Sağ Sol Durumu 
						calisan->sag = solCocukIleDegistir(calisan->sag); 
						calisan = sagCocukIleDegistir(calisan); 
					}
				}
			}
			
			
			//Yüksekliği güncelle
			calisan->yukseklik = Yukseklik(calisan);	
			return calisan;
}

void calisanTree::postorder(calisanNode* calisan){
	if (calisan!=NULL) 
   { postorder(calisan->sol); 
    postorder(calisan->sag);
	if(calisan!=root)
	cout<<calisan->isim<<" "<<"-"<<" "<<calisan->calisanYil<<" "<<"|"<<" ";
	else
		cout<<calisan->isim<<" "<<"-"<<" "<<calisan->calisanYil;
   }
}