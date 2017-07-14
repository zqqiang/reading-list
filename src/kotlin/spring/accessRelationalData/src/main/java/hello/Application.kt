package hello

import org.slf4j.Logger
import org.slf4j.LoggerFactory
import org.springframework.beans.factory.annotation.Autowired
import org.springframework.boot.CommandLineRunner
import org.springframework.boot.SpringApplication
import org.springframework.boot.autoconfigure.SpringBootApplication
import org.springframework.jdbc.core.JdbcTemplate

import java.util.Arrays
import java.util.stream.Collectors

import java.awt.SystemColor.info
import jdk.nashorn.internal.objects.NativeArray.forEach

@SpringBootApplication
class Application : CommandLineRunner {

    @Autowired
    internal var jdbcTemplate: JdbcTemplate? = null

    @Throws(Exception::class)
    fun run(vararg strings: String) {

        log.info("Creating tables")

        jdbcTemplate!!.execute("DROP TABLE customers IF EXISTS")
        jdbcTemplate!!.execute("CREATE TABLE customers(" + "id SERIAL, first_name VARCHAR(255), last_name VARCHAR(255))")

        // Split up the array of whole names into an array of first/last names
        val splitUpNames = Arrays.asList("John Woo", "Jeff Dean", "Josh Bloch", "Josh Long").stream()
                .map { name -> name.split(" ".toRegex()).dropLastWhile { it.isEmpty() }.toTypedArray() }
                .collect<List<Array<Any>>, Any>(Collectors.toList<Array<Any>>())

        // Use a Java 8 stream to print out each tuple of the list
        splitUpNames.forEach { name -> log.info(String.format("Inserting customer record for %s %s", name[0], name[1])) }

        // Uses JdbcTemplate's batchUpdate operation to bulk load data
        jdbcTemplate!!.batchUpdate("INSERT INTO customers(first_name, last_name) VALUES (?,?)", splitUpNames)

        log.info("Querying for customer records where first_name = 'Josh':")
        jdbcTemplate!!.query(
                "SELECT id, first_name, last_name FROM customers WHERE first_name = ?", arrayOf<Any>("Josh"),
                { rs, rowNum -> Customer(rs.getLong("id"), rs.getString("first_name"), rs.getString("last_name")) }
        ).forEach { customer -> log.info(customer.toString()) }
    }

    companion object {

        private val log = LoggerFactory.getLogger(Application::class.java)

        @JvmStatic fun main(args: Array<String>) {
            SpringApplication.run(Application::class.java, args)
        }
    }
}