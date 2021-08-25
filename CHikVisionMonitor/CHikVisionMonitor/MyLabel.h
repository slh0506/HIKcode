#pragma once
#include <QLabel>
#include <QMouseEvent>
class CMyLabel:public QLabel
{

	Q_OBJECT
public:
	explicit CMyLabel( QWidget* parent = 0);
	~CMyLabel();
signals:
	void clicked();
protected:
	void mousePressEvent(QMouseEvent *ev);

};

