#include "couchutil.h"
#include <QByteArray>
#include <QVariantMap>
#include <qjson/parser.h>
#include <qjson/serializer.h>
#include <QDebug>

int main(int argc, char *argv[])
{

    bool ok;
    QByteArray json = CouchUtil::getData("alexandre");
    QJson::Parser parser;
    QJson::Serializer serializer;

    if(json.contains("no_db_file"))
    {
        qDebug() << CouchUtil::getData("",json,"PUT");
        return 1;
    }

    QVariantMap result = parser.parse (json, &ok).toMap();

    if(!ok)
    {
        qDebug() << parser.errorString();
        return 1;
    }

    if(result.value("error").isValid())
    {
        result.clear();
        result.insert("_id","alexandre");
        result.insert("age",27);
        json = serializer.serialize(result);
        qDebug() << CouchUtil::getData("alexandre",json,"PUT");
        return 0;
    }
    else
    {
        QVariantList childrens;
        childrens.append("Isabella");
        childrens.append("Isadora");
        result.insert("childrens",childrens);
        result.insert("wife","Marcinha");
        json = serializer.serialize(result);
        qDebug() << CouchUtil::getData("alexandre",json,"PUT");
    }
    return 1;
}

