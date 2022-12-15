#include "MainWindow.hpp"
#include "IPAddressField.hpp"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setCentralWidget(new IPAddressField);
}

MainWindow::~MainWindow()
{
}

