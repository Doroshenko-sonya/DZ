#include <iostream>
#include <vector>
#include <fstream>

#include "Histogram.h"

using namespace std;
//struct Histogram
//{
//	vector<double> values;
//	double min_hist;//min value in hist
//	double max_hist;
//	static  unsigned M; 
//	unsigned* frequency = new unsigned[M]; // 
//	//unsigned frrequency[M];
//	
//	void setMin(double m)
//	{
//		min_hist = m;
//	}
//	void setMa(unsigned m)
//	{
//		M = m;
//	}
//	void addNumber(double x)
//	{
//		if (x > max_hist && x < min_hist)
//		{
//			cout << "Dont added" << endl;
//			/*max_hist = max_hist + x;
//			min_hist = min_hist + x;*/
//		}
//		
//	}
//	void addbatch(double data[], size_t dataSize)
//	{
//		for (int i = 0; i < dataSize; i++)
//		{
//			if (x > data[i] < max_hist && data[i] < min_hist)
//			{
//				cout << "Dont added" << endl;
//				/*max_hist = max_hist + x;
//				min_hist = min_hist + x;*/
//			}
//			values.push_back(data[i]);
//		}
//	}
//	unsigned num()
//	{
//		int cnt = 0;
//		for (int i = 0; i < M; i++)
//		{
//			cnt += frequency[i];
//		}
//		return cnt;
//	}
//	unsigned numHist(unsigned i)
//	{
//		return frequency[i];
//	}
//	double mean()
//	{
//		int cnt = 0;
//		int iter = 0;
//		for (int i = 0; i < values.size(); i++)
//		{
//			cnt += values[i];
//			iter++;
//		}
//		return cnt/iter;
//	}
//	double median()
//	{
//		if (values.size() % 2 != 1)
//		{
//			int position = (values.size() + 1) / 2;
//			return values[position];
//		}
//	}
//	double dev()
//	{
//
//	}
//	double variance()
//	{
//
//	}
//};
struct Values
{
	int freq;
	double rate;
	Values(double r, int f) : rate(r), freq(f)
	{}
};
double findMax(double* values, int size);
double findMin(double* values, int size);
void printHistogram(vector<Values> new_values);


int main()
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	//setlocale(LC_ALL, "");
	 //write to File values.txt 
	/*std::ofstream out("./values.txt");
	vector <Values> operations = {
	Values(12, 1),
	Values(32, 2),
	Values(43.2, 3),
	Values(56.3, 4),
	Values(41, 5),
	Values(32.12, 6),
	Values(5.43, 7)
	};






	if (out.is_open())
	{
		for (int i = 0; i < operations.size(); i++)
		{
			out << operations[i].rate << " " << operations[i].freq << std::endl;
		}
	}
	out.close();
*/

	std::vector<Values> new_values;
	double rate;
	int sum;
	std::ifstream in("./values.txt"); // оpen file to read
	if (in.is_open())
	{
		while (in >> rate >> sum)
		{
			new_values.push_back(Values(rate, sum));
		}
	}
	in.close();

	for (int i = 0; i < new_values.size(); i++)
	{
		std::cout << new_values[i].rate << " - " << new_values[i].freq << std::endl;
	}

	Histogram hist;
	hist.setM( 7);
	double* values = new double[new_values.size()];
	unsigned int* frequencyMass = new unsigned int[new_values.size()];
	for (int i = 0; i < new_values.size(); i++)
	{
		values[i] = new_values[i].rate;
		frequencyMass[i] = new_values[i].freq;
	}
	 double max = findMax(values, new_values.size());
	 hist.setMax(max);
	 double min = findMin(values, new_values.size());
	 hist.setMin(min);
	 hist.setValues(values, new_values.size());
	 hist.setFrequency(frequencyMass, new_values.size());
	 hist.addNumber(54);
	 cout << "Count of values in histogram" << hist.num()  << endl;

	 cout << "Count of values in i colmn (i=1)" << hist.numHist(1) << endl;

	 cout << "Mean histogram: " << hist.mean() << endl;

	 cout << "Median histogram: " << hist.median() << endl;

	 cout << "Mean histogram: " << hist.dev() << endl;

	 cout << "Variance histogram: " << hist.variance() << endl;

	 bool Puasson = false;
	 bool Prison = false;
	 Puasson = hist.PuassonCheck();
	 Prison = hist.PirsonCheck();
	 if (Puasson)
	 {
		 cout << "Histogram have Puasson  equation" << endl;
	 }
	 else
	 {
		 cout << "Histogram dont have Puasson equation" << endl;

	 }
	 if (Prison)
	 {
		 cout << "Histogram have normal equation, by Prison crytery" << endl;

	 }
	 else
	 {
		 cout << "Histogram don't have, a normal equation, by Prison crytery" << endl;

	 }
	 printHistogram(new_values);

}
void printHistogram(vector<Values> new_values)
{
	cout << "\n\n\tPrint histogram\n" << endl;
	int perminter = 5;
	for (int i = 0; i < new_values.size(); i++)
	{
		cout << "\t"<< new_values[i].rate << "\t | \t";
		int cnts = new_values[i].rate / perminter;
		string str = "";
		for (int j = 0; j < cnts; j++)
		{
			str += (char)254;
		}
		cout  << str << endl;
	}
}

double findMax(double* values, int size)
{
	double max = values[0];
	for (int i = 0; i < size; i++)
	{
		if (max < values[i])
			max = values[i];
	}
	//cout << "Max " << max << endl;

	return max;
}
double findMin(double* values, int size)
{
	double  min = values[0];
	for (int i = 0; i < size; i++)
	{
		if (min > values[i])
			min = values[i];
	}
	//cout << "Min" << min << endl;

	return min;
}


