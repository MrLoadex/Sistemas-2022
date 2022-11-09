:: Compilo código objeto
g++ -Wall -std=c++11 -I.\Animal -c .\Animal\Animal.cpp
g++ -Wall -std=c++11 -I.\Animal\Oviparous -c .\Animal\Oviparous\Oviparous.cpp
g++ -Wall -std=c++11 -I.\Animal\Oviparous\Cocodrile -c .\Animal\Oviparous\Cocodrile\Cocodrile.cpp
g++ -Wall -std=c++11 -I.\Animal\Oviparous\Goose -c .\Animal\Oviparous\Goose\Goose.cpp
g++ -Wall -std=c++11 -I.\Animal\Oviparous\Pelican -c .\Animal\Oviparous\Pelican\Pelican.cpp
g++ -Wall -std=c++11 -I.\Animal -c .\Animal\Mammal\Mammal.cpp
g++ -Wall -std=c++11 -I.\Animal -c .\Animal\Mammal\Bat\Bat.cpp
g++ -Wall -std=c++11 -I.\Animal -c .\Animal\Mammal\SeaLion\SeaLion.cpp
g++ -Wall -std=c++11 -I.\Animal -c .\Animal\Mammal\Whale\Whale.cpp
g++ -Wall -std=c++11 -I.\Zoo -c .\Zoo\Zoo.cpp
g++ -Wall -std=c++11 -I.\ -c .\bd.cpp


:: Compilo el Binario
g++ -I.\Animal Animal.o -I.\Oviparous Oviparous.o -I.\Cocodrile Cocodrile.o -I.\Goose Goose.o -I.\Pelican Pelican.o -I.\Mammal Mammal.o -I.\Bat Bat.o -I.\SeaLion SeaLion.o -I.\Whale Whale.o -I.\Zoo Zoo.o -I.\ bd.o -o Zoo.exe

:: Limpio los códigos objeto
DEL .\*.o

:: Ejecuto
Zoo.exe