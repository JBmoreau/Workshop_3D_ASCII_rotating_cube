/*
** EPITECH PROJECT, 2021
** Workshop 3D ASCII Rotating cube
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <math.h>
    #define TIME_SLEEP          30000
    #define ANGLE               2 * M_PI /180
    #define NB_VECTORS          12
    #define NB_POINTS           8
    #define NB_D                3  // nb de dimensions
    #define NB_CHR_LUMINANCE    12
    #define X                   0
    #define Y                   1
    #define Z                   2
    #define DEPTH               Y

typedef struct vector_s {
    double vect[NB_D];
    int i; // L'indice du point au quel il est rattaché
} vector_t;

static double VERTICES[NB_POINTS][NB_D] = {
        {-1, -1, -1},
        { 1, -1, -1},
        { 1,  1, -1},
        {-1,  1, -1},
        {-1, -1,  1},
        { 1, -1,  1},
        { 1,  1,  1},
        {-1,  1,  1}
};

static const char LUMINANCE[NB_CHR_LUMINANCE] = ".,-~:;=!*#$@";

vector_t *create_vectors(void);
void clear_output(char **output, int size);
char **create_output_buffer(int output_size);
void set_vertices_width(int width);

void calculate_vectors(vector_t *vector, double p1[NB_D], double p2[NB_D], int k);
void set_vector(vector_t *vectors);

double depth_max(void);
int get_depth(double y, double depth_max);

void rotate_vertices(double angle);

void place_vertices(int size, char **output);
void place_edges(int size, vector_t *vectors, char **output);

/* math.c */
void rotate(double rotation[NB_D][NB_D], double point[NB_D]);
void rotate_matrice_x(double matrice[NB_D][NB_D], double a);
void rotate_matrice_y(double matrice[NB_D][NB_D], double a);
void rotate_matrice_z(double matrice[NB_D][NB_D], double a);
double get_vector_norm(double vect[NB_D]);
int min(int nb1, int nb2);

#endif /* !MY_H */
