package main

import (
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
)

func main() {
	response, err := http.Get("https://lupricht.net/assets/debian.png")
	if err != nil {
		log.Fatalf("Etwas ist schief gelaufen: %s", err)
	}
	data, err := io.ReadAll(response.Body)
	defer response.Body.Close()
	if err != nil {
		log.Fatalf("Etwas ist parsen vom Body schief gelaufen: %s", err)
	}
	err=os.WriteFile("./output.png", data, 0644)
	if err != nil {
		log.Fatalf("Etwas ist beim schreiben schief gelaufen: %s", err)
	}

	fmt.Print("Done")

}
