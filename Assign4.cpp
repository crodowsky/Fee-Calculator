// Created by Cherie Rodowsky 09/30/2013
#include <iostream>
#include <iomanip>

using namespace std;

const double RegularServiceFee = 10.00;				//setup of constant amounts
const double RegularMinutecharge = 0.20;
const double PremiumServiceFee = 25.00;
const double DayMinuteFee = 0.20;					//premium service day minute fee charge
const double NightMinuteFee = 0.05;					//premium serice night minute fee charge
int main ()
{
	int x;
	int accountN, minutes,dayminutes,nightminutes;			//declare variables
	double amountDue,dayAmount,nightAmount;
	char service;

		cout << "Type your account number\n ";					//User inputs their account number
		cin >> accountN;

		cout << "Please enter an R for Regular service\n"		//User indicated service type
		<< "or a P for premium service: ";
		cin>>service;
		cout << endl;
		
	switch (service)								//Beginning of service type switch/calculation
	{
		case 'r':											//begin swith for the user with regular service
		case 'R':
			cout << "Enter the number of minutes used: ";	//request for use to enter the number of minutes they have used
			cin >> minutes;
			cout << endl;
			
		if (minutes >= 50)
			amountDue = RegularServiceFee +					//calculation for regular users amount due with more than 50 minutes used
			(minutes- 50)* RegularMinutecharge;
		else
			amountDue = RegularServiceFee;					//calculation for the regular users amount due with less than 50 minutes used
			
			cout << "Account number: "						//Output of user's account number
			<< accountN
			<< endl;
			
			cout <<"Service Type: "							//Output of user's service type
			 <<"Regular"
			<<endl;
		
			cout << fixed << showpoint << setprecision (2);		//output of regular service users amount due
			cout << "Amount Due: $"
			<< amountDue
			<< endl;
			break;

		case 'p':												//The switch for premium service users
		case 'P':
			cout << "Enter the number of minutes used during the day 6AM and 6PM: \n"; // user inputs number of day minutes
				cin>>dayminutes;
		
		if (dayminutes >=75)												//if else for premium day minute range
			dayAmount = (dayminutes-75)*DayMinuteFee;						//calculate day minutes over 75
		else
			dayAmount = 0;													//calculate day minutes under 75
		
		cout << "Enter the number of minutes used during the night 6PM to 6AM: \n"; //User inputs their number of night minutes
				cin >>nightminutes;

		if (nightminutes >=100)											//if else for premium night minute range
			nightAmount = (nightminutes - 100)*NightMinuteFee;			//calculation for night minutes over 100
		else
			nightAmount = 0;											//calculation for night minutes under 100
			
			amountDue = PremiumServiceFee + dayAmount + nightAmount;	//caluclation of Premium user's amount due
		
			cout << "Account Number: "								//Output of premium account number
			<< accountN
			<< endl;
			
			cout <<"Service Type: "									//Output of premium serivce type
			<< "Premium"
			<<endl;
			
			cout << fixed << showpoint << setprecision (2);			//Output of premium user's amount due
			cout << "Amount Due: $"								
			<< amountDue
			<< endl;
			break;

		default:												//default for incorrect service type entry
			cout << "Error please enter an R or a P to indicate your service type" << endl;
	}

	cin>>x;
}