Point3D structure

Create a Point3D structure that represents a 3D point in space with X, Y and Z coordinates, defined as follows:

typedef struct {
    double x;
    double y;
    double z;
} Point3D;

Edge structure

The Edge structure represents a line segment in 3D space, defined by two Point3D structures (points) representing it's endpoints. It's defined as follows:

typedef struct {
    Point3D p1;
    Point3D p2;
} Edge;

drawLine function

The drawLine function is responsible for drawing a line on the screen from the point (x1, y1) to the point (x2, y2). In this example, it's just a plaholder function and does not actually perform any drawing. You will need to implement this function using some graphics library or function to draw the lines on the screen.

void drawLine(int x1, int y1, int x2, int y2) {
    // draw a line from (x1, y1) to (x2, y2) using some graphics library or function
}

draWireframe function

The drawWireframe function takes an array of Edge structures and the number of edges as arguments, and iteratees through the array, drawing each edge using the drawLine function.

Before drawing the edger, the 3D points are projected onto a 2D screen using a simple projection method. In this example, the projection method used is an orthographic projection, which maps the 3D points directly onto the 2D screen without any perspective distortion. This is done by calculating the 2D coordinates of the points using the formulas x2D = WIDTH / 2 + x3D * WIDTH / z3D and y2D = HEIGHT / 2 + y3D * HEIGHT / z3D, where WIDTH and HEIGHT are the width and height of the screen, and the x3D and y3D, and z3D are the 3D coordinates to the point.

void drawWireframe(Edge edges[], int numEdges) {
    for (int i = 0; i < numEdges; i++) {
        Point3D p1 = edges[i].p1;
        Point3D p2 = edges[i].p2;

        // project 3D points onto 2D screen
        int x1 = (int)(WIDTH / 2 + p1.x * WIDTH / p1.z);
        int y1 = (int)(HEIGHT / 2 + p1.y * HEIGHT / p1.z);
        int x2 = (int)(WIDTH / 2 + p2.x * WIDTH / p2.z);
        int y2 = (int)(HEIGHT / 2 + p2.y * HEIGHT / p2.z);

        drawLine(x1, y1, x2, y2);
    }
}

main function

In the main function, we define a set of 8 points representing the Point3D structure, which represents a 3D point in a cartesian space, with x, y and z coordinates. The Edge structure represents a 3D edge as a pair of 3D points.

The drawWireframe function takes an array of the Edge structures and the number of edges as input, an iterates through the array, drawing each edge using the drawLine function.

Before drawing each edge, the draWireframe function projects the 3D points onto a 2D screen using the following projection method:

int x1 = (int)(WIDTH / 2 + p1.x * WIDTH / p1.z);
int y1 = (int)(HEIGHT / 2 + p1.y * HEIGHT / p1.z);
int x2 = (int)(WIDTH / 2 + p2.x * WIDTH / p2.z);
int y2 = (int)(HEIGHT / 2 + p2.y * HEIGHT / p2.z);

This method scales the x and y coordinates of the 3D points basedon their z coordinates, and then shifts them by half the with and height of the screen to center the projection.

The drawLine function is a placeholder for a function or library that actually draws a line on the screen. You will need to provide an implementation of this function to draw the wireframe. There are many ways to draw lines on a screen, depending on the platform and graphics library you're using. For example, you could use the SDL library, the OpenGL API, or a custom drawing funtion (MiniLibX) that writes pixels to a framebuffer.

using MiniLibX:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mlx.h"

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    double x;
    double y;
    double z;
} Point3D;

typedef struct {
    Point3D p1;
    Point3D p2;
} Edge;

void drawLine(void *mlx, void *win, int x1, int y1, int x2, int y2) {
    // use minilibx functions to draw a line from (x1, y1) to (x2, y2)
    mlx_pixel_put(mlx, win, x1, y1, 0xFFFFFF);
    mlx_pixel_put(mlx, win, x2, y2, 0xFFFFFF);
}

void drawWireframe(void *mlx, void *win, Edge edges[], int numEdges) {
    for (int i = 0; i < numEdges; i++) {
        Point3D p1 = edges[i].p1;
        Point3D p2 = edges[i].p2;

        // project 3D points onto 2D screen
        int x1 = (int)(WIDTH / 2 + p1.x * WIDTH / p1.z);
        int y1 = (int)(HEIGHT / 2 + p1.y * HEIGHT / p1.z);
        int x2 = (int)(WIDTH / 2 + p2.x * WIDTH / p2.z);
        int y2 = (int)(HEIGHT / 2 + p2.y * HEIGHT / p2.z);

        drawLine(mlx, win, x1, y1, x2, y2);
    }
}

int main() {
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, WIDTH, HEIGHT, "Wireframe");

    Point3D p1 = {-1, -1, 3};
    Point3D p2 = {1, -1, 3};
    Point3D p3 = {1, 1, 3};
    Point3D p4 = {-1, 1, 3};
    Point3D p5 = {-1, -1, 5};
    Point3D p6 = {1, -1, 5};
    Point3D p7 = {1, 1, 5};
    Point3D p8 = {-1, 1, 5};

    Edge edges[] = {
        {p1, p2}, {p2, p3}, {p3, p4}, {p4, p1},
        {p5, p6}, {p6, p7}, {p7, p8}, {p8, p5},
        {p1, p5}, {p2, p6}, {p3, p7}, {p4, p8}
    };

    drawWireframe(mlx, win, edges, 12);

    mlx_loop(mlx);

\\it's incomplete after this