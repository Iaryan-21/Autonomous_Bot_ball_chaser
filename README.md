# PROJECT SIMULATION #


https://user-images.githubusercontent.com/86413005/126012040-154ae073-8494-48c2-a11c-6924be07be16.mp4



# STRUCTURE #

```
.RoboND-Go-Chase-It                # Go Chase It Project
├── my_robot                       # my_robot package
│   ├── launch                     # launch folder for launch files
│   │   ├── robot_description.launch
│   │   ├── world.launch
│   ├── meshes                     # meshes folder for sensors
│   │   ├── hokuyo.dae
│   ├── urdf                       # urdf folder for xarco files
│   │   ├── my_robot.gazebo
│   │   ├── my_robot.xacro
│   ├── world                      # world folder for world files
│   │   ├── UdacityOffice.world
│   ├── CMakeLists.txt             # compiler instructions
│   ├── package.xml                # package info
├── ball_chaser                    # ball_chaser package
│   ├── launch                     # launch folder for launch files
│   │   ├── ball_chaser.launch
│   ├── src                        # source folder for C++ scripts
│   │   ├── drive_bot.cpp
│   │   ├── process_images.cpp
│   ├── srv                        # service folder for ROS services
│   │   ├── DriveToTarget.srv
│   ├── CMakeLists.txt             # compiler instructions
│   ├── package.xml                # package info
└──
```

my_robot: This package defines the world and the robot.

ball_chaser: This package contains two ROS nodes for commanding the robot to chase the white ball.

# BUILD AND LAUNCH #

#### 1. Clone and initialize project with a catkin workspace ####
```
$ mkdir catkin_ws 
$ cd catkin_ws
$ git clone https://github.com/Iaryan-21/GoChaseIt.git 
$ mv GoChaseIt src
$ cd src && catkin_init_workspace
```
#### 2. Move back to catkin_ws and build ####
```
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```
#### 3. Launch the world ####
```
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```
#### 4. Open another terminal (Ctrl+Shift+T), and launch the ball_chaser package ####
```
$ source devel/setup.bash
$ roslaunch ball_chaser ball_chaser.launch
```
#### 5. For image view ####
```
$ source devel/setup.bash
$ rosrun rqt_image_view rqt_image_view
```
