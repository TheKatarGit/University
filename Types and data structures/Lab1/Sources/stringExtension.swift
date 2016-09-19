extension String {
  func countOccurence(of: Character ) -> Int {
    var timesOccured: Int = 0
    for element in self.characters {
      if element == of {
        timesOccured += 1
      }
    }
    return timesOccured
  }
}
