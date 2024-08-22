/*
KDE Plasma Auto Dark Mode
Created by hhk02
*/
#include "autodark.h"

void set_theme(const QString& themeName)
{
    QString c = QString::fromLatin1("%1/.config/plasmarc").arg(getenv("HOME"));
    KConfig configuration(c);
    KConfigGroup generalgroup = configuration.group("Theme");

    generalgroup.writeEntry("LookAndFeel",themeName);
    configuration.sync();

    QProcess::execute("qdbus org.kde.KWin /KWin reconfigure");
}

int main() {
    info = localtime(atime);

    if (info->tm_hour >= 7)
    {
        set_theme("Breeze");
    }
    if (info->tm_hour >= 19)
    {
        set_theme("BreezeDark");
    } else {
        std::cout << "INFO: Running in background..." << std::endl;
    }
    
    
}
