require 'random_in_c'

include RandomModule

puts "A random number less than?"
max = gets 
rand = RandomInC.random_number(max.to_i)
puts "C says: #{rand}" 