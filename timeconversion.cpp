#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

/* tests:
 *  07:05:45PM -> 19:05:45
 *  12:00:00AM -> 00:00:00
 *  12:00:00PM -> 12:00:00
 *  12:00:01PM -> 12:00:01
 *  13:00:01PM -> 13:00:01
 *  12:00:01AM -> 00:00:01
 *  01:00:01AM -> 01:00:01
 */

int main(){
    string time;
    cin >> time;
    if(time.length() != 10)
        return 0;
    if(time == "12:00:00AM")
        cout << "00:00:00" << endl;
    else if(time == "12:00:00PM")
        cout << "12:00:00" << endl;
    else {
        string unchangable = time.substr(2, time.length() - 4);
	string str_hh = time.substr(0,2);
        int hh = atoi(str_hh.c_str());
        if(time[time.length() - 2] == 'P') {
            if(hh != 12)
                hh += 12;
        } else {
            if(hh == 12)
                hh -= 12;
        }

        if(hh < 10)
            cout << '0';
        cout << hh << unchangable << endl;
    }

    /*
    * Option B
    static char am[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0};
    static char pm[] = {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 0};

    string unchangable = time.substr(2, time.length() - 4);
    string str_hh = time.substr(0,2);
    int hh = atoi(str_hh.c_str());
    if(time[time.length() - 2] == 'A')
	    hh = am[hh];
    else
	    hh = pm[hh];
    if(hh < 10)
	    cout << '0';
    cout << hh << unchangable << endl;*/


    return 0;
}


