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
	//�������ݿ�����
	bool createConnection();
	//���ݿ⽨��
	bool createTable();
	//���ݲ�����Ϣ
	bool insertValues(struSqliteData struSqlInfo);
	//���ݿ�ɾ����Ϣ
	void deleteValues(const QString &strValues);
	//���ݿ��滻��Ϣ
	void replaceValues(struSqliteData struSqlInfo,const int &id);
	//���ݿ���Ϣ����
	int selectSize();
	//������ѯID
	QStringList selectID();
	//��ѯ����ȫ������
	struSqliteData selectRow(const int &iNum);
public:
	QSqlDatabase db;//��һ�����ݿ�
private:
	
};

