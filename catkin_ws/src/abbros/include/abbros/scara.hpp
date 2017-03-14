#ifndef SCARA_H
#define SCARA_H

#include <QObject>
#include <cmath>
#include <vector>

#include "model.hpp"

enum SteeringMode { PAUSE, SIMPLE, TARGET };

class Scara : public QObject
{
    Q_OBJECT
public:
    explicit Scara(QObject *parent = 0);





public Q_SLOTS:
    void go(double dt, double sl);
    void displayPath();
    void display();

    double getTh1();
    double getTh2();
    double getTh3();
    double getTh4();
    double getTh5();
    double getTh6();

    double getX();
    double getY();
    double getZ();

    double getl1();
    double getl2();
    double getl3();
    double getl4();
    double getl5();
    double getl6();

    double settoold(double i);

    double setl1(double i);
    double setl2(double iu);
    double setl3(double ia);
    double setl4(double iau);
    double setl5(double iaua);
    double setl6(double ier);

    void setTh1(double th1);
    void setTh2(double th2);
    void setTh3(double th3);
    void setTh4(double th4);
    void setTh5(double th5);
    void setTh6(double th6);
    void setZ(double z);
    //void settoold(double zi);

    void setpathpoint();

    void setMode(SteeringMode mode);
    void setTarget(double tx, double ty, double tz);

private Q_SLOTS:
    void kinPr();
    void kinOdwr();
    void invkin(double px, double py, double pz);
    void gentray(QVector<double> posi, QVector<double> posf);
    bool calcSpeed(double vx, double vy, double vz);

private:
    double th1, th2, th3, th4, th5, th6, z;
    double dth1, dth2, dth3, dth4, dth5, dth6, dz;
    double posx, posy, posz, wx, wy, wz;
    double tx, ty, tz;

    //ensayo rotaciones articulaciones ABB

    double rot1, rot2, rot3, rot4, rot5, rot6;

    double D;

    SteeringMode mode;

    double r1, r2, a1, a2, d1, d4, toold;

    double Limit1 = 180.0;
    double Limit2 = 100.0;
    double Limit3 = 140.0;
    double Limit4 = 180.0;
    double Limit5 = 120.0;
    double Limit6 = 180.0;
    double speedlimit = 0.8;
    QVector<double> dposx;
    QVector<double> dposy;
    QVector<double> dposz;
    int intervalo = 1;
    QVector<double> posstart;
    QVector<double> posend;
    double L0 = 0.273;
    double L1 = 0.9;
    double L2 = 1.42;
    double L3 = 0.9;
    double L4 = 0.6;
    double L5 = 0.25;



    Model baseModel, link1Model, link2Model, link3Model, link4Model, link5Model, link6Model, axisModel;

    struct PathPoint { double x, y, z; };
    std::vector<PathPoint> path;
};

extern Scara *robot;

#endif // SCARA_H
