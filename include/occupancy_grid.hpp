#ifndef OCCUPANCY_GRID_H
#define OCCUPANCY_GRID_H

#include <iostream>

#include <Eigen/Dense>
#include "opencv2/opencv.hpp"

class OccupancyGrid
{

public:
    OccupancyGrid(int width_, int heigth);

    void updateMap(cv::Point p0, cv::Point p1, double range);
    void drawMap();

    double inverseSensorModel(double x, double range);

    ~OccupancyGrid();

private:
    cv::Mat map_;
    int width_;
    int heigth_;
};



#endif

