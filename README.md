# occupancy_greed

In this project I implemented the 2D occupancy greed map using the probabilistic approach

To install occupancy_grid repo and the the example you need the  [robot_model](https://github.com/2u121o/robot_model) and openCV.

The installation steps are:

```
git clone 
cd occupancy_grid
mkdir build
cmake ..
make 
./occupancy_grid
```

Once run the program it appear the real map with the robot. The robot is represented as a circumference with a line, that allows the visualization of the orientation. Addittionally, are drawn a crtain number of line that represnt the beams produced by a possible sensor. In this image, it is possible to see the robot with the beams in a map drawn by hand.

![gt_map](https://user-images.githubusercontent.com/32509386/187079780-a880cac2-c8da-4192-808d-ffe6e4d69cef.png)

Both the control and the measurements are affected by noise to make the simulation more realistic and the problem non so trivial. A really strong assuption is that the position of the robot in the space is known.


When the robot start moving also the reconstracted map appear, where the pixels can have three possible colors; gray when the space is unknown, white when the space is free and black when the space is occupied. 

![recon_map](https://user-images.githubusercontent.com/32509386/187079947-13462d1a-36fa-49ec-88da-60e83ebd6a9a.png)


