## Copyright (C) 2020 Dov Kruger
## 
# Simulate a star of radius r1
# and mass m
# occulted by a planet of radius r2
# orbiting at a distance d from the star
# planet
# this simulation has simplifying assumptions:
# 1. the planet orbits in a circle, not an ellipse
# 2. We are viewing edge on, with the planet traversing the equator of the star
# There are 4 possible cases
# 1. The planet is behind the star, full light visible
# 2. The planet is next to the star, full light visible
# 3. The planet is fully in front of the star blocking the entire circle
#    of its area
# 4. The planet is partially blocking the star. Because the star
#    is so much bigger we can consider the edge of the star to
#    be a straight line making the math much easier.
#
## Author: Dov Kruger <Dov.Kruger@stevens.edu>
## Created: 2020-05-22

function light = occult (starRadius, starMass, planetRadius, planetDistance)
  starArea = pi * starRadius^2;
  planetArea = pi * planetRadius^2;

  # if x is +/- bigger than the sum of the radii, then the planet
  # will not intersect the star
  notOverlap = starRadius + planetRadius; 
  totalOverlap = starRadius - planetRadius;
  ratio = 1- planetArea/starArea;
  
  n = 10000;
  light = zeros(1, n);
  t=0:2*pi/(n-1):2*pi;
  for i=1:length(t)
    x = planetDistance * cos(t(i));
    z = planetDistance * sin(t(i));
    if z < 0 || x > notOverlap || x < -notOverlap
        light(i) = 1; # planet in back or to side, full light
    else
        if x > 0 && x < totalOverlap || x < 0 && x > -totalOverlap
          light(i) = ratio; # planet fully occulting with entire area
        else
          d = starRadius - abs(x);
          # poor approximation: we are assuming that  area being
          # covered is linear
          light(i) = 1 - planetArea * d/planetRadius / starArea;
        end
    end
  end
 
endfunction
