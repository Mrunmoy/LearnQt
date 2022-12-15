#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

class IPAddressField : public QWidget
{
public:
    IPAddressField(QWidget *parent = nullptr);
    virtual ~IPAddressField();

public slots:
    void onEditingFinished(QLineEdit* sender);
    void onInputRejected(QLineEdit* sender);
    void onReturnPressed(QLineEdit* sender);
    void onTextChanged(QLineEdit* sender, const QString &text);
    void onTextEdited(QLineEdit* sender, const QString &text);

private:
    static constexpr int    kNumSegments = 4;
    QLineEdit*              m_ipSeg[kNumSegments];
};

