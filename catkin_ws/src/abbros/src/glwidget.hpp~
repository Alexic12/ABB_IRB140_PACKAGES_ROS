#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL/QGLWidget>

#include "scara.hpp"


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);



//protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

public Q_SLOTS:
    void setPitch(double pitch);
    void setYaw(double yaw);
    void setDistance(double distance);

private:
    void setView();
    void setLight();

    int w, h;
    double pitch, yaw, distance;
};

#endif // GLWIDGET_H
