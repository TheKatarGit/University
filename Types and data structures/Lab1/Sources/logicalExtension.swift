func ^(left: Bool, right: Bool) -> Bool {
  if left && right {
    return false
  }
  else if left || right {
    return true
  }
  else {
    return false
  }
}
