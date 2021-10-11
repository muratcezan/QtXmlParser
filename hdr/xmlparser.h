#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QObject>
#include <QtXml>

class XmlParser : public QObject
{
    Q_OBJECT
public:
    explicit XmlParser(QObject *parent = nullptr);
    void elements(QDomElement root, QString tagname, QString attribute, QString attribute2);

signals:

};

#endif // XMLPARSER_H
