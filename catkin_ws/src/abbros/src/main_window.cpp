/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/abbros/main_window.hpp"
#include "ui_main_window.h"
#include "../include/abbros/scara.hpp"
#include <QDebug>
/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace abbros {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent) :
  QMainWindow(parent),

  qnode(argc,argv)
{
  ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

  connect(&tmr, SIGNAL(timeout()), this, SLOT(go()));
  tmr.setInterval(0);
  tmr.start();

  robot = new Scara(this);

  clk = clock();
  //escribo valores actuales de limites en la ventana de configuracion
  QString text1;
  text1.sprintf("%.3f", robot->getl1());
  ui.actl1->setText(text1);
  text1.sprintf("%.3f", robot->getl2());
  ui.actl2->setText(text1);

  text1.sprintf("%.3f", robot->getl3());
  ui.actl3->setText(text1);

  text1.sprintf("%.3f", robot->getl4());
  ui.actl4->setText(text1);

  text1.sprintf("%.3f", robot->getl5());
  ui.actl5->setText(text1);

  text1.sprintf("%.3f", robot->getl6());
  ui.actl6->setText(text1);


  ui.horizontalSliderTh1->setMaximum(robot->getl1());
  ui.horizontalSliderTh1->setMinimum(-(robot->getl1()));

  ui.horizontalSliderTh2->setMaximum(robot->getl2());
  ui.horizontalSliderTh2->setMinimum(-(robot->getl2()));

  ui.horizontalSliderTh3->setMaximum(robot->getl3());
  ui.horizontalSliderTh3->setMinimum(-(robot->getl3()));

  ui.horizontalSliderTh4->setMaximum(robot->getl4());
  ui.horizontalSliderTh4->setMinimum(-(robot->getl4()));

  ui.horizontalSliderTh5->setMaximum(robot->getl5());
  ui.horizontalSliderTh5->setMinimum(-(robot->getl5()));

  ui.horizontalSliderTh6->setMaximum(robot->getl6());
  ui.horizontalSliderTh6->setMinimum(-(robot->getl6()));

  //ui->horizontalSliderZ->setMaximum(robot->getl3());

  QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    ReadSettings();
	setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

	/*********************
	** Logging
	**********************/
	ui.view_logging->setModel(qnode.loggingModel());
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));
    QObject::connect(ui.commandLinkButtonGo, SIGNAL(clicked()), this, SLOT(on_commandLinkButtonGo_clicked()));
    QObject::connect(ui.botongo, SIGNAL(clicked()), this, SLOT(buttongoclick()));
    QObject::connect(ui.horizontalSliderTh1, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSliderTh1_valueChanged(int)));
    QObject::connect(ui.horizontalSliderTh2, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSliderTh2_valueChanged(int)));
    QObject::connect(ui.horizontalSliderTh3, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSliderTh3_valueChanged(int)));
    QObject::connect(ui.horizontalSliderTh4, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSliderTh4_valueChanged(int)));
    QObject::connect(ui.horizontalSliderTh5, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSliderTh5_valueChanged(int)));
    QObject::connect(ui.horizontalSliderTh6, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSliderTh6_valueChanged(int)));
    QObject::connect(ui.botonguardarpos, SIGNAL(clicked()), this, SLOT(clickbotonguardarpos()));

    QObject::connect(ui.botonenviar, SIGNAL(clicked()), this, SLOT(on_botonenviar_clicked()));

    QObject::connect(ui.botonherramienta, SIGNAL(clicked()), this, SLOT(botonherramientaclick()));

    senddata();

    /*********************
    ** Auto Start
    **********************/
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }
}


void MainWindow::botonherramientaclick()
{
    robot->settoold(ui.spiny->value()/100.0);

    QString text;

    text.sprintf("%.3f", (ui.spinx->value()/1000.0));
    ui.actxh->setText(text);

    text.sprintf("%.3f", (ui.spiny->value()/1000.0));
    ui.actyh->setText(text);

    text.sprintf("%.3f", (ui.spinz->value()/1000.0));
    ui.actzh->setText(text);
    qDebug() << ui.spiny->value();

    robot->setpathpoint();

    ui.view->updateGL();




}

void MainWindow::senddata() {

    //jointstates << (ui.horizontalSliderTh1->value()*M_PI/180.0) << (ui.horizontalSliderTh2->value()*M_PI/180.0) << (ui.horizontalSliderTh3->value()*M_PI/180.0) << (ui.horizontalSliderTh4->value()*M_PI/180.0) << (ui.horizontalSliderTh5->value()*M_PI/180.0) << (ui.horizontalSliderTh6->value()*M_PI/180.0);

    jointstates.resize(6);
    jointstates[0] = (ui.horizontalSliderTh1->value()*M_PI/180.0);
    jointstates[1] = (ui.horizontalSliderTh2->value()*M_PI/180.0);
    jointstates[2] = (ui.horizontalSliderTh3->value()*M_PI/180.0);
    jointstates[3] = (ui.horizontalSliderTh4->value()*M_PI/180.0);
    jointstates[4] = (ui.horizontalSliderTh5->value()*M_PI/180.0);
    jointstates[5] = (ui.horizontalSliderTh6->value()*M_PI/180.0);
    //qDebug() << jointstates;
    qnode.setvalue(jointstates);
    //valorestfj1.resize[7];




    qnode.setflag(1);

}

void MainWindow::on_botonenviar_clicked(bool check2) {


    for(int i = 0; i < contador; i++)
    {

        robot->setTarget(posguardada[i][0], posguardada[i][1], posguardada[i][2]);




    }

}


MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked(bool check ) {
	if ( ui.checkbox_use_environment->isChecked() ) {
		if ( !qnode.init() ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
		}
	} else {
		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
				   ui.line_edit_host->text().toStdString()) ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
			ui.line_edit_topic->setReadOnly(true);
		}
	}
}


void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
	//ui.line_edit_topic->setEnabled(enabled);
}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
        ui.view_logging->scrollToBottom();
        //qnode.setvalue(ui.slider->value());

        senddata();
       // qDebug() << 1;

}
/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}



/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "abbros");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    //ui.line_edit_topic->setText(topic_name);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }
}

void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "abbros");
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}
int MainWindow::getvalue()
{

  //return ui.slider->value();

}

void MainWindow::movement()
{
    
    

}

void MainWindow::go()
{
    dt = 1.0 * (clock() - clk) / CLOCKS_PER_SEC;
    clk = clock();
    t += dt;
    sl = 1.4 * (ui.velocityslider->value()*0.01);

    robot->go(dt, sl);

    bool mode = ui.radioButtonTarget->isChecked();

    QString text;

    text.sprintf("%.3f", robot->getTh1());
    ui.labelTh1->setText(text);

    text.sprintf("%.3f", robot->getTh2());
    ui.labelTh2->setText(text);

    text.sprintf("%.3f", robot->getTh3());
    ui.labelTh3->setText(text);

    text.sprintf("%.3f", robot->getTh4());
    ui.labelTh4->setText(text);

    text.sprintf("%.3f", robot->getTh5());
    ui.labelTh5->setText(text);

    text.sprintf("%.3f", robot->getTh6());
    ui.labelTh6->setText(text);


    text.sprintf("%.3f", robot->getY()*factor);
    ui.labelY->setText(text);

    text.sprintf("%.3f", robot->getX()*factor);
    ui.labelX->setText(text);

    //text.sprintf("%.3f", robot->getY());
    //ui.labelY->setText(text);

    text.sprintf("%.3f", robot->getZ()*factor);
    ui.labelZ->setText(text);

    if(mode) {
        ui.horizontalSliderTh1->setValue(robot->getTh1());
        ui.horizontalSliderTh2->setValue(robot->getTh2());
        ui.horizontalSliderTh3->setValue(robot->getTh3());
        ui.horizontalSliderTh4->setValue(robot->getTh4());
        ui.horizontalSliderTh5->setValue(robot->getTh5());
        ui.horizontalSliderTh6->setValue(robot->getTh6());
        //ui->horizontalSliderZ->setValue(100.0*robot->getZ());
    }

    ui.view->updateGL();
}

void MainWindow::on_verticalSliderPitch_valueChanged(int value)
{
    ui.view->setPitch(value);
}

void MainWindow::on_horizontalSliderYaw_valueChanged(int value)
{
    ui.view->setYaw(value);
}

void MainWindow::on_horizontalSliderTh1_valueChanged(int value)
{
    mode = ui.radioButtonTarget->isChecked();

    if(!mode) robot->setTh1(value);

    valorestfj1.resize(7);
    valorestfj1[0] = 0.0;
    valorestfj1[1] = 0.0;
    valorestfj1[2] = M_PI*double(ui.horizontalSliderTh1->value())/180.0;
    valorestfj1[3] = 1.0;
    valorestfj1[4] = 0.0;
    valorestfj1[5] = 0.0;
    valorestfj1[6] = 0.0;
    qnode.settf(1, valorestfj1);

}

void MainWindow::on_horizontalSliderTh2_valueChanged(int value)
{
    mode = ui.radioButtonTarget->isChecked();

    if(!mode) robot->setTh2(value);

    valorestfj2.resize(7);
    valorestfj2[0] = 0.0;
    valorestfj2[1] = M_PI*double(ui.horizontalSliderTh2->value())/180.0;
    valorestfj2[2] = 0.0;
    valorestfj2[3] = 1.0;
    valorestfj2[4] = 0.28;
    valorestfj2[5] = 0.0;
    valorestfj2[6] = 1.38;
    qnode.settf(2, valorestfj2);


}

void MainWindow::on_horizontalSliderTh3_valueChanged(int value)
{
    mode = ui.radioButtonTarget->isChecked();

    if(!mode) robot->setTh3(value);

    valorestfj3.resize(7);
    valorestfj3[0] = 0.0;
    valorestfj3[1] = M_PI*double(ui.horizontalSliderTh3->value())/180.0;
    valorestfj3[2] = 0.0;
    valorestfj3[3] = 1.0;
    valorestfj3[4] = 0.0;
    valorestfj3[5] = 0.0;
    valorestfj3[6] = 1.42;
    qnode.settf(3, valorestfj3);


}

void MainWindow::on_horizontalSliderTh4_valueChanged(int value)
{
    mode = ui.radioButtonTarget->isChecked();

    if(!mode) robot->setTh4(value);

    valorestfj4.resize(7);
    valorestfj4[0] = M_PI*double(ui.horizontalSliderTh4->value())/180.0;
    valorestfj4[1] = 0.0;
    valorestfj4[2] = 0.0;
    valorestfj4[3] = 1.0;
    valorestfj4[4] = 0.0;
    valorestfj4[5] = 0.0;
    valorestfj4[6] = 0.0;
    qnode.settf(4, valorestfj4);


}

void MainWindow::on_horizontalSliderTh5_valueChanged(int value)
{
    mode = ui.radioButtonTarget->isChecked();

    if(!mode) robot->setTh5(value);

    valorestfj5.resize(7);
    valorestfj5[0] = 0.0;
    valorestfj5[1] = M_PI*double(ui.horizontalSliderTh5->value())/180.0;
    valorestfj5[2] = 0.0;
    valorestfj5[3] = 1.0;
    valorestfj5[4] = 0.0;
    valorestfj5[5] = 0.0;
    valorestfj5[6] = 0.0;
    qnode.settf(5, valorestfj5);



}

void MainWindow::on_horizontalSliderTh6_valueChanged(int value)
{
    mode = ui.radioButtonTarget->isChecked();

    if(!mode) robot->setTh6(value);

    valorestfj6.resize(7);
    valorestfj6[0] = M_PI*double(ui.horizontalSliderTh6->value())/180.0;
    valorestfj6[1] = 0.0;
    valorestfj6[2] = 0.0;
    valorestfj6[3] = 1.0;
    valorestfj6[4] = 0.0;
    valorestfj6[5] = 0.0;
    valorestfj6[6] = 0.02;
    qnode.settf(6, valorestfj6);


}


void MainWindow::on_pushButton_4_clicked()
{
    int u = 0;
    mode = ui.radioButtonTarget->isChecked();


    //hallar ángulo mayor

    if(u<abs(robot->getTh1())){

        u = abs(robot->getTh1());

    }

    if(u<abs(robot->getTh2())){

        u = abs(robot->getTh2());

    }

    if(u<abs(robot->getTh3())){

        u = abs(robot->getTh3());

    }

    if(u<abs(robot->getTh4())){

        u = abs(robot->getTh4());

    }

    if(u<abs(robot->getTh5())){

        u = abs(robot->getTh5());

    }

    if(u<abs(robot->getTh6())){

        u = abs(robot->getTh6());

    }



    //trayectoria de retorno a posicion inicial

    for(int i = 0; i < u + 1; i = i + 1)
    {
       Sleeper::msleep(speed);
       //robot->go(dt, sl);
       ui.view->updateGL();

       ui.horizontalSliderTh1->setValue(robot->getTh1());
       ui.horizontalSliderTh2->setValue(robot->getTh2());
       ui.horizontalSliderTh3->setValue(robot->getTh3());
       ui.horizontalSliderTh4->setValue(robot->getTh4());
       ui.horizontalSliderTh5->setValue(robot->getTh5());
       ui.horizontalSliderTh6->setValue(robot->getTh6());
       ui.view->update();
    if(!mode){
        //eje 1
        if(robot->getTh1()<0)
        {
            robot->setTh1(robot->getTh1() + 1);
        }else if(robot->getTh1()>0)
        {
            robot->setTh1(robot->getTh1() - 1);
        }else if(robot->getTh1() == 0)
        {
            robot->setTh1(0);
        }

        //eje 2
        if(robot->getTh2()<0)
        {
            robot->setTh2(robot->getTh2() + 1);
        }else if(robot->getTh2()>0)
        {
            robot->setTh2(robot->getTh2() - 1);
        }else if(robot->getTh2() == 0)
        {
            robot->setTh2(0);
        }

        //eje 3
        if(robot->getTh3()<0)
        {
            robot->setTh3(robot->getTh3() + 1);
        }else if(robot->getTh3()>0)
        {
            robot->setTh3(robot->getTh3() - 1);
        }else if(robot->getTh3() == 0)
        {
            robot->setTh3(0);
        }

        //eje 4
        if(robot->getTh4()<0)
        {
            robot->setTh4(robot->getTh4() + 1);
        }else if(robot->getTh4()>0)
        {
            robot->setTh4(robot->getTh4() - 1);
        }else if(robot->getTh4() == 0)
        {
            robot->setTh4(0);
        }

        //eje 5
        if(robot->getTh5()<0)
        {
            robot->setTh5(robot->getTh5() + 1);
        }else if(robot->getTh5()>0)
        {
            robot->setTh5(robot->getTh5() - 1);
        }else if(robot->getTh5() == 0)
        {
            robot->setTh5(0);
        }

        //eje 6
        if(robot->getTh6()<0)
        {
            robot->setTh6(robot->getTh6() + 1);
        }else if(robot->getTh6()>0)
        {
            robot->setTh6(robot->getTh6() - 1);
        }else if(robot->getTh6() == 0)
        {
            robot->setTh6(0);
        }






       // paintgl();
       // robot->display();


    }

    }

}

void MainWindow::on_horizontalSliderZ_valueChanged(int value)
{
   //( mode = ui.radioButtonTarget->isChecked();

    //if(!mode) robot->setZ(0.01 * value);
}

void MainWindow::on_commandLinkButtonGo_clicked()
{
    robot->setTarget(ui.lineEditTx->text().toDouble(), ui.lineEditTy->text().toDouble(), ui.lineEditTz->text().toDouble());
}

void MainWindow::buttongoclick()
{
    robot->setTarget(ui.lineEditTx->text().toDouble(), ui.lineEditTy->text().toDouble(), ui.lineEditTz->text().toDouble());


    qDebug() << 1;

}

void MainWindow::on_radioButtonSimple_clicked()
{
    if(flag == 1)
    {

    robot->setMode(SIMPLE);
    ui.tcpmanual->setEnabled(true);
    ui.groupBoxSimple->setEnabled(true);
    ui.groupBoxTarget->setDisabled(true);
    }
}

void MainWindow::on_radioButtonTarget_clicked()
{
    if(flag == 1)
    {
    robot->setMode(TARGET);
    ui.tcpmanual->setDisabled(true);
    ui.groupBoxSimple->setDisabled(true);
    ui.groupBoxTarget->setEnabled(true);
    }
}

void MainWindow::on_pushButton_21_clicked()
{
    mode = ui.radioButtonSimple->isChecked();

   // ui->horizontalSliderZ->setValue(ui->horizontalSliderZ->value() + 1);

    //if(!mode) robot->setZ(ui->horizontalSliderZ->value()*0.01);
    //Sleeper::msleep(500);

}

void MainWindow::on_pushButton_22_clicked()
{
    mode = ui.radioButtonSimple->isChecked();
   // ui->horizontalSliderZ->setValue(ui->horizontalSliderZ->value() - 1);

    //if(!mode) robot->setZ(ui->horizontalSliderZ->value()*0.01);
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_21_pressed()
{

}



void MainWindow::on_pushButton_16_clicked()
{


}



void MainWindow::on_radioButtonSimple_2_clicked()
{
    robot->setMode(PAUSE);

    ui.groupBoxSimple->setDisabled(true);
    ui.groupBoxTarget->setDisabled(true);
    ui.tcpmanual->setDisabled(true);
}

void MainWindow::on_pushButton_18_clicked()
{

}

void MainWindow::on_pushButton_5_clicked()//ajustar límites de articulaciones del robot
{

    l1 = ui.limitj1->value();
    l2 = ui.limitj2->value();
    l3 = ui.limitj3->value();
    l4 = ui.limitj4->value();
    l5 = ui.limitj5->value();
    l6 = ui.limitj6->value();
    robot->setl1(l1);
    robot->setl2(l2);
    robot->setl3(l3);
    robot->setl4(l4);
    robot->setl5(l5);
    robot->setl6(l6);

    QString text1;
    text1.sprintf("%.3f", robot->getl1());
    ui.actl1->setText(text1);
    text1.sprintf("%.3f", robot->getl2());
    ui.actl2->setText(text1);

    text1.sprintf("%.3f", robot->getl3());
    ui.actl3->setText(text1);

    text1.sprintf("%.3f", robot->getl4());
    ui.actl4->setText(text1);

    text1.sprintf("%.3f", robot->getl5());
    ui.actl5->setText(text1);

    text1.sprintf("%.3f", robot->getl6());
    ui.actl6->setText(text1);


    ui.horizontalSliderTh1->setMaximum(robot->getl1());
    ui.horizontalSliderTh1->setMinimum(-(robot->getl1()));

    ui.horizontalSliderTh2->setMaximum(robot->getl2());
    ui.horizontalSliderTh2->setMinimum(-(robot->getl2()));

    ui.horizontalSliderTh3->setMaximum(robot->getl3());
    ui.horizontalSliderTh3->setMinimum(-(robot->getl3()));

    ui.horizontalSliderTh4->setMaximum(robot->getl4());
    ui.horizontalSliderTh4->setMinimum(-(robot->getl4()));

    ui.horizontalSliderTh5->setMaximum(robot->getl5());
    ui.horizontalSliderTh5->setMinimum(-(robot->getl5()));

    ui.horizontalSliderTh6->setMaximum(robot->getl6());
    ui.horizontalSliderTh6->setMinimum(-(robot->getl6()));

    //ui->horizontalSliderZ->setMaximum(robot->getl3());

    //Scara::Limit1
    //Scara::Limit1 = ui->limitj1->value();
    //Scara::Limit2 = ui->limitj2->value();
    //Scara::Limit1 = ui->limitj1->value();
}

void MainWindow::on_startbutton_clicked()
{
    if(startbool == 0)
    {
        ui.oncheckbox->toggle();
        ui.offcheckbox->toggle();
        startbool = 1;
        stopbool = 0;
    flag = 1;
    }else
    {

    }
}

void MainWindow::on_stopbutton_clicked()
{
    if(stopbool == 0)
    {
        ui.oncheckbox->toggle();
        ui.offcheckbox->toggle();
    flag = 0;
    stopbool = 1;
    startbool = 0;
    ui.groupBoxSimple->setDisabled(true);
    ui.groupBoxTarget->setDisabled(true);
    ui.tcpmanual->setDisabled(true);


    Sleeper::msleep(100);
    }else
    {


    }
}

void MainWindow::on_pausebutton_clicked()
{

}


void MainWindow::on_velocityslider_valueChanged(int value)
{
    speed = 101 - (value);

}

void MainWindow::clickbotonguardarpos()
{


    double x = ui.labelX->text().toDouble();
    double y = ui.labelY->text().toDouble();
    double z = ui.labelZ->text().toDouble();

    QString px = QString::number(x);
    QString py = QString::number(y);
    QString pz = QString::number(z);
    posguardada.resize(contador + 1);
    posguardada[contador].resize(3);
    posguardada[contador][0] = x;
    posguardada[contador][1] = y;
    posguardada[contador][2] = z;

    ui.listapuntos->addItem("Pos: " + QString::number(contador) + " = " + px + ",  " + py + ",  " + pz);

    qDebug() << posguardada;
    contador++;



}


}  // namespace abbros

