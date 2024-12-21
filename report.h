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
	cout<<"ID\tRoom\tStatus\t\tDate\t\tNo of nights\tName\t\tNational ID\t\tE-mail\t\t\tPhone"<<endl;
	for(reservation r:report){
		cout<<r.id<<"\t"<<r.room_no<<"\t"<<r.confirm<<"\t"<<r.check_in<<"\t"<<r.nights<<"\t\t"<<r.name<<"\t"<<r.nat_id<<"\t\t"<<r.email<<"\t"<<r.phone<<endl;
	}
	cout<<endl;
	return;

}