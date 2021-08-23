


class Calculator 
    attr_accessor :number1, :number2
    def initialize (number1, number2)
        @number1 = number1
        @number2 = number2
    end

    def Addition 
        puts @number1 + @number2
    end

    def subtraction 
        puts @number1 - @number2
    end

    def Multiplication 
        puts @number1 * @number2
    end

    def Division 
        puts @number1 / @number2
    end
end

puts "Enter two number" 

number1 = gets.to_i
number2 = gets.to_i

puts "Enter the operation you want to perform "
puts "1. Addition "
puts "2. Subtraction"
puts "3. Multiplication "
puts "4. Division"

navMenu = gets.chomp

obj = Calculator.new(number1 , number2)

if navMenu == "1"
    obj.Addition
elsif navMenu == "2"
    obj.subtraction
elsif navMenu == "3"
    obj.Multiplication
elsif navMenu == "4"
    obj.Division
end



    
    
    
    
