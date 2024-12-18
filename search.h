#include <bits/stdc++.h>
#include "structs.h"
#include "colors.h"

#pragma once

using namespace std;


// ------------------------------------------------------------------- RESEVATION SEARCHES -------------------------------------------

int searchReservationByID(string ID) // returns the index of the reservation 
{
    for(int i=0;i<reservations.size();i++)
    {
        if(reservations[i].id == ID)return i;
    }
    return -1;
}


int searchReservationByRoomNumber(string number) // returns the index of the reservation
{
    for(int i=0;i< reservations.size() ;i++)
    {
        if(reservations[i].room_no == number)return i;
    }
    return -1;
}


//------------------------------------------------------------- ROOM SEARCHES ---------------------------------------------------------------------

int searchRoomByCategory(string cat)
{
    if(cat == "S")cat = "SeaView";
    if(cat == "L")cat = "LakeView";
    if(cat == "G")cat = "GardenView";
    for(int i=0; i<rooms.size() ;i++)
    {
        if(rooms[i].type == cat && rooms[i].type == "Available")return i;
    }
    return -1;
}



int searchRoomByNumber(string num)
{
    for(int i=0; i<rooms.size() ;i++)
    {
        if(rooms[i].room_no == num)return i;
    }
    return -1;
}