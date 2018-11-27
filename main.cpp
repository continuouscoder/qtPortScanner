#include <QCoreApplication>
#include <iostream>
#include <QtNetwork/QTcpSocket>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char server[20];
    quint16 startPort;
    quint16 endPort;
    int waitTime;

    // Only scan servers you have permission to scan....
    qInfo() << "Server IP: ";
    cin >> server;
    qInfo() << "Start Port: ";
    cin >> startPort;
    qInfo() << "End Port: ";
    cin >> endPort;
    qInfo() << "Wait time(ms): ";
    cin >> waitTime;
    QTcpSocket socket;
    QByteArray dataSent;
    for(quint16 i = startPort; i < endPort; i++){
        socket.connectToHost(server, i);
        if(socket.waitForConnected(waitTime)){
            qInfo() << "Open Port: " << i;
            socket.disconnectFromHost();
        }
    }

    qInfo() << "Scan Complete";
    return a.exec();
}

// User definatble wait time(ms) was added.
