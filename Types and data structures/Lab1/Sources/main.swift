import Foundation

func isStringANumber(testedString : String) -> Bool{
  if testedString.range(of : "e") == nil || testedString.countOccurence(of: "e") > 1 {
    print("Seems like your input is NaN")
    return false
  }
  else
    {
    var perhapsInt : Int?;
    for index in testedString.characters.indices {
      perhapsInt = Int(String(testedString[index]))
      if perhapsInt == nil && testedString[index] != "e" && testedString[index] != "." && testedString[index] != "-"{
        return false
      }
    }
  }
  return true
}

func enterNumber() -> Number?  {
  let inputString : String = readLine()!;
  var number = Number();
  if inputString.isEmpty  {
    print("String is empty!")
    return nil
  }
  if !isStringANumber(testedString : inputString){
    print("Seems like your input is NaN")
    return nil
  }
  let newNumber = inputString.components(separatedBy: "e")
  var mantiss = newNumber[0]
  if mantiss.characters.count > 31 {
    print("Mantiss is greater than 30 digits!")
    return nil
  }

  var power = newNumber[1]
  if power.characters.count > 5 {
    print("Power is greater than 5 digits!")
    return nil
  }
  else if Int(power) == nil {
    if power.characters.count == 0{
      power = "0"
    }
    else
      {
        print("Seems like your input is NaN")
        return nil
      }
  }
  number.goInt(mantiss: mantiss, power: power)
  return number
  }

func enterLongInt() -> LongInt? {
  var inputString : String = readLine()!

  if inputString.isEmpty  {
    print("String is empty!")
    return nil
  }
  var newLongInt = LongInt(from : inputString)
  print(newLongInt)
  return newLongInt

}

func main(){
  var firstNumber = enterNumber()
  var secondNumber = enterLongInt()
  if firstNumber == nil || secondNumber == nil{
    print("Wrong input!")
  }
  else {
    print(firstNumber!)

  for index in 1...firstNumber!.mantiss.count{
    // print(firstNumber!.mantiss[firstNumber!.mantiss.count - index])
  }
  var result = firstNumber!.times(otherNumber: secondNumber!)
  print(result)
}
}

main()