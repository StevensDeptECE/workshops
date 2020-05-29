function exoplanetdemo()
  pkg load geometry;
  pkg load io
  s = csv2cell('exoexample.dat'); # the names
  sys = csvread('exoexample.dat'); # the numbers
  a=[0:.02:2*pi 0];
  starRadius = 1e9;
  [x,y,z] = sphere(20);
  x=x*starRadius;
  y=y*starRadius;
  z=z*starRadius;
  starArea = pi * starRadius^2;
#  plot(x,z); # draw the sun in 2d
  numPlanets = rows(s);
  for i = 3:numPlanets
    name = s{i,1};
    meanDist(i) = mean(sys(i,4:5));
    t(i)=rand() * 2*pi; # pick a random angle for the planet
    dt(i)=2*pi/sys(i,7); 
  end
  n=10000;
  light = zeros(1,n);
  for f = 1:n
    clf;
    drawCircle(0,0,starRadius);
    hold on
    L=1;
    for i=3:numPlanets
      x = meanDist(i) * cos(t(i)); y = meanDist(i) * sin(t(i));
      rPlanet = sys(i,4)/2;
      possibleIntersect = starRadius + rPlanet;
      if (y > 0) && (abs(x) < possibleIntersect)
        drawCircle(x, 0, rPlanet, 'r');
        planetArea = pi * rPlanet^2;
        L = L - planetArea/starArea;
      end
      t(i) = t(i) + dt(i);
    end
    light(i) = L;
    if L < 1
      xlim([-starRadius,starRadius]);
      text(0,0, ['t=' num2str(f)]);
      drawnow();
    end
  end
endfunction
