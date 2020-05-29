function solarsystem(systemfile)
          %  titles=textread(systemfile, '%s %s %s %s %s %s %s %s %s')
  s = csv2cell(systemfile); # the strings
  sys = csvread(systemfile); # the numbers
  a=[0:.02:2*pi 0];
  starRadius = 1e9;
  close all
  figure('position', [0 0 800 800]);
  [x,y,z] = sphere(20);
  x=x*starRadius;
  y=y*starRadius;
  z=z*starRadius;
  surf(x,y,z); # draw the sun
  hold on
  axis equal
  for i = 2:rows(s)
    name = s{i,1}
    orbits = s{i,2}
    if strcmp(orbits, 'Sun')
      meanDist = mean(sys(i,4:5))
      t=rand() * 2*pi; # pick a random angle for the planet
      x=meanDist*cos(t); y = meanDist*sin(t);
      text(x,y,0, name);
      plot(meanDist*cos(a), meanDist*sin(a),0);
    end
  end

endfunction
