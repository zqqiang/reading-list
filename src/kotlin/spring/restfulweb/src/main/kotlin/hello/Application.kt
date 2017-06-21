package org.jetbrains.kotlin.hello

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.web.client.RestTemplateBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.web.client.RestTemplate;

@SpringBootApplication
open class Application {
    companion object {
        val log = LoggerFactory.getLogger(Application::class.java);

        @JvmStatic fun main(args: Array<String>) {
            SpringApplication.run(Application::class.java, *args)
        }

        @Bean
        fun restTemplate(builder: RestTemplateBuilder) {
            return builder.build();
        }

        @Bean
        fun run(restTemplate: RestTemplate) {
            return (args) -> {
                var quote = restTemplate.getForObject("http://gturnquist-quoters.cfapps.io/api/random", Quote::class);
                log.info(quote.toString());
            };
        }
    }
}