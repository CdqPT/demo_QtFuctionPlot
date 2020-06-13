#include "widgetpainter.h"
#include "ui_widgetpainter.h"
#include    <QPainter>
#include<QtMath>
WidgetPainter::WidgetPainter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetPainter)
{
    m_x=0.0;
    m_y=0.0;
    m_E=128000.0;
    m_I=0.02;
    m_m=10.0;
    m_num=1000;
    m_step=0.1;
    m_l=m_step*m_num;
    m_xratio=1.0;
    m_TangentLength=30.0;
    m_thetaB=-(m_m*m_l)/(m_E*m_I);

    ui->setupUi(this);
}

WidgetPainter::~WidgetPainter()
{
    delete ui;
}

void WidgetPainter::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);//渲染
    painter.setRenderHint(QPainter::TextAntialiasing);//文本渲染

    float W=this->width(); //绘图区宽度
    float H=this->height(); //绘图区高度

    float base_x= W/2;
    float base_y= H/2;

    QPoint points[m_num];

    for(int i=0;i<m_num;i++)
    {
        points[i].setX(base_x+m_x*m_xratio);
        points[i].setY(base_y+m_y);

        m_x+=m_step;
        m_y=m_m/(2*m_E*m_I)*(m_x*m_x);
    }
    m_x=m_y=0;

//绘制曲线
    QPainterPath  path(points[0]);
    for (int i = 0; i < m_num-2; ++i) {
        QPointF sp = points[i];
        QPointF ep = points[i+1];
        QPointF c1 = QPointF((sp.x() + ep.x()) / 2, sp.y());
        QPointF c2 = QPointF((sp.x() + ep.x()) / 2, ep.y());
        path.cubicTo(c1, c2, ep);
    }


//设置画笔
   QPen    pen;
   pen.setStyle(Qt::SolidLine);//线的类型，实线、虚线等
   pen.setCapStyle(Qt::FlatCap);//线端点样式
   pen.setJoinStyle(Qt::BevelJoin);//线的连接点样式


   pen.setColor(Qt::black); //划线颜色
   pen.setWidth(1); //线宽
   painter.setPen(pen);

   painter.drawLine(0,H/2,W,H/2);
   painter.drawLine(W/2,H,W/2,0);

   pen.setColor(Qt::red); //划线颜色
   pen.setWidth(3); //线宽
   painter.setPen(pen);
   painter.drawPath(path);


   //切线
   float theta=(360-(90-m_thetaB)-90)/3.1415926*180;
   painter.translate(points[m_num-1]);
   painter.rotate(theta);
   pen.setStyle(Qt::DashLine);//线的类型，实线、虚线等
   pen.setColor(Qt::green); //划线颜色
   pen.setWidth(2); //线宽
   painter.setPen(pen);

   painter.drawLine(-m_TangentLength,0,m_TangentLength,0);
   painter.restore();
}


void WidgetPainter::Setm(float m)
{
    if(m&&m!=0.0)
    {m_m=m;}
}
void WidgetPainter::SetE(float e)
{
    if(e&&e!=0.0)
    { m_E=e;}
}
void WidgetPainter::SetI(float i)
{
    if(i&&i!=0.0)
    {m_I=i;}
}
void WidgetPainter::SetStep(float s)
{
    if(s&&s!=0.0)
    {m_step=s;}

}
void WidgetPainter::SetXRatio(float r)
{
    if(r&&r!=0.0)
    {m_xratio=r;}
}
void WidgetPainter::SetNum(int n)
{
    if(n&&n!=0.0)
    {m_num=n;}
}
void WidgetPainter::SetTan(float t)
{
    if(t&&t!=0.0)
    {m_TangentLength=t;}
}
