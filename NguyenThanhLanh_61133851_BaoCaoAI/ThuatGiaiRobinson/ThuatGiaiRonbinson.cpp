
#include <iostream>
#include <fstream>
#include <string.h>
#include <list>
#include <iterator> 

using namespace std;

fstream fi;

list<string> ds1, ds2;

bool KiemTraDoiNgau(string str1, string str2); // kiem tra 2 menh de co doi ngau hay khong => true/flase
bool KiemTraDoiNgauDS(); // kiem tra trong danh sach co 2 menh de doi ngau hay khong
string HopGiai3(string str1, string str2); // phep hop giai: a ^ (-a v b) => b
string HopGiai4(string str1, string str2); // phep hop giai: (x v a) ^ (-x v y) => (a v y)
void ChuanHoa(); // chuyen doi gia thuyet dua vao thanh dang chuan robinson
void XuLyRoBinSon(); // xu ly thuat toan robinson

int main(){
	// Kiem tra thu thuat toan
	string a = "(-avb)";
	string b = "a";
	string c = "(yva)";
	
	cout << "Kiem tra thu thuat toan" << endl;
	cout << "a ^ (-a v b): " << HopGiai3(a, b) << endl;
	cout << "(-a v b) ^ (y v a): "<< HopGiai4(a, c) << endl;
	cout << endl << "--- Ket qua data truyen vao ---" << endl;
	
	ChuanHoa();
	cout << endl;
	XuLyRoBinSon();
	
	// xuat 2 danh sach
	list<string> :: iterator it; 
	
   for (it = ds1.begin(); it != ds1.end(); ++it) 
      cout << *it << "\t";
   cout << endl;
    
    
	list<string> :: iterator ot; 
	cout << "Xuat hien gia tri doi ngau!" << endl;
	
	for (ot = ds2.begin(); ot != ds2.end(); ++ot)
   	cout << *ot << "\t";
   cout << endl;
	
}


// kiem tra 2 menh de co doi ngau hay khong => true/flase
bool KiemTraDoiNgau(string str1, string str2){
	int size_str1 = str1.size();
	int size_str2 = str2.size();
	
	if(size_str1 > size_str2){
		str1.erase(0, 1);
		if(str1.compare(str2) == 0)
			return true;
	} else
			if(size_str1 < size_str2){
				str2.erase(0, 1);
				if(str2.compare(str1) == 0)
					return true;
			}
	return false;
}

// kiem tra trong danh sach co 2 menh de doi ngau hay không
bool KiemTraDoiNgauDS(){
	int i, j = 0;
	int size_i = ds2.size();
	int size_j = size_i - 1;
	
	list<string> ds3 = ds2;
	list<string> :: iterator it;
	list<string> :: iterator ot;
	
    for(it = ds2.begin(); it != ds2.end(); ++it){
    	string s1 = *it;
    	ds3.pop_front();
    	
		for(ot = ds3.begin(); ot != ds3.end(); ++ot){
			string s2 = *ot;
			if(KiemTraDoiNgau(s1, s2))
				return true;
		}	
	}
	return false;	
}

// phep hop giai: a ^ (-a v b) => b
string HopGiai3(string str1, string str2){	
	string s = str1;
	string s1, s2;
	
	s1 = s.substr(1, s.find("v") - 1);
	s.erase(0, s.find("v") + 1);
	s2 = s.substr(0, s.find(")"));
	
	if(KiemTraDoiNgau(s1, str2))
		return s2;
		
	if(KiemTraDoiNgau(s2, str2))
		return s1;
	
	// khong the hop giai
	return str1;
}

// phep hop giai: (x v a) ^ (-x v y) => (a v y)
string HopGiai4(string str1, string str2){
	string s1 = str1;
	string s1_1, s1_2;
	
	s1_1 = s1.substr(1, s1.find("v") - 1);
	s1.erase(0, s1.find("v") + 1);
	s1_2 = s1.substr(0, s1.find(")"));
	
	string s2 = str2;
	string s2_1, s2_2;

	s2_1 = s2.substr(1, s2.find("v") - 1);
	s2.erase(0, s2.find("v") + 1);
	s2_2 = s2.substr(0, s2.find(")"));
	
	if (KiemTraDoiNgau(s1_1, s2_1)){
		string s;
		
		s.insert(s.size(), "(");
		s.insert(s.size(), s1_2);
		s.insert(s.size(), "v");
		s.insert(s.size(), s2_2);
		s.insert(s.size(), ")");
		
		return s;
	}
	
	if(KiemTraDoiNgau(s1_1, s2_2)){
		string s;
		
		s.insert(s.size(), "(");
		s.insert(s.size(), s1_2);
		s.insert(s.size(), "v");
		s.insert(s.size(), s2_1);
		s.insert(s.size(), ")");
		
		return s;
	}
	
	if(KiemTraDoiNgau(s1_2, s2_1)){
		string s;
		
		s.insert(s.size(), "(");
		s.insert(s.size(), s1_1);
		s.insert(s.size(), "v");
		s.insert(s.size(), s2_2);
		s.insert(s.size(), ")");
		
		return s;
	}
	
	if(KiemTraDoiNgau(s1_2, s2_2)){
		string s;
		
		s.insert(s.size(), "(");
		s.insert(s.size(), s1_1);
		s.insert(s.size(), "v");
		s.insert(s.size(), s2_1);
		s.insert(s.size(), ")");
		
		return s;
	}
	
	string s;
	s.insert(s.size(), "88888888");
	
	// khong the hop giai
	return s;
	
}

// chuyen doi gia thuyet dua vao thanh dang chuan robinson
void ChuanHoa(){
	string s;
	
	// doc file dua vao 2 list
	fi.open("data.txt", ios::in);
	
	getline(fi, s, '>');
	cout << s << endl;
	
	s.insert(s.size(), "^");
	
	while(!s.empty()){
		ds1.push_back(s.substr(0, s.find("^")));
		s.erase(0, s.find("^") + 1);
	}
	
	getline(fi, s);
	cout << s << endl;
	s.insert(s.size(), "v");
	
	while(!s.empty()){
		ds2.push_back(s.substr(0, s.find("v")));
		s.erase(0, s.find("v") + 1);
	}
	
	fi.close();

	// xu ly chuan hoa ds2
	for(int i = 0; i < ds2.size(); i++){
		string s2;
		
		if(ds2.front().size() == 2){
			s2 = ds2.front().erase(0, 1);
		} else
				if(ds2.front().size() == 1){
					s2 = ds2.front().insert(0, "-");
				}
				
		ds2.pop_front();
		ds2.push_back(s2);
	}
	
}

void XuLyRoBinSon(){
	
	// xu ly theo phep hop giai: a ^ (-a v b) => b
	while (!KiemTraDoiNgauDS()){
		string s1 = ds1.front();
		string s2 = ds2.front();
		string s = HopGiai3(s1,s2);
		cout << s1 << " ^ " << s2 << " -> " << s << endl;
		if (s.size() <= 2){
			ds1.pop_front();
			ds2.pop_front();
			ds2.push_back(s);
		} else {
				ds1.push_back(ds1.front());
				ds1.pop_front();
		}
	}
}
