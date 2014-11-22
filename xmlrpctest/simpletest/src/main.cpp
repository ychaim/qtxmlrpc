
#include <QCoreApplication>
#include <QWaitCondition>
#include <QDebug>
#include <QMutex>
#include <QTimer>

#include "server.h"
#include "client.h"


int main( int argc, char **argv )
{
    QCoreApplication    app( argc, argv );
    QTimer::singleShot( 20000, &app, SLOT( quit()) );

    qDebug() << "Test build with Qt " << QT_VERSION_STR ;

    QString address = "127.0.0.1";
    quint16 port    = 8080;
    TServer s( address, port );
    Client  c( address, port );

    QTimer::singleShot( 1, &c, SLOT( start() ) );

    return app.exec();

    Q_UNUSED(s);
}
