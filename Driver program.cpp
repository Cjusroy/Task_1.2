/*************
 Driver program to test below functions

int main()
{
    int count1,count2,choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }

    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }

    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;

        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

    }

    return 0;
}
****************/

class Polynomial {
         // Name of your array (Don't change this)
    int capacity;
    //int *degCoeff;
    public:

    int *degCoeff;
    Polynomial(){
       degCoeff=new int[100];
        capacity=100;
        for(int i=0;i<capacity;i++){
            degCoeff[i]=0;

        }

    }
    // default
    Polynomial(Polynomial const &p){
        int * newcpyconst=new int[p.capacity];
        for (int i=0;i<p.capacity;i++){
          newcpyconst[i]=p.degCoeff[i];


        }
        this -> degCoeff=newcpyconst;
        this -> capacity=p.capacity;
    }
    //copy assignment operator
    Polynomial operator=(Polynomial const &p){

    int * newcpyconst=new int[p.capacity];
        for (int i=0;i<p.capacity;i++){
          newcpyconst[i]=p.degCoeff[i];


        }
        this -> degCoeff=newcpyconst;
        this -> capacity=p.capacity;
        return *this;
    }
    //set coff
    void setCoefficient(int deg,int coff){
        int *newdegg;

        if (deg>=capacity){
            int size =2*capacity;
            while(size<=deg){
                 size*=2;
            }
            newdegg = new int[size];
            for(int i=0;i<size;i++){
            newdegg[i]=0;

             }
            for(int i=0;i<capacity;i++){
                newdegg[i]=degCoeff[i];

            }
            capacity=size;
            delete [] degCoeff;
           degCoeff=newdegg;


        }

        degCoeff[deg]=coff;

    }
    //copy constructer
    /*
    Polynomial(Polynomial const &ploy){
        int *newppoly=m=new int[capacity];
        for (int i=0;i<capacity;i++){
            newpoly[i]=ploy.degCoeff[i];

        }
        this* degCoeff =newppoly;
        this* capacity= ploy.capacity;
    }*/
    //add oprartor overloaded
    Polynomial operator+(Polynomial p2){

        int max_capacity;
        int min_capacity;
        int * max_arr;
        //int * max_arr =new int[]
        if (this -> capacity>p2.capacity){
            max_capacity=this -> capacity;
            min_capacity=p2.capacity;
            //max_arr =new int[max_capacity];
            max_arr=this -> degCoeff;
        }
        else{
            max_capacity=p2.capacity;
            min_capacity=this -> capacity;
            //max_arr =new int[max_capacity];
            max_arr=p2.degCoeff;
        }
        int* addpoly =new int[max_capacity];
        for(int i=0;i<max_capacity;i++){
            addpoly[i]=0;

        }

        int i=0;
        for (i;i<min_capacity;i++){
            addpoly[i]=degCoeff[i]+p2.degCoeff[i];
        }
        while(i<max_capacity){
             addpoly[i]=max_arr[i];

            i++;
        }
        this -> degCoeff= addpoly;
        this -> capacity = max_capacity;
        return *this;

    }
// subtraction operator over loaded
    Polynomial operator-(Polynomial p2){

        int max_capacity;
        int min_capacity;
        int * max_arr;
        //int * max_arr =new int[]
        if (this -> capacity>p2.capacity){
            max_capacity=this -> capacity;
            min_capacity=p2.capacity;
            //max_arr =new int[max_capacity];
            max_arr=this -> degCoeff;
        }
        else{
            max_capacity=p2.capacity;
            min_capacity=this -> capacity;
//max_arr =new int[max_capacity];
            max_arr=p2.degCoeff;
        }
        int* subpoly =new int[max_capacity];
        for(int i=0;i<max_capacity;i++){
            subpoly[i]=0;

        }
        int i=0;
        for (i;i<min_capacity;i++){
            subpoly[i]=degCoeff[i]-p2.degCoeff[i];
        }
        while(i<max_capacity){
             subpoly[i]=max_arr[i];

            i++;
        }
        this -> degCoeff= subpoly;
        this -> capacity = max_capacity;
        return *this;

    }
    //  multiplication
    Polynomial operator*(Polynomial p2){
       int *newdeg;
        int newcapacity=this->capacity+p2.capacity;
        newdeg=new int[newcapacity];
        for(int i=0;i<newcapacity;i++){
            newdeg[i]=0;

        }
        for (int i=0;i<this->capacity;i++){
           for(int j=0;j<p2.capacity;j++){
               if(i==0 or j==0){
                   continue;

               }
               int new1=i+j;
               int k = this->degCoeff[i]*p2.degCoeff[j];
               newdeg[new1]=newdeg[new1]+k;

           }
        }
        this -> degCoeff= newdeg;
        this -> capacity = newcapacity;
        return *this;




    }
    //print
    void print(){
        for (int i=0;i<capacity;i++){
            if (degCoeff[i]==0){
				continue;
            }
            cout<<degCoeff[i]<<'x'<<i<<" ";
}

    }

};
