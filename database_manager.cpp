#include "database_manager.h"
#include <QtSql/QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

DatabaseManager::~DatabaseManager()
{
    closeDatabase();
}

DatabaseManager& DatabaseManager::instance()
{
    static DatabaseManager instance;
    return instance;
}

bool DatabaseManager::openDatabase(const QString& path)
{
    db.setDatabaseName(path);

    if (!db.open()) {
        qDebug() << "DB open error:" << db.lastError().text();
        return false;
    }

    qDebug() << "Database connected";
    return true;
}

void DatabaseManager::closeDatabase()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::isOpen() const
{
    return db.isOpen();
}

QSqlDatabase DatabaseManager::database() const
{
    return db;
}