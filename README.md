# Curves

## About
This project was written as a test task for a job interview. The task is described at the end of this document.

This repository containts two projects:
- `curves`: The core library that implements the curves functionality.
- `app`: The application that uses the core library.

The `app` project requires the `OpenMP` library to be installed on the system.

The project was written using `GCC 13.2.0` in `Visual Studio Code` on Windows 11.

## Building
The project uses CMake as a build system. To build the project, run the following commands:
```bash
mkdir build
cd build
cmake ..
```

## [Test task](https://it-selection.ru/page59048677.html)
Design a small program in C++ that would implement support of 3D curves hierarchy.
1. Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified
definitions are below). Each curve should be able to return a 3D point and a first derivative (3D
vector) per parameter t along the curve.
2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
random parameters.
3. Print coordinates of points and derivatives of all curves in the container at $t=\frac{\pi}{4}$.
4. Populate a second container that would contain only circles from the first container. Make sure the
second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
5. Sort the second container in the ascending order of circles' radii. That is, the first element has the
smallest radius, the last - the greatest.
6. Compute the total sum of radii of all curves in the second container.  
__(*) Additional optional requirements:__
7. Split implementation into a library of curves (.dll or .so) and executable which uses API of this
library.
8. Implement computation of the total sum of radii using parallel computations (e.g. OpenMP or Intel
TBB library).
Requirements to the implementation:
1. The implementation must use virtual methods.
2. Has neither explicit memory deallocation nor memory leaks.
3. Curves must be physically correct (e.g. radii must be positive).
4. Containers and sorting must be implemented using STL (C++ Standard Template Library).
5. The implementation may use constructs of C++11 or higher.
6. The code must compile with any compiler of your choice (gcc, Visual C++, etc).
Curve definitions:
- All curves are parametrically defined, i.e. a point is calculated using some C(t) formula.
- Circle is planar in the plane XoY (i.e. all Z-coordinates are 0) and is defined by its radius.
- Ellipse is planar in the plane XoY and is defined by its two radii, along X and Y axes.
- Helix is spatial and is defined by its radius and step (see the figure below). It takes $2\pi$ in
parametric space to make a round, i.e. any y point on helix satisfies the condition $C(t + 2\pi) = C(t) +
\{0, 0, step\}$.

