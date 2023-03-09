//******************************************************************************
// Team #             CSCI 1470      Spring 2023                    Homework # 1
// First and Last Name Jan Cesareo
// First and Last Name Daniel Perez-Rodriguez
//  Using your own words, write here a description of what the program does: This program takes in user-input foreign currency values to be 
// converted to U.S. dollars.
//******************************************************************************

#include <iostream>				// to be able to use cout
#include <typeinfo>				// to be able to use operator typeid

// Include here all the libraries that you need for your program to compile.
#include <iomanip>  // output manipulators
#include <cmath>  // for the round function



using namespace std;

// Ignore this; it's a little function used for making tests
inline void _test(const char* expression, const char* file, int line)
{
	cerr << "test(" << expression << ") failed in file " << file;
	cerr << ", line " << line << "." << endl << endl;
}
// This goes along with the above function...don't worry about it
#define test(EXPRESSION) ((EXPRESSION) ? (void)0 : _test(#EXPRESSION, __FILE__, __LINE__))

int main()
{
// Enter here your algorithm as a series of MEANINGFUL steps.
// Write below EACH step of the algorithm the C++ statement that implements it.
  const double DOL2MEX = 18.62, DOL2EURO = 0.93;
  // I declare & initialize constant variables to use 
    // throughout the program
  
  double pesos, euros, dollarsp, dollarse, entire;
  // Declared double-precision variables needed for calculations
  
  int wholedollarsp, centdollarsp, wholedollarse;
  int centdollarse, wholetotal, centtotal;
  // These integer variables will hold the results for the final output
  
  cout<<"Mexican Peso and Euro to U.S. Dollar converter"<<endl<<endl;  // A small greeting

  cout<<"Please enter the amount in Pesos: ";
  cin>>pesos; 
  // We prompt the user for the amount in pesos and read from keyboard
  
  cout<<"Please enter the amount in Euros: ";
  cin>>euros; 
  // We prompt the user for the amount in Euros and read from keyboard

  cout<<endl<<endl;  // for readability purposes

  dollarsp = pesos / DOL2MEX;  // We convert pesos to dollars (1a)
  
  dollarsp *= 100;
  dollarsp = round(dollarsp);  // and round it to the nearest cent (2a)
  dollarsp /= 100;

  wholedollarsp = dollarsp / 1;  // so that we get whole dollars (3a)
  
  centdollarsp = round((dollarsp - wholedollarsp) * 100);
  // and so that we can get whole cents - rounded function needed (4a)

  // ----------We repeat the same process with euros------------

  dollarse = euros / DOL2EURO;  // We convert euros to dollars (1b)
  
  dollarse *= 100;
  dollarse = round(dollarse);  // and round to the nearest cent (2b)
  dollarse /= 100;
  
  wholedollarse = dollarse / 1;  // so that we get whole dolalrs (3b)
  
  centdollarse = round((dollarse - wholedollarse) * 100) ;
  // and so that we can get whole cents - rounded function needed (4b)
  
  entire = dollarse + dollarsp;
  // The above line of code will add up the cents to ensure we don't end up with >100 cents (which would increase whole dollars)
  
  wholetotal = entire/1;
  // Once we have added up the cents, we can then truncate whole dollars of both euros and pesos added together.
  
  centtotal = round(((entire - wholetotal) * 100));
  // Once again we need the 'round' function so that we can get cents as a whole number


  cout<<"Mexican Peso and Euro to U.S. Dollar converter"<<endl<<endl<<endl;  // Last greeting
  
  cout<<fixed<<setprecision(2);  // Formatting output to 2 decimal places

  cout<<setw(10)<<pesos<<" pesos: "<<setw(9)<<wholedollarsp<<" US dollars with "<<centdollarsp<<" cents"<<endl<<endl;
  
  cout<<setw(10)<<euros<<" euros: "<<setw(9)<<wholedollarse<<" US dollars with "<<centdollarse<<" cents"<<endl<<endl;
  
  cout<<setw(18)<<"Total: "<<setw(9)<<wholetotal<<" US dollars with "<<centtotal<<" cents"<<endl<<endl;

  // The above three lines of code format the output of the final result according to instructions. 

// ----------------------------- Your code ends here -----------------------------

// Do NOT remove or modify the following statements

	cout << endl << "Testing your solution" << endl << endl;
	test(typeid(DOL2MEX) == typeid(1.));			// Incorrect data type used for DOL2MEX
	test(typeid(DOL2EURO) == typeid(1.));			// Incorrect data type used for DOL2EURO
	test(typeid(pesos) == typeid(1.));				// Incorrect data type used for pesos
	test(typeid(euros) == typeid(1.));				// Incorrect data type used for euros
	test(typeid(wholedollarsp) == typeid(1));		// Incorrect data type used for wholedollarsp
	test(typeid(centdollarsp) == typeid(1));		// Incorrect data type used for centdollarsp
	test(typeid(wholedollarse) == typeid(1));		// Incorrect data type used for wholedollarse
	test(typeid(centdollarse) == typeid(1));		// Incorrect data type used for centdollarse
	test(typeid(wholetotal) == typeid(1));			// Incorrect data type used for wholetotal
	test(typeid(centtotal) == typeid(1));			// Incorrect data type used for centtotal
	if (pesos == 230.0 && euros == 24.50)			// Does not pass test 1
	{
		test(wholedollarsp == 12 && centdollarsp == 35);
		test(wholedollarse == 26 && centdollarse == 34);
		test(wholetotal == 38 && centtotal == 69);
	}
	if (pesos == 190.29 && euros == 130.00)				// Does not pass test 2
	{
		test(wholedollarsp == 10 && centdollarsp == 22);
		test(wholedollarse == 139 && centdollarse == 78);
		test(wholetotal == 150 && centtotal == 0);
	}
	if (pesos == 856.70 && euros == 93.07)			// Does not pass test 3
	{
		test(wholedollarsp == 46 && centdollarsp == 1);
		test(wholedollarse == 100 && centdollarse == 8);
		test(wholetotal == 146 && centtotal == 9);
	}
	if (pesos == 241.87 && euros == 42.82)				// Does not pass test 4
	{
		test(wholedollarsp == 12 && centdollarsp == 99);
		test(wholedollarse == 46 && centdollarse == 4);
		test(wholetotal == 59 && centtotal == 3);
	}
	return 0;
}
