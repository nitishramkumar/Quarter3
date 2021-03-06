#pragma once
#include<vector>
#include<iostream>
#include <math.h>
#include <fstream>
using namespace std;


template <typename T>
double inline mean(vector<T> nums)
{
	double sum = 0.0;
	for (vector<T>::iterator it = nums.begin(); it != nums.end(); ++it)
	{
		sum += *it;
	}
	return sum / nums.size();
}

template <typename T>
double inline stddev(vector<T> nums)
{
	double avg = mean(nums);
	double sum = 0.0;
	for (vector<T>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		sum += pow(*it - avg, 2);
	}
	return pow(sum / nums.size(), 0.5);
}

template <typename T>
vector<T> inline cumsum(vector<T> nums)
{
	vector<T> cumsum;
	for (int count = 0; count < nums.size(); count++)
	{
		cumsum.push_back(nums[0]);
		for(int j = 1; j <= count ; j++)
		{
			cumsum[count] += nums[j];
		}
	}
	return cumsum;
}

template <typename T>
void inline writeToExcel(string fileName, vector<T> vals)
{
	ofstream myfile(fileName);
	int vsize = vals.size();
	for (int n = 0; n < vsize; n++)
		myfile << vals[n] << endl;
}

template <typename T>
void inline writeToConsole(vector<T> vals)
{
	int vsize = vals.size();
	for (int n = 0; n < vsize; n++)
		cout << vals[n] << " ";
	cout << endl;
}

template <typename T>
void inline writeToConsole(vector<vector<T>> vals)
{
	int vsize = vals.size();
	for (int n = 0; n < vsize; n++)
	{
		vector<double> vec = vals[n];
		for (int j = 0; j < vec.size(); j++) 
		{
			cout << vec[j] << " ";
		}
		cout << endl;
	}
	
}

template <typename T>
void inline writeToExcel(string fileName, vector<vector<T>> vals)
{
	ofstream myfile(fileName);
	int vsize = vals.size();
	for (int n = 0; n < vsize; n++)
	{
		vector<T> vec = vals[n];
		for(int j=0; j < vec.size(); j++)
		{
			myfile << vec[j] << ",";
		}
		myfile << endl;
	}
}

template <typename T>
void inline writeToExcel(string fileName, vector<T> vals1, vector<T> vals2)
{
	ofstream myfile(fileName);
	int vsize = vals1.size();
	for (int n = 0; n < vsize; n++)
		myfile << vals1[n] << ","<< vals2[n] << endl;
}

template <typename T>
void inline writeToExcel(string fileName, T** vals, int rows, int cols)
{
	ofstream myfile(fileName);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			myfile << vals[i][j] << ",";
		}
		myfile << endl;
	}
}

