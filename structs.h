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
vector<reservation> reservations;
vector<room> rooms;

int resID = 1;

void newID(){
    //for now
    resID++;
}