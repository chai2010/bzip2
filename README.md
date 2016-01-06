# bzip2 compression for Go

https://godoc.org/github.com/chai2010/bzip2

## Install

Install `GCC` or `MinGW` ([download here](http://tdm-gcc.tdragon.net/download)) at first,
and then run these commands:

1. `go get github.com/chai2010/bzip2`
2. `go run bzipper.go < bzip2.go > bzip2.go.bz2`


## Example

```Go
package main

import (
	"io"
	"log"
	"os"

	bzip "github.com/chai2010/bzip2"
)

func main() {
	w := bzip.NewWriter(os.Stdout)
	if _, err := io.Copy(w, os.Stdin); err != nil {
		log.Fatalf("bzipper: %v\n", err)
	}
	if err := w.Close(); err != nil {
		log.Fatalf("bzipper: close: %v\n", err)
	}
}
```

## BUGS

Report bugs to <chaishushan@gmail.com>.

Thanks!
