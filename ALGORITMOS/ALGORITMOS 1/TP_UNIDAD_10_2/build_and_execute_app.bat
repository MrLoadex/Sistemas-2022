:: Compilo código objeto
g++ -Wall -std=c++11 -I.\figura\figura -c .\figura\figura.cpp
g++ -Wall -std=c++11 -I.\circulo -c .\circulo\circulo.cpp 
g++ -Wall -std=c++11 -I.\rectangulo -c .\rectangulo\rectangulo.cpp
g++ -Wall -std=c++11 -I.\triangulo -c .\triangulo\triangulo.cpp
g++ -Wall -std=c++11 -I.\main -c \main\bd.cpp


:: Compilo el Binario
g++ -I.\figura figura.o -I.\circulo circulo.o -I.\rectangulo rectangulo.o -I.\triangulo triangulo.o .\main\bd.cpp -o application.exe


:: Limpio los códigos objeto
DEL .\*.o

:: Ejecuto
application.exe