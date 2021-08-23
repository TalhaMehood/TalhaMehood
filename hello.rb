puts"hello World"
value1 = 2
value2 = 8

puts value1*value2
#                    ARRAY
array = ['my','name','is','Talha']

array.each_with_index do |i,index|
    puts index.to_s + ": "+ i
end
#                   FUNCTION
# def say_my_name name,age = 23
#     puts "Your name is #{name} and you are #{age}"
# end

# say_my_name "Talha"


                #    CLASS

class Person
    def initialize name
        @name = name
    end
    
    def details age
        puts "This person is called #{@name} and you are #{age}!"
    end

end

puts "Enter your name"
name = gets.chomp
puts "Enter your age"
age = gets.chomp
object =  Person.new(name)
object.details(age)




