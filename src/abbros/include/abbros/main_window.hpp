/**
 * @file /include/abbros/main_window.hpp
 *
 * @brief Qt based gui for abbros.
 *
 * @date November 2010
 **/
#ifndef abbros_MAIN_WINDOW_H
#define abbros_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include <QTimer>
#include <cmath>
/*****************************************************************************
** Namespace
*****************************************************************************/
class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};

namespace abbros {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();
  //MainWindow main;
	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();

  //abbros::MainWindow *a;


public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_button_connect_clicked(bool check );
	void on_checkbox_use_environment_stateChanged(int state);
    void on_botonenviar_clicked(bool check2);

    void senddata();
  int getvalue();
    /******************************************
    ** Manual connections
    *******************************************/
  void updateLoggingView(); // no idea why this can't connect automatically

  //agrego slots de interfaz abb

  void go();

  void on_verticalSliderPitch_valueChanged(int value);

  void on_horizontalSliderYaw_valueChanged(int value);

  void on_horizontalSliderTh1_valueChanged(int value);

  void on_horizontalSliderTh2_valueChanged(int value);

  void on_horizontalSliderZ_valueChanged(int value);

  void on_commandLinkButtonGo_clicked();

  void buttongoclick();

  void on_radioButtonSimple_clicked();

  void on_radioButtonTarget_clicked();

  void on_pushButton_21_clicked();

  void on_pushButton_22_clicked();

  void on_pushButton_clicked();

  void on_pushButton_21_pressed();

  void on_pushButton_16_clicked();


  void on_radioButtonSimple_2_clicked();

  void on_pushButton_18_clicked();

  void on_pushButton_5_clicked();

  void on_startbutton_clicked();

  void on_stopbutton_clicked();

  void on_pausebutton_clicked();

  void on_horizontalSliderTh3_valueChanged(int value);

  void on_horizontalSliderTh4_valueChanged(int value);

  void on_horizontalSliderTh5_valueChanged(int value);

  void on_horizontalSliderTh6_valueChanged(int value);

  void on_pushButton_4_clicked();

  void on_velocityslider_valueChanged(int value);

  void movement();

  void clickbotonguardarpos();
  void botonherramientaclick();

private:
  Ui::MainWindowDesign ui;
	QNode qnode;
  class QTimer tmr;
  //int a;
  QSlider * slide;
  QVector<double> jointstates;
  QVector<double> valorestfj1;
  QVector<double> valorestfj2;
  QVector<double> valorestfj3;
  QVector<double> valorestfj4;
  QVector<double> valorestfj5;
  QVector<double> valorestfj6;
  QVector<double> valorestfj6t;
  QVector<double> valorestfjbb;

  double t, dt, sl;

  clock_t clk;
  double counterz;
  double countery;
  double counterx;
  int flag = 0;
  int stopbool = 0;
  int startbool = 0;
  bool mode;
  double l1;
  double l2;
  double l3;
  double l4;
  double l5;
  double l6;

  double speed = 20;

  double factor = 0.30689655;

  //double factor = 1;

  int contador = 0;
  QVector < QVector < double > > posguardada;

};

}  // namespace abbros

#endif // abbros_MAIN_WINDOW_H
