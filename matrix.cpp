#include<iostream>
#include<cstdlib>
#include<cmath>
/*201710757 ±èÁöÈÆ*/
#define N 4
using namespace std;

double det(double(*A)[N], int n)
{
	int y;
	double det_a = 0, temp[N][N];

	if (n != 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				y = 0;
				for (int k = 0; k < n; k++)
				{
					if (k != i)
					{
						temp[j - 1][y++] = *(A[0] + j * N + k);
					}
				}
			}
			det_a = det_a + *(A[0] + i) * (pow(-1, i)) * det(temp, n - 1);
		}
		return det_a;
	}
	else
	{
		return *A[0];
	}
}

int main(void)
{
	int n;
	double A[N][N] = { 0, };

	cout << "matrix size : "; cin >> n;
	cout << "\nmatrix value" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << " " << i + 1 << " X " << j + 1 << " : "; cin >> A[i][j];
		}
	}
	
	cout << "\nmatrix setting" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\nresult" << endl;
	cout << "Det(A) = " << det(A, n) << endl;
	return 0;
}