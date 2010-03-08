#include "couchutil.h"
#include <QTcpSocket>
#include <QStringList>

QString CouchUtil::database_name = "/test/";

CouchUtil::CouchUtil()
{
}

QByteArray CouchUtil::getData(QString url, QString data, QString method)
{
    url.prepend(database_name);
    QTcpSocket socket;

    socket.connectToHost("localhost",5984);
    socket.write(QString("%1 %2 HTTP/1.0\r\n").arg(method).arg(url).toAscii());
    socket.write("Host: localhost\r\n");

    if(!data.isNull())
    {
        socket.write(QString("Content-Length: %1\r\n").arg(data.length()).toAscii());
        socket.write("Content-Type: application/json\r\n");
        socket.write(QString("\r\n%1\r\n").arg(data).toAscii());
    }
    socket.write("\r\n");

    while( socket.waitForReadyRead( -1 ) )
        data.append( socket.readAll() );

    QStringList results = data.split("\n");
    foreach(QString text, results)
    {
        if(text.trimmed().isEmpty())
            break;
        else
            results.removeFirst();
    }

    return results.join("\n").trimmed().toAscii();
}
