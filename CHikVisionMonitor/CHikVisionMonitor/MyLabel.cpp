#include "MyLabel.h"



CMyLabel::CMyLabel(QWidget* parent)
	:QLabel(parent)
{
	
}


CMyLabel::~CMyLabel()
{
}
void CMyLabel::mousePressEvent(QMouseEvent *ev)
{
	if (ev->button() == Qt::LeftButton)
	{
		emit clicked();
	}
	QLabel::mousePressEvent(ev);
}