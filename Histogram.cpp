#include <iostream>
#include "Histogram.h"
using namespace std;

void Histogram::setMax(double m)
{
	max_hist = m;

}

void Histogram::setMin(double m)
{
	min_hist = m;
}

void Histogram::setM(unsigned m)
{
	M = m;
	frequency = new unsigned[M];
}

void Histogram::setValues(double* mas, int size)
{
	for (int i = 0; i <size ; i++)
	{
		values.push_back(mas[i]);
	}
}

void Histogram::setFrequency(unsigned* freq, int size)
{
	for (int i = 0; i < size; i++)
	{
		frequency[i] = freq[i];
	}
}

void Histogram::addNumber(double x)
{
	if (x > max_hist && x < min_hist)
	{
		cout << "Dont added" << endl;
		/*max_hist = max_hist + x;
		min_hist = min_hist + x;*/
	}
	else
	{
		unsigned* oldFreq = new unsigned[M];
		for (int i = 0; i < M; i++)
		{
			oldFreq[i] = frequency[i];
		}
		setM(M + 1);
		for (int i = 0; i < M - 1; i++)
		{
			frequency[i] = oldFreq[i];
		}
		frequency[M - 1] = oldFreq[M-1];
	}
}

void Histogram::addbatch(double data[], size_t dataSize)
{
	for (int i = 0; i < dataSize; i++)
	{
		if (data[i] > max_hist && data[i] < min_hist)
		{
			cout << "Dont added" << endl;
			/*max_hist = max_hist + x;
			min_hist = min_hist + x;*/
		}
		values.push_back(data[i]);
	}
}

unsigned Histogram::num()
{
		return M;
}

unsigned Histogram::numHist(unsigned i)
{
	return frequency[i];
}

double Histogram::mean()
{
	int cnt = 0;
	int iter = 0;
	for (int i = 0; i < values.size(); i++)
	{
		cnt += values[i];
		iter++;
	}
	return cnt / iter;
}

double Histogram::median()
{
	double* mass = new double[values.size()];
	int n = values.size();
	for (int i = 0; i < n; i++)
	{
		mass[i] = values[i];
	}
	int temp = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (mass[i] < mass[j])
			{
				temp = mass[i];
				mass[i] = mass[j];
				mass[j] = temp;
			}
		}
	}
	if (values.size() % 2 != 1)
	{
		int position = (values.size() + 1) / 2;
		return mass[position];
	}
	else
	{
		int pos = values.size() / 2;
		double medi = (mass[pos - 1] + mass[pos] + mass[pos + 1]) / 3;
		return medi;
	}
}

double Histogram::dev()
{
	double aver = mean();
	double sum = 0;
	for (int i = 0; i < values.size(); i++)
	{
		sum += pow(values[i] - aver, 2);
	}
	double res = sqrt(sum / values.size() - 1);
	return res;

}

double Histogram::variance()
{
	return dev() / mean() * 100;
}

bool Histogram::PuassonCheck()
{
	bool pusasson = true;
	double tmp = values[0];
	for (int i = 1; i < values.size(); i++)
	{
		if (values[i] > tmp)
		{
			pusasson = false;
		}
	}
	return pusasson;
}

bool Histogram::PirsonCheck()
{
	double* mass = new double[values.size()];
	int n = values.size();
	for (int i = 0; i < n; i++)
	{
		mass[i] = values[i];
	}
	int temp = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (mass[i] < mass[j])
			{
				temp = mass[i];
				mass[i] = mass[j];
				mass[j] = temp;
			}
		}
	}
	int position = 0;
	if (values.size() % 2 != 1)
	{
		position = (values.size() + 1) / 2;
	}
	else
	{
		position  = values.size() / 2;
	}
	if (position - 1 > 0 && values[position - 1] < values[position] && position + 1 < values.size() && values[position + 1] < values[position])
	{
		return true;
	}
}
