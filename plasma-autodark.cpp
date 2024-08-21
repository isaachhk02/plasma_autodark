/*
KDE Plasma Auto Dark Mode
Created by hhk02
*/

#include "plasma-autodark.h"

void ChangeToDarkTheme() {
    if (fopen("/usr/bin/lookandfeeltool","r"))
    {
        printf("Changing to dark theme\n");
        popen("bash -c '/usr/bin/lookandfeeltool -a org.kde.breezedark.desktop'","r");
    }
}
void ChangeToLightTheme() {
    if (fopen("/usr/bin/lookandfeeltool","r"))
    {
        printf("Changing to light theme\n");
        popen("bash -c '/usr/bin/lookandfeeltool -a org.kde.breeze.desktop'","r");
    }
}

void Update()
{
    auto lt = std::chrono::system_clock::now();
    time_t atime = std::chrono::system_clock::to_time_t(lt);
    tm *info = localtime(&atime);

    if (info->tm_hour >= 18)
    {
        ChangeToDarkTheme();
    }
    else {
        printf("INFO: No change for the moment\n");
    }
    if (info->tm_hour > 7)
    {
        ChangeToLightTheme();
    } else {
        printf("INFO: No change for the moment\n");
    }
}

int main(int argc, int argv[]) {
    Update();
}
