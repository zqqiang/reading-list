SSL_want() examines the internal state information of the SSL object.  
The information must therefore only be used for normal operation under non-blocking I/O.  
Error conditions are not handled and must be treated using ssl_get_error(3)

The following return values can currently occur for SSL_want():

SSL_WRITING  
There are data in the SSL buffer that must be written to the underlying BIO layer in order to complete the actual operation.  
A call to ssl_get_error(3) should return SSL_ERROR_WANT_WRITE

SSL_READING  
More data must be read from the underlying BIO layer in order to complete the actual operation.  
A call to ssl_get_error(3) should return SSL_ERROR_WANT_READ

SSL_X509_LOOKUP  
The operation did not complete because an application callback set by SSL_CTX_set_client_cert_cb() has asked to be called again.  
A call to ssl_get_error(3) should return SSL_ERROR_WANT_X509_LOOKUP
