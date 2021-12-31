starprof: main.c ../integration/solver.c ../integration/bisection.c ../ec_edo/polytropic.c ../regime/tov.c ../libs/main.h ../libs/user.h
	gcc -I../libs main.c ../ec_edo/polytropic.c ../regime/tov.c ../integration/solver.c ../integration/bisection.c -o starprof -lm
clean:
	rm starprof profilecgs.dat profile.dat profile.png
