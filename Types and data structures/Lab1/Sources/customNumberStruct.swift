struct Number {
  var mantiss = [Character]()
  var power = Int()
  var sign = Bool()
  init(mantiss: String = "", power: String = "") {
        if mantiss != ""{
          self.mantiss = Array(mantiss.characters)
          if self.mantiss[0] == "-"{
            self.sign = true
            self.mantiss.remove(at: 0)
          }
          else{
            self.sign = false
          }
        }
        else{
          self.mantiss = []
          self.sign = false
        }
        if power != ""{
          self.power = Int(power)!
        }
        else {
          self.power = 0
        }
    }

  mutating func times(otherNumber: LongInt) -> Number? {
    var result = Number()
    result.power = self.power
    var greaterMantiss = (self.mantiss.count >= otherNumber.mantiss.count ? self.mantiss : otherNumber.mantiss)
    var lesserMantiss = (self.mantiss.count < otherNumber.mantiss.count ? self.mantiss : otherNumber.mantiss)
    var greaterMantissSize = (self.mantiss.count >= otherNumber.mantiss.count ? self.mantiss.count : otherNumber.mantiss.count)
    var lesserMantissSize = (self.mantiss.count < otherNumber.mantiss.count ? self.mantiss.count : otherNumber.mantiss.count)
    var dotIndex : Int?
    var multiplyMatrix = [[String]]()

    for index in 1...lesserMantissSize
    {
      //Initializing line of multiplyMatrix and filling it with zeroes
      var multiplyMatrixLine = [String]()
      for zero in 1..<index
      {
        multiplyMatrixLine.append("0")
      }
      //filling lines of multiplyMatrix, also detecting dot index
      for otherIndex in 1...greaterMantissSize
      {
        if greaterMantiss[greaterMantissSize - otherIndex] != "."
        {
        var multiplyResult = Int(String(greaterMantiss[greaterMantissSize - otherIndex]))! * Int(String(lesserMantiss[lesserMantissSize - index]))!
        multiplyMatrixLine.insert(String(multiplyResult), at: 0)
        }
        else{
          dotIndex = greaterMantissSize - otherIndex
        }
      }

      multiplyMatrix.append(multiplyMatrixLine)
    }
    //searching for the longest line in multiplyMatrixLine
    var longestLineCount = multiplyMatrix[0].count
    for line in multiplyMatrix{
      if line.count > longestLineCount{
        longestLineCount = line.count
      }
    }
    // Inserting zeroes in front of lines shorter than max line
    // Makes it easier to multiply
    for line in 0..<multiplyMatrix.count{
      if (longestLineCount - multiplyMatrix[line].count) != 0
      {
      for pos in 1...longestLineCount - multiplyMatrix[line].count
        {
          multiplyMatrix[line].insert("0", at: 0)
        }
      }
    }
    //Initializing array to hold addition result and filling it with zeroes
    var sumArray = [Int]()
    for zero in 0..<longestLineCount{
      sumArray.append(0)
    }
    //addition
    for columnNumber in 0..<longestLineCount{
      for rowNumber in 1...multiplyMatrix.count{
        sumArray[columnNumber] += Int(multiplyMatrix[rowNumber-1][columnNumber])!
      }
    }
    //
    var dozens = Int()
    var units = Int()
    for element in 1...sumArray.count{
      if sumArray[sumArray.count - element] >= 10{
        if sumArray.count - element == 0{
          if element == 30 {
          result.power += 1
          if result.power > 99999{
            print("Result exceeds given power limit.")
            return nil
          }
        }
        else{
          sumArray.insert(0, at: 0)
        }
      }
        var tempString = Array(String(sumArray[sumArray.count - element]).characters)
        dozens = Int(String(tempString[0]))!
        sumArray[sumArray.count - element - 1] += dozens
        units = sumArray[sumArray.count - element] % 10
        sumArray[sumArray.count - element] = units
      }
    }
    result.sign = self.sign ^ otherNumber.sign
    for element in sumArray{
      result.mantiss.append(Character(String(element)))
    }
    if dotIndex != nil{
      result.mantiss.insert(".", at:dotIndex! + multiplyMatrix.count - 1 )
    }
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
