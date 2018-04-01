all:
	
part2: part2main.c app1.c app2.c app3.c
	gcc part2main.c -o part2 -lm
	gcc app1.c -o solver -lm
	gcc app2.c -o trace -lm
	gcc app3.c -o fib -lm
clean:
	rm -f part2
	rm -f solver
	rm -f trace
	rm -f fib
