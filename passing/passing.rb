require 'passing_in_c'

include PassingModule

puts "Enter a string for C:"
string = gets 
result = PassingInC.pass_string(string)
puts "C says: #{result}"

result = PassingInC.pass_array([1,2,3])
puts "Returned array of arrays:"
for array in result do
  puts "#{array[0]}, #{array[1]}"
end