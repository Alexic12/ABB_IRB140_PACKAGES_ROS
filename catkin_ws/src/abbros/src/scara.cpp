#include "../include/abbros/scara.hpp"


#include <iostream>
#include <QDebug>

Scara *robot;


Scara::Scara(QObject *parent) :
    QObject(parent),
    th1(0.0), th2(0.0),th3(0.0),th4(0.0), th5(0.0), th6(0.0), z(0.0),
    dth1(0.0), dth2(0.0), dth3(0.0), dth4(0.0), dth5(0.0), dth6(0.0), dz(0.0),
    posx(2.0), posy(2.0), posz(2.0),
    tx(1.0), ty(1.0), tz(1.0),
    mode(PAUSE),
    r1(1.0), r2(1.5), a1(0.273), a2(1.404), d1(0.9), d4(1.53), toold(0.10)
{
    //d4 = 1.735

    baseModel.load("base.obj");
    link1Model.load("link1.obj");
    link2Model.load("link2.obj");

    link3Model.load("link3.obj");
    link4Model.load("link4.obj");
    link5Model.load("link5.obj");
    link6Model.load("link6.obj");


    //ensayo cinemática inversa
   // kinOdwr();


    kinPr();

}

void Scara::go(double dt, double sl)
{

    if(mode == TARGET) {
        double rx = tx - posx;
        double ry = ty - posy;
        double rz = tz - posz;


        double vmax = sl;

        double v = sqrt(rx*rx + ry*ry + rz*rz);
        rx *= vmax/v;
        ry *= vmax/v;
        rz *= vmax/v;

        calcSpeed(rx, ry, rz);
    } else {
        dth1 = 0.0;
        dth2 = 0.0;
        dth3 = 0.0;
        dth4 = 0.0;
        dth5 = 0.0;
        dth6 = 0.0;
        dz = 0.0;
    }

    /*
    th1 += dt * dth1;
    th2 += dt * dth2;
    th3 += dt * dth3;
    th4 += dt * dth4;
    th5 += dt * dth5;
    th6 += dt * dth6;
    z += dt * dz;
    */


    //if(th1 > Limit1) th1 -= 360.0-(180.0-Limit1);
    //if(th1 < -Limit1) th1 += 360.0-(180.0-Limit1);
    //if(th2 > Limit2) th2 -= 360.0-(180.0-Limit2);
    //if(th2 < -Limit2) th2 += 360.0-(180.0-Limit2);

    if(th1 > Limit1) th1 = Limit1;
    if(th1 < -Limit1) th1 = -Limit1;

    if(th2 > Limit2) th2 = Limit2;
    if(th2 < -Limit2) th2 = -Limit2;

    if(th3 > Limit3) th3 = Limit3;
    if(th3 < -Limit3) th3 = -Limit3;

    if(th4 > Limit4) th4 = Limit4;
    if(th4 < -Limit4) th4 = -Limit4;

    if(th5 > Limit5) th5 = Limit5;
    if(th5 < -Limit5) th5 = -Limit5;

    if(th6 > Limit6) th6 = Limit6;
    if(th6 < -Limit6) th6 = -Limit6;

    //if(z < 0.0) z = 0.0;
    //if(z > Limit3/100.0) z = Limit3/100.0;

    //kinPr();
   // kinOdwr();

    PathPoint p = { posx, posy, posz };
    path.push_back(p);

    if(path.size() > 10000) path.erase(path.begin());
}

void Scara::setpathpoint()
{
    PathPoint p = { posx, posy, posz };
    path.push_back(p);

}

void Scara::displayPath()
{
    std::vector<PathPoint>::iterator i;
    glBegin(GL_LINE_STRIP);
        for(i = path.begin(); i < path.end(); ++i)
            glVertex3f(i->y, -i->x, i->z+0.5);
    glEnd();
}

void Scara::display()
{

    float rot1 = 180;

    double L0 = 0.07;
    double L1 = 0.352;
    double L2 = 0.360;
    double L3 = 0.254;
    double L4 = 0.126;
    double L5 = 0.065;
    double borde = 0.07;

/*

    baseModel.display();
    link1Model.display();
    glRotatef(th2, 0.0, 1.0, 0.0);
    link2Model.display();
    link3Model.display();
    link4Model.display();
    link5Model.display();
    link6Model.display();
*/

    glRotatef(rot1, 0.0, 0.0, 1.0);

    baseModel.display();



    glRotatef(th1, 0.0, 0.0, 1.0);
    link1Model.display();


    glTranslatef(0.27, 0.0, 1.37);//traslacion a origen de link 2
    glRotatef(th2, 0.0, 1.0, 0.0);
    glTranslatef(-0.27, 0.0, -1.37);

    link2Model.display();

    glTranslatef(0.27, 0.0, 2.80);//traslacion a origen de link 3
    glRotatef(th3, 0.0, 1.0, 0.0);
    glTranslatef(-0.27, 0.0, -2.80);

    link3Model.display();

    glTranslatef(0.0, 0.0, 2.80);//traslacion a origen de link 4
    glRotatef(th4, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, -2.80);


    link4Model.display();

    glTranslatef(1.75, 0.0, 2.80);//traslacion a origen de link 5
    glRotatef(th5, 0.0, 1.0, 0.0);
    glTranslatef(-1.75, 0.0, -2.80);

    link5Model.display();

    glTranslatef(0.0, 0.0, 2.80);//traslacion a origen de link 4
    glRotatef(th6, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, -2.80);


    link6Model.display();


    /*
    glRotatef(rot1, 0.0, 0.0, 1.0);
    baseModel.display();



    glRotatef(th1, 0.0, 0.0, 1.0);
    link1Model.display();



    glTranslatef(0.110, 0.0, 0.5617); //traslacion a origen de link 2
    glRotatef(th2, 0.0, 1.0, 0.0);
    glTranslatef(-0.110, 0.0, -0.5617);

    link2Model.display();

    glTranslatef(0.07, 0.0, 0.712);//traslacion a origen de link 3
    glRotatef(th3, 0.0, 1.0, 0.0);
    glTranslatef(-0.07, 0.0, -0.712);

    link3Model.display();

    glTranslatef(0.0, 0.0, 0.712);//traslacion a origen de link 4
    glRotatef(th4, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, -0.712);


    link4Model.display();

    glTranslatef(0.380, 0.0, 0.712);//traslacion a origen de link 5
    glRotatef(th5, 0.0, 1.0, 0.0);
    glTranslatef(-0.380, 0.0, -0.712);

    link5Model.display();

    glTranslatef(0.0, 0.0, 0.712);//traslacion a origen de link 4
    glRotatef(th6, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, -0.712);


    link6Model.display();

*/
/*
    glRotatef(90.0, 0.0, 1.0, 0.0);//rotacion axis para ajustarlo a scara en eje y de ejes 2 y 3 y 5
    glRotatef(90.0, 1.0, 0.0, 0.0);//rotacion axis para ajustarlo a scara en eje y de ejes 2 y 3 y 5

   // glTranslatef(-1.37, 0.27, 0.0);//eje de rotación 2
    //glTranslatef(-2.80, 0.27, 0.0);//eje de rotación 3

   // glRotatef(90.0, 0.0, 1.0, 0.0);//para ajustar axis en x para rotación de eje 4 y 6
    //glTranslatef(-2.80, 0.0, 0.0);//eje de rotación 4 y 6
    //glTranslatef(-2.8, 1.75, 0.0);//eje de rotación 5

    //axisModel.display();
*/
}

double Scara::settoold(double i)
{

    toold = i;
}

double Scara::setl1(double i)
{

    Limit1 = i;
}
double Scara::setl2(double iu)
{

    Limit2 = iu;

}

double Scara::setl3(double ia)
{

    Limit3 = ia;

}

double Scara::setl4(double iau)
{

    Limit4 = iau;

}

double Scara::setl5(double iaua)
{

    Limit5 = iaua;

}

double Scara::setl6(double ier)
{

    Limit6 = ier;

}



double Scara::getl1()
{
    return Limit1;
}
double Scara::getl2()
{
    return Limit2;
}
double Scara::getl3()
{
    return Limit3;
}

double Scara::getl4()
{
    return Limit4;
}

double Scara::getl5()
{
    return Limit5;
}

double Scara::getl6()
{
    return Limit6;
}

double Scara::getTh1()
{
    return th1;
}

double Scara::getTh2()
{
    return th2;
}

double Scara::getTh3()
{
    return th3;
}

double Scara::getTh4()
{
    return th4;
}

double Scara::getTh5()
{
    return th5;
}

double Scara::getTh6()
{
    return th6;
}


double Scara::getX()
{
    return posx;
}

double Scara::getY()
{
    return posy;
}

double Scara::getZ()
{
    return posz;
}

void Scara::setTh1(double _th1)
{
    th1 = _th1;

    kinPr();
}

void Scara::setTh2(double _th2)
{
    th2 = _th2;

    kinPr();
}

void Scara::setTh3(double _th3)
{
    th3 = _th3;

    kinPr();
}

void Scara::setTh4(double _th4)
{
    th4 = _th4;

    kinPr();
}

void Scara::setTh5(double _th5)
{
    th5 = _th5;

    kinPr();
}

void Scara::setTh6(double _th6)
{
    th6 = _th6;

    kinPr();
}

void Scara::setZ(double _z)
{
    z = _z;

    kinPr();
}

void Scara::setMode(SteeringMode _mode)
{
    mode = _mode;
}

void Scara::setTarget(double _tx, double _ty, double _tz)
{
    /*
    tx = _tx;
    ty = _ty;
    tz = _tz;
    */
    posstart.resize(3);
    posend.resize(3);
    posstart[0] = posx;
    posstart[1] = posy;
    posstart[2] = posz;
    if(posstart[0] < 0.001)
    {
        posstart[0] = 0;

    }
    if(posstart[1] < 0.001)
    {
        posstart[0] = 0;

    }
    if(posstart[2] < 0.001)
    {
        posstart[0] = 0;

    }
    //qDebug() << posstart;

    posend[0] = _tx;
    posend[1] = _ty;
    posend[2] = _tz;

    if(posend[0] < 0.001)
    {
        posend[0] = 0;

    }
    if(posend[1] < 0.001)
    {
        posend[1] = 0;

    }
    if(posend[2] < 0.001)
    {
        posend[2] = 0;

    }
    //gentray(posstart, posend);


}

void Scara::kinPr()
{



        double A=cos(M_PI*th1/180.0);
        double B=sin(M_PI*th1/180.0);
        double C=cos(M_PI*th2/180.0);
        double D=sin(M_PI*th2/180.0);
        double E=cos(M_PI*th3/180.0);
        double F=sin(M_PI*th3/180.0);
        double G=cos(M_PI*-th4/180.0);
        double H=sin(M_PI*-th4/180.0);
        double I=cos(M_PI*th5/180.0);
        double J=sin(M_PI*th5/180.0);
        double K=cos(M_PI*-th6/180.0);
        double L=sin(M_PI*-th6/180.0);
        double M=L0;
        double N=L1;
        double O=L2;
        double P=L3;
        double Q=L4;
        double R=L5;
        double S = toold*0.31;




        posx=Q*(B*C*E - B*D*F) - S*(J*(G*(B*C*F + B*D*E) + A*H) - I*(B*C*E - B*D*F)) + B*M + B*D*O - J*R*(G*(B*C*F + B*D*E) + A*H) + I*R*(B*C*E - B*D*F) + B*C*E*P - B*D*F*P;

        posy=S*(J*(G*(A*C*F + A*D*E) - B*H) - I*(A*C*E - A*D*F)) - Q*(A*C*E - A*D*F) - A*M - A*D*O + J*R*(G*(A*C*F + A*D*E) - B*H) - I*R*(A*C*E - A*D*F) - A*C*E*P + A*D*F*P;

        posz=N - S*(I*(C*F + D*E) + G*J*(C*E - D*F)) - Q*(C*F + D*E) + C*O - I*R*(C*F + D*E) - C*F*P - D*E*P - G*J*R*(C*E - D*F);








}

void Scara::kinOdwr()
{




}
void Scara::invkin(double px, double py, double pz)
{

    double L = 0;


    if(px == 0)
    {

        th1 = 0;
    }else
    {
    th1 = atan2(px, py)*180.0/M_PI;

    }

    L = sqrt(pow(py, 2) + pow(px, 2));



    th2 = 90 - atan2(pz - L1, L -L0)*180.0/M_PI;

    qDebug() << "Angulos: ";
    qDebug() << "";
    qDebug() << "th1: " << th1;
    qDebug() << "th2: " << th2;
    qDebug() << "";


    kinPr();

}

void Scara::gentray(QVector<double> posi, QVector<double> posf)
{


    double distanciax = posi[0] - posf[0];
    double distanciay = posi[1] - posf[1];
    double distanciaz = posi[2] - posf[2];

    double deltax = distanciax/intervalo;
    double deltay = distanciay/intervalo;
    double deltaz = distanciaz/intervalo;

    dposx.resize(intervalo);
    dposy.resize(intervalo);
    dposz.resize(intervalo);


    for(int i = 0; i < intervalo; i++)
    {



        dposx[i] = posi[0] + deltax*(i+1);
        dposy[i] = posi[1] + deltay*(i+1);
        dposz[i] = posi[2] + deltaz*(i+1);
        invkin(posf[0], posf[1], posf[2]);
        //invkin(dposx[i], dposy[i], dposz[i]);
        qDebug() << "Intervalo: " << i;
        qDebug() << "";
        qDebug() << "dposx: " << posf[0];
        qDebug() << "dposy: " << posf[1];
        qDebug() << "dposz: " << posf[2];
        qDebug() << "";




    }



}

bool Scara::calcSpeed(double vx, double vy, double vz)
{
    double sth1 = sin(M_PI*th1/180.0);
    double cth1 = cos(M_PI*th1/180.0);
    double sth2 = sin(M_PI*th2/180.0);
    double cth2 = cos(M_PI*th2/180.0);
    double sth12 = sin(M_PI*(th1+th2)/180.0);
    double cth12 = cos(M_PI*(th1+th2)/180.0);
    double sth23 = sin(M_PI*(th2+th3)/180.0);
    double cth23 = cos(M_PI*(th2+th3)/180.0);

    double det = (-r1*sth1-r2*sth12) * (r2*cth12) + (r2*sth12) * (r1*cth1+r2*cth12) ;

    //qDebug() << det;
    if(!det) {
        dth1 = 0.0;
        dth2 = 0.0;
        dth3 = 0.0;
        dth4 = 0.0;
        dth5 = 0.0;
        dth6 = 0.0;
        //dz = 0.0;

        return false;
    }

    //std::cout << det << '\n';
    //inicio calculo original

    //double t11 = r2*cth12/det;
    //double t12 = r2*sth12/det;
    //double t21 = -(r1*cth1+r2*cth12)/det;
    //double t22 = -(r1*sth1+r2*sth12)/det;

    //final cálculo original

    //inicio calculo prueba


    double t11 = (a1)*cth1/det;
    double t12 = (a1)*sth1/det;
    double t21 = -(r1*cth1+r2*cth12)/det;
    double t22 = -(r1*sth1+r2*sth12)/det;
    double t31 = -(r1*sth1+r2*sth12)/det;
    //final calculo prueba


    //descomentar para funcionamiento original
    dth1 = 1;
    dth2 = 2;
    //dz = vz;
    //prueba velocidades estandar
    //dth1 = vx*th1;
    //dth2 = vx*th2;
    dth3 = 1;
    //dth4 = vx*th4;
    //dth5 = vx*th5;
    //dth6 = vx*th6;


    dth1 *= 180.0/M_PI;
    dth2 *= 180.0/M_PI;
    dth3 *= 180.0/M_PI;
    //dth4 *= 180.0/M_PI;
    //dth5 *= 180.0/M_PI;
    //dth6 *= 180.0/M_PI;



    return true;
}
