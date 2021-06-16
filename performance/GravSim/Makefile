DEBUG	:= -g
OPT	:= #-O2
CXX	:= g++ $(DEBUG) $(OPT)
gravsim: GravSim.o Body.o Vec3d.o main.o
	$(CXX) $^ -o $@ # link all .o into a single executable

GravSim.o: GravSim.cc GravSim.hh
	$(CXX) -c $<

Body.o: Body.cc GravSim.hh
	$(CXX) -c $<

Vec3d.o: Vec3d.cc Vec3d.hh
	$(CXX) -c $<

main.o: main.cc GravSim.hh
	$(CXX) -c $<

clean:
	rm *.o gravsim
