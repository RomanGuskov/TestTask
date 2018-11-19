#include "stdafx.h"
#include <fstream>
#include <iostream> 
#include<vector>
#include <locale>
using namespace std;
int main()
{
	//Алгоритм Дейкстры//
	setlocale(LC_ALL, "Russian");
	int N,M;
	ifstream fin("Data.txt");
	fin >> N;
	vector<int> w(N); //вес (длина) ребра

	for (int i = 0; i < N; i++) 
	{
		fin >> w.at(i);
	}
	fin >> M;

	vector < pair<int, int> > E(M); //множество рёбер графа

	for (int i = 0; i < M; i++)
	{
		fin >> E.at(i).first;
		fin >> E.at(i).second;
	}
	vector<int> d(N); //длины кратчайшего пути 
	vector<bool> U(N); // множество посещённых вершин
	fin.close();
	const int INF = 1000000000;

	for (int i = 0; i < N; i++)
	{
		d[i] = INF;
		U[i] = false;
	}
	d[0] = 0;
	for (int i = 0; i < M; i++) //номера вершин начнем с нуля
	{
		E[i].first -= 1;
		E[i].second -= 1;
	}
	for (int i=0;i<N;i++) // проходим все вершины
	{
		for (int j = 0; j < M; j++) //проходим все ребра
		{
			if ((E[j].first == i)&&(U[E[j].second]==false))
			{
				if (d[i] + w[E[j].second] < d[E[j].second])
					d[E[j].second] = d[i] + w[E[j].second];
			}
		}
		U[i] = true; //просмотрели вершину
	}
	if (d[N - 1]!=INF)
	cout <<"Минимальное время, через которое посылка может оказаться в пункте N: "<<d[N-1] << endl;
	else cout << "Минимальное время, через которое посылка может оказаться в пункте N: " << -1 << endl;
    return 0;
}

