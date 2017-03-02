# Nginx Source Code Reading Notes

## core

### nginx.c

* define string and length in one struct  
~~~~
#define ngx_string(str)     { sizeof(str) - 1, (u_char *) str }
~~~~

* define null string as zero length and null pointer  
~~~~
#define ngx_null_string     { 0, NULL }
~~~~

* [offsetof](http://www.cplusplus.com/reference/cstddef/offsetof/) Return member offset  
~~~~
offsetof(ngx_core_conf_t, daemon)
~~~~

* [char *const argv[]](http://stackoverflow.com/questions/7026350/whats-char-const-argv)  
~~~~
main(int argc, char *const *argv)
~~~~

* ngx_array_t - dynamic array  
