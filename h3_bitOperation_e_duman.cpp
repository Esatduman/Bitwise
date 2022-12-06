/*
====================================================================================
Course: Harper CSC122-S01 by Mr. Jin Guo, Spring 2021
Student Name: <Esat Duman>

Program Name: Play with bitwise operators
Program Description:
	This program is for you to understand bitwise operations such as bitwise AND,
	bitwise OR, bitwise exlusive OR, bitwise complement and shift, etc.

Instructions: 
	1. First, try to understand and run the given program without any change.
	2. Your job is to implement the function DecToHex(). 
	3. Insert your code below wherever is marked "Your code below...".	
	4. h3_JG.out is the finished executable	for Unix. When you are done, your 
		program should perform the same as this one does. 
	5. Submit only the .cpp file with your change. Name your file properly
		as usual.

Notes:
	1. An integer type or integer variable takes 4 bytes.
	2. When shifting a variable to left or right, 0 is filled in at the end 
		or the beginning.                                      
	3. Refer to CSC121 ClassNote2 "Number System", Chapter 22 and programs 
		fig22_06.cpp, fig22_08.cpp, fig22_11.cpp, Ex22_12.cpp and Ex22_13.cpp
		in textbook.

Created: 	10/3/2007 by Jin Guo.
Updated:	8/21/2018 by Jin Guo. Adapted for CSC122.
Updated:	2/7/2021 by Jin Guo. Adapted for this semester.
=====================================================================================
*/
#include <iostream>
#include <iomanip>

using namespace std;

void displayInBin(unsigned);	// print out number in binary
void displayInHex(unsigned);	// print out number in Hex	
void displayInOct(unsigned);	// print out nmber in Oct

void DecToHex(unsigned);		// print a digit in Hex
void DecToOct(unsigned);		// pirnt a digit in Oct

int main()
{
	// Print header.
	cout << "=============================================================\n";
	cout << "Harper CSC122-S01 by Mr. Jin Guo: Assignment #3, Spring 2021\n";
	cout << "Student: <Esat Duman>\n\n";
	cout << "This program will do some bitwise operations.\n";
	cout << "=============================================================\n\n";

	unsigned num1;
	unsigned num2;
	unsigned mask;

	cout << "Demonstrate bitwise AND, operator & ...\n";
	num1 = 123563121;
	mask = 255; // or mask = \xFF, i.e., 11111111;
	displayInBin(num1);
	displayInBin(mask);
	cout << "-------- -------- -------- --------\n";
	displayInBin(num1 & mask);

	cout << "\nDemonstrate bitwise OR, operator | ...\n";
	num1 = 126;
	num2 = 3214;
	displayInBin(num1);
	displayInBin(num2);
	cout << "-------- -------- -------- --------\n";
	displayInBin(num1 | num2);

	cout << "\nDemonstrate bitwise exclusive OR, operator ^ ...\n";
	num1 = 231;
	num2 = 453;
	displayInBin(num1);
	displayInBin(num2);
	cout << "-------- -------- -------- --------\n";
	displayInBin(num1 ^ num2);

	cout << "\nDemonstrate bitwise complement, operator ~ ...\n";
	num1 = 23435;
	cout << "The one's complement of\n";
	displayInBin(num1);
	cout << "-------- -------- -------- --------\n";
	displayInBin(~num1);

	cout << "\nPlease input a non-negative number (e.g., 127) ==> ";
	cin >> num1;

	cout << num1 << "(oct) : ";
	displayInOct(num1);
	cout << num1 << "(hex) : ";
	displayInHex(num1);

	cout << "\nDemonstrate two's complement with the above number:\n";
	cout << "The original:      ";
	displayInBin(num1);
	cout << "One's complement:  ";
	displayInBin(~num1);
	cout << "Two's complement:  ";
	unsigned m = (~num1) + 1;
	displayInBin(m);

	cout << "\nThe original + two's complement:\n";
	displayInBin(num1);
	displayInBin(m);
	cout << "-------- -------- -------- --------\n";
	displayInBin(num1 + m);
	cout << endl;

	return 0;
} 

void displayInBin(unsigned n)
{
	unsigned mask = (1 << 31); // shift "1" from righ-most to left most.

	for (int i = 1; i <= 32; i++) 
	{
		cout << (n & mask ? '1' : '0');
		mask >>= 1;

		if (i % 8 == 0) // output a space after 8 bits
			cout << ' ';
	} 
	cout << endl;
} 

void displayInOct(unsigned n) // Version 1
{
	unsigned tmp;
	
	// Process the first two digits.
	const unsigned mask1 = 3 << 30; // shift "11" from righ-most to left most.
	tmp = n & mask1;	// get the first 2 digits.
	tmp = tmp >> 30;	// shift the first 2 digits to right-most.
	DecToOct(tmp);		// print the last 2 digits in Oct.
	n <<= 2;			// shift the first 2 digits out.

	// Process the rest of the digits.
	const unsigned mask2 = 7 << 29; // shift "111" from righ-most to left most.

	for (int i = 1; i <= 10; i++)
	{
		tmp = n;
		tmp = tmp & mask2;	// get the first 3 digits.
		tmp = tmp >> 29;	// shift the first 3 digits to right-most.
		DecToOct(tmp);		// print the last 3 digits in Oct.
		n <<= 3;			// shift the first 3 digits out.
	}
	cout << endl;
}

/*
void displayInOct(unsigned n) // Version 2
{
	unsigned tmp;

	// Process the first two digits.
	unsigned mask1 = 3 << 30; // shift "11" from righ-most to left most.

	tmp = n & mask1;	// get the first 2 digits.
	tmp = tmp >> 30;	// shift the first 2 digits to right-most.
	DecToHex(tmp);		// print the last 2 digits in Oct.

	// Process the rest of the digits.
	unsigned mask2 = 7 << 29;	// shift "111" from righ-most to left most.
	mask2 >>= 2;				// skip the first two digits.

	for (int i = 1; i <= 10; i++)
	{
		tmp = n & mask2;			// get the first 3 digits.
		tmp = tmp >> (10 - i) * 3;	// shift the first 3 digits to right-most.
		DecToOct(tmp);				// print the last 3 digits in Oct.
		mask2 >>= 3;				// shift the first 3 digits out.
	}
	cout << endl;
}
*/

void displayInHex(unsigned n)
{
	/*
	=========================================
	<<<<<< Your code below... >>>>>
	=========================================
	*/
	unsigned tmp;

	const unsigned mask = 15 << 28;

	for (int i = 1; i <= 8; i++)
	{
		tmp = n;
		tmp = tmp & mask;
		tmp = tmp >> 28;
		DecToHex(tmp);
		n <<= 4;
	}
	
	cout << endl;
}

void DecToHex(unsigned n)
{
	switch (n)
	{ 
		case 0: cout << '0'; break;
		case 1: cout << '1'; break;
		case 2: cout << '2'; break;
		case 3: cout << '3'; break;
		case 4: cout << '4'; break;
		case 5: cout << '5'; break;
		case 6: cout << '6'; break;
		case 7: cout << '7'; break;
		case 8: cout << '8'; break;
		case 9: cout << '9'; break;
		case 10: cout << 'A'; break;
		case 11: cout << 'B'; break;
		case 12: cout << 'C'; break;
		case 13: cout << 'D'; break;
		case 14: cout << 'E'; break;
		case 15: cout << 'F'; break;
		default:
		{
			cout << "Something wrong in function DecToHex()!\n";
			exit(1);
		}
	}
}

void DecToOct(unsigned n)
{
	switch (n)
	{
		case 0: cout << '0'; break;
		case 1: cout << '1'; break;
		case 2: cout << '2'; break;
		case 3: cout << '3'; break;
		case 4: cout << '4'; break;
		case 5: cout << '5'; break;
		case 6: cout << '6'; break;
		case 7: cout << '7'; break;
		default:
		{
			cout << "Something wrong in function DecToOct()!\n";
			exit(1);
		}
	}
}

/* A Sample Output
=============================================================
Harper CSC122-S01 by Mr. Jin Guo: Assignment #3, Spring 2021
Student: <Your Name>

This program will do some bitwise operations.
=============================================================

Demonstrate bitwise AND, operator & ...
00000111 01011101 01101100 01110001
00000000 00000000 00000000 11111111
-------- -------- -------- --------
00000000 00000000 00000000 01110001

Demonstrate bitwise OR, operator | ...
00000000 00000000 00000000 01111110
00000000 00000000 00001100 10001110
-------- -------- -------- --------
00000000 00000000 00001100 11111110

Demonstrate bitwise exclusive OR, operator ^ ...
00000000 00000000 00000000 11100111
00000000 00000000 00000001 11000101
-------- -------- -------- --------
00000000 00000000 00000001 00100010

Demonstrate bitwise complement, operator ~ ...
The one's complement of
00000000 00000000 01011011 10001011
-------- -------- -------- --------
11111111 11111111 10100100 01110100

Please input a non-negative number (e.g., 127) ==> 127
127(oct) : 00000000177
127(hex) : 0000007F

Demonstrate two's complement with the above number:
The original:      00000000 00000000 00000000 01111111
One's complement:  11111111 11111111 11111111 10000000
Two's complement:  11111111 11111111 11111111 10000001

The original + two's complement:
00000000 00000000 00000000 01111111
11111111 11111111 11111111 10000001
-------- -------- -------- --------
00000000 00000000 00000000 00000000
*/

/*
************************************************
* (C) Copyright - by Jin Guo
*
* This program is free for my class students.
* For any other purpose of using this program,
* please ask for permisson by sending email to:
* taiji.guo@gmail.com
************************************************
*/
