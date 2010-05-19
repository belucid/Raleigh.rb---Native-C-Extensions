require 'factorial_in_c'
require 'benchmark'

include FactorialModule

puts "A number to get the factorial?"
number = gets.to_i 

factorial = 0
puts "Ruby factorial computation time:\n" + Benchmark.measure {
  factorial = 1; 
  for i in 1..number
    factorial = factorial * i;
  end
}.to_s
puts "Ruby says: #{factorial}"

puts "C factorial computation time:\n" + Benchmark.measure {
  factorial = FactorialInC.factorial(number)
}.to_s
puts "C says: #{factorial}"