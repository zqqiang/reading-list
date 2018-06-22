# Echo
Echo golang source code reading notes.  
Heavy reuse golang http module so little framework code.  

## Start
start from a simple echo server
```golang
  package main

  import (
    "net/http"

    "github.com/labstack/echo"
    "github.com/labstack/echo/middleware"
  )

  // Handler
  func hello(c echo.Context) error {
    return c.String(http.StatusOK, "Hello, World!")
  }

  func main() {
    // Echo instance
    e := echo.New()

    // Middleware
    e.Use(middleware.Logger())
    e.Use(middleware.Recover())

    // Routes
    e.GET("/", hello)

    // Start server
    e.Logger.Fatal(e.Start(":1323"))
  }
```

## Content
1. [echo.go](#echogo)
1. [router.go](#routergo)


## echo.go
create an instance of Echo  
A return statement without arguments returns the [named return values](https://tour.golang.org/basics/7)  
If so, they are treated as variables defined at the top of the function  
```golang
func New() (e *Echo) {
  e = $Echo{...}
  return
}
```
register Middleware
```golang
func (e *Echo) Use(middleware ...MiddlewareFunc) {
  e.middleware = append(e.middleware, middleware...)
}
```
register GET handler
```golang
func (e *Echo) GET(path string, h HandlerFunc, m ...MiddlewareFunc) *Route {
  return e.Add(GET, path, h, m...)
}
```
call router Add, construct Route and add it to routes array
```golang
func (e *Echo) Add(method, path string, handler HandlerFunc, middleware ...MiddlewareFunc) *Route {
  e.router.Add(method, path, func(c Context) error {})
  r := &Route{}
  e.router.routes[mehod+path] = r
  return r
}
```
start http server
```golang
func (e *Echo) Start(address string) error {
  e.Server.Addr = address
  return e.StartServer(e.Server)
}
func (e *Echo) StartServer(s *http.Server) (err error) {
  ...
  // todo: 
  s.Handler = e
  ...
  return s.Serve(e.Listener)
  or ...
  return s.Serve(e.TLSListener)
}
```

## router.go
router register handler
```golang
func (r *Router) Add(method, path string, h HandlerFunc) {
  // e.GET("/", hello) => return e.Add(GET, "/", hello)
  r.insert(method, path, h, skind, ppath, pnames)
}

func (r *Router) insert(method, path string, h HandlerFunc, t kind, ppath string, pnames []string) {
  cn := r.tree // Current node as root
  ...
  cn.addHandler(method, h)
  ...
}

func (n *node) addHandler(method string, h HandlerFunc) {
  case GET:
    n.methodHandler.get = h
}
```