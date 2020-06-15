/* Example of polymorphism in C */
#include<stdio.h>

enum shapes {SQUARE, CIRCLE};

#define COUNT 2
#define PI 3.14159

/* Defines the generic parts of a shape object */
#define SHAPE_HEAD     \
     int id;             \
     enum shapes type;   \
     char name[20];      \
     double (*area)(void* this); \
     double (*perimeter)(void* this); \

/* Shape structs - note that each contains SHAPE_HEAD giving us the common
    interface for each shape then defines the attributes specific to itself */
typedef struct shape {
    SHAPE_HEAD
} shape_t;

typedef struct square {
    SHAPE_HEAD
    double s;
} square_t;

typedef struct circle {
    SHAPE_HEAD
    double r;
} circle_t;

/* Square functions */
double s_area(void* this) {
    square_t * me = (square_t *) this;
    return me->s * me->s;
}
double s_perimeter(void* this) {
    square_t * me = (square_t *) this;
    return me->s * 4.0;
}

/* Circle functions */
double c_area(void* this) {
    circle_t * me = (circle_t *) this;
    return me->r * me->r * PI;
}
double c_perimeter(void* this) {
    circle_t * me = (circle_t *) this;
    return me->r * 2.0 * PI;
}

/* These #defines are intended to clean up the syntax */
#define S_ID(s)      (((shape_t*)(s))->id)
#define S_TYPE(s)    (((shape_t*)(s))->type)
#define S_NAME(s)    (((shape_t*)(s))->name)
#define S_AREA(s)    (((shape_t*)(s)))->area((s))
#define S_PERIMETER(s)    (((shape_t*)(s)))->perimeter((s))

int main() {
    square_t s1 = {1, SQUARE, "square1", &s_area, &s_perimeter, 3}; 
    circle_t c1 = {2, CIRCLE, "circle1", &c_area, &c_perimeter, 3}; 
    shape_t * shapes[COUNT];
    shape_t ** sptr = shapes;
    int ii;
 
    shapes[0] = (shape_t *) &s1;
    shapes[1] = (shape_t *) &c1;
 
    /* This is an array of shape_t, but we call the appropriate function for
         each individual shape type */
    for(ii=0;ii<COUNT;ii++) {
        printf("%s: id=%d, type=%d, area=%f, perimeter=%f\n", S_NAME(*sptr), 
                S_ID(*sptr), S_TYPE(*sptr), S_AREA(*sptr), S_PERIMETER(*sptr));
        sptr ++;
    }

    return 0;
}