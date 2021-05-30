# RayTracing
This project was inspired by the awesome tutorial ["Ray Tracing in One Weekend"](http://in1weekend.blogspot.com/2016/01/ray-tracing-in-one-weekend.html) by Peter Shirley.
Apart from learning about ray tracing, I've used the project to practice TDD and to try the  [Catch2](https://github.com/catchorg/Catch2) unit testing framework.

<img src="https://raw.githubusercontent.com/Shamanskiy/RayTracing/media/images/positionalbe_camera.png" width="500">

## Building
The project uses CMake. To build it, navigate to the project root folder and do the usual:
```
mkdir build
cd build
cmake ..
```
On Windows with Visual Studio installed, this should generate a VS solution file. On MacOS and Linux, you can use 
```
make
```
to build the project.

## Running
THe main app of the project is RayTracer. In Visual Studio, you can right-click it in the Solution Explorer and Set as Startup Project. Then hit Ctrl+F5 to run it.
On MacOS and Linux, from the build folder call
```
apps/RayTracer
```
RayTracer generates a .ppm image. On Windows and Linux, you can open it with GIMP. On MacOS, the default viewer should do.

## Testing
You can run unit tests by running the UnitTests target in Visual Studio or by calling
```
tests/UnitTests
```


