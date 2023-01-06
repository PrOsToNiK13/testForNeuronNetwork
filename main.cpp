#include <QApplication>
#include <QtSql>
#include <QWidget>
#include <mainwindow.h>
#include "database.h"

int main( int argc, char ** argv )
{
    QApplication app( argc, argv );

    database::connectToDataBase("./database.db");

    MainWindow w;
    w.show();

    return app.exec();
}
