all: compile link

compile:
	g++ -c sources/main.cpp -I"D:\Users\Arthur\Documents\libraries\SFML-2.5.1\include" -DSFML_STATIC

link:
	g++ main.o -o main -L"D:\Users\Arthur\Documents\libraries\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clean:
	del -rf *.exe *.o