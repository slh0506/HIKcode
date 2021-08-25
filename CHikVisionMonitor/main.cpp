#include "CHikVisionMonitor.h"
#include <QtWidgets/QApplication>
#include "DeviceInit.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CHikVisionMonitor w;
	w.show();
	return a.exec();
}
