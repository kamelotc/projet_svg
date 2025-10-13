#ifndef structures
#define structures

typedef struct Rectangle {
    unsigned int width;
    unsigned int height;
} Rectangle;

typedef struct Circle {
    unsigned int radius;
} Circle;

typedef struct Ellipse {
    unsigned int x;
    unsigned int y;
    unsigned int width;
    unsigned int height;
} Ellipse;

typedef struct Line {
    unsigned int x1;
    unsigned int x2;
    unsigned int y1;
    unsigned int y2;
} Line;

typedef struct Polyline {
    unsigned int x1;
    unsigned int y1;
} Polyline;

typedef struct Polygon {
    unsigned int x1;
    unsigned int y1;
} Polygon;

typedef union Shape {
    Rectangle rectangle;
    Circle circle;
    Ellipse ellipse;
    Line line;
    Polyline polyline;
    Polygon polygon;
} Shape;

#endif
