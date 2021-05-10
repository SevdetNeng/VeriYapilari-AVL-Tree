#include <string>
#include <iostream>
#include <fstream>
#include "sirkettree.hpp"
#include <sstream>
#include <clocale>
#include <windows.h>



using namespace std;

int main(){
	SetConsoleOutputCP(65001);
	sirketTree* agacDis=new sirketTree;
	
	ifstream isimler;
	isimler.open("isimler.txt");
	
	
	while(!isimler.eof()){
		int sayac=0;
		string sirketAdi;
		string calisanAdi;
		int yil;
		string temp;
		string delimiter = "#";
		getline(isimler,temp);
	
		size_t pos = 0;
		string token;
		while ((pos = temp.find(delimiter)) != string::npos) {
		token = temp.substr(0, pos);
		if(sayac==0)
			sirketAdi=token;
		if(sayac==1)
			calisanAdi=token;
					
		
			sayac++;
			temp.erase(0, pos + delimiter.length());
		}
		stringstream ss;
		ss<<temp;
		ss>>yil;
		
		if(!agacDis->sirketVarMi(agacDis->root,sirketAdi)){
			agacDis->root=agacDis->sirketEkle(agacDis->root,sirketAdi,0);
			agacDis->calisanEkle(agacDis->root,calisanAdi,sirketAdi,yil);
				
		}
		else{
			
			agacDis->calisanEkle(agacDis->root,calisanAdi,sirketAdi,yil);
				
		}
	} 
		
	agacDis->postorder(agacDis->root);	
	
	system("pause");
}