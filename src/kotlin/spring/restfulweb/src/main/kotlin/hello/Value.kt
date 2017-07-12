package org.jetbrains.kotlin.hello

import com.fasterxml.jackson.annotation.JsonIgnoreProperties

@JsonIgnoreProperties(ignoreUnknown = true)
class Value {

    var id: Long? = null
    var quote: String? = null

    override fun toString(): String {
        return "Value{" +
                "id=" + id +
                ", quote='" + quote + '\'' +
                '}'
    }
}