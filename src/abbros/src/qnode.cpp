/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/abbros/qnode.hpp"
#include "../include/abbros/main_window.hpp"
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>
#include "glob.h"
/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace abbros {

/*****************************************************************************
** Implementation
*****************************************************************************/



QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"abbros");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;

   // QFile file("irb140.urdf");
    XmlRpc::XmlRpcValue file ="irb140.urdf";
	// Add your ros communications here.
    joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
    n.setParam("robot_description", file);
    //broadcaster = n.advertise<geometry_msgs::Transform>("tf", 1);
    //extern tf::TransformBroadcaster broadcaster;
    //tf::TransformBroadcaster broadcaster;
	start();
	return true;

}

bool QNode::init(const std::string &master_url, const std::string &host_url) {

	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"abbros");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
    //chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
	start();
	return true;

}

void QNode::run() {
  ros::Rate loop_rate(10);
  //int count = 0;

    if(bandera == 1){

        bandera = 0;
    }

    tf::TransformBroadcaster broadcaster;
	while ( ros::ok() ) {

        //std_msgs::String msg;
        //std::stringstream ss;

        //ss << count;
        //msg.data = ss.str();




        //envío datos de articulaciónes

        joint_pub.publish(joint_state);

        double th1 = joint_state.position[0];
        double th2 = joint_state.position[1];
        double th3 = joint_state.position[2];
        double th4 = joint_state.position[3];
        double th5 = joint_state.position[4];
        double th6 = joint_state.position[5];

/*
        //envío datos transformada de articulación  joint_1
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, 0.0, 0.0, 1.0), tf::Vector3(0.0, 0.0, 0.0)),
               ros::Time::now(),"base", "base_link"));
        //envío datos transformada de articulación  joint_1
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, 0.0, th1+(M_PI/2), 1.0), tf::Vector3(0.0, 0.0, 0.0)),
               ros::Time::now(),"base_link", "link_1"));

        //envío datos transformada de articulación  joint_2
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(th2, 0.0, 0.0, 1.0), tf::Vector3(0.0, -0.273, 0.9)),
               ros::Time::now(),"link_1", "link_2"));

        //envío datos transformada de articulación  joint_3
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(th3, 0.0, 0.0, 1.0), tf::Vector3(0.0, 0.0, 1.42)),
               ros::Time::now(),"link_2", "link_3"));

        //envío datos transformada de articulación  joint_4
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, th4, 0.0, 1.0), tf::Vector3(0.0, -0.9, 0.0)),
               ros::Time::now(),"link_3", "link_4"));

        //envío datos transformada de articulación  joint_5
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(th5, 0.0, 0.0, 1.0), tf::Vector3(0.0, -0.6, 0.0)),
               ros::Time::now(),"link_4", "link_5"));

        //envío datos transformada de articulación  joint_6
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, th6, 0.0, 1.0), tf::Vector3(0.0, -0.2, 0.0)),
               ros::Time::now(),"link_5", "link_6"));

        //envío datos transformada de articulación  base_link-base
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, 0.0, 0.0, 1.0), tf::Vector3(0.0, 0.0, 0.0)),
               ros::Time::now(),"base_link", "base"));

        //envío datos transformada de articulación  link_6-tool
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, 0.0, 0.0, 1.0), tf::Vector3(0.0, 0.0, 0.0)),
               ros::Time::now(),"link_6", "tool0"));

*/

        double factor = 0.9;
        //envío datos transformada de articulación  joint_1
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, 0.0, 0.0, 1.0), tf::Vector3(0.0, 0.0, 0.0)),
               ros::Time::now(),"base", "base_link"));
        //envío datos transformada de articulación  joint_1
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, 0.0, th1, 1.0), tf::Vector3(0.0, 0.0, 0.0)),
               ros::Time::now(),"base_link", "link_1"));

        //envío datos transformada de articulación  joint_2
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, th2, 0.0, 1.0), tf::Vector3(0.273, 0.0, 1.42)),
               ros::Time::now(),"link_1", "link_2"));

        //envío datos transformada de articulación  joint_3
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, th3, 0.0, 1.0), tf::Vector3(0.0, 0.0, 1.42)),
               ros::Time::now(),"link_2", "link_3"));

        //envío datos transformada de articulación  joint_4
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(th4, 0.0, 0.0, 1.0), tf::Vector3(0.9, 0.0, 0.0)),
               ros::Time::now(),"link_3", "link_4"));

        //envío datos transformada de articulación  joint_5
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, th5, 0.0, 1.0), tf::Vector3(0.6, 0.0, 0.0)),
               ros::Time::now(),"link_4", "link_5"));

        //envío datos transformada de articulación  joint_6
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(th6, 0.0, 0.0, 1.0), tf::Vector3(0.25, 0.0, 0.0)),
               ros::Time::now(),"link_5", "link_6"));

        //envío datos transformada de articulación  base_link-base
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, 0.0, 0.0, 1.0), tf::Vector3(0.0, 0.0, 0.0)),
               ros::Time::now(),"base_link", "base"));

        //envío datos transformada de articulación  link_6-tool
        broadcaster.sendTransform(
             tf::StampedTransform(
               tf::Transform(tf::Quaternion(0.0, 0.0, 0.0, 1.0), tf::Vector3(0.0, 0.0, 0.0)),
               ros::Time::now(),"link_6", "tool0"));


        log(Info,std::string("Dato Enviado: "));

/*
        if(flag1 == 1)
               {
                   joint_pub.publish(joint_state);
                   //

                   flag1 = 0;


               }
*/
		ros::spinOnce();
		loop_rate.sleep();
    //++count;
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

void QNode::setvalue(QVector<double> i)
{

    double factor = 0.65;

    joint_state.name.resize(6);
    joint_state.name[0] = "joint_1";
    joint_state.name[1] = "joint_2";
    joint_state.name[2] = "joint_3";
    joint_state.name[3] = "joint_4";
    joint_state.name[4] = "joint_5";
    joint_state.name[5] = "joint_6";

    joint_state.position.resize(6);
    joint_state.position[0] = i[0]*factor;
    joint_state.position[1] = i[1]*factor;
    joint_state.position[2] = i[2]*factor;
    joint_state.position[3] = i[3]*factor;
    joint_state.position[4] = i[4]*factor;
    joint_state.position[5] = i[5]*factor;

    joint_state.velocity.resize(6);
    joint_state.velocity[0] = 0.0;
    joint_state.velocity[1] = 0.0;
    joint_state.velocity[2] = 0.0;
    joint_state.velocity[3] = 0.0;
    joint_state.velocity[4] = 0.0;
    joint_state.velocity[5] = 0.0;

    joint_state.effort.resize(6);
    joint_state.effort[0] = 0.0;
    joint_state.effort[1] = 0.0;
    joint_state.effort[2] = 0.0;
    joint_state.effort[3] = 0.0;
    joint_state.effort[4] = 0.0;
    joint_state.effort[5] = 0.0;





}



void QNode::settf(int i, QVector<double> valores) {
    if(i == 1) {

        joint_1.resize(7);
        joint_1[0] = valores[0];
        joint_1[1] = valores[1];
        joint_1[2] = valores[2];
        joint_1[3] = valores[3];
        joint_1[4] = valores[4];
        joint_1[5] = valores[5];
        joint_1[6] = valores[6];


    }else if(i == 2) {
        joint_2.resize(7);
        joint_2[0] = valores[0];
        joint_2[1] = valores[1];
        joint_2[2] = valores[2];
        joint_2[3] = valores[3];
        joint_2[4] = valores[4];
        joint_2[5] = valores[5];
        joint_2[6] = valores[6];


    }else if(i == 3) {
        joint_3.resize(7);
        joint_3[0] = valores[0];
        joint_3[1] = valores[1];
        joint_3[2] = valores[2];
        joint_3[3] = valores[3];
        joint_3[4] = valores[4];
        joint_3[5] = valores[5];
        joint_3[6] = valores[6];


    }else if(i == 4) {
        joint_4.resize(7);
        joint_4[0] = valores[0];
        joint_4[1] = valores[1];
        joint_4[2] = valores[2];
        joint_4[3] = valores[3];
        joint_4[4] = valores[4];
        joint_4[5] = valores[5];
        joint_4[6] = valores[6];


    }else if(i == 5) {
        joint_5.resize(7);
        joint_5[0] = valores[0];
        joint_5[1] = valores[1];
        joint_5[2] = valores[2];
        joint_5[3] = valores[3];
        joint_5[4] = valores[4];
        joint_5[5] = valores[5];
        joint_5[6] = valores[6];


    }else if(i == 6) {
        joint_6.resize(7);
        joint_6[0] = valores[0];
        joint_6[1] = valores[1];
        joint_6[2] = valores[2];
        joint_6[3] = valores[3];
        joint_6[4] = valores[4];
        joint_6[5] = valores[5];
        joint_6[6] = valores[6];


    }else if(i == 7) {
        joint_6_tool0.resize(7);
        joint_6_tool0[0] = valores[0];
        joint_6_tool0[1] = valores[1];
        joint_6_tool0[2] = valores[2];
        joint_6_tool0[3] = valores[3];
        joint_6_tool0[4] = valores[4];
        joint_6_tool0[5] = valores[5];
        joint_6_tool0[6] = valores[6];


    }else if(i == 8) {
        base_link_base.resize(7);
        base_link_base[0] = valores[0];
        base_link_base[1] = valores[1];
        base_link_base[2] = valores[2];
        base_link_base[3] = valores[3];
        base_link_base[4] = valores[4];
        base_link_base[5] = valores[5];
        base_link_base[6] = valores[6];


    }









}

int QNode::getflag()
{

    return flag1;
}

void QNode::setflag(int i)
{

    flag1 = i;
}


void QNode::log( const LogLevel &level, const std::string &msg) {
	logging_model.insertRows(logging_model.rowCount(),1);
	std::stringstream logging_model_msg;
	switch ( level ) {
		case(Debug) : {
				ROS_DEBUG_STREAM(msg);
				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Info) : {
				ROS_INFO_STREAM(msg);
                //logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                 logging_model_msg << "[INFO] " << msg;
                break;
		}
		case(Warn) : {
				ROS_WARN_STREAM(msg);
                logging_model_msg << "[WARN] [" << ros::Time::now() << "]: " << msg;

				break;
		}
		case(Error) : {
				ROS_ERROR_STREAM(msg);
				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
				break;
		}
		case(Fatal) : {
				ROS_FATAL_STREAM(msg);
				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
				break;
		}

	}
	QVariant new_row(QString(logging_model_msg.str().c_str()));
	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
	Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}

}  // namespace abbros
