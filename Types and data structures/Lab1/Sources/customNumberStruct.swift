struct Number {
  var mantiss = [Character]()
  var power = Int()
  var sign = Bool()
  init() {
    self.mantiss = []
    self.power = 0
    self.sign = false // false stands for Plus
  }
  mutating func goInt(mantiss: String, power: String) {
      self.mantiss = Array(mantiss.characters)
      self.power = Int(power)!
      if self.mantiss[0] == "-"{
        self.sign = true
        self.mantiss.remove(at: 0)
      }
      else{
        self.sign = false
      }
    }
  mutating func times(otherNumber: LongInt) -> Number? {
    var result = Number()
    result.power = self.power
    var greaterMantiss = (self.mantiss.count >= otherNumber.mantiss.count ? self.mantiss : otherNumber.mantiss)
    var lesserMantiss = (self.mantiss.count < otherNumber.mantiss.count ? self.mantiss : otherNumber.mantiss)
    var greaterMantissSize = (self.mantiss.count >= otherNumber.mantiss.count ? self.mantiss.count : otherNumber.mantiss.count)
    var lesserMantissSize = (self.mantiss.count < otherNumber.mantiss.count ? self.mantiss.count : otherNumber.mantiss.count)

    var multiplyMatrix = [[String]]()

    for index in 1...lesserMantissSize
    {
      var multiplyMatrixLine = [String]()
      for zero in 1..<index
      {
        multiplyMatrixLine.append("0")
      }
      for otherIndex in 1...greaterMantissSize
      {
        if greaterMantiss[greaterMantissSize - otherIndex] != "."
        {
        var multiplyResult = Int(String(greaterMantiss[greaterMantissSize - otherIndex]))! * Int(String(lesserMantiss[lesserMantissSize - index]))!
        multiplyMatrixLine.insert(String(multiplyResult), at: 0)
        }
      }
      multiplyMatrix.append(multiplyMatrixLine)
    }
    var longestLineCount = multiplyMatrix[0].count
    for line in multiplyMatrix{
      if line.count > longestLineCount{
        longestLineCount = line.count
      }
    }
    for line in 0..<multiplyMatrix.count{
      if (longestLineCount - multiplyMatrix[line].count) != 0
      {
      for pos in 1...longestLineCount - multiplyMatrix[line].count
        {
          multiplyMatrix[line].insert("0", at: 0)
        }
      }
    }
    var sumArray = [Int]()
    for zero in 0..<longestLineCount{
      sumArray.append(0)
    }
    for columnNumber in 0..<longestLineCount{
      for rowNumber in 1...multiplyMatrix.count{
        sumArray[columnNumber] += Int(multiplyMatrix[rowNumber-1][columnNumber])!
      }
    }
    var dozens = Int()
    var units = Int()
    for element in 1...sumArray.count{
      if sumArray[sumArray.count - element] >= 10{
        if sumArray.count - element == 0{
          result.power += 1
          if result.power > 99999{
            print("Result exceeds given power limit.")
            return nil
          }
        }
        else{
          var tempString = Array(String(sumArray[element]).characters)
          dozens = Int(String(tempString[0]))!
          print(dozens)
          sumArray[sumArray.count - element - 1] += dozens
        }
        units = sumArray[sumArray.count - element] % 10
        print(units)
        sumArray[sumArray.count - element] = units


      }
    }
    print(sumArray)
    result.sign = self.sign ^ otherNumber.sign
    return result
  }
}


struct LongInt {
  var mantiss = [Character]()
  var sign = Bool()
  init(from : String) {
    self.mantiss = Array(from.characters)
    if self.mantiss[0] == "-"{
      self.sign = true
      self.mantiss.remove(at: 0)
    }
    else{
      self.sign = false
    }
  }
}
