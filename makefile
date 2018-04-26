grafica1.png : datos.txt
	python grafica1.py
datos.txt : a.out
	./a.out > datos.txt
a.out :
	c++ punto1.cpp
clean :
	rm grafica1.png datos.txt a.out
