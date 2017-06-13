package demo

fun getGreeting(): String {
    val words = mutableListOf<String>()
    words.add("Hello,")
    words.add("world!")

    return words.joinToString(separator = " ")
}

fun loop() {
    val items = listOf("apple", "banana", "kiwi")
    for (item in items) {
        println(item)
    }
    for (index in items.indices) {
        println("item at $index is ${items[index]}")
    }
}

fun describe(obj: Any): String = 
when (obj) {
    1 -> "One"
    "Hello" -> "Greeting"
    is Long -> "Long"
    !is String -> "Not a String"
    else -> "Unknown"
}

fun testWhen() {
    println(describe(1));
    println(describe("Hello"));
    println(describe(100));
    println(describe(true));
}

fun testRange() {
    val x = 10
    val y = 9
    if (x in 1..y+1) {
        println("fit in range")
    }
}

fun main(args: Array<String>) {
    println(getGreeting())

    loop();
    testWhen();
    testRange();
}