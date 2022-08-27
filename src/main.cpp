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
    

    std::string paht_map = "/home/ddario/Workspace/occupancy_grid/map.png";

    cv::Mat map = cv::imread(paht_map);

    Robot robot(map, initial_state, 20, false);

    robot.drawRobot(map);
    cv::imshow("Map", map);
    int k = cv::waitKey(0);
    

    Eigen::VectorXd ranges; 
    std::vector<Eigen::Vector2d> min_points;
    while(1){
        // std::cout << distribution(generator) << std::endl;
        map = cv::imread(paht_map);
        if(k==27 || k==-1) return 0;
        robot.moveRobot(map, k);
        
        robot.takeMeasurementsRange(map, ranges);

        robot.getMinPoints(min_points);

        robot.drawRobot(map);
        cv::imshow("Map", map);
        k = cv::waitKey(0);

        Eigen::Vector3d current_state = robot.getStates();
        cv::Point current_point(current_state(0), current_state(1));
        
        for(int i=0; i<min_points.size(); i++){
            cv::Point min_point(min_points[i][0], min_points[i][1]);
            double range = ranges[i];
            range = range>=50 ? -1:range;
            og.updateMap(current_point, min_point, range);
            //og.drawMap();
        }
        og.drawMap();
    }

    //og.drawMap();


    
}