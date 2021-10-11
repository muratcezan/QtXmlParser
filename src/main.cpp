#include <QCoreApplication>
#include <QDebug>

#include "hdr/xmlparser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    XmlParser xParse;

    return a.exec();
}
