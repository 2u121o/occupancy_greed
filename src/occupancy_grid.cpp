#include "occupancy_grid.hpp"

OccupancyGrid::OccupancyGrid(int width, int heigth): width_(width), heigth_(heigth)
{
    map_ = cv::Mat( heigth_,width_, CV_8UC3, cv::Scalar(128, 128, 128));

}

void OccupancyGrid::updateMap(cv::Point p0, cv::Point p1, double range){

    
    if(range == -1){
        //no detectecd any points
          cv::line(map_, p0, p1, cv::Scalar( 255, 255, 255 ));
    }
    else{
        //point detected
        cv::LineIterator it(map_, p0, p1, 8);
        std::vector<cv::Point> points_line(it.count);

        int num_points = it.count;
        for(int i = 0; i < num_points; i++, ++it)
        {
            int x = it.pos().x;
            int y = it.pos().y;

            double r = std::sqrt(std::pow(x-p0.x,2)+std::pow(y-p0.y,2));

            cv::Vec3b &px_color = map_.at<cv::Vec3b>(y,x);
            double p_sensor =  std::log(inverseSensorModel(r,  range)/(1-inverseSensorModel(r,  range)));
            
            //se tutti yero prob 0 se 255 prob 1 se 128 prob 0.5

            double log_p;
            if(px_color[0] == 0)
                log_p = 0.8;
            else if(px_color[0] == 255)
                log_p = 0.2;
            else
                log_p = 0.5;
            
            log_p = std::log(log_p/(1-log_p)) + p_sensor;
            double p =  1-1/(1+std::exp(log_p));

            
            if(p <= 0.2 ){
                px_color[0] = 0;
                px_color[1] = 0;
                px_color[2] = 0;
            }
            else if(p >= 0.8){
                px_color[0] = 255;
                px_color[1] = 255;
                px_color[2] = 255;
            }
            

        }
    }
}

void OccupancyGrid::drawMap(){
    cv::imshow("Reconstructed Map", map_);
    cv::waitKey(0);
}

double OccupancyGrid::inverseSensorModel(double r, double range){

    double epsilon = 1.0;
    if(r>=0 && r<range-epsilon)
        return 0.8;
    else if(r>=range-epsilon && r<range+epsilon)
        return 0.2;
    else return 0.5;
}

OccupancyGrid::~OccupancyGrid()
{
}