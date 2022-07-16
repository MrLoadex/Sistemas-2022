/**
* Copyright (c) 2017 Gabriel Ferreira <gabrielinuz@gmail.com>. All rights reserved. 
* Timer (first example)
* Released under the GPL3 license
* https://opensource.org/licenses/GPL-3.0
**/


#ifdef __unix__
    #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif __APPLE__
    #include <unistd.h>

// defined


#include <string>
#include <iostream>

using namespace std;

//Variables Globales (hablaremos en clase...)
int seconds = 0;


void showTime()
{
    seconds++;
    int dias, horas, min, seg;
    dias = seconds / 86400;
    horas = seconds / 3600;
    min = seconds / 60;
    seg = seconds % 60;

    string hoursText = to_string(horas);
    string minutesText = to_string(min);
    string secondsText = to_string(seg);

    if(hoursText.size() == 1){hoursText = "0"+hoursText;}
    if(minutesText.size() == 1){minutesText = "0"+minutesText;}
    if(secondsText.size() == 1){secondsText = "0"+secondsText;}

    if(dias != 0)
    {
        cout << "Dias: " << endl;
    }
    
    cout << hoursText << ":" << minutesText << ":" << secondsText << endl;
}

int main()

{
    //En la terminal de visual studio pueden cortar la ejecución
    //de este "while" con CTRL+C
    while(1)
    {
        showTime();

        #ifdef __unix__ || __APPLE__
            sleep(1);
            system("clear");
        #elif defined(_WIN32) || defined(WIN32)
            Sleep( 1000 );
            system("cls");
        #endif  // defined
    }
    return 0;
}
