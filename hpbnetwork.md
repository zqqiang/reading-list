# High Performance Browser Networking Reading Notes

## Transport Layer Security (TLS)

### RSA, Diffie-Hellman and Forward Secrecy
* RSA critical weakness: if get server's private key then they can decrypt the entire session.  
* Diffie-Hellman key exchange: client and server to negotiate a shared secret without explicitly communicating it in the handshake  

### Server Name Indication (SNI)  
### TLS Session Resumption  