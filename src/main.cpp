#include <iostream>

#include <Eigen/Dense>
#include "opencv2/opencv.hpp"

#include "utils.hpp"
#include "occupancy_grid.hpp"

#include "robot.hpp"




int main (){

    OccupancyGrid og(1000, 600);

    Eigen::Vector3d initial_state;
    initial_state << 100, 100, 3.14/2;
    Robot robot(initial_state, 20, false);

    std::string paht_map = "/home/dario/Workspace/occupancy_greed/map.png";

    cv::Mat map = cv::imread(paht_map);

    robot.drawRobot(map);
    cv::imshow("Map", map);
    int k = cv::waitKey(0);
    

    while(1){

        
        // std::cout << distribution(generator) << std::endl;
        map = cv::imread(paht_map);
        if(k==27 || k==-1) return 0;
        robot.moveRobot(map, k);
        double range;
        cv::Point min_point = robot.getPointRange(map, 50, range, true);
        double bearing = robot.getBearing(min_point);
        robot.drawRobot(map);
        cv::imshow("Map", map);
        k = cv::waitKey(0);

        Eigen::Vector3d current_state = robot.getStates();
        cv::Point current_point(current_state(0), current_state(1));


        og.updateMap(current_point, min_point, range);
        og.drawMap();
        
    }

    //og.drawMap();


    
}