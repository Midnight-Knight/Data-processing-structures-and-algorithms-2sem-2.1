#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

string newNameFile()
{
	string nameFile;
	cout << "Имя файла: ";
	cin >> nameFile;
	nameFile += ".txt";
	return nameFile;
}

bool createFile(string nameFile)
{
	ifstream fileI(nameFile);
	if (fileI.is_open())
	{
		fileI.close();
		return false;
	}
	else
	{
		fileI.close();
		ofstream fileC(nameFile);
		fileC.close();
		return true;
	}
}

bool addFile(string nameFile,unsigned int n,vector <int> A)
{
	ifstream fileI(nameFile);
	if (fileI.is_open())
	{
		fileI.close();
		ofstream fileC(nameFile, ios_base::app);
		for (unsigned int i = 0; i < n; ++i)
		{
			fileC << " " << A[i];
		}
		fileC.close();
		return true;
	}
	else
	{
		fileI.close();
		
		return false;
	}
}

bool readFile(string nameFile)
{
	ifstream file(nameFile);
	int buf;
	if (file.is_open())
	{
		do
		{
			file >> buf;
			cout << buf << " ";
		} while (!(file.eof()));
		cout << endl;
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
}

bool poiskFile(string nameFile, unsigned int n)
{
	ifstream file(nameFile);
	int buf;
	if (file.is_open())
	{
		int i = 1;
		do
		{
			file >> buf;
			if (i == n)
			{
				cout << "Число под номеро 3: " << buf << endl;
			}
			i++;
		} while (!(file.eof()));
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
}

bool kolvoIntFile(string nameFile)
{
	ifstream file(nameFile);
	int buf;
	if (file.is_open())
	{
		int i = 0;
		do
		{
			file >> buf;
			i++;
		} while (!(file.eof()));
		cout << "Кооличество чисел в файле: " << i << endl;
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
}

bool DopOperationFile(string nameOldFile, string nameNewFile)
{
	ifstream file1(nameOldFile);
	int buf;
	vector <int> A;
	if (file1.is_open())
	{
		ofstream file2(nameNewFile);
		if (file2.is_open())
		{
			do
			{
				file1 >> buf;
				A.push_back(buf);
			} while (!(file1.eof()));
			for (int i = 0; i < A.size(); ++i)
			{
				file2 << " " << A[i] * buf;
			}
			file2.close();
			file1.close();
			return true;
		}
		else
		{
			file2.close();
			file1.close();
			return true;
		}
	}
	else
	{
		file1.close();
		return false;
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	string nameFile = newNameFile();
	bool status = createFile(nameFile);
	if (status == true)
	{
		cout << "Файл создан!" << endl;
	}
	else
	{
		cout << "Данный файл уже существует!" << endl;
	}

	vector <int> A;
	unsigned int n;
	int x;
	cout << "Введите количество чисел: ";
	cin >> n;
	for (unsigned int i = 0; i < n; ++i)
	{
		cout << "Введите число №" << i + 1 << ": ";
		cin >> x;
		A.push_back(x);
	}
	status = addFile(nameFile, n ,A);
	if (status == false)
	{
		cout << "Not file!" << endl;
	}
	else
	{
		status = readFile(nameFile);
		if (status == false)
		{
			cout << "Not file!" << endl;
		}
		else
		{
			cout << "Введите номер числа N: ";
			cin >> n;
			status = poiskFile(nameFile,n);
			if (status == false)
			{
				cout << "Not file!" << endl;
			}
			else
			{
				status = kolvoIntFile(nameFile);
				if (status == false)
				{
					cout << "Not file!" << endl;
				}
				else
				{
					string newFile = newNameFile();
					status = DopOperationFile(nameFile, newFile);
					if (status == false)
					{
						cout << "Not file!" << endl;
					}
					else
					{
						status = readFile(newFile);
						if (status == false)
						{
							cout << "Not file!" << endl;
						}
						else
						{

						}
					}
				}
			}
		}
	}
	return 0;
}