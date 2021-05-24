#pragma once
#include <vector>
using namespace std;
struct Histogram
{
	vector<double> values;
	double min_hist;//min value in hist
	double max_hist;
	 unsigned M;
	 unsigned* frequency; ; // 
	//unsigned frrequency[M];
	void setMax(double m);
	void setMin(double m);
	void setM(unsigned m);
	void setValues(double* mas, int size);
	void setFrequency(unsigned* freq, int size);
	
	void addNumber(double x);
	
	void addbatch(double data[], size_t dataSize);
	unsigned num();
	unsigned numHist(unsigned i);
	double mean();
	double median();
	
	double dev();
	
	double variance();
	
	bool PuassonCheck();

	bool PirsonCheck();
};