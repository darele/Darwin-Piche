fun main(args: Array<String>) {
  var n = readLine()!!.toInt()
  var arr = Array(n, {_ -> 0})
  var entrada = readLine()!!.split(' ')
  for (i in 0..n-1) {
    arr[i] = entrada[i].toInt()
  }
  var mayor1 = arr[0]
  var mayor2 = if (n > 1) arr[1] else arr[0]
  var ans = 0
  for (i in 1..n-1) {
    if (arr[i] > mayor1) {
      mayor2 = mayor1
      mayor1 = arr[i]
    } else if (arr[i] > mayor2) {
      mayor2 = arr[i]
    } else {
      if (i > 1 && arr[i] < mayor2) ans++
    }
  }
  println(ans)
}
