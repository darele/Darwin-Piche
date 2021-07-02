fun main(args: Array<String>) {
   //condicional if, else if y else, ya lo conoces

  /*
  //Operador ternario
  val num = 7
  val result = if (num > 0) "Positive" else "Negative"
  println(result)
  */

  //operador multinario
  val num = -7
    
  val result = when {
      num > 0 -> "Positive"
      num < 0 -> "Negative"
      else -> "Zero"
  }
  println(result)

  //Operadores logicos son los mismos

  //while
  var i = 1

  while (i <= 5) {
      println("Hello")
      i++
  }
    //aqui tambien existe break y continue
    
}