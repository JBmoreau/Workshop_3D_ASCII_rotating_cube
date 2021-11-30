/*
** EPITECH PROJECT, 2021
** Workshop 3D ASCII Rotating cube
** File description:
** math.c
*/

#include <math.h>

/*
    Calcul la norme d'un vecteur.
*/
double get_vector_norm(double vect[3])
{
    /*
        Retourne la norme du vecteur (la racine
        carré de la somme de ses poids au carré).
    */
    return ;
}

/*
    Multiplication matricielle à appliquer avec une
    matrice de rotation.
    Résultat: le 'point' contient ses nouvelles
    coordonées après rotation.
*/
void rotate(double rotation[3][3], double points[3])
{
    double step[3] = {0};

    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++)
            step[i] += rotation[i][k] * points[k];
    }
    for (int i = 0; i < 3; i++)
        points[i] = step[i];
}

/*
    Matrice de rotation sur l'axe X.
     1     0       0
     0  cos(a) -sin(a)
     0  sin(a)  cos(a)
*/
void rotate_matrice_x(double matrice[3][3], double a)
{
    matrice[0][0] = 1;
    matrice[0][1] = 0;
    matrice[0][2] = 0;

    matrice[1][0] = 0;
    matrice[1][1] = cosf(a);
    matrice[1][2] = -sinf(a);

    matrice[2][0] = 0;
    matrice[2][1] = sinf(a);
    matrice[2][2] = cosf(a);
}

/*
    Matrice de rotation sur l'axe Y.
     cos(a)  0  sin(a)
       0     1    0
    -sin(a)  0  cos(a)
*/
void rotate_matrice_y(double matrice[3][3], double a)
{
    matrice[0][0] = cosf(a);
    matrice[0][1] = 0;
    matrice[0][2] = sinf(a);

    matrice[1][0] = 0;
    matrice[1][1] = 1;
    matrice[1][2] = 0;

    matrice[2][0] = -sinf(a);
    matrice[2][1] = 0;
    matrice[2][2] = cosf(a);
}

/*
    Matrice de rotation sur l'axe Z.
     cos(a) -sin(a)  0
     sin(a)  cos(a)  0
       0       0     1
*/
void rotate_matrice_z(double matrice[3][3], double a)
{
    matrice[0][0] = cosf(a);
    matrice[0][1] = -sinf(a);
    matrice[0][2] = 0;

    matrice[1][0] = sin(a);
    matrice[1][1] = cosf(a);
    matrice[1][2] = 0;

    matrice[2][0] = 0;
    matrice[2][1] = 0;
    matrice[2][2] = 1;
}

int min(int nb1, int nb2)
{
    return nb1 < nb2 ? nb1 : nb2;
}
