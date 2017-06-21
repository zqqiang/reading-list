package org.jetbrains.kotlin.hello

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

@JsonIgnoreProperties(ignoreUnknown = true)
data class Quote(val type: String, val value: Value)
