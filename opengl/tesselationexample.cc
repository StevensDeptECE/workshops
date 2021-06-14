/*

          Efficient Polygon Triangulation
  Submitted by John W. Ratcliff



Here's a nice little code snippet that will triangulate any polygon efficiently.
This snippet actually compiles directly to a little test application. It uses
STL to act as a container for the polygon outline and the triangulated results.
By simply replacing the Vector2d class with whatever your own favorite Vector
class might be you can easily adapt it to your own application. It could also be
reworked as a template class that could operate on any vertice type of any kind.

I did not write the original code for this algorithm, but I did rework it into a
C++ class and provide a clean interface to use it.

Efficient polygon triangulation has a lot of uses when performing CSG operations
or when creating parametric surfaces. For example, you could provide a GUI
interface to let someone draw any arbritrary outline and then quickly turn that
outline into a piece of geometry for your 3d engine.

John W. Ratcliff
Senior Technology Architect
Verant Interactive

COTD Entry submitted by John W. Ratcliff [jratcliff@verant.com]

** THIS IS A CODE SNIPPET WHICH WILL EFFICIENTLY TRIANGULATE ANY
** POLYGON/CONTOUR (without holes) AS A STATIC CLASS.  THIS SNIPPET
** IS COMPRISED OF 3 FILES, TRIANGULATE.H, THE HEADER FILE FOR THE
** TRIANGULATE BASE CLASS, TRIANGULATE.CPP, THE IMPLEMENTATION OF
** THE TRIANGULATE BASE CLASS, AND TEST.CPP, A SMALL TEST PROGRAM
** DEMONSTRATING THE USAGE OF THE TRIANGULATOR.  THE TRIANGULATE
** BASE CLASS ALSO PROVIDES TWO USEFUL HELPER METHODS, ONE WHICH
** COMPUTES THE AREA OF A POLYGON, AND ANOTHER WHICH DOES AN EFFICENT
** POINT IN A TRIANGLE TEST.
** SUBMITTED BY JOHN W. RATCLIFF (jratcliff@verant.com) July 22, 2000
*/

/**********************************************************************/
/************ HEADER FILE FOR TRIANGULATE.H ***************************/
/**********************************************************************/

#ifndef TRIANGULATE_H

#define TRIANGULATE_H

/*****************************************************************/
/** Static class to triangulate any contour/polygon efficiently **/
/** You should replace Vector2d with whatever your own Vector   **/
/** class might be.  Does not support polygons with holes.      **/
/** Uses STL vectors to represent a dynamic array of vertices.  **/
/** This code snippet was submitted to FlipCode.com by          **/
/** John W. Ratcliff (jratcliff@verant.com) on July 22, 2000    **/
/** I did not write the original code/algorithm for this        **/
/** this triangulator, in fact, I can't even remember where I   **/
/** found it in the first place.  However, I did rework it into **/
/** the following black-box static class so you can make easy   **/
/** use of it in your own code.  Simply replace Vector2d with   **/
/** whatever your own Vector implementation might be.           **/
/*****************************************************************/

#include <vector>  // Include STL vector class.

class Vector2d {
 public:
  Vector2d(float x, float y) { Set(x, y); };

  float GetX(void) const { return mX; };

  float GetY(void) const { return mY; };

  void Set(float x, float y) {
    mX = x;
    mY = y;
  };

 private:
  float mX;
  float mY;
};

// Typedef an STL vector of vertices which are used to represent
// a polygon/contour and a series of triangles.
typedef std::vector<Vector2d> Vector2dVector;

class Triangulate {
 public:
  // triangulate a contour/polygon, places results in STL vector
  // as series of triangles.
  static bool Process(const Vector2dVector &contour, Vector2dVector &result);

  // compute area of a contour/polygon
  static float Area(const Vector2dVector &contour);

  // decide if point Px/Py is inside triangle defined by
  // (Ax,Ay) (Bx,By) (Cx,Cy)
  static bool InsideTriangle(float Ax, float Ay, float Bx, float By, float Cx,
                             float Cy, float Px, float Py);

 private:
  static bool Snip(const Vector2dVector &contour, int u, int v, int w, int n,
                   int *V);
};

#endif

/**************************************************************************/
/*** END OF HEADER FILE TRIANGULATE.H BEGINNING OF CODE TRIANGULATE.CPP ***/
/**************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "triangulate.h"

static const float EPSILON = 0.0000000001f;

float Triangulate::Area(const Vector2dVector &contour) {
  int n = contour.size();

  float A = 0.0f;

  for (int p = n - 1, q = 0; q < n; p = q++) {
    A += contour[p].GetX() * contour[q].GetY() -
         contour[q].GetX() * contour[p].GetY();
  }
  return A * 0.5f;
}

/*
  InsideTriangle decides if a point P is Inside of the triangle
  defined by A, B, C.
*/
bool Triangulate::InsideTriangle(float Ax, float Ay, float Bx, float By,
                                 float Cx, float Cy, float Px, float Py)

{
  float ax, ay, bx, by, cx, cy, apx, apy, bpx, bpy, cpx, cpy;
  float cCROSSap, bCROSScp, aCROSSbp;

  ax = Cx - Bx;
  ay = Cy - By;
  bx = Ax - Cx;
  by = Ay - Cy;
  cx = Bx - Ax;
  cy = By - Ay;
  apx = Px - Ax;
  apy = Py - Ay;
  bpx = Px - Bx;
  bpy = Py - By;
  cpx = Px - Cx;
  cpy = Py - Cy;

  aCROSSbp = ax * bpy - ay * bpx;
  cCROSSap = cx * apy - cy * apx;
  bCROSScp = bx * cpy - by * cpx;

  return ((aCROSSbp >= 0.0f) && (bCROSScp >= 0.0f) && (cCROSSap >= 0.0f));
};

bool Triangulate::Snip(const Vector2dVector &contour, int u, int v, int w,
                       int n, int *V) {
  int p;
  float Ax, Ay, Bx, By, Cx, Cy, Px, Py;

  Ax = contour[V[u]].GetX();
  Ay = contour[V[u]].GetY();

  Bx = contour[V[v]].GetX();
  By = contour[V[v]].GetY();

  Cx = contour[V[w]].GetX();
  Cy = contour[V[w]].GetY();

  if (EPSILON > (((Bx - Ax) * (Cy - Ay)) - ((By - Ay) * (Cx - Ax))))
    return false;

  for (p = 0; p < n; p++) {
    if ((p == u) || (p == v) || (p == w)) continue;
    Px = contour[V[p]].GetX();
    Py = contour[V[p]].GetY();
    if (InsideTriangle(Ax, Ay, Bx, By, Cx, Cy, Px, Py)) return false;
  }

  return true;
}

bool Triangulate::Process(const Vector2dVector &contour,
                          Vector2dVector &result) {
  /* allocate and initialize list of Vertices in polygon */

  int n = contour.size();
  if (n < 3) return false;

  int *V = new int[n];

  /* we want a counter-clockwise polygon in V */

  if (0.0f < Area(contour))
    for (int v = 0; v < n; v++) V[v] = v;
  else
    for (int v = 0; v < n; v++) V[v] = (n - 1) - v;

  int nv = n;

  /*  remove nv-2 Vertices, creating 1 triangle every time */
  int count = 2 * nv; /* error detection */

  for (int m = 0, v = nv - 1; nv > 2;) {
    /* if we loop, it is probably a non-simple polygon */
    if (0 >= (count--)) {
      //** Triangulate: ERROR - probable bad polygon!
      return false;
    }

    /* three consecutive vertices in current polygon, <u,v,w> */
    int u = v;
    if (nv <= u) u = 0; /* previous */
    v = u + 1;
    if (nv <= v) v = 0; /* new v    */
    int w = v + 1;
    if (nv <= w) w = 0; /* next     */

    if (Snip(contour, u, v, w, nv, V)) {
      int a, b, c, s, t;

      /* true names of the vertices */
      a = V[u];
      b = V[v];
      c = V[w];

      /* output Triangle */
      result.push_back(contour[a]);
      result.push_back(contour[b]);
      result.push_back(contour[c]);

      m++;

      /* remove v from remaining polygon */
      for (s = v, t = v + 1; t < nv; s++, t++) V[s] = V[t];
      nv--;

      /* resest error detection counter */
      count = 2 * nv;
    }
  }

  delete V;

  return true;
}

/************************************************************************/
/*** END OF CODE SECTION TRIANGULATE.CPP BEGINNING OF TEST.CPP A SMALL **/
/*** TEST APPLICATION TO DEMONSTRATE THE USAGE OF THE TRIANGULATOR     **/
/************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "triangulate.h"

void triangulateExample(const Vector2dVector &v) {
  //  Invoke the triangulator to triangulate this polygon.
  printf("Contour\n");
  for (int i = 0; i < v.size(); i++)
    printf("%8.4f %8.4f\n", v[i].GetX(), v[i].GetY());

  Vector2dVector result;
  Triangulate::Process(v, result);
  // print out the results.

  printf("\n\nTriangles out\n");
  for (int i = 0; i < result.size(); i += 3) {
    const Vector2d &p1 = result[i + 0];
    const Vector2d &p2 = result[i + 1];
    const Vector2d &p3 = result[i + 2];
    printf("%8.4f,%8.4f,   %8.4f,%8.4f,   %8.4f,%8.4f\n", p1.GetX(), p1.GetY(),
           p2.GetX(), p2.GetY(), p3.GetX(), p3.GetY());
  }
}

int main(int argc, char **argv) {
  // Small test application demonstrating the usage of the triangulate
  // class.

  // Create a pretty complicated little contour by pushing them onto
  // an stl vector.

  Vector2dVector a = {{0, 6},  {0, 0},  {3, 0},  {4, 1}, {6, 1},
                      {8, 0},  {12, 0}, {13, 2}, {8, 2}, {8, 4},
                      {11, 4}, {11, 6}, {6, 6},  {4, 3}, {2, 6}};

  Vector2dVector b = {{-157.7211151, 21.4683857}, {-157.7212372, 21.4687824},
                      {-157.7216339, 21.4689808}, {-157.7217255, 21.4698753},
                      {-157.7216644, 21.4699993}, {-157.7212677, 21.4702702},
                      {-157.7210693, 21.4703159}, {-157.7207031, 21.4702816},
                      {-157.7205811, 21.4702072}, {-157.7203979, 21.4702168},
                      {-157.7201538, 21.4703445}, {-157.7199097, 21.4703960},
                      {-157.7196045, 21.4708157}, {-157.7193451, 21.4708633},
                      {-157.7190094, 21.4707184}, {-157.7186279, 21.4706726},
                      {-157.7184601, 21.4707298}, {-157.7183075, 21.4706306},
                      {-157.7182617, 21.4705410}, {-157.7183533, 21.4704113},
                      {-157.7183075, 21.4701862}, {-157.7180939, 21.4696751},
                      {-157.7182159, 21.4696522}, {-157.7183380, 21.4696903},
                      {-157.7184906, 21.4695721}, {-157.7191315, 21.4694271},
                      {-157.7195740, 21.4688873}, {-157.7200317, 21.4685745},
                      {-157.7208405, 21.4684906}, {-157.7209625, 21.4684048},
                      {-157.7211151, 21.4683857}};
  triangulateExample(a);
  triangulateExample(b);
}
