#include "stdafx.h"
#include <fstream>
#include <iostream> 
#include<vector>
#include <locale>
using namespace std;
int main()
{
	//�������� ��������//
	setlocale(LC_ALL, "Russian");
	int N,M;
	ifstream fin("Data.txt");
	fin >> N;
	vector<int> w(N); //��� (�����) �����

	for (int i = 0; i < N; i++) 
	{
		fin >> w.at(i);
	}
	fin >> M;

	vector < pair<int, int> > E(M); //��������� ���� �����

	for (int i = 0; i < M; i++)
	{
		fin >> E.at(i).first;
		fin >> E.at(i).second;
	}
	vector<int> d(N); //����� ����������� ���� 
	vector<bool> U(N); // ��������� ���������� ������
	fin.close();
	const int INF = 1000000000;

	for (int i = 0; i < N; i++)
	{
		d[i] = INF;
		U[i] = false;
	}
	d[0] = 0;
	for (int i = 0; i < M; i++) //������ ������ ������ � ����
	{
		E[i].first -= 1;
		E[i].second -= 1;
	}
	for (int i=0;i<N;i++) // �������� ��� �������
	{
		for (int j = 0; j < M; j++) //�������� ��� �����
		{
			if ((E[j].first == i)&&(U[E[j].second]==false))
			{
				if (d[i] + w[E[j].second] < d[E[j].second])
					d[E[j].second] = d[i] + w[E[j].second];
			}
		}
		U[i] = true; //����������� �������
	}
	if (d[N - 1]!=INF)
	cout <<"����������� �����, ����� ������� ������� ����� ��������� � ������ N: "<<d[N-1] << endl;
	else cout << "����������� �����, ����� ������� ������� ����� ��������� � ������ N: " << -1 << endl;
    return 0;
}

