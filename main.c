/*
** EPITECH PROJECT, 2021
** Workshop 3D ASCII Rotating cube
** File description:
** main.c
*/

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void calculate_vector(vector_t *vector, double p1[NB_D],
    double p2[NB_D], int indice_first_point)
{
    /*
        Calcule le vecteur entre les points p2 et p1.
    */

    vector->i = indice_first_point;
}

/* Associe chaque vecteur à des points stratégiques du cube */
void set_vector(vector_t *vectors)
{
    calculate_vector(&vectors[0], VERTICES[0], VERTICES[1], 0);
    calculate_vector(&vectors[1], VERTICES[0], VERTICES[4], 0);
    calculate_vector(&vectors[2], VERTICES[0], VERTICES[3], 0);
    calculate_vector(&vectors[8], VERTICES[1], VERTICES[5], 1);
    calculate_vector(&vectors[9], VERTICES[1], VERTICES[2], 1);
    calculate_vector(&vectors[11], VERTICES[2], VERTICES[3], 2);
    calculate_vector(&vectors[4], VERTICES[2], VERTICES[6], 2);
    calculate_vector(&vectors[3], VERTICES[6], VERTICES[7], 6);
    calculate_vector(&vectors[5], VERTICES[6], VERTICES[5], 6);
    calculate_vector(&vectors[6], VERTICES[4], VERTICES[7], 4);
    calculate_vector(&vectors[7], VERTICES[4], VERTICES[5], 4);
    calculate_vector(&vectors[10], VERTICES[7], VERTICES[3], 7);
}

/* Retourne la valeur de la coordonnée Y du point le plus éloigné. */
double depth_max(void)
{
    double max = ;

    /*
        Calcule la valeur de la coordonnée Y du point le plus
        éloigné (coordonée DEPTH).
    */
    return (max);
}

/*
    Projette l'intervalle [-depth_max, depth_max] sur
    [0, NB_CHR_LUMINANCE - 1] et retourne la valeur de
    'y' projeter sur ce dernier intervalle.
*/
int get_depth(double y, double depth_max)
{
    y += depth_max;
    depth_max = 2 * depth_max / (NB_CHR_LUMINANCE -1);
    return (int) roundf(y / depth_max);
}

/* Place les sommets du cube dans l'output */
void place_vertices(int size, char **output)
{
    double depth = depth_max();
    int x = 0;
    int z = 0;

    for (int i = 0; i < NB_POINTS; i++) {
        x = size + roundf(VERTICES[i][X]);
        z = (size + roundf(VERTICES[i][Z])) / 2;
        output[z][x] = LUMINANCE[get_depth(VERTICES[i][DEPTH], depth)];
    }
}

/* Place les arrêtes du cube dans l'output */
void place_edges(int size, vector_t *vectors, char **output)
{
    double norm_vect = 0;
    double x = 0, y = 0, z = 0;
    int rX = 0, rZ = 0;
    int i = 0;
    double depth = ; // profondeur maximum du cube.

    for (int j = 0; j < NB_VECTORS; j++) {
        norm_vect = ; // Calcule la norme du vecteur j.
        i = vectors[j].i;
        x = ; // coordonnée X du point d'indice i.
        y = ; // coordonnée Y du point d'indice i.
        z = ; // coordonnée Z du point d'indice i.
        for (int k = 0; k < norm_vect - 2; k++) {
            x += (vectors[j].vect[X] / norm_vect);
            y += (vectors[j].vect[Y] / norm_vect);
            z += (vectors[j].vect[Z] / norm_vect);
            rX = size + roundf(x);
            rZ = (size + roundf(z)) / 2;
            output[rZ][rX] = LUMINANCE[get_depth(y, depth)];
        }
    }
}

/* Fait tourner les sommets. */
void rotate_vertices(double angle)
{
    double rotate_x[NB_D][NB_D] = {0};
    double rotate_y[NB_D][NB_D] = {0};
    double rotate_z[NB_D][NB_D] = {0};

    /*
        Initialise les matrice de rotation avec l'angle.
        (Voir math.c)
    */

    /*
        Fait tourner tous les sommets avec les matrice de rotations.
    */
}

/* Réinitialise le buffer de l'output. */
void clear_output(char **output, int size)
{
    /*
        Remplie l'output d'espace.
    */
}

/* Animation du cube. */
void render_frame(int size, char **output, vector_t *vectors,
    double angle)
{
    while (1) {
        /*
            Tourner les sommets du cube.
        */
        /*
            Affiche les somets.
        */
        set_vector(vectors);
        /*
            Affiche les arrêtes du cube.
        */
        /*
            Afficher l'output, vous pouvez utilisez printf("\033c")
            pour clear le terminal et rendre l'affichage plus propre.
        */
        clear_output(output, size * 2);
        /*
            Une fonction qui permet de sleep pour ralentir le programe ? :3
        */
    }
}

/* Crée un tableau de vecteurs */
vector_t *create_vectors(void)
{
    vector_t *vectors = malloc(sizeof(vector_t) * NB_VECTORS);

    /*
        Initialise tous les vecteurs à 0
    */
    return vectors;
}

char **create_output_buffer(int output_size)
{
    char **output;
    /*
        Allocation de la mémoire pour l'output
    */

    /*
        Initialise l'output
    */
    return output;
}

/* Initialise la taille du carré. */
void set_vertices_width(int width)
{
    /*
    Multiplie les coordonnées des sommets du carré (VERTICES)
    par la width pour l'adapter au terminal.
    */
}

int main(void)
{
    struct winsize w;
    int square_width = 0;
    char **output = NULL;
    vector_t *vectors = create_vectors();

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    square_width = min(w.ws_col / 4, w.ws_row / 2);
    output = create_output_buffer(4 * square_width);
    set_vertices_width(square_width);
    render_frame(square_width * 2, output, vectors, ANGLE);
    return (0);
}

