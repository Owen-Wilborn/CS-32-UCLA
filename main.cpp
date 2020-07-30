//Owen Wilborn
//main.cpp
//Used to test the LinkedList class implementation

//Local Libraries
#include "LinkedList.h"
#include "LinkedList.h"
//Standard Libraries
//#include <string>
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
	
	//CS test cases (Provided by UCLA Professor Edwin Ambrosio)
	cout << "****Provided Test Cases****" <<endl;
	cout << "---Test 1---" << endl;
	LinkedList ls;
	ls.insertToFront("Hawkeye");
	ls.insertToFront("Thor");
	ls.insertToFront("Hulk");
	ls.insertToFront("Black Widow");
	ls.insertToFront("Iron Man");
	ls.insertToFront("Captain America");
	string check[6] = {"Captain America", "Iron Man","Black Widow","Hulk","Thor","Hawkeye"};
	for (int k = 0; k < ls.size(); k++)
	{
		string x;
		ls.get(k, x);
		assert(x == check[k]);
		cout << x << endl;
	}
	ls.~LinkedList();

	cout << endl << "---Test 2---" << endl;


	//LinkedList ls;
	ls.insertToFront("The Mandalorian");
	ls.insertToFront("Baby Yoda");
	ls.insertToFront("Cara Dune");
	ls.insertToFront("Greef Karga");
	string Front;
	string value;
	for (int i = 0; i < (ls.size()); i++)
	{
		ls.get(i, value);
		//Write out the item and a space
		Front = Front + value + " ";
	}
	assert(Front == "Greef Karga Cara Dune Baby Yoda The Mandalorian ");
	string Reverse;
	for (int i = ls.size()-1; i >= 0; i--)
	{
		ls.get(i, value);
		//Write out the item and a space
		Reverse = Reverse + value + " ";
	}
	assert(Reverse == "The Mandalorian Baby Yoda Cara Dune Greef Karga ");
	ls.printList();
	ls.printReverse();
	ls.~LinkedList();

	cout << endl << "---Test 3---" << endl;

	LinkedList e1;
	e1.insertToFront("Athos");
	e1.insertToFront("Porthos");
	e1.insertToFront("Aramis");
	LinkedList e2;
	e2.insertToFront("Robin");
	e2.insertToFront("Batman");
	e1.append(e2); // adds contents of e2 to the end of e1
	string s;
	assert(e1.size() == 5 && e1.get(3, s) && s == "Batman");
	assert(e2.size() == 2 && e2.get(1, s) && s == "Robin");
	e1.~LinkedList();
	e2.~LinkedList();
	cout << "Test 3 Passed" << endl;

	cout << endl << "---Test 4---" << endl;

	//LinkedList e1;
	e1.insertToFront("Jim");
	e1.insertToFront("Oz");
	e1.insertToFront("Paul");
	e1.insertToFront("Kevin");
	e1.reverseList(); // reverses the contents of e1
	assert(e1.size() == 4 && e1.get(0, s) && s == "Jim");
	e1.~LinkedList();
	cout << "Test 4 Passed" << endl;

	cout << endl << "---Test 5---" << endl;

	//LinkedList e1;
	e1.insertToFront("A");
	e1.insertToFront("B");
	e1.insertToFront("C");
	e1.insertToFront("D");
	//LinkedList e2;
	e2.insertToFront("X");
	e2.insertToFront("Y");
	e2.insertToFront("Z");
	e1.swap(e2); // exchange contents of e1 and e2
	//string s;
	assert(e1.size() == 3 && e1.get(0, s) && s == "Z");
	assert(e2.size() == 4 && e2.get(2, s) && s == "B");
	cout << "Test 5 Passed" << endl;
	cout <<"****End Provided Test Cases****" << endl << endl;

	//Owen Wilborn test cases
	cout << "****My Test Cases****" << endl;
	LinkedList list1;
	string item = "Hello";
	assert(list1.size() == 0 && list1.get(0, item) == false && item == "Hello" );
	list1.insertToFront("1");
	assert(list1.size() == 1 && list1.get(0, item) == true && item == "1");
	list1.insertToFront("2");
	assert(list1.size() == 2);
	assert(list1.get(0, item) == true && item == "2");
	assert(list1.get(1, item) == true && item == "1");
	assert(list1.get(2, item) == false && item == "1");
	LinkedList list2(list1);
	list1.~LinkedList();
	item = "Hello";
	assert(list1.size() == 0 && list1.get(0, item) == false && item == "Hello");
	assert(list2.size() == 2 && list2.get(0, item) == true && item == "2" && list2.get(1, item) == true && item == "1" && list2.get(2, item) == false && item == "1");
	LinkedList list3(list1);
	item = "Hello";
	assert(list3.size() == 0 && list3.get(0, item) == false && item == "Hello");
	list1 = list2;
	assert(list1.size() == 2 && list1.get(0, item) == true && item == "2" && list1.get(1, item) == true && item == "1" && list1.get(2, item) == false && item == "1");
	list1 = list3;
	item = "Hello";
	assert(list1.size() == 0 && list1.get(0, item) == false && item == "Hello");
	list1.~LinkedList();
	assert(list1.size() == 0 && list1.get(0, item) == false && item == "Hello");
	list1.insertToFront("1");
	list1.insertToFront("2");
	list1.insertToFront("3");
	assert(list1.size() == 3 && list1.get(0, item) == true && item == "3" && list1.get(1, item) == true && item == "2" && list1.get(2, item) == true && item == "1" && list1.get(3, item) == false && item == "1");
	list1.reverseList();
	assert(list1.size() == 3 && list1.get(0, item) == true && item == "1" && list1.get(1, item) == true && item == "2" && list1.get(2, item) == true && item == "3" && list1.get(3, item) == false && item == "3");
	list1.reverseList();
	list1.insertToFront("4");
	assert(list1.size() == 4 && list1.get(0, item) == true && item == "4" && list1.get(1, item) == true && item == "3" && list1.get(2, item) == true && item == "2" && list1.get(3, item) == true && item == "1" && list1.get(4, item) == false && item == "1");
	list1.reverseList();
	assert(list1.size() == 4 && list1.get(0, item) == true && item == "1" && list1.get(1, item) == true && item == "2" && list1.get(2, item) == true && item == "3" && list1.get(3, item) == true && item == "4" && list1.get(4, item) == false && item == "4");
	list2.~LinkedList();
	list1.append(list2);
	assert(list1.size() == 4 && list1.get(0, item) == true && item == "1" && list1.get(1, item) == true && item == "2" && list1.get(2, item) == true && item == "3" && list1.get(3, item) == true && item == "4" && list1.get(4, item) == false && item == "4");
	list2.insertToFront("6");
	list2.insertToFront("5");
	list1.append(list2);
	list2.~LinkedList();
	assert(list1.size() == 6 && list1.get(0, item) == true && item == "1" && list1.get(1, item) == true && item == "2" && list1.get(2, item) == true);
	assert(list1.get(4, item) == true && item == "5");
	assert(list1.get(5, item) == true && item == "6");
	assert(list1.get(6, item) == false && item == "6");
	list1.~LinkedList();
	list2.~LinkedList();
	list1.insertToFront("1");
	list1.insertToFront("2");
	list2.insertToFront("3");
	list2.insertToFront("4");
	list1.swap(list2);
	assert(list1.size() == 2 && list1.get(0, item) == true && item == "4");
	assert(list2.size() == 2 && list2.get(0, item) == true && item == "2");
	list1.~LinkedList();
	list2.swap(list1);
	assert(list1.size() == 2 && list1.get(0, item) == true && item == "2");
	assert(list2.size() == 0 && list2.get(0, item) == false && item == "2");
	list1.~LinkedList();
	list2.~LinkedList();
	list3.~LinkedList();
	list1.insertToFront("2");
	list1.insertToFront("1");
	list1 = list1;
	//list1.printList();
	//list1.printReverse();
	assert(list1.get(-1, item) == false);
	list1.~LinkedList();
	cout << "****End My Test Cases****" << endl << endl;
}
