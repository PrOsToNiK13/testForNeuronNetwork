#ifndef DATABASE_H
#define DATABASE_H
#include <QWidget>

class database
{
public:
    database();
    //основное
    static bool connectToDataBase(QString path);
    static bool openDataBase(QString path);
    static bool restoreDataBase(QString path);
    static bool createTables();

};

#endif // DATABASE_H
