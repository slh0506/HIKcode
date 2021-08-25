#pragma once
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDateTime>
#include <QStringList>
#include <QMessageBox>
#include <QDebug>
class CMonitorDatabase :public QWidget
{
public:
	typedef	struct struSql
	{
		QString IP;
		int Port;
		QString Username;
		QString Password;
	}struSqliteData;
public:
	explicit CMonitorDatabase(QWidget* parent = 0);
	~CMonitorDatabase();
	//建立数据库连接
	bool createConnection();
	//数据库建表
	bool createTable();
	//数据插入信息
	bool insertValues(struSqliteData struSqlInfo);
	//数据库删除信息
	void deleteValues(const QString &strValues);
	//数据库替换信息
	void replaceValues(struSqliteData struSqlInfo,const int &id);
	//数据库信息行数
	int selectSize();
	//单独查询ID
	QStringList selectID();
	//查询单行全部数据
	struSqliteData selectRow(const int &iNum);
public:
	QSqlDatabase db;//类一个数据库
private:
	
};

