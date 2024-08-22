#define AUTODARK_H

#include <KConfig>
#include <KConfigGroup>
#include <QProcess>
#include <QString>

#include <iostream>

int hour;
int min;
tm *info;
time_t *atime;
auto lt = std::chrono::system_clock::now();
void set_theme(const QString& themeName);
