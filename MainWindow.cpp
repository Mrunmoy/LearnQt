#include "MainWindow.hpp"
#include "IPAddressField.hpp"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug() << __FUNCTION__;
    setCentralWidget(new IPAddressField);
}

MainWindow::~MainWindow()
{
    qDebug() << __FUNCTION__;
}

