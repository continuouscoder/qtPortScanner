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

// initial test is way too slow: 2.20 for a range of 80 - 8888 on local host.  python did the same range in 1.08.
// changing the waitforconnected to 2ms gave mea  result of 24s to run 80-8888! way faster.
// Even faster, lowering to a 1ms wait time, got me the same accuracy, at 11s.
// Fastest I could get python to run was 1m 09s.
