package org.jetbrains.kotlin.hello

import com.fasterxml.jackson.annotation.JsonIgnoreProperties

@JsonIgnoreProperties(ignoreUnknown = true)
class Quote {

    var type: String? = null
    var value: Value? = null

    override fun toString(): String {
        return "Quote{" +
                "type='" + type + '\'' +
                ", value=" + value +
                '}'
    }
}