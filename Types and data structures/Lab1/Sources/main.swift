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
  let inputString : String = readLine()!
  var number = Number()
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
  if mantiss.characters.count > 31 && inputString.countOccurence(of: ".") == 1 {
    print("Mantiss is greater than 30 digits!")
    return nil
  }

  if mantiss.characters.count > 30 && inputString.countOccurence(of: ".") == 0 {
    print("Mantiss is greater than 30 digits!")
    return nil
  }
  if inputString.countOccurence(of: ".") > 1{
    print("Seems like your input is NaN")
    return nil
  }
  if mantiss[mantiss.startIndex] == "."{
    print("Seems like your input is NaN")
    return nil
  }

  var power = newNumber[1]
  if (power.characters.count > 5 && power.countOccurence(of: "-") < 1) {
    print("Power is greater than 5 digits!")
    return nil
  }
  else if (power.characters.count > 6 && power.countOccurence(of: "-") > 0){
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
  number = Number(mantiss: mantiss, power: power)
  return number
  }

func enterLongInt() -> LongInt? {
  let inputString : String = readLine()!

  if inputString.isEmpty  {
    print("String is empty!")
    return nil
  }
  let newLongInt = LongInt(from : inputString)
  return newLongInt

}

func main(){
  print("Input real number: ")
  var firstNumber = enterNumber()
  print("\nInput integer number: ")
  let secondNumber = enterLongInt()
  if firstNumber == nil || secondNumber == nil{
    print("Wrong input!")

  }
  else {
  let result = firstNumber!.times(otherNumber: secondNumber!)
  if result != nil{
    var resultString = ""
    if result!.sign{
      resultString.append("-")
    }
    for element in result!.mantiss{
      resultString.append(String(element))
    }
    resultString.append("e")
    resultString.append(String(result!.power))
    print("Result of multiplication : \(resultString)")
  }

}
}

main()
