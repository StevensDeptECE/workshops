#include "GravSim.hh"
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <vector>
#include <random>
#include <unordered_map>

using namespace std;


default_random_engine gen(0); // always select same random numbers for debugging
uniform_int_distribution<int> dist(1,6);
normal_distribution<double> angle(0,2*M_PI);
unordered_map<string,Body*> bodiesByName;

GravSim::GravSim(const char filename[]) {
  t = 0;
  ifstream f(filename);
  char buf[4096];
  f.getline(buf, sizeof(buf)); // skip the first line with the metadata
  char name[16];
  char orbits[16];
  double m, diam, perihelion, aphelion, x,y,z, vx, vy, vz;
  double orbPeriod, rotPeriod;
  double theta = 0; 

  cout << "Name\tPosition\t\tVelocity\t\tAcceleration\n" << setprecision(15);
  while (!f.eof()) {
    f.getline(buf, sizeof(buf));
    istringstream line(buf);
    line >> name >> m >> diam >> perihelion >> aphelion >>
      orbPeriod, rotPeriod;
#if 0
    double theta = angle(gen); // pick a random angle to start the orbit
#endif
    /*
      For a repeatable simulation always pick the same starting angle 0.
      So all planets are lined up along the x axis to start.
      Not much of a simulation, but repeatable debugging 
    */
    //		cout <<			"creating body " << name <<		" start angle= " << theta << " (radians)\n";

    // compute x,y,z for the body
    // simplified, assume circular orbits at average of near and far point for each body
    double r = (perihelion + aphelion) / 2;
    double x = r * cos(theta), y = r * sin(theta), z = 0;
          
    // handle special case for sun: if r = 0, then v = 0
    //TODO: Kepler's law, change this to be correct for circular orbit
    double v = r == 0 ? 0 : sqrt(G*m * (2 / r - 1 / aphelion));
    //TODO: later, change to full elliptical orbits

    double vx = -v * sin(theta), vy = v * cos(theta), vz = 0;
    bodies.push_back(new Body(name, orbits, m, diam/2, x, y, z, vx, vy, vz));
    bodiesByName[orbits] = bodies.back();
    cout << *bodies.back() << "\n";
    theta += M_PI * 1.2;
  }
}

void GravSim::forward(uint32_t n, double dt) {
  for (uint32_t i = 0; i < n; i++) {
    timestep(dt);
  }
  // print out the solar system
  cout << *this;
}


/*
  Calculate all bodies accelerations and
  step forward in time
*/
void GravSim::timestep(double dt) {
  for (int i = 0; i < bodies.size(); i++) {
    bodies[i]->a = Vec3d(); // set acceleration of this body to zero
    for (int j = 0; j < bodies.size(); j++)
      if (i != j)
	bodies[i]->a = bodies[i]->a + bodies[i]->gravAccel(*bodies[j]);
  }
  for (int i = 0; i < bodies.size(); i++) {
    bodies[i]->pos = bodies[i]->pos +
      0.5 * bodies[i]->a * pow(dt,2.0) + bodies[i]->v * dt;
    bodies[i]->v = bodies[i]->v +  bodies[i]->a * dt;
  }
  t += dt;
}

std::ostream& operator <<(std::ostream& s, GravSim sim) {
  s << "GravSim t=" << sim.t << '\n';
  for (auto b : sim.bodies)
    s << *b << '\n';
  return s;
}
