WARNING_FLAGS=-Wall -Wpedantic -Wextra -Werror -Wconversion
main:
	# NOTE: including the optimization flag to consider how well naive
	# solutions (or any solution, for that matter) at performing in ideal
	# environments

	g++ -std=c++20 $(WARNING_FLAGS) -O2 main.cpp -o test

clean:
	rm test
