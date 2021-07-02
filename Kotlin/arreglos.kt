fun main(args: Array<String>) {
  var contacts = arrayOf("John", "James", "Amy")
  for (x in contacts) {
    println(x)
  }
  //se puede iterar en caracteres de cadena
  for (x in contacts[0]) {
    println(x)
  }

  //rangos
  for (i in 2..5) {
    println(i)
  }
  for (i in 'a'..'e') {
    println(i)
  }
    // el in sirve para saber si un elemento esta en el rango marcado

  //until
  for (i in 2 until 5) {
    println(i)
  }
  //imprime de 2 a 4, pero no 5

  //se pueden hacer asignaciones de rangos
  var x = 2..6
}