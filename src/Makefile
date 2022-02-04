MAIN := $(MYPATH)/src/main.c \

include $(MYPATH)/src/integration/Makefile
include $(MYPATH)/src/io/Makefile
include $(MYPATH)/src/model/Makefile
include $(MYPATH)/physics/Makefile

LIBS = $(MYPATH)/src/libs/main.h \
			$(MYPATH)/src/libs/physics.h \
				$(MYPATH)/src/libs/eos.h \
					$(MYPATH)/src/libs/model.h

starprof: $(MAIN) $(LIBS)
	@echo ""
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠏⠙⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠏⠀⠀⠘⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⡏⠀⠀⠀⠀⠹⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡟⠀⠀⠀⠀⠀⠀⢻⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⢀⣤⣤⣶⠶⠶⠾⠿⠿⠛⠛⠀⠀⠀⠀⠀⠀⠀⠀⠛⠛⠿⠿⠶⠶⠶⣶⣤⣤⡀"
	@echo "⠘⣿⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠔⡀⠀⠀⢀⠢⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣽⠏"
	@echo "⠀⠈⠻⣦⡀⠀⠀⠀⠀⠀⠀⢸⣦⡇⠀⠀⢸⣤⡇⠀⠀⠀⠀⠀⠀⢀⣴⠟⠁⠀"
	@echo "⠀⠀⠀⠈⠛⢷⣄⠀⠀⠀⠀⠘⣿⡇⠀⠀⠸⣿⠇⠀⠀⠀⠀⣠⣴⠟⠁⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠙⣷⡄⠀⠀⠀⠉⠀⠀⠀⠀⠉⠀⠀⠀⠠⣾⠋⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣇⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⣿⠁⠀⠀⠀⠀⣀⣤⡾⢷⣤⣀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⢰⡿⠀⢀⣠⣴⠾⠋⠁⠀⠀⠈⠙⠷⣦⣄⡀⠀⢻⡇⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠸⣿⠾⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠷⣾⠇⠀⠀⠀⠀⠀"
	@echo ""
	@echo "Compiling files..."
	@echo ""
	@-gcc -I../src/libs $(MAIN) -o stars -lm && echo "\033[0;32m=== Compilation SUCCEED ===\033[0m"|| echo "\033[1;31m=== Compilation FAILED ===\033[0m";
	@echo ""
	@echo "###########################################################"
	@echo "################### Makefile parameters ###################"
	@echo "###########################################################"
	@echo "" 
	@echo " Code path = "$(MYPATH)
	@echo " Physics = "$(REGIME)
	@echo " Equation of State (EOS) = "$(EOS)
	@echo " Stars to build = "$(EJECUTION) 
	@echo " SPROFILE for a star's profile with a specific central density"
	@echo " FPROFILE for a family of stars in a range of central densities"
	@echo ""
	@echo "###########################################################"
	@echo "" 
	
clean:
	rm -f *.o *.dat *.png stars
	
save:
	tar -czvf archive.tar.gz $(MYPATH)/start/profile.png \
		$(MYPATH)/start/profilecgs.png \
			$(MYPATH)/start/profileandmetric.png \
				$(MYPATH)/start/profileandmetric.png \
					$(MYPATH)/start/profile.dat \
						$(MYPATH)/start/profilecgs.dat
