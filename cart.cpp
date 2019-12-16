/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <ctype.h>
#include <vector>


using namespace std;

class ShoppingCart
{
public:
  string id;
  int billAmount;

    ShoppingCart ()
  {
    id = "idGeneratingLogic";
  }
public:
  void add ()
  {
  }

public:
  void deleteEntry ()
  {
  }

public:
  void setBillAmount (int newBillAmount)
  {
    this->billAmount = newBillAmount;
  }
};

class Discounts
{
public:
  vector < int >slabs;
    vector < int >discountsPer;
    Discounts (vector < int >enteredSlabs, vector < int >enteredDiscounts)
  {
    this->slabs = enteredSlabs;
    this->discountsPer = enteredDiscounts;
  }

  int calculateDiscount (int billAmount)
  {
     int index = 0;
    for (; index < slabs.size (); index++)
    {
	    if (billAmount <= slabs[index])
	    {
	        break;

	    }
    }
    int discountPercentage = discountsPer[index];
    cout<< "discount percentage = " << discountPercentage <<endl;

    return discountPercentage;
  }

};
class UnitTests
{
    public:
    UnitTests(){
        
    
  vector<int> slabs;
  slabs.push_back(0);
  slabs.push_back(5000);
  slabs.push_back(10000);
  slabs.push_back(15000);

 vector<int> discounts;
  discounts.push_back(0);
  discounts.push_back(0);
  discounts.push_back(10);
  discounts.push_back(15);
  
  Discounts disc(slabs, discounts);
  int testFailed= 0; int testPassed = 0;
  if(disc.calculateDiscount(5000) != 0){
      cout<<"Test failed";
      testFailed++;
  }else{
      testPassed++;
  }
  if(disc.calculateDiscount(10000) !=  10){
      cout<<"Test failed";
      testFailed++;
  }else{
      testPassed++;
  }
  
  cout<<"test failed = "<< testFailed<<endl;
  cout<<"test Passes = "<< testPassed<<endl;
 }
};
bool
isValidNumber (string rawInput)
{
  bool isNum = true;
  for (int i = 0; i < rawInput.length () && isNum; ++i)
    {
      isNum = isdigit (rawInput[i]);
    }
  return isNum;
}
vector < int > split (string str, string token)
{
  vector < int > result;
  while (str.size ())
    {
      int index = str.find (token);
      if (index != string::npos)
	    {
	        bool isNum = false;
	        string temp = str.substr (0, index);
	        isNum = isValidNumber (temp);
	        if (isNum)
	        {
	            int currentNumber = stoi (temp);
	            result.push_back (currentNumber);
	        }
	        else
	        {
	            vector<int> error;
	            return error;
	        }
	        str = str.substr (index + token.size ());
	        if (str.size () == 0)
	        result.push_back (stoi(str));
	   }
        else
	    {
	        result.push_back (stoi(str));
	        str = "";
	    }
    }
  return result;
}
vector<int> storeToVector (vector< int > toStore)
{
  string rawInput;
  getline (cin, rawInput);
  toStore = split (rawInput, " ");
   

 return toStore;
}
void printResults(Discounts disc, int billedAmount){
    cout << "Total bill amount " << billedAmount << endl;
    int discAmt = disc.calculateDiscount(billedAmount) * billedAmount/100;
    cout << "Discount amount " << discAmt <<endl;
    cout << "Payable Amount " << (billedAmount - discAmt) << endl;
}

int
main ()
{
    string run;
  cout<<"to run tests type 't' else enter to run program" <<endl;
  getline(cin, run);
  if(run == "t"){
      UnitTests runtests;
  }else{
      

  string rawInput;
  vector < int >slabs;
  vector < int >discounts;
  int billAmount;
  cout<< "Please enter the inputs without trailing spaces" <<endl;
  cout<< "Incorrect inputs will result in termination of program" <<endl;
  cout<< "Put the higher ends of the slab as its value for eg. "<< endl;
  cout<< "slabs of 0-5000, 5000 -1000, 10000-15000 ender as below"<<endl;
  cout<< "0 5000 10000 15000" <<endl<<endl<<endl;
  cout << " Enter discount Slabs in sorted order(ascending)" << endl;
   slabs = storeToVector (slabs);
  if(slabs.size() <= 0) {
      cout<< "Invalid arguments found pls rerun";
      return 0;
  }
  cout << " Enter discount percentage for above slabs" << endl;
  discounts = storeToVector (discounts);
if(discounts.size() <= 0 || discounts.size() != slabs.size()) {
      cout<< "Invlid arguments found pls rerun";
      return 0;
  }
  Discounts dis (slabs, discounts);
  // if validate is false then do it again  :)

  while (true)
    {
      string temp;
      cout << "Enter bill Amount or press 'e' to Exit" << endl;
      cin >> temp;
      ShoppingCart scart;
      if (isValidNumber (temp))
	{
	int billedAmt = stoi(temp);
	  //do stuff here. ;
    scart.setBillAmount(billedAmt);
    printResults(dis, billedAmt);

	}
      else if (temp == "e")
	{
	  cout << "Thank you!";
	  return '0';
	}
      else
	{
	  cout << "invalid input pls try again";
	}

    }
  }
  return 0;
}
