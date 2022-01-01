starprof: main.c ../integration/solver.c ../integration/bisection.c ../integration/save.c ../ec_edo/polytropic.c ../regime/tov.c ../io/print.c ../io/cgs.c ../libs/main.h ../libs/user.h
	gcc -I../libs main.c ../ec_edo/polytropic.c ../regime/tov.c ../integration/solver.c ../integration/bisection.c ../integration/save.c ../io/print.c ../io/cgs.c -o starprof -lm
clean:
	rm starprof profilecgs.dat profile.dat profile.png
