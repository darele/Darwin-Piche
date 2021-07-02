fun apply(x:Int, action: (Int) -> Int): Int {
    return action(x)
}

fun sum(x: Int, y: Int): Int {
  return (x+y)
}

fun main(args: Array<String>) {
  println(sum(3,2))

  //funciones anonimas
  val f: (Int, Int) -> Int = { a, b -> a+b }
    var result = f(8, 42)
    println(result)

  //foreach
  var arr = arrayOf(1, 3, 5)
  arr.forEach {
      item -> println(item * 4)
  }

  //funciones de orden superior
  println(apply(4, {x -> x*2}))
    println(apply(4, {x -> x/2}))
}