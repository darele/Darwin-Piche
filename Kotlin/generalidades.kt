fun main(args: Array<String>) {
    
    //Impresion de datos
    println("Hello World")
    print("Hello World") //sin salto de linea

    //declaracion de variables
    var num: Int = 42;
        //pueden ser tipo Int, Double, Float, Char, String, Boolean
    println(num);
        //Se puede obviar el tipo
    var num2 = 42
    println(num2)
    // Para constantes es lo mismo, solo que con "val"

    //Operadores
        // +-*/%; el + tambien se usa para concatenar
        //se puede +=, *=, -=, etc
        //se puede ++, --, a ambos lados
        
        //Operadores de comparacion (ya los conoces)

    //Entrada
        //readLine() //lee el valor como cadena
    var age = readLine()
    println("You are " + age + " years old");
        
        //casting de la Entrada
    var kika = readLine()!!.toInt()
    println(kika * kika)
        //el !! significa not-null assertion operator
        //se asegura que el readLine() tenga algo
        //Si, es necesario XD
}
