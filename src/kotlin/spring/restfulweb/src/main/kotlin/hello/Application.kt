package org.jetbrains.kotlin.hello

import org.slf4j.Logger
import org.slf4j.LoggerFactory
import org.springframework.boot.CommandLineRunner
import org.springframework.boot.SpringApplication
import org.springframework.boot.autoconfigure.SpringBootApplication
import org.springframework.boot.web.client.RestTemplateBuilder
import org.springframework.context.annotation.Bean
import org.springframework.web.client.RestTemplate

@SpringBootApplication
open class Application {
    @Bean
    open fun restTemplate(builder: RestTemplateBuilder): RestTemplate {
        return builder.build()
    }

    @Bean
    @Throws(Exception::class)
    open fun run(restTemplate: RestTemplate): CommandLineRunner {
        return CommandLineRunner {
            val quote = restTemplate.getForObject(
                    "http://gturnquist-quoters.cfapps.io/api/random", Quote::class.java)
            log.info(quote.toString())
        }
    }

    companion object {
        private val log = LoggerFactory.getLogger(Application::class.java)
        @JvmStatic fun main(args: Array<String>) {
            SpringApplication.run(Application::class.java, *args)
        }
    }
}