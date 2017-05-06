all:
	g++ -std=c++11 main.cpp memory.cpp cpu.cpp CPUProgramDyn.cpp computer.cpp -o exe

clean:
	rm exe
