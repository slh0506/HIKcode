#include "MonitorDatabase.h"

CMonitorDatabase::CMonitorDatabase(QWidget* parent)
	: QWidget(parent)
{
}

bool CMonitorDatabase::createConnection()//建立数据库连接，新建数据库
{
	db = QSqlDatabase::addDatabase("QSQLITE", "device_sqlite");
	db.setDatabaseName("deviceDB");
	if (!db.open())
	{
		qDebug() << QObject::tr("open failed！\n");
		return false;
	}
	return true;
	db.close();
}

bool CMonitorDatabase::createTable()//新建数据库表
{
	db.database("device_sqlite");
		if (!db.open())
		{
			qDebug() << QObject::tr("open failed！\n");
			return false;
		}
		else
		{
			qDebug() << QObject::tr("open success！\n");
			QSqlQuery query(db);
			bool b = query.exec("create table device(IP varchar,Port varchar,Username varchar, Password varchar, id INTEGER PRIMARY KEY AUTOINCREMENT)");
			//query.next();
			if (!b)
			{
				qDebug() << QObject::tr("table failed！\n");
				qDebug() << "query error :" << query.lastError();
			}
			else
			{
				qDebug() << QObject::tr("table success！\n");
			}
			return true;
		}	
		db.close();
	
}

bool CMonitorDatabase::insertValues(const struSqliteData &struSqlInfo)//数据库插入信息
{
	db = QSqlDatabase::addDatabase("QSQLITE", "device_sqlite");
	db.setDatabaseName("deviceDB");
	/*db.database("device_sqlite");*/
	QSqlQuery query(db);
	if (!db.open())
	{
		qDebug() << QObject::tr("open failed！\n");
	}
	else
	{
		qDebug() << QObject::tr("open success！\n");
	}
	
	query.prepare("INSERT INTO device(IP, Port, Username, Password, id)"
		"VALUES (?, ? ,? ,?, NULL)");
	query.addBindValue(struSqlInfo.IP);
	query.addBindValue(struSqlInfo.Port);
	query.addBindValue(struSqlInfo.Username);
	query.addBindValue(struSqlInfo.Password);
	if (!query.exec()) 
	{
		qDebug() << "insert data failed!";
		qDebug() << "query error :" << query.lastError();
		return false;
	}
	else 
	{
		qDebug() << "insert data success!";
		return true;
	}
	db.close();
}

void CMonitorDatabase::replaceValues(const struSqliteData &struSqlInfo,const int &id)//数据库替换信息
{
	QSqlQuery query(db);
	db.database("device_sqlite");
	if (!db.open())
	{
		qDebug() << QObject::tr("open failed！\n");
	}
	else
	{
		qDebug() << QObject::tr("open success！\n");
	}
	QString strModify = QString("update device set IP = '%1', Port = '%2', Username = '%3', Password = '%4' where id='%5'")
		.arg(struSqlInfo.IP).arg(struSqlInfo.Port).arg(struSqlInfo.Username).arg(struSqlInfo.Password).arg(id);
	query.prepare(strModify);
	if (!query.exec())
	{
		qDebug() << "replace data failed!";
		qDebug() << "query error :" << query.lastError();
	}
	else
	{
		qDebug() << "replace data success!";
	}
	db.close();
}

void CMonitorDatabase::deleteValues(const QString &strValues)//删除数据库信息
{
	db = QSqlDatabase::addDatabase("QSQLITE", "device_sqlite");
	db.setDatabaseName("deviceDB");
	QSqlQuery query(db);
	bool bok = db.open();
	if (!bok)
	{
		qDebug() << "open data failed!";
		qDebug() << "query error :" << query.lastError();
	}
	else
	{
		qDebug() << "open data success!";
	}

	QString strDelete = QString("DELETE FROM device where IP = '%1'").arg(strValues);
	query.exec(strDelete);
	db.close();
}

int CMonitorDatabase::selectSize()
{
	db = QSqlDatabase::addDatabase("QSQLITE", "device_sqlite");
	db.setDatabaseName("deviceDB");
	db.database("device_sqlite");
	QSqlQuery queryAll("SELECT IP FROM device", db);
	int count = 0;
	if (queryAll.last())
	{
		count = queryAll.at() + 1;
	}
	else
	{
		count = 0;
	}
	bool bok = db.open();
	if (!bok)
	{
		qDebug() << "open data failed!";
		qDebug() << "query error :" << queryAll.lastError();
	}
	else
	{
		qDebug() << "open data success!";
	}
	db.close();
	return count;
}

QStringList CMonitorDatabase::selectID()
{
	db = QSqlDatabase::addDatabase("QSQLITE", "device_sqlite");
	db.setDatabaseName("deviceDB");
	db.database("device_sqlite");
	QSqlQuery query("SELECT id FROM device ORDER BY id asc", db);
	QStringList m_strlistID;//存放ID
	while (query.next())
	{
		m_strlistID.push_back(query.value(0).toString());
	}
	return m_strlistID;
}

CMonitorDatabase::struSqliteData CMonitorDatabase::selectRow(const int &iNum)
{
	db = QSqlDatabase::addDatabase("QSQLITE", "device_sqlite");
	db.setDatabaseName("deviceDB");
	db.database("device_sqlite");
	QSqlQuery query(db);
	QString strSelect = QString("SELECT * FROM device where id = '%1'").arg(iNum);
	query.exec(strSelect);
	struSqliteData struSQLInfo;
	while (query.next())
	{
		struSQLInfo.IP = query.value(0).toString();
		struSQLInfo.Port = query.value(1).toInt();
		struSQLInfo.Username = query.value(2).toString();
		struSQLInfo.Password = query.value(3).toString();
	}
	return struSQLInfo;
}

CMonitorDatabase::~CMonitorDatabase()
{
}
