# ABB_IRB140_PACKAGES_ROS

*ABB_IRB140_SUPPORT:

ROS-Industrial and MoveIT support for the ABB IRB140.

This packages contains configuration data, 3D models and launch files for ABB IRB 140 manipulator.

Joint limits and max joint velocities are based on the information in the ABB data sheets. 
All URDFs / XACROs are based on the default motion and joint velocity limits, unless noted otherwise 
(ie: no support for high speed joints, extended / limited motion ranges or other options).

Before using any of the configuration files and / or meshes included in this package, 
be sure to check they are correct for the ABB IRB140.


*ABB_IRB140_MOVEIT_CONFIG:

MoveIt package for the ABB IRB 2400.

An automatically generated package with all the configuration and launch files
for using the ABB IRB 140 with the MoveIt Motion Planning Framework.


*ABB_DRIVER:

ROS-Industrial nodes for interfacing with ABB robot controllers.

This package is part of the ROS-Industrial program and contains
nodes for interfacing with ABB industrial robot controllers.


*ABBROS:

This package contains an Open-Source graphical user interface for controlling the ABB IRB140.

This package has its own .URDF for interfacing with Rviz, due to OpenGL Coordinate system conflicts with 
the standard .URDF included in ABB_IRB140_SUPPORT.

