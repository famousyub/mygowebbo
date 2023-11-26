#include <iostream>


#include <fstream>

#include<string>
#include<sstream>
#include<cmath>
#define KUBERNITES "https://www.bogotobogo.com/DevOps/Docker/Docker-from-Monolithic-to-Micro-services-GCP-Kubernetes.php"
#define _Image_h
#define WIDTH 128
#define HEIGHT 128




using namespace std;

typedef struct  Delta Delta ;
typedef struct Droneconfig Droneconfig;

typedef struct Drone Drone ;
typedef  unsigned  char  unchar ;

 struct  Delta {
    int _sizer ;
    char fg_drone[1024];
    char deltaname [1024];
    char droneconf_actif [20];
    int  droneIdbyte ;
    char droneId[512];
};

struct Droneconfig {

     Delta dela ;
     char config_beta[1024];
      int droneElice  ;
      char portNum [20];

      int urlFetch[1024];
      char filelog [1024];

};

struct Drone  {
    Droneconfig  droneconfig ;
    int drones_fg;
    int dronebyte ;
    char droneName [50]; 
    char linenName[1024];
    int lines ;

    int user_id ;
    int isUsed ;
    FILE *readdrone ;
    
};


typedef struct node node;



struct node  {
     
     int valdrone ;
     char dronenode[100] ;
     Drone  drone ;
     node *next ;


};


//function store drones 



int writedronelinkedlist(char filename[] , node *head)
{
   node  * temp =head;
   FILE *saver ;

   saver = fopen(filename , "a+");
   if(!saver){
     perror("eeror  open file") ;
     return -1;
   }

   while (temp!=NULL){
         fwrite(temp ,sizeof(node),1,saver);
         temp = temp->next;
   }

   if(fwrite!=0){
      printf("list stroed   in file succesfully");
      
  fclose(saver);
      return 0;
   }

   else printf("erroor white  writing");

  fclose(saver);

  return -1;
}


class MImage  {
      

       private  :

       ifstream *pInFile1 ;
       ostream *pOutFile1 ;
       unchar imageHeaderData1[1078];
       unchar ** imageData1 ;
       unchar m_smoothFilter1[3][3];

       unchar **filterdData1 ;


          ifstream* pInFile; 
         ofstream* pOutFile;
          unchar imageHeaderData[1078]; //.bmp header data with offset 1078.
          unchar** imageData;
          unchar m_smoothFilter[3][3]; // Smoothing Filter.
          unchar**  filteredData;



       public  :

       MImage(const char* fileName); //Constructor
       ~MImage(); //Deconstructor
       void write(const char* fileName);
       void smoothFilter(); //smoothing filer.

};



MImage::MImage(const char* fileName){

    imageData = new unchar* [HEIGHT]; // create new array size: height of image.
    filteredData = new unchar* [HEIGHT];// create new array size: height of image.

    for (int i = 0; i < HEIGHT; i++) {

        imageData[i] = new unchar [WIDTH]; //create matrix.
        filteredData[i] = new unchar [WIDTH]; //create matrix.
    }

    //image I/O
    pInFile = new ifstream;
    pInFile->open(fileName, ios::in | ios::binary); // open fileName and read as binary.
    pInFile->seekg(0, ios::beg); //pos filter at beginning of image file.
    pInFile->read(reinterpret_cast<char*>(imageHeaderData),1078); //read bmp header data into array.

    for(int i=0; i<HEIGHT; i++) {
        pInFile->read(reinterpret_cast<char*>(imageData[i]),WIDTH);//read row into each array entry.
    }

    pInFile->close(); //close stream.

    char m_smoothFilter[3][3] = {
                                 {1,1,1},
                                 {1,2,1},
                                 {1,1,1}
                                };

}

MImage::~MImage(){

    delete pInFile;
    delete pOutFile;

    for(int i=0; i<HEIGHT; i++){
        delete[] imageData[i];
        delete[] filteredData[i];
    }

    delete[] imageData;
    delete[] filteredData;
}

void MImage::write(const char* fileName) {

    smoothFilter();
    pOutFile = new ofstream;
    pOutFile->open(fileName, ios::out | ios::trunc | ios::binary);
    pOutFile->write(reinterpret_cast<char*>(imageHeaderData), 1078); //write header data onto output

    for(int i = 0; i < HEIGHT; i++){

        pOutFile->write(reinterpret_cast<char*>(filteredData[i]),WIDTH); // write new image data.

    }

    pOutFile->close(); //close stream
}

void MImage::smoothFilter(){

    //copy input image into new image
    for(int i = 0; i < HEIGHT; i++) {
        strcpy(reinterpret_cast<char*>(filteredData[i]), reinterpret_cast<char*>(imageData[i]));
    }

    int sumOfPixels = 0;

    for(int i = 1; i < HEIGHT -1; i++) {

        for(int j = 1; j < WIDTH -1; j++) {

            sumOfPixels = m_smoothFilter[0][0] * imageData[i+1][j-1] + // top left corner
                          m_smoothFilter[0][1] * imageData[i+1][j]   + // top center
                          m_smoothFilter[0][2] * imageData[i+1][j+1] + // top right corner
                          m_smoothFilter[1][0] * imageData[i][j-1]   + // center left
                          m_smoothFilter[1][1] * imageData[i][j]     + // center center
                          m_smoothFilter[1][2] * imageData[i][j+1]   + // center right
                          m_smoothFilter[2][0] * imageData[i-1][j-1] + // bottom left corner
                          m_smoothFilter[2][1] * imageData[i-1][j]   + // bottom center
                          m_smoothFilter[2][2] * imageData[i-1][j+1];  // bottom right corner

            filteredData[i][j] = (sumOfPixels / ( m_smoothFilter[0][0] + m_smoothFilter[0][1] +
                                                  m_smoothFilter[0][2] + m_smoothFilter[1][0] +
                                                  m_smoothFilter[1][1] + m_smoothFilter[1][2] +
                                                  m_smoothFilter[2][0] + m_smoothFilter[2][1] +
                                                 m_smoothFilter[2][2]));
        }
    }

}




int  main(int argc , const char *argv[])
{




   if(argc > 1){
     
      MImage img(argv[1]);
      img.write("output.jpg");
      return 1;
   }

   else  cout << "number argc  missing " <<endl ;


    return  1;

}