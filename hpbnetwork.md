# High Performance Browser Networking Reading Notes

## 4. Transport Layer Security (TLS)

### TLS Handshake

#### RSA, Diffie-Hellman and Forward Secrecy
* RSA critical weakness: if get server's private key then they can decrypt the entire session.  
* Diffie-Hellman key exchange: client and server to negotiate a shared secret without explicitly communicating it in the handshake  

### TLS Session Resumption  
* the server to create and send a 32-byte session identifier as part of its ServerHello message  
* both the client and server can store the previously negotiated session parameters—keyed by session ID—and reuse them for a subsequent session.  
* the client can include the session ID in the ClientHello message to indicate to the server that it still remembers the negotiated cipher suite and keys from previous handshake and is able to reuse them.  

#### Session Tickets
* all session data is stored only on the client  
* The main improvement of stateless resumption is the removal of the server-side session cache  

### Chain of Trust and Certificate Authorities
*  Specifically, public key encryption allows us to use the public key of the sender to verify that the message was signed with the right private key  

### Certificate Revocation
#### Certificate Revocation List (CRL)
* each certificate authority maintains and periodically publishes a list of revoked certificate serial numbers  

#### Online Certificate Status Protocol (OCSP)
* perform a real-time check for status of the certificate  

#### OCSP Stapling
* allowing the validation to be performed by the server and be sent ("stapled") as part of the TLS handshake to the client  
* server that periodically retrieves the signed and timestamped OCSP response from the CA  
* The server then appends (i.e. "staples") the signed OCSP response as part of the TLS handshake  

### TLS Record Protocol
* receive application data => divided into blocks => MAC or HMAC added => encrypted using cipher  

### Optimizing for TLS

#### Reduce Computational Costs
#### Enable 1-RTT TLS Handshakes
#### Optimize Connection Reuse
#### Leverage Early Termination
#### Configure Session Caching and Stateless Resumption
#### Enable TLS False Start
* an optional protocol extension that allows the sender to send application data (Figure 4-10) when the handshake is only partially complete.  

#### Optimize TLS Record Size
#### Optimize the Certificate Chain
#### Configure OCSP Stapling
#### Enable HTTP Strict Transport Security (HSTS)
#### Enable HTTP Public Key Pinning (HPKP)
#### Update Site Content to HTTPS
#### Performance Checklist

### Testing and Verification

## 5. Introduction to Wireless Networks

### Ubiquitous Connectivity

### Types of Wireless Networks

### Performance Fundamentals of Wireless Networks

### Measuring Real-World Wireless Performance

## 6. WiFi (todo)
