// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <cstring>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::hex;
using std::dec;
using std::setw;

#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))

//int number{};
//int * pnumber{ &number };
struct Person {
	int Name;
	int age;
};

double power(double x, int n);
double yield(double array[][4], int n);

double random(double start, double end)
{
	return start + (end - start)*rand() / (RAND_MAX + 1.0);
}

//point function
int incr10(int *num);
int incr10(const int& num);
int test(int *num);
double average(double *array, int count);
double *treble(double);

double &lowest(double values[], int length);
int factorial(int a);
void switchNumbers(int *num1,int *num2);

void inputFunction(int num, int *charInput);
void inputFunction2(int num, int datar[]);
int *getinputFunction(int num, int *charInput);
//************************************
// Method:    outputFunction
// FullName:  outputFunction
// Access:    public 
// Returns:   void
// Qualifier:
//************************************
void outputFunction(int *charOutput);

//function pointer
long sum(long a, long b);
long product(long a, long b);

//point parament
double squared(double);
double cubed(double);
double summarray(const double data[], size_t len, double(*pfn)(double));
char *extract(const char*str, size_t& index);

//pratice
int ascVal(size_t i, const char *p)
{
	cout << strlen(p)<<p[i] << endl;
	if (!p || i > strlen(p))
		return -1;
	else
		return p[i];
}

int test(size_t i, const char a)
{
	return 1;
}

//int max( const int data[],const size_t len );
//long max(const long data[], const size_t len);
template<typename T>T max(const T x[], const size_t len)
{
	T maxium{ x[0] };
	for (size_t i{ 1 }; i < len; i++)
		if (maxium < x[i])
			maxium = x[i];
	return maxium;
}

template<typename T1,typename T2>
//decltype(v1[0] * v2[0]) f(T1 v1[], T2 v2[], const size_t count)
auto f(T1 v1[],T2 v2[],const size_t count)->decltype(v1[0] * v2[0])
{
	decltype(v1[0] * v2[0]) sum{};
	for (size_t i{}; i < count; i++) sum += v1[i] * v2[i];
	return sum;
}
void eatspaces(char *str)
{
	size_t i{};
	size_t j{};
	while ((*(str + i) = *(str + j++)) != '\0')
		if (*(str + i) != ' ')
			i++;
	return;
}

double term(const char *str, size_t& index);

double number(const char *str, size_t& index);
double expr(const char *str);

template<typename T>
size_t equal(T p1,T p2);


const size_t MAX{ 80 };
int main(int argc ,char*argv[])
{
	//equal
	equal(1, 2);
	int data1[15]{ 1,2,3,4 };
	int *pcharInput1{ data1 };
	cout<<"is p::"<<std::is_pointer<int *>::value<<endl;
	//pratice
	int(*pPratice)(size_t, const char*) { ascVal };
	const char* str{ "A miss is as good as mile." };

	cout << str[3] << endl;
	equal(*pcharInput1, *pcharInput1);
	//pPratice = ascVal;/// (0, str);
	cout<<"The ASCII int is:: "<<pPratice(0, str)<<endl;
	//caculator
	char buffer[MAX]{};
	cout << "Enter an expression,or an empty line to quit." << endl;

	for (;;)
	{
		cin.getline(buffer, sizeof buffer);
		eatspaces(buffer);

		if (!buffer[0])
			return 0;

		try
		{
			cout << "\t= " << expr(buffer) << endl;
		}
		catch (const char* pEx)
		{
			cerr << pEx << endl;
			cerr << "Ending program. " << endl;
			return 1;
		}
		
	}

	//function overload
	int small[] { 1,24,34,22 };
	long medium[]{ 23,245,123,1 };

	const size_t lensmall{ _countof(small) };

	cout << "Result type is " << typeid(f(small, medium, 4)).name() << endl;
	cout << "Result  " << f(small, medium, 4) << endl;

	cout << endl << max(small, lensmall);
	//try catch
	int counts[]{ 34,54,0,27,0,10,0 };
	double time{ 60 };
	int hour{};



	for (auto count : counts)
	{
		try {
			cout << endl << "Hour" << ++hour;

			if (0 == count)
				throw "Zero coutn";
			cout << "minutes oer item:" << time / count;
		}
		catch (const char aMessage[])
		{
			cout << endl << aMessage << endl;
		}
	}
	//point parament
	double _data[]{ 1.5,2.5,3.5,4.5,5.5,6.5,7.5 };
	size_t len{ _countof(_data) };

	cout << endl << "Sum of squares =" << summarray(_data, len, squared);
	cout << endl << "Sum of Cubes =" << summarray(_data, len, cubed);
	//recursion
	long(*pdo_it)(long, long);
	pdo_it = product;
	cout << endl << "3*5=" << pdo_it(3, 5);

	pdo_it = sum;
	cout << endl << "3*(4+5)+6=" << pdo_it(product(3, pdo_it(4, 5)), 6);
	cout << endl;

	int input{11};
	//cin>> input;
	int data[15]{1,2,3,4};
	int *pcharInput{data};
	cout << "PLEASE input a int" << endl;
	//while (input != 0)
	while (input != 0)
	{
		cin >> input;
		//inputFunction(input, pcharInput);
		//outputFunction(pcharInput);
		outputFunction(getinputFunction(input, pcharInput));
	}

	
	//{
		//inputFunction(input, pcharInput);
	//}
	

	/*
	cout << "factorial is ::" << factorial(input) << endl;

	int a = 2;
	int b = 3;

	int *pa{ &a };
	int *pb{ &b };
	switchNumbers(pa, pb);

	cout << cos(0)<<endl;

	cout << "A::"<<a<<"B::" << b;*/

	/*double num{ 5.0 };
	double *ptr{};
	ptr = treble(num);
	cout << endl << "Three times num = " << 3.0*num;
	cout << endl << "Result = " << *ptr;
	delete ptr;
	ptr = nullptr;
	cout << endl;*/
	/*double data[]{ 3.0,10.0,1.5,15.0,2.7,23.0,4.5 };
	int len{ _countof(data) };
		for (auto value : data)
			cout << setw(6) << value;

		cout << endl;
		lowest(data, len) = 6.9;
		lowest(data, len) = 7.9;

		for (auto value : data)
			cout << setw(6) << value;

		cout << endl;*/
	/*cout << endl << "argc = " << argc << endl;
	cout << "Command line ::" << endl;
	for (int i{}; i < argc; i++)
	{
		cout << "argument" << (i + 1) << ":" << argv[i] << endl;
	}
	double beans[3][4]{ {1.0,2.0,3.0,4.0},
						{5.0,6.0,7.0,8.0},
						{9.0,10.0,11.0,12.0} };

	cout << endl << "Yield = " << yield(beans, _countof(beans)) << endl;

	const int num{ 3 };
	int value{ 6 };
	int result{ incr10(num) };
	cout << endl << "incr10(num)= " << result << endl << "num = " << num;
	result = incr10(value);
	cout << endl << "incr10(num)= " << result << endl << "num = " << num;
	cout<<endl<<"====================================="<<endl;*/
	/*double values[]{ 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };
	cout << endl << "Average =" << average(values, _countof(values)) << endl;

	cout << values[2] << endl;
	//point function 
	int num{ 3 };
	int*pnum{ &num };
	cout << endl << "Address passed =" << pnum;
	int result{ incr10(pnum) };
	cout << endl << "incr10(pnum) =" << result;

	cout << endl << "num = " << num << endl;

	int x{ 4 };
	int *px{ &x };
	cout << endl << "Address x is " << px;
	int r{ test(px) };

	cout << endl << "test is " << r;*/	
	//home work
	/*
	char s[10]{ "abcdefg" };
	char *str{s};
	int count1{ 0 };
	char temp{};
	while (*(str + count1) != '\0') {
		//ch[i] += 'A' - 'a';
		temp = *(str + count1);
		*(str + count1)-= 32;
		cout << *(str + count1);
		count1++;
	}
	//double rand
	double hsDegree[12]{};
	double *pDegree{ hsDegree };
	cout << endl;
	int cot2{ 0 };
	double min{100};
	double max1{0};
	double temp1{};
	double sum{};
	while (cot2 < 12)
	{
		*(pDegree + cot2) = ((double)random(0,100));
		temp1 = *(pDegree + cot2);

		if (temp1 > max1) {
			max1 = temp1;
		}

		if (temp1 <min) {
			min = temp1;
		}
		sum += temp1;

		cout << *(pDegree + cot2)<<",";
		cot2++;
	}

	cout <<endl<< "min is ::" << min << "max is::" << max1 << "average is::" << sum / 12;
	*/
	//functions
	/*int index{ 3 };
	double x{ 1 };
	double y{};

	y = power( 5.0,3 );

	cout << endl << "5.0 cubed = " << y;
	cout << endl << "3.0 cubed =" << power(3.0, index);
	x = power(x, power(2.0, 2));
	cout << endl << "x=" << x;
	cout << endl;*/	
	//while (cin >> input) {
		//cout << "OUT";
	//}
	//Lvalue and rvalue;
	/*Person p;
	Person &sp = p;
	sp.Name = 100;
	p.age = 2;
	cout << "Name " << p.Name << "AGE " << sp.age;
	//
	//string
	const char* str{"A miss is as good as mile."};
	char str2[30]{ "A miss is as good as mile." };
	cout <<endl<< "The string contains " <<strnlen(str2 , _countof(str2)) << " characters.";
	char str1[]{ "I agree with everything." };
	const char* vowels{ "aeiouAEIOU " };
	std::strspn { str1,vowels };
	size_t index { std::strspn{str1,vowels} };
	std::cout << "First " << str[index] << " at " << index;
	//str
	char str11[30]{ "Many hands" };
	const char* str3{ "make light work." };

	errno_t error{ strcat_s(str11,str3) };

	cout << "Joined \n" << str11 << endl;*/
	/*cout << endl << "ssssss";
	long * pnumber{};
	long number1{ 55 }, number2{ 99 };

	pnumber = &number1;
	*pnumber += 11;
	cout << endl << "number1=" << number1 << " &number1 = " << hex << pnumber<<endl;


	pnumber = &number2;
	number1 = *pnumber * 10;

	cout << endl <<
		"number1=" << dec << number1
		<< " pnumber = " << hex << pnumber
		<< " *pnumber =" << dec << *pnumber;

	//08
	const char * const pstr[] = {"RO","GE","PS"};

	int value{ 5 }, value2{ 6 };

	int* pvalue{&value2};//{ &value };

	*pvalue = 5;

	pvalue = &value;

	cout << endl << pvalue;*/
	/*
	const int MAX{ 100 };
	long primes[MAX]{ 2,3,5 };

	long trial{ 5 };
	int count{ 3 };
	bool found{ false };

	do
	{
		trial += 2;
		found = false;

		for (int i{}; i < count; i++)
		{
			found = (trial%*(primes + i)) == 0;
			if (found)
				break;
		}

		if (!found)
			*(primes + count++) = trial;
	} while (count < MAX);

		for (int i{}; i < MAX; i++)
		{
			if (i % 5 == 0)
				cout << endl;
			cout <<setw(10)<< *(primes + i);
		}

		//part2
		char buffer[MAX];
		int pstr[]{ 1,2,3,4 };
		char ps[]{ '2','3' };

		char *pps{};
		int *pint{};

		pint = pstr;

		//while (*pint++) {
		for(auto t: pstr){
			cout <<endl<< t << endl;
			//cout <<  *pint;
		}*/
		/*char *pbuffer{ buffer };

		cout << endl
			<< "Enter a string of less than"
			<< MAX << " characters:"
			<< endl;

		cin.getline(pbuffer, MAX, '\n');
		char number;
		while (*pbuffer) {
			pbuffer++; 
			number = *pbuffer;
			cout << number  <<endl;
		}

		cout << endl
			<< "The string \"" << buffer
			<< "\"has " << pbuffer - buffer << " characters.";
		cout << endl;*/
/*
	int max{};
	cout << endl
		<< "Enter the number of primes you would like (at least 4):";
	cin >> max;

	if (max < 4)
		max = 4;

	long * pprime{ new long[max] {2L,3L,5L} };

	long trial{ 5L };
	int count{ 3 };
	bool found{ false };

	do
	{
		trial += 2L;
		found = false;

		for (int i{}; i < count; i++)
		{
			found = (trial %*(pprime + i)) == 0;
			if (found)
				break;
		}
	} while (count < max);

	for (int i{}; i < max; i++)
	{
		if (i % 5 == 0)cout << endl;
		cout << setw(10) << *(pprime + i);
	}

	delete[] pprime;
	pprime = nullptr;
	cout << endl;*/	
	char str1[10];

	cin >> str1;

	return 0;
}

double power(double x, int n)
{
	double result{ 1.0 };
	for (int i{ 1 }; i <= n; i++)
	{
		result *= x;
	}
	return result;
}

double yield(double array[][4], int n)
{
	//return 0.0;
	double sum{};
	for (int i{}; i < n; i++)
	{
		for (int j{}; j < 4; j++)
			sum += array[i][j];

	}
	return sum;
}

int incr10(int * num)
{
	cout << endl << "ADDRESS received = " << num;
	*num += 10;
	return *num;
}

int incr10(const int & num)
{
	cout << endl << "Value received= " << num;
	//num += 10;
	return num+10;
}

int test(int * num)
{
	*num+=2;
	return *num;
}

double average(double * array, int count)
{
	double sum{};
	for (int i{}; i < count; i++)
	{
		*array += 100;
		sum += *array++;
		
	}

	return sum/count;
}

double * treble(double data)
{
	double *result{ new double{} };
	*result = 3.0*data;
	return result;
}

double & lowest(double values[], int length)
{
	// TODO: insert return statement here
	int j{};
	for (int i{ 1 }; i < length; i++)
		if (values[j]>values[i])
			j = i;
	return values[j];
}

int factorial(int a)
{
	int result{a};
	int i{ 1 };
	if (a <= 1)
	{
		result = 1;
	}
	if (a > 1)
	{
		result = a*factorial(a-1);
	}
	cout << result << endl;
	//while (i < a)
	//{
		//cout << result<<endl;
		//result = i*factorial(--i);
		//cout << result << endl;
	//}

	return result;
}

void switchNumbers(int * num1, int * num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void inputFunction(int num, int * charInput)
{
	//if num ==0,out put char input;
	//else continue input num;
	static int len{ 0 };	
	//cout << "Length is ::" << len << endl;

	//*(charInput+len) = num;
	*charInput++=num;
	//len++;
	//if (num == 0)
	//{
		//outputFunction();
	//}
	//else {
		//cout << "Length is::" << *charInput;
		//*(charInput ++)= num;
		//cout << "Length is::" << *charInput;
	//}
}

void inputFunction2(int num, int datar[])
{
	int leng = _countof(datar);
	datar[leng+1] = num;
	cout << leng<<endl;
}

int * getinputFunction(int num, int * charInput)
{
	*charInput = num;
	return charInput++;
}

void outputFunction(int * charOutput)
{
	cout << "input is  ::" << *charOutput << endl;
}

long sum(long a, long b)
{
	return a+b;
}

long product(long a, long b)
{
	return a*b;
}

double squared(double x)
{
	return x*x;
}

double cubed(double x)
{
	return x*x*x;
}

double summarray(const double data[], size_t len, double(*pfun)(double))
{
	double total{};
	for (size_t i{}; i < len; i++)
		total += pfun(data[i]);
	return total;
}

char * extract(const char * str, size_t & index)
{
	//return nullptr;
	char* pstr{};
	size_t numL{};
	size_t bufindex{ index };
		
	do 
	{
		switch (*(str + index))
		{
			case')':
				if (0 == numL)
				{
					++index;
					pstr = new char[index - bufindex];
					if (!pstr)
					{
						throw "Memory allocation failed.";
					}

					strncpy_s(pstr, index - bufindex, str + bufindex, index - bufindex - 1);

					return pstr;
				}
				else
					numL--;
					break;
			case '(':
				numL++;
				break;
		}
	} while (*(str+index++)!='\0');
	throw "Ran off the end";
}

double term(const char * str, size_t & index)
{
	double value{};
	value = number(str, index);
	while (true)
	{
		if (*(str + index) == '*')
			value *= number(str, ++index);
		else if (*(str + index) == '/')
			value /= number(str, ++index);
		else
			break;
	}
	return value;
}

double expr(const char *str)
{
	double value{};
	size_t index{};
	value = term(str, index);

	for (;;)
	{
		switch (*(str + index++))
		{
		case '\0':
			return value;
		case '+':
			value += term(str, index);
			break;
		case '-':
			value -= term(str, index);
			break;
		default:
			char message[38]{ "Expression evaluation Error. Found:" };
			strncat_s(message, str + index - 1, 1);
			throw message;
			break;

		}
	}
}

double number(const char * str, size_t & index)
{
	double value{};

	if (*(str + index) == '(')
	{
		char* psubstr{};
		psubstr = extract(str, ++index);
		value = expr(psubstr);
		delete[]psubstr;
		return value;
	}

	if (!isdigit(*(str + index)))
	{
		char message[31]{ "Invalid character in number: " };
		strncat_s(message, str + index, 1);
		throw message;
	}

	while (isdigit(*(str + index)))
		value = 10 * value + (*(str + index++) - '0');

	if (*(str + index) != '.')
		return value;

	double factor{ 1.0 };
	while (isdigit(*(str + (++index))))
	{
		factor *= 0.1;
		value = value + (*(str + index) - '0')*factor;
	}
	return value;

	return 0.0;
}

/*int max(const int data[], const size_t len)
{
	//return 0;
	int test{ _countof(data) };
	int maxium{ data[0] };
	for (size_t i{ 1 }; i < len; i++)
		if (maxium < data[i])
			maxium = data[i];
	return maxium;
}

long max(const long data[], const size_t len)
{
	//return 0;
	long maxium{ data[0] };
	for (size_t i{ 1 }; i < len; i++)
		if (maxium < data[i])
			maxium = data[i];
	return maxium;
}*/

template<typename T>
size_t equal(T p1, T p2)
{
	size_t temp{ 0 };
	cout << "isPoint:??" << std::is_pointer<T>::value << endl;
	//cout << p1 == p2 << endl;
	//if (strcmp(p1 == p2)) {
		return p1 == p2;
	//}

	return size_t();
}
