#include <iostream>
#include<map>
#include<algorithm>
#include<functional>
#include<string>
#include<math.h>
#include<vector>

#include<cstdlib>

using namespace std ;



bool _test(vector <int> vect)
{

     sort(vect.begin(), vect.end());

     int j = 0;


    for(;    j   <vect.size()  - 1  ; j++)
    {

      if(vect[j+1]  !=  (vect[j] + 1) ){
            return false ;
      }
    }

    return true;

}

int  _find_greatest_elements(int nums[] , int n)
{


       int j , i ;
       int ctr = 0;

       for(i = 0 ;  i <n ; i++){

            for(j = 0 ;  j  <n ; j++){
                 if(nums[j] > nums[i])
                 ctr ++;
            }

            if(ctr ==2){
                 return nums[i];
            }
       }

}



int  _mosoccur(int nums[] , int  size)
{

       int max_oocur = 0;
    int i , j ; 
       for (i = 0; i <size; i++){

             int count  = 1;

             for (j = i+1 ; j <size ;j++)
             {

                   if(nums[i] == nums[j]){

                         count ++ ; 
                   }
                   if(count > max_oocur)
                        max_oocur = count ;
             }
       }

       for (int i=0;i<size;i++)
  {
   int count=1;
   for (int j=i+1;j<size;j++)
       if (nums[i]==nums[j])
           count++;
   if (count==max_oocur){
     cout << nums[i] << endl;
     return nums[i];
   }
       
  }
}


void rerange_array_elements(int nums[], int x , int  n){
     multimap<int , int>  m;


    int i = 0;


     for (; i <x ; i++){
          m.insert(make_pair(abs(n-nums[i])  , nums[i]));
     }

     int j ;

     for(auto t  =  m.begin() ; t!= m.end()  ; t++) {
         nums[i++]  = (*t).second;
         
     }

    
}





