#include "../hdr/xmlparser.h"

XmlParser::XmlParser(QObject *parent) : QObject(parent)
{
    QDomDocument doc("data");
    QFile file("/home/czn/Projects/xmlParser/data.xml");

    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "File Read Error!";
        return;
    }
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();


    QDomElement docElem = doc.documentElement();

    elements(docElem,"rec", "usagecount","type");
}

void XmlParser::elements(QDomElement root, QString tagname, QString attribute, QString attribute2)
{
    QDomNodeList items = root.elementsByTagName(tagname);

    qDebug() << "Total Items = " << items.count();

    for(int i=0;i<items.count();i++){
        QDomNode itemNode = items.at(i);

        // convert to element
        if(itemNode.isElement())
        {
            QDomElement itemEle = itemNode.toElement();
            qDebug() << "Attr 1 =" << itemEle.attribute(attribute);
            qDebug() << "Attr 2 =" << itemEle.attribute(attribute2);
        }
    }
}
