import Foundation

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
    var dotIndex : Int?
    for i in 0..<self.mantiss.endIndex{
      if self.mantiss[i] == "."{
        dotIndex = i;
      }
    }
    // print(self.power)
    if dotIndex != nil{
      self.mantiss.remove(at: dotIndex!)
      let j = 0
      while self.mantiss[j] == "0"{
        self.mantiss.remove(at: j)
        self.power-=1
        if self.power < -99999{
          // print("Result exceeds given power limit.")
          return nil
        }
      }
    }
    result.power = self.power
    // print(self)
    var greaterMantiss =  self.mantiss
    var lesserMantiss = otherNumber.mantiss
    let greaterMantissSize = self.mantiss.count
    let lesserMantissSize = otherNumber.mantiss.count

    var multiplyMatrix = [[String]](repeating: [String](repeating: String(), count: lesserMantissSize), count: greaterMantissSize)

    for index in 1...lesserMantissSize
    {
      //Initializing line of multiplyMatrix and filling it with zeroes

      //filling lines of multiplyMatrix, also detecting dot
      var counter = 0;
      for otherIndex in 1...greaterMantissSize
      {
        var multiplyMatrixLine = [String](repeating: "0", count: greaterMantissSize)
        if greaterMantiss[greaterMantissSize - otherIndex] != "."
        {

        let multiplyResult = Int(String(greaterMantiss[greaterMantissSize - otherIndex]))! * Int(String(lesserMantiss[lesserMantissSize - index]))!
        // print(multiplyResult)
        multiplyMatrixLine[greaterMantissSize - counter - 1] = String(multiplyResult)
        print(multiplyMatrixLine)
        // for i in 0..<counter{
        //   multiplyMatrixLine.append("0")
        // }

        counter+=1

        }
        else{
          dotIndex = greaterMantissSize - otherIndex
        }
        multiplyMatrix[counter-1] = multiplyMatrixLine
      }
      // print(multiplyMatrix)

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
      for _ in 1...longestLineCount - multiplyMatrix[line].count
        {
          multiplyMatrix[line].insert("0", at: 0)
        }
      }
    }

    for line in 0..<multiplyMatrix.count{
      multiplyMatrix[line] = multiplyMatrix[line].reversed()
    }
    // // print(multiplyMatrix)
    // multiplyMatrix = multiplyMatrix.reversed()
    //Initializing array to hold addition result and filling it with zeroes
    // print("MATRIX\(multiplyMatrix)")
    var sumArray = [Int](repeating: 0, count:longestLineCount)

    for columnNumber in 0..<longestLineCount{
      for rowNumber in 0..<multiplyMatrix.count{
        // print(multiplyMatrix[rowNumber][columnNumber])
        sumArray[columnNumber] += Int(multiplyMatrix[rowNumber][columnNumber])! //* Int(pow(Double(10), Double(rowNumber)))
        // print("RES \(sumArray[columnNumber])")
      }
    }

    sumArray = sumArray.reversed()
    print(sumArray)
    // var dozens = Int()
    // var units = Int()
    for element in 1...sumArray.count{
      if sumArray[sumArray.count - element] >= 10{
        // print("BREAK AT \(element)")
        var tempString = String(sumArray[sumArray.count - element])
        var arr = Array(tempString.characters)
        // print("ARR \(arr)")
        let units = Int(String(arr[arr.endIndex - 1]))
        arr.remove(at: arr.endIndex - 1)
        let dozens = Int(String(arr))
        if sumArray.count - element == 0{
          sumArray.insert(0, at: 0)
        }
        sumArray[sumArray.count - element] = units!
        sumArray[sumArray.count - element - 1] += dozens!
      }
      // print(sumArray)
    }


    while sumArray[0] >= 10{
      sumArray.insert(0, at:0)
      var tempString = String(sumArray[1])
      var arr = Array(tempString.characters)
      // print("ARR \(arr)")
      let units = Int(String(arr[arr.endIndex - 1]))
      arr.remove(at: arr.endIndex - 1)
      let dozens = Int(String(arr))
      sumArray[1] = units!
      sumArray[0] += dozens!

    }
    // print("COUNT \(sumArray.count)")
    result.sign = self.sign ^ otherNumber.sign
    if sumArray.count > 30{
      while sumArray.count > 30{
        if sumArray[sumArray.endIndex - 1] >= 5{
          sumArray[sumArray.endIndex - 2] += 1
        }
        // print("ARA \(sumArray)")
        sumArray.remove(at: sumArray.endIndex - 1)
        if result.power > 99999{
          // print("Result exceeds given power limit.")
          return nil
        }
        else{
          result.power += 1
        }
      }
      sumArray.remove(at: sumArray.endIndex - 1)
    }
      // print("COUNT \(sumArray.count)")
    sumArray.insert(0,at: 0)
    for element in sumArray{
      result.mantiss.append(Character(String(element)))
    }
    result.mantiss.insert(".", at:1)
    var i = 1
    let lastElement = result.mantiss.endIndex

    while result.mantiss[lastElement - i] == "0"{
      result.mantiss.remove(at: lastElement - i)
      result.power += 1
      i+=1
    }
    // print(result.mantiss[2])
    // print("THIS")
    // print(result.mantiss.endIndex)
      for _ in 2..<result.mantiss.endIndex{
        if result.power > 99999{
          // print("Result exceeds given power limit.")
          return nil
        }
        else{
          // print("DONE")
          result.power += 1
        }
      }
    // print(result)
    // print(result.power)
    i = 2
    while result.mantiss[i] == "0"{
      // print("BLAH")
      result.mantiss.remove(at: i)
      result.power-=1
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
