all: test run

run: fizzbuzz
	./fizzbuzz

fizzbuzz: fizzbuzz.rs
	rustc fizzbuzz.rs

test-fizzbuzz: fizzbuzz.rs
	rustc --test fizzbuzz.rs -o test-fizzbuzz

test: test-fizzbuzz
	./test-fizzbuzz
