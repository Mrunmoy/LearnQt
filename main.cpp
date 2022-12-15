#include "MainWindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    auto result = a.exec();

    qDebug() << "End of main()";

    return result;
}
