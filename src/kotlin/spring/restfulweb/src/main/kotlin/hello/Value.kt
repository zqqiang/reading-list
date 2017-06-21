package org.jetbrains.kotlin.hello

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

@JsonIgnoreProperties(ignoreUnknown = true)
data class Value(val id: Long, val quote: String)
