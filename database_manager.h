#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <QtSql/QSqlDatabase>

class DatabaseManager
{
public:
    static DatabaseManager& instance();

    bool openDatabase(const QString& path);
    void closeDatabase();
    bool isOpen() const;

    QSqlDatabase database() const;

private:
    DatabaseManager();
    ~DatabaseManager();

    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    QSqlDatabase db;
};

#endif // DATABASE_MANAGER_H