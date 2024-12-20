#include <bits/stdc++.h>
#include "structs.h"
#include "colors.h"
#include "search.h"

#pragma once

using namespace std;

void reservationReport(){
	cout<<"Enter the date for the report (dd-mm-yyyy): ";
	string date;
	cin>>date;

	//if(!validateDate(date)){
	//cout<<endl<<setColor(white, yellow)<<"Invalid Date or incorrect format"<<resetColor()<<endl<<endl;
	//	return;
	//}


	vector<reservation> report;

	for(reservation i:reservations){
		if(i.check_in == date) report.push_back(i);
	}

	if(!report.size()){
		cout<<endl<<setColor(white, yellow)<<"No reservations found on "<<date<<resetColor()<<endl<<endl;
		return;
	}

	cout<<"Reservations on "<<date<<":"<<endl<<endl;
	for(reservation i:report){
		cout<<i.name<<" in room "<<i.room_no<<" for "<<i.nights<<" nights."<<endl;
	}
	cout<<endl;
	return;

}