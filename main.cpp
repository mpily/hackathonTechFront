#include <iostream>
#include <string>
# include <map>

using namespace std;



class Darasa{
 public:
struct Pupils{//a data structure that will hold the pupils entries
string name;
int regNumber;
Pupils* nextPupil;
};



Pupils * head;//first element of the linked list is set to teacher a s default
Pupils * traverseClass;
Darasa* nextClass;
void addClassMember(string );
void removeClassMember(string );
void getDarasaMembers ( );
void setDarasaMembers ();// used to set default characteristics of members in the darasa

};



    Darasa standard1;
    Darasa standard2;
    Darasa standard3;
    Darasa traverseShule;

class Shule{//creating the data structure shule will have the name of the school- schoolname- a library containing all darasas in the shule

   public:
        string schoolname="primarySchool";
        void removeDarasa(string name);
        void addDarasa (string name);
        void getShule();
        void setshule();
        Darasa* findDarasa(string name);// used to locate a darasa from the library

   private:
     string classname;
     Darasa * thisclass;
     Darasa* nextclass;
     map<string,Darasa*> namesToDarasa;

};

  Darasa* Shule ::findDarasa(string nameIssued){
      map<string,Darasa*>::const_iterator counter=namesToDarasa.begin();
      counter=namesToDarasa.find(nameIssued);
      return(counter->second);
  }
    void Shule::addDarasa(string name)
    {
        traverseShule=standard3;//begins at standard3 the default value of darasa
        while(traverseShule.nextClass!=NULL)
        {
            traverseShule= *traverseShule.nextClass;
        }
        traverseShule.nextClass=new Darasa;
        traverseShule=*traverseShule.nextClass;
        traverseShule.nextClass=NULL;
        traverseShule.setDarasaMembers();
        namesToDarasa.insert(pair<string,Darasa*>(name,&traverseShule));

    }//goes to end of darasa and adds next darasa there
void Shule::setshule()
{
    namesToDarasa.insert(pair<string,Darasa*>("standard1",&standard1));
        namesToDarasa.insert(pair<string,Darasa*>("standard2",&standard2));
        namesToDarasa.insert(pair<string,Darasa*>("standard3",&standard3));
}
void Shule::removeDarasa(string nameIssued)
{
   traverseShule=standard1;
   map<string,Darasa*>::const_iterator counter=namesToDarasa.begin();
   counter=namesToDarasa.find(nameIssued);
   namesToDarasa.erase(nameIssued);
}//erases darasa from our map
void Shule::getShule()
{
    cout <<schoolname<<endl;
    for (map<string,Darasa*>::const_iterator counter=namesToDarasa.begin();counter!=namesToDarasa.end();counter++)
        {
            cout<<counter->first<<"\t"<<counter->second<<endl;
         (*counter->second).getDarasaMembers();

        }
} //prints out darasa and all its members

void Darasa::addClassMember(string nameIssued)//to add a pupil to class
{
    int flag=0;
    int formerRegNumber;
    traverseClass=head;//takes traverseClass to beginning of list
    // checking if the student is in the class
   while (traverseClass->nextPupil!=NULL)//traverses class looking for the end of the class
   {
       if(traverseClass->name.compare(nameIssued)==0){

        flag=1;
        traverseClass=traverseClass->nextPupil;
       }
       else{
        traverseClass=traverseClass->nextPupil;
       }
   }

   if(traverseClass->name.compare(nameIssued)==0){
        flag=1;
       }
       else{
       }
   if (flag==0){


   traverseClass->nextPupil=new Pupils;
   formerRegNumber=traverseClass->regNumber;

   formerRegNumber+=1;

   traverseClass=traverseClass->nextPupil;
   traverseClass->regNumber=formerRegNumber;

   traverseClass->nextPupil=NULL;

   traverseClass->name=nameIssued;
  // cout<<traverseClass->regNumber<<endl;
   }


}
void Darasa::getDarasaMembers()
{
    traverseClass=head;//takes traverseClass to beginning of list
    while (traverseClass->nextPupil!=NULL)//traverses class looking for the end of the class
   {
       cout<<traverseClass->name<<endl;
       traverseClass=traverseClass->nextPupil;

   }
   cout<<traverseClass->name<<endl;
}
void Darasa::removeClassMember(string nameIssued){
    traverseClass=head;
Pupils * prior;
prior=new Pupils;
prior=traverseClass;
while((traverseClass->name.compare(nameIssued)!=0)&&(traverseClass->nextPupil!=NULL)&&(traverseClass->name.compare(nameIssued)!=0)){// checking if the student is in the class
    prior=traverseClass;
    traverseClass=traverseClass->nextPupil;
}
prior->nextPupil=traverseClass->nextPupil;//replaces pointer to the object to be deleted with the pointer held in the object to be deleted i.e. in a way looks to skip the object to be deleted
}
void Darasa::setDarasaMembers(){
    head= new Pupils;
    traverseClass=new Pupils;
    string aname="teacher";
    int i=0;
  head->name=aname;
  head->nextPupil=NULL;
  head->regNumber=i;
}


int main()
{

  standard1.nextClass= &standard2;
  standard2.nextClass=&standard3;
  standard3.nextClass=NULL;
  standard1.setDarasaMembers();

  standard2.setDarasaMembers();
  standard3.setDarasaMembers();
  Shule please;
  please.setshule();
please.getShule();
int choice;
while (choice!=0){
cout<<"=============================================================================="<<endl;
cout<<"what would you like to do ?"<<endl;
cout<<"1: add a pupil to a class"<<endl;
cout<<"2: expel a pupil "<<endl;
cout<<"3: add a class"<<endl;
cout<<"4: remove  a class"<<endl;
cout<<"=============================================================================="<<endl;
cin>>choice;

switch (choice){

case(1): {
 string classToBeIncreased,nameofStudent;
 cout<<"enter the class name"<<endl;
 cin>>classToBeIncreased;
 Darasa tempo=*please.findDarasa(classToBeIncreased);
 cout<<"enter student's name"<<endl;
 cin>>nameofStudent;
 tempo.addClassMember(nameofStudent);
 please.getShule();
 break;
}
case(2):{
    string classToBeIncreased,nameofStudent;
 cout<<"enter the class in which he/she/prefersNotToIdentify is found"<<endl;
 cin>>classToBeIncreased;
 Darasa tempo=*please.findDarasa(classToBeIncreased);
 cout<<"enter student's name"<<endl;
 cin>>nameofStudent;
 tempo.removeClassMember(nameofStudent);
 please.getShule();
 break;
}
case(3):{
string classname;
cout<<"enter class name"<<endl;
cin>>classname;
please.addDarasa(classname);
please.getShule();
break;
}
case(4):{
string classname;
cout<<"enter class name"<<endl;
cin>>classname;
please.removeDarasa(classname);
please.getShule();
break;
}
}
}
    return 0;
}
