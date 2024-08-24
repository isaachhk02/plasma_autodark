/*"
KDE Plasma Auto Dark Mode
Created by hhk02
*/
#include "autodark.h"
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

FILE * lookandfeeltool;
void set_theme_dark()
{
    lookandfeeltool = popen("/usr/bin/lookandfeeltool","-a org.kde.breezedark.desktop");
    if (lookandfeeltool == NULL) {
        std::cout << "Changing to dark mode!" << std::endl;
    }
}

void set_theme_light() {
    lookandfeeltool = popen("/usr/bin/lookandfeeltool", "-a org.kde.breeze.desktop");
    if (lookandfeeltool == NULL) {
        std::cout << "Changing to light mode!" << std::endl;
    }
}

int main() {
    tm *info; 
    time_t *attime;
    auto lt = chrono::system_clock::now();
    info = localtime(attime);

    if (info->tm_hour <= 7)
    {
        set_theme_dark();
    }

    if (info->tm_hour >= 7)
    {
        set_theme_light();
    }
    if (info->tm_hour >= 19)
    {
        set_theme_dark();
    } else {
        std::cout << "INFO: Running in background..." << std::endl;
    }
}
