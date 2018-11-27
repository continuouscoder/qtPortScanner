#include <QCoreApplication>
#include <iostream>
#include <QtNetwork/QTcpSocket>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    char server[20];
    quint16 startPort;
    quint16 endPort;

//    qInfo() << "Server IP: ";
//    cin >> server;
    qInfo() << "Start Port: ";
    cin >> startPort;
    qInfo() << "End Port: ";
    cin >> endPort;

    for(quint16 i = startPort; i < endPort; i++){
        QTcpSocket *socket = new QTcpSocket();
        socket -> connectToHost("0.0.0.0", i);
        if(socket->waitForConnected(5000)){
            qInfo() << "Connected on Port ";
            qInfo() << i;
            socket ->disconnectFromHost();
        }
    }

    qInfo() << "Scan Complete";
    return a.exec();
}
