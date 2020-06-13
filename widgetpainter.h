#ifndef WIDGETPAINTER_H
#define WIDGETPAINTER_H

#include <QWidget>

namespace Ui {
class WidgetPainter;
}

class WidgetPainter : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetPainter(QWidget *parent = nullptr);
    ~WidgetPainter();

private:
    Ui::WidgetPainter *ui;

protected:
    void    paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    float m_x,m_y,m_m,m_E,m_I,m_l,m_step,m_xratio,m_thetaB,m_TangentLength;
    int m_num;
public:
    void Setm(float);
    void SetE(float);
    void SetI(float);
    void SetStep(float);
    void SetXRatio(float);
    void SetNum(int);
    void SetTan(float);
};

#endif // WIDGETPAINTER_H
