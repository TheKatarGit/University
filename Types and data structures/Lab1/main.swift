import Foundation

struct Number {
  var mantiss : String
  var power : String
  init() {
    mantiss = ""
    power = ""
  }
}

func enterArray() -> Number?  {
  let inputString : String = readLine()!;
  var number = Number();
  if inputString.isEmpty  {
    print("String is empty!")
    return nil
  }
  if inputString.range(of : "e") == nil{
    print("Seems like your input is NaN")
    return nil
  }
  let newNumber = inputString.components(separatedBy: "e")
  number.mantiss = newNumber[0]
  if number.mantiss.characters.count > 31 {
    print("Mantiss is greater than 30 digits!")
    return nil
  }
  else if Int(number.mantiss) == nil {
    print("Seems like your input is NaN")
    return nil
  }
  number.power = newNumber[1]
  if number.power.characters.count > 5 {
    print("Power is greater than 5 digits!")
    return nil
  }
  else if Int(number.power) == nil {
    print("Seems like your input is NaN")
    return nil
  }
  return number
  }


func main(){
  let firstNumber = enterArray()
  if firstNumber == nil {
    print("Wrong input!")
  }
  else {
    print(firstNumber!)
  }

}

main()
