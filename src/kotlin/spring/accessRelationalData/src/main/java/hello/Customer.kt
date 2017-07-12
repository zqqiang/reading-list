package hello;

class Customer(private val id: Long, private val firstName: String, private val lastName: String) {
    override fun toString(): String {
        return String.format(
            "Customer[id=%d, firstName='%s', lastName='%s']",
                id, firstName, lastName);
    }
}