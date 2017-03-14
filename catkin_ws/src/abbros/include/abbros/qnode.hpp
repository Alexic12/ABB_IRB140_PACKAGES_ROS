/**
 * @file /include/abbros/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef abbros_QNODE_HPP_
#define abbros_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
//#include "main_window.hpp"
#include <sensor_msgs/JointState.h>
#include <QVector>
#include <tf/transform_broadcaster.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace abbros {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
	void run();
    void setvalue(QVector<double> i);
    void settf(int i, QVector<double> valores);
    void setflag(int i);
    int getflag();
  //abbros::MainWindow a;
  //abbros::MainWindow a;
  //QNode(main *a);


	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
             Fatal
	 };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);

Q_SIGNALS:
	void loggingUpdated();
    void rosShutdown();

private:
	int init_argc;
	char** init_argv;
    ros::Publisher joint_pub;
  QStringListModel logging_model;
  std::string count;
  sensor_msgs::JointState joint_state;
  //tf::TransformBroadcaster broadcaster;
  QVector<double> joint_1;
  QVector<double> joint_2;
  QVector<double> joint_3;
  QVector<double> joint_4;
  QVector<double> joint_5;
  QVector<double> joint_6;
  QVector<double> joint_6_tool0;
  QVector<double> base_link_base;
  //QVector<double> joint1;
  //geometry_msgs::TransformStamped odom_trans;
  int flag1;
  int bandera = 1;

  //int* a = NULL;

};

}  // namespace abbros

#endif /* abbros_QNODE_HPP_ */
