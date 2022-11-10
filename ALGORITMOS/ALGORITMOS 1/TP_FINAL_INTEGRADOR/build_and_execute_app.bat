:: Compilo código objeto
g++ -Wall -std=c++11 -I.\Include -c .\src\Zoo\Animals\Animal.cpp
g++ -Wall -std=c++11 -I.\Include -c .\src\Zoo\Animals\Oviparous\Oviparous.cpp
g++ -Wall -std=c++11 -I.\Include -c .\src\Zoo\Animals\Oviparous\Cocodrile\Cocodrile.cpp
g++ -Wall -std=c++11 -I.\Include -c .\src\Zoo\Animals\Oviparous\Goose\Goose.cpp
g++ -Wall -std=c++11 -I.\Include -c .\src\Zoo\Animals\Oviparous\Pelican\Pelican.cpp
g++ -Wall -std=c++11 -I.\Include -c .\src\Zoo\Animals\Mammal\Mammal.cpp
g++ -Wall -std=c++11 -I.\Include -c .\src\Zoo\Animals\Mammal\Bat\Bat.cpp
g++ -Wall -std=c++11 -I.\Include -c .\src\Zoo\Animals\Mammal\SeaLion\SeaLion.cpp
g++ -Wall -std=c++11 -I.\Include -c .\src\Zoo\Animals\Mammal\Whale\Whale.cpp
g++ -Wall -std=c++11 -I.\Include -c .\src\Zoo\Zoo.cpp
g++ -Wall -std=c++11 -I.\ -I.\Include\  -c .\bd.cpp


:: Compilo el Binario
g++ -I.\Animal Animal.o -I.\Oviparous Oviparous.o -I.\Cocodrile Cocodrile.o -I.\Goose Goose.o -I.\Pelican Pelican.o -I.\Mammal Mammal.o -I.\Bat Bat.o -I.\SeaLion SeaLion.o -I.\Whale Whale.o -I.\Zoo Zoo.o -I.\ bd.o -o Zoo.exe

:: Limpio los códigos objeto
DEL .\*.o

:: Ejecuto
Zoo.exe
