#include "IPAddressField.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QIntValidator>
#include <QDebug>

IPAddressField::IPAddressField(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << __FUNCTION__;

    setFixedWidth(300);

    const QString lineEditStyle = "QLineEdit{ "
                    "background-color:rgb(202, 255, 227);"
                    "border: 2px solid gray;"
                    "border-radius: 5px;"
                    "padding: 0 8px;"
                    "selection-background-color: darkgray;"
                    "font-size: 16px;}"
                    "QLineEdit:focus { "
                    "background-color:rgb(192, 192, 255);}";

    QHBoxLayout* layout = new QHBoxLayout(this);

    for (int i = 0; i < kNumSegments; ++i)
    {
        m_ipSeg[i] = new QLineEdit(this);
        m_ipSeg[i]->setStyleSheet(lineEditStyle);
        m_ipSeg[i]->setMaximumWidth(60);
        m_ipSeg[i]->setFixedWidth(55);
        m_ipSeg[i]->setValidator(new QIntValidator(1, 255, nullptr));

        connect(m_ipSeg[i], &QLineEdit::editingFinished, this, std::bind(&IPAddressField::onEditingFinished, this, m_ipSeg[i]));
        connect(m_ipSeg[i], &QLineEdit::inputRejected, this, std::bind(&IPAddressField::onInputRejected, this, m_ipSeg[i]));
        connect(m_ipSeg[i], &QLineEdit::returnPressed, this, std::bind(&IPAddressField::onReturnPressed, this, m_ipSeg[i]));
        connect(m_ipSeg[i], &QLineEdit::textChanged, this, std::bind(&IPAddressField::onTextChanged, this, m_ipSeg[i], std::placeholders::_1));
        connect(m_ipSeg[i], &QLineEdit::textEdited, this, std::bind(&IPAddressField::onTextEdited, this, m_ipSeg[i], std::placeholders::_1));
    }

    const QString labelStyle = "QLabel{ "
                               "font: bold;"
                               "font-size: 16px;}";

    layout->addWidget(m_ipSeg[0]);
    QLabel* sep1 = new QLabel(this);
    sep1->setText(".");
    sep1->setStyleSheet(labelStyle);
    layout->addWidget(sep1);

    layout->addWidget(m_ipSeg[1]);
    QLabel* sep2 = new QLabel(this);
    sep2->setText(".");
    sep2->setStyleSheet(labelStyle);
    layout->addWidget(sep2);

    layout->addWidget(m_ipSeg[2]);
    QLabel* sep3 = new QLabel(this);
    sep3->setText(".");
    sep3->setStyleSheet(labelStyle);
    layout->addWidget(sep3);

    layout->addWidget(m_ipSeg[3]);
}

IPAddressField::~IPAddressField()
{
    qDebug() << __FUNCTION__;
}

void IPAddressField::onEditingFinished(QLineEdit* sender)
{
    qDebug() << __FUNCTION__;
    qDebug() << "value: " << sender->text();
}

void IPAddressField::onInputRejected(QLineEdit* sender)
{
    qDebug() << __FUNCTION__;
    qDebug() << "value: " << sender->text() << " is invalid";
}

void IPAddressField::onReturnPressed(QLineEdit* sender)
{
    qDebug() << __FUNCTION__;
    qDebug() << "value: " << sender->text();
}

void IPAddressField::onTextChanged(QLineEdit* sender, const QString &text)
{
    qDebug() << __FUNCTION__;
    qDebug() << "value: " << text;
}

void IPAddressField::onTextEdited(QLineEdit* sender, const QString &text)
{
    qDebug() << __FUNCTION__;
    qDebug() << "value: " << text;
}
