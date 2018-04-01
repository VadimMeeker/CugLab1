#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

void printArray1(double** a, double* b, int n) // ���������� �������� A � B
{
	int i, j;
	
	cout << "������� A" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}

	cout << endl;

	cout << "������ B" << endl;
	for (i = 0; i < n; i++)
	{
		cout << b[i] << "  ";
	}
}

void printArray2(double** a, int* p, int n) // ���������� �������� A � B
{
	int i, j;

	cout << "������� A" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << a[p[i]][j] << "  ";
		}
		cout << endl;
	}

	cout << endl;

	
}

void LU(double** a, double* b, int* p, int& z, int n) // LU - ���������� �� ���������� ����� ������
{
	int i, k, t, j, max = 0, imax = 0, buf;

    // ������ ������������
	for (i = 0; i < n; i++)
	{
		p[i] = i;
		cout << p[i] << endl;
	}

	double Sum = 0;

	for (k = 0; k < n; k++) // ������������ ������� (�������� 7)
	{
		// ��������� k-�� ������� ������� L �� �������
		for (i = k; i < n; i++) 
		{
			Sum = 0;
			for (t = 0; t <= k - 1; t++)
			{
				Sum += a[p[i]][t] * a[p[t]][k];
			}

			a[p[i]][k] = a[p[i]][k] - Sum;
		}

		// �������� ����� ��������� k-��� ������� ������� �������

		max = fabs(a[p[k]][k]);
		imax = k;
		for (i = k + 1; i < n; i++)
		{
			if (fabs(a[p[i]][k]) > max)
			{
				max = fabs(a[p[i]][k]);
				imax = i;
			}
		}

		if (imax != k)
			// �����
		/*{
			buf = p[k];
			z = -z;
			p[k] = p[imax];
			p[imax] = buf;
		}*/

		// ��������� k-�� ������ ������� U �� �������
		for (int j = k + 1; j < n; j++) 
		{
			Sum = 0;
			for (int t = 0; t <= k - 1; t++)
			{
				Sum += a[p[k]][t] * a[p[t]][j];
			}

			a[p[k]][j] = (a[p[k]][j] - Sum) / a[p[k]][k];
		}
	}

	printArray2(a, p, n); // ���������� LU-�������
}

double defA(double** a, int* p, int n, int z) // ������������ �������
{
	double dA = 1;
	for (int i = 0; i < n; i++)
	{
		dA *= a[p[i]][i];
	}

	return dA*z;
}

void SLAU(double** a, double* b, double* x, int n, int* p)
{

}

void SLAU(double** a, double* b, double* x, int* p, int n)
{
	double *y = new double[n];
	
	int i, j, Sum = 0;

	cout << "������ P" << endl;
	for (i = 0; i < n; i++)
	{
		cout << p[i] << "  ";
	}

	for (i = 0; i < n; i++)
	{
		Sum = 0;

		for (j = 0; j < i; j++)
		{
			Sum += a[p[i]][j] * y[j];
		}

		y[i] = ((b[p[i]] - Sum) / a[p[i]][i]);
	}

	for (i = n - 1; i >= 0; i--)
	{
		Sum = 0;

		for (j = i + 1; j < n; j++)
		{
			Sum += a[p[i]][j] * x[j];
		}

		x[i] = (y[i] - Sum);
	}

	
	
	delete []y;
}

void Inv1(double** A, int n, int* p, double** v)
{

}

void main()
{
	setlocale(0, "RUS"); // �����������
	size_t switcher1, switcher2;

	// ������� �������
	int N, i, j, Z=1;
	double Sum = 0;

	cout << "������������ ������ �1. ������� �.�., ������ �.�. . ������� 8." << endl;
	cout << "������ ������� = "; cin >> N;
	
	double *X = new double[N];
	double *Y = new double[N]; // UX=y
	double **A = new double *[N]; // �������

	double **V = new double *[N]; // �������� �������

	double *v = new double[N]; // ��
	double *E = new double[N]; // ��������� ������
	double *B = new double[N]; // ������
	int* P = new int[N]; // ������ ������������ �����

	for (i = 0; i < N; i++)
	{
		A[i] = new double[N];
	}

	for (i = 0; i < N; i++)
	{
		V[i] = new double[N];
	}

	// ����
	while (1)
	{
		system("CLS");
		cout << "������������ ������ �1. ������� �.�. ������� 8." << endl;
		cout // ����
			<< "1 - ���� ������" << endl
			<< "2 - ������������ �������" << endl
			<< "3 - ������� ����" << endl
			<< "4 - ���������� ������������ �������" << endl
			<< "5 - ������� ������� Ax = E" << endl
			<< "6" << endl
			<< "7" << endl
			<< "8" << endl
			<< "9" << endl
			<< "10 - Exit" << endl;

		cin >> switcher1; 

		switch (switcher1)
		{
		case 1: // ���� ������
		{
			system("CLS");
			cout << "���� ������" << endl;
			cout << endl;
			cout << "�������:" << endl;
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
				{
					cout << "A[" << i + 1 << "][" << j + 1 << "] = "; cin >> A[i][j];
				}
			}

			cout << endl;
			cout << "������:" << endl;
			for (i = 0; i < N; i++)
			{
				cout << "B[" << i + 1 << "] = "; cin >> B[i];
			}

			cout << endl;

			printArray1(A, B, N);

			system("pause");
			break;
		}
		case 2: // ������������ �������
		{
			system("CLS");

			LU(A, B, P, Z, N);

			system("pause");
			break;
		}
		case 3:
		{
			system("CLS");

			SLAU(A, B, X, P, N);

			cout << endl;
			cout << "������ x" << endl;
			for (i = 0; i < N; i++)
			{
				cout << X[i] << "  ";
			}

			system("pause");
			break;
			
		}
		case 4: // ������������ (�����������) ������� LU
		{
			system("CLS");

			cout << "|A| = " << defA(A, P, N, Z) << endl;

			system("pause");
			break;
		}
		case 5: // AX=E
		{
			system("CLS");

			/*AX(A, B, Y, X, P, N);*/

			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
				{
					if (i == j) E[i] = 1;
					else E[i] = 0;
				}

				SLAU(A, E, v, P, N);

				for (j = 0; j < N; j++)
				{
					V[j][i] = v[j];
				}
			}

			cout << "������� V" << endl;
			for (i = 0; i < N; i++)
			{
				for (j = 0; j<N; j++)
					cout << V[i][j] << "  ";
				cout << endl;
			}

			system("pause");
			break;
			

			system("pause");
			break;
		}
		case 6:
		{


			system("pause");
			break;
		}
		case 7:
		{
			system("pause");
			break;
		}
		case 8:
		{
			system("pause");
			break;
		}
		case 9:
		{
			system("pause");
			break;
		}
		case 10:
		{
			return;
		}

		}
		}
		system("pause");
		return;
	}