package main 


import (
    "log"

    "os"
    "sync"
    "time"
	"io/ioutil"
)


func mylogger(gh string){
    

	var wg sync.WaitGroup

    wg.Add(3)

	log.Println(gh)
	go func() {
        defer wg.Done()
        for i := 0; i < 10; i++ {
            log.Println("F1; loop:", i)
            time.Sleep(time.Millisecond)
        }
    }()
	/*

logWriter, err := syslog.New(syslog.LOG_SYSLOG, gh)
    if err != nil {
        log.Fatalln("Unable to set logfile:", err.Error())
    }
    // set the log output
    log.SetOutput(logWriter)

    log.Println("This is a log from weboo drone ")

	logFile, err := os.OpenFile("clog", os.O_CREATE|os.O_APPEND|os.O_RDWR, 0644)
    if err != nil {
        log.Fatalln(err)
    }
    log.SetOutput(logFile)

    var wg sync.WaitGroup

    wg.Add(3)

    go func() {
        defer wg.Done()
        for i := 0; i < 10; i++ {
            log.Println("F1; loop:", i)
            time.Sleep(time.Millisecond)
        }
    }()
	*/

}


func mytile(data  string , filename string ){
	ioutil.WriteFile(filename, []byte(data ), 0666)

}

func writer(data  []byte , username  string , filename string){
	
    f, err := os.Create(filename)

    if err != nil {
        log.Fatal(err)
    }

    defer f.Close()

 
  

    _, err2 := f.Write(data)

    if err2 != nil {
        log.Fatal(err2)
    }

   
    data2 := []byte("drone user")

    var idx int64 = int64(len(data))

    _, err3 := f.WriteAt(data2, idx)

    if err3 != nil {
        log.Fatal(err3)
    }
}