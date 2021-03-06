#include "pch.h"
#include <iostream>
#include <string>
#include "customer.h"
#include "ticket.h"
#include "show.h"
#include "showSeat.h"
#include <Windows.h>
#include <stdio.h>


int main()
{
	system("color 8f");//changes the color of the system

	/////////////////////////////////////////////////////////////
	//Initial variable declarations
	string a,
		b,
		c,
		f,
		g,
		h
		;

	int d;
	double e, l;//discount

	char ch,
		terminator;

	/////////////////////////////////////////////////////////////
	//Objects
	showSeat SEAT;
	Customer CUST;
	Show SHOW;
	ticket TICK;
	/////////////////////////////////////////////////////////////
	//Deals with getting customer's information

	CUST.getLogin();
	CUST.getProfileInfo(f,g,h);

	/////////////////////////////////////////////////////////////
	//Displays Main Menu, and allows customer to choose option

	system("CLS");
	do
	{
		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MAIN MENU ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n" << endl;

		cout << "1. Buy tickets for upcoming shows" << endl;
		cout << "2. View Shows" << endl;
		cout << "3. Log out\n" << endl;
		cout << "Please enter a menu choice number: ";
		cin.get(ch);

		while (ch != '1' && ch != '2' && ch != '3')
		{
			cin.clear();
			cin.ignore(100, '\n');// ensures buffer is completrly clear (if, say, the user has previosly input a long string)
			cout << "Please select a valid menu choice number: ";
			cin.get(ch);
		}
		if (ch == '2')
		{
			cout << "\n";
			cout << "THE SHOWS WILL BE DISPLAYED FOR 10 SECONDS!\n";
			cout << "1. Star Wars: The Musical (20/05/2013)      1pm & 7pm" << endl;
			cout << "2. Les Miserables (21/05/2013)              1pm & 7pm" << endl;
			cout << "3. The Phantom of the Opera (22/05/2013)    1pm & 7pm" << endl;

			Sleep(10000); //Sleeps for 10000 ms or 10 sec

			system("CLS");
		}
		if (ch == '3')
		{
			return EXIT_SUCCESS;
		}
	} while (ch!='1');


	////////////////////////////////////////////////////////////////////////////////////////////////////
	//Deals with selecting a show
	do
	{
		SHOW.selectShow(a, b);
		SHOW.selectTime(c);

		do
		{
			cout << "\nAre you happy with yout choice (Y=Yes, N=No)?: ";
			cin.get(ch);

		} while (ch!='Y' && ch!='y' &&ch!='N' && ch!='n');
		cin.get(terminator);//clears buffer
		system("CLS");
	} while (ch=='N' || ch=='n');
	////////////////////////////////////////////////////////////////////////////////////////////////////
	//Deals with selecting seat and calculating price of seats
	
	SEAT.initialiseFloorPlan();
	d = SEAT.getNumSeats();
	e=SEAT.getSeatSelection();
	cout << " Your final price is: " << (char)156 << e << endl;
	cin.get(terminator);//clears buffer
	Sleep(3000); //Sleeps for 3000 ms or 3 sec
	system("CLS");
	////////////////////////////////////////////////////////////////////////////////////////////////////
	//Deals with discounts, payment and ticket generation
	
	l = 0;
	l = TICK.getDiscount(e, l);
	Sleep(2000);
	system("CLS");
	CUST.getPaymentInfo();
	system("CLS");
	TICK.getTicketinfo(f,g,h,a,b,c,e,d,l);
	cin.get(terminator);//clears buffer

	////////////////////////////////////////////////////////////////////////////////////////////////////
	system("pause");
	return EXIT_SUCCESS;






}

