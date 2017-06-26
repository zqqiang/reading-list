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

interface Clickable {
    fun click()
    fun showOff() = println("I'm clickable!")
}

interface Focusable {
    fun setFocus(b: Boolean) = println("I ${if (b) "got" else "lost"} focus.")
    fun showOff() = println("I'm focusable!")
}

class Button : Clickable, Focusable {
    override fun click() = println("I was clicked")
    override fun showOff() {
        super<Clickable>.showOff()
        super<Focusable>.showOff()
    }
}

fun main(args: Array<String>) {
    println(getGreeting())

    loop()
    testWhen()
    testRange()

    val button = Button()
    button.showOff()
    button.setFocus(true)
    button.click()
}