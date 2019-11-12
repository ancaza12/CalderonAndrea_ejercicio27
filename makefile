pre27.dat : pre27.x
	./pre27.x > pre27.dat
    
pre27.x : pre27.cpp
	c++ pre27.cpp -o pre27.x