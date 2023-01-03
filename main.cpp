#include <QApplication>
#include <QtSql>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QPaintEvent>
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
