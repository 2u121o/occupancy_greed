# occupancy_greed

In this project I implemented the 2D occupancy greed map using the probabilistic approach as described in this paper [An Efficient Probabilistic 3D Mapping Framework Based on Octrees](http://www.arminhornung.de/Research/pub/hornung13auro.pdf).

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

Once run the program it appear the real map with the robot

![Screenshot from 2022-08-16 21-25-21](https://user-images.githubusercontent.com/32509386/184966794-84f34f40-7499-46fb-a8ec-114d3dfffa17.png)

and when the robot start moving also the reconstracted map appear

![Screenshot from 2022-08-16 21-24-52](https://user-images.githubusercontent.com/32509386/184967030-14346980-877c-4c3c-bc7e-e95a6939e165.png)

