#ifndef COUCHUTIL_H
#define COUCHUTIL_H

#include <QString>

class CouchUtil {
public:
    static QByteArray getData(QString url,QString data = NULL,QString method = "GET");
    static QString database_name;
private:
    CouchUtil();
};
#endif // COUCHUTIL_H
