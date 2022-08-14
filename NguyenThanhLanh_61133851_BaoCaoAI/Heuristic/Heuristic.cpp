

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>

using namespace std;


// Khoi tao class Do Thi
struct Graph
{
	int n; 
	int** G; 

};

// Khai bao bien tinh tong duong di theo giai thuat Heuristic.
int sum = 0;

// Khoi tao mot do thi moi
void initGraph(Graph & Gr)
{
	Gr.G = new int*[Gr.n];
	for (int i = 1; i <= Gr.n; i++)
	{
		Gr.G[i] = new int[Gr.n];
	}
}

// Ham doc do thi tu file .txt.
void ReadGraph(Graph &Gr)
{
	ifstream inputm("graph.txt");	
	if ( inputm == NULL)
	{
		cout<<" Khong the doc file."<<endl;
		return;

	}
	else
	{		
		inputm>>Gr.n;
		initGraph(Gr);		
		for (int i = 1; i<= Gr.n; i++)
		{
			for (int j = 1; j <= Gr.n ; j++)
			{				
				inputm>>Gr.G[i][j]; 			

			}
		}

	}
}

// Ham xu ly nhap do thi bang tay.
void InputHandle(Graph &Gr)
{
	cout<<"\n Nhap do lon cua ma tran:   ";
	cin>>Gr.n;
	initGraph(Gr);

	cout<<"\n Nhap cac phan tu cua ma tran:  "<<endl;
	for (int i = 1; i<= Gr.n; i++)
	{
		for (int j = 1; j <= Gr.n; j++)
		{
			cin>>Gr.G[i][j];
		}		
	}

}

// Xuat do thi len man hinh
void outputGraph(Graph Gr)
{	
	for (int i = 1; i <= Gr.n; i++)
	{
		for ( int j = 1; j<= Gr.n; j++)
		{
			cout<<Gr.G[i][j] <<" ";
		}
		cout<<"\n";
	}
}

// Ham kiem tra do thi co trung voi dinh da duyet hay khong.
bool testGraph(int a, int* v, Graph Gr)
{

	for(int i = 1; i <= Gr.n; i++)
	{
		if(v[i]== a)
			return false;
	}
	return true;
}

// Ham tim dinh ke nho nhat.
int topNear(int a, Graph Gr, int* v)
{
	int min = 0, d = 1000;
	for(int i = 1; i <= Gr.n; i++)
	{
		bool k = testGraph(i, v, Gr);
		if((Gr.G[a][i] > 0) && (k == true))
		{				
			if(Gr.G[a][i] < d)
			{
				min = i;
				d = Gr.G[a][i];					
			}
		}
	}
	return min;	
}


// Ham tim duong di dua tren Dinh Ke nho nhat da tim duoc theo thuat giai Heuristic
void  FindWay(int x, Graph Gr, int* v)
{
	int e = x; 
	v[1] = x;
	for (int i = 2; i <= Gr.n; i++)
	{
		int next = topNear(e, Gr,v);
		v[i] = next;
		e = next;	
	}
	v[Gr.n+1] = x;
}


// Ham Chinh
int main(int argc, char** argv)
{	
	do
	{
		Graph Gr;
		
		int key; 
		cout<< "\n Bai toan nguoi dua thu "<<endl;
		cout<<"\n Chon 1 hoac 2 "<<endl;
		cout<<"\n 1. Nhap do thi bang file."<<endl;
		cout<<"\n 2. Nhap do thi bang tay.";
		cout<<"\n"<<endl;
		cin>>key;
		switch (key)
		{
		case 1:
			ReadGraph(Gr);	
			break;
		case 2:
			InputHandle(Gr);
			break;
		default:
			ReadGraph(Gr);
			break;
		}

		int* v;
		int x;
		
		v = new int[Gr.n + 1];
		for (int i = 1; i <= (Gr.n + 1); i++)
		{
			v[i] = -1;
		}


		cout<< "\n Ma Tran da nhap la: \n"<<endl;
		outputGraph(Gr);
		cout<< "\n";
		cout<<" Nhap dinh bat dau:  "; 	
		cin>>x; 
		FindWay(x, Gr, v);
		for (int k = 1; k <= Gr.n; k++)
		{			
			sum += Gr.G[v[k]][v[k+1]];
			
		}

		cout<<"\n Duong di ngan nhat theo giai thuat Heuristic co do dai la:    "<< sum<<endl;
		sum = 0;
		cout<< "\n Thu tu duong di la:";
		cout<<"\t";

		for (int z = 1; z<= Gr.n + 1; z++)
		{
			cout<<v[z]<<" ";
		}
		cout<<"\n\n";
		cout<<"Nhan phim bat ki de tiep tuc";
		
		
	}while(getch()!=27);
				
		return 0;
}
