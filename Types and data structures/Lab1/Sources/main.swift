import Foundation

struct Number {
  var mantiss = [Character]()
  var power = Int()
  init() {
    self.mantiss = []
    self.power = 0
  }
  mutating func goInt(mantiss: String, power: String) {
    self.mantiss = Array(mantiss.characters)
    self.power = Int(power)!
  }
  mutating func times(otherNumber: Number) -> Number {
    var result = Number()
    var greaterMantiss = (self.mantiss.count >= otherNumber.mantiss.count ? self.mantiss : otherNumber.mantiss)
    var lesserMantiss = (self.mantiss.count < otherNumber.mantiss.count ? self.mantiss : otherNumber.mantiss)
    var greaterMantissSize = (self.mantiss.count >= otherNumber.mantiss.count ? self.mantiss.count : otherNumber.mantiss.count)
    var lesserMantissSize = (self.mantiss.count < otherNumber.mantiss.count ? self.mantiss.count : otherNumber.mantiss.count)
    var multiplyMatrix = [[String]]()
    //TODO Add negative numbers support
    for index in 1...lesserMantissSize{
      var multiplyMatrixLine = [String]()
      for zero in 1..<index{
        multiplyMatrixLine.append("0")
      }
      for otherIndex in 1...greaterMantissSize {
        if greaterMantiss[greaterMantissSize - otherIndex] != "."{
        var multiplyResult = Int(String(greaterMantiss[greaterMantissSize - otherIndex]))! * Int(String(lesserMantiss[lesserMantissSize - index]))!
        multiplyMatrixLine.insert(String(multiplyResult), at: 0)
        }
      }
      multiplyMatrix.append(multiplyMatrixLine)
    }
    //TODO bring both numbers to same power by adding zeroes
    print(multiplyMatrix)
    return result
  }
}



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
      if perhapsInt == nil && testedString[index] != "e" && testedString[index] != "."{
        return false
      }
    }
  }
  return true
}

func enterArray() -> Number?  {
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


func main(){
  var firstNumber = enterArray()!
  var secondNumber = enterArray()!
  if firstNumber == nil {
    print("Wrong input!")
  }
  else {
    print(firstNumber)
  }
  for index in 1...firstNumber.mantiss.count{
    print(firstNumber.mantiss[firstNumber.mantiss.count - index])
  }
  var result = firstNumber.times(otherNumber: secondNumber)
  print(result)
}

main()
