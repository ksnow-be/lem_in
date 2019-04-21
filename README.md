# Lem_in (Graph Data Structure And Algorithms)

Another School project.

The main goal of the algorithm is to find the **best, non-intersecting paths** and transport the ants through them.

To make it easier to understand, let me explain how the program starts its work.

## Start
```
./lem-in < exp.map
```
## Cat exp.map
```
5          //Amount of the ants
##start     //Establish starting room
1 100 100   //Name of the room;     x position;       y position;
2 400 100
3 700 100
##end       //Establish ending room
4 700 400
5 400 400
6 100 400
1-2         //Start connecting rooms
2-3
3-4
4-5
5-6
1-6
1-5
2-6
2-4
5-3
5-2         //Finish connecting rooms
```
## Example of the vizualization (./lem-in < exp.amp)
![](https://media.giphy.com/media/5tgWLNAm8aNhkG8hDB/giphy.gif)
