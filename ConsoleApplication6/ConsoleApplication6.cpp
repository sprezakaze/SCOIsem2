// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
	int n, m, x, y; //n,m - размерность изображения; x,y - размерность фильтра
	cin >> n;
	cin >> m;
	while (true)
	{
		cin >> x;
		cin >> y;
		if (x % 2 != 0 && y % 2 != 0)
			break;
		else cout << "daun";
	}
	int** picture = new int* [n];
	for (int i = 0; i < n; ++i) 
	{
		picture[i] = new int[m];
	}
	int** Newpicture = new int* [n];
	for (int i = 0; i < n; ++i) 
	{
		Newpicture[i] = new int[m];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
		{
			picture[i][j] = std::rand() % 100;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
		{
			Newpicture[i][j] = picture[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
		{
			std::cout << picture[i][j] << " ";
		}
		std::cout << std::endl;
	}
	int** filter = new int* [x];
	for (int i = 0; i < x; ++i) 
	{
		filter[i] = new int[y];
	}
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) 
		{
			filter[i][j] = std::rand() % 2;
		}

	}
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) 
		{
			std::cout << filter[i][j] << " ";
		}
		std::cout << std::endl;
	}
	int q = x / 2;
	int w = y / 2;
	int result = 0;
	int i2 = 0; int j2=0;
std:cout << '\n';
	for (int i = q; i < n - q; i++)
	{
		for (int j = w; j < m - w; j++)
		{
			for (int i1 = i-q; i1 <= i+q; i1++)
			{
				for (int j1 = j-w; j1 <= j+w; j1++)
				{
					result += picture[i1][j1] * filter[i2][j2];
					j2++;
				}
				i2++;
				j2 = 0;
			}
			Newpicture[i][j] = result;
			result = 0;
			j2 = 0;
			i2 = 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
		{
			std::cout << Newpicture[i][j] << " ";
		}
		std::cout << std::endl;
	}
}