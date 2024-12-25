#include <bits/stdc++.h>
#pragma once
using namespace std;

struct user{
    string username;
    string pw;
};

struct reservation{
    string id;
    string room_no;
    string confirm;
    string name;
    string nat_id;
    string nights;
    string check_in;
    string email;
    string phone;
};

struct room{
    string room_no;
    string status;
    string type;
    string price;
};


vector<user> users;
vector<reservation> reservations,reservationsOG;
vector<room> rooms,roomsOG;

long long resID = 1;
string today;

void getDate(){
    time_t t = time(nullptr);
    tm* local = localtime(&t);
    string year = to_string(local->tm_year + 1900);
    string month = to_string(local->tm_mon + 1);
    if(month.size()==1) month = "0"+month;
    string day = to_string(local->tm_mday);
    if(day.size()==1) day = "0"+day;
    today = day + "-" + month + "-" + year;
}

void newID(){
    //resID++;
    bool flag;
    do{
        flag = 0;
        srand(time(0));
        resID = rand();
        for(reservation r : reservations) if(r.id == to_string(resID)) {flag = 1; break;}
    }while(flag);
}
