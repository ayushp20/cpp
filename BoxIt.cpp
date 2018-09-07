
//Implement the class Box
//l,b,h are integers representing the dimensions of the box
class Box
{
  long long l,b,h;
    public:
        Box()
        {
            l=0;b=0;h=0;
        }
        Box(long long a,long long br,long long c)
        {
            l=a;b=br;h=c;
        }
        Box(Box &temp)
        {
            l=temp.l;b=temp.b;h=temp.h;
        }

        long long getLength()
        {
            return this->l;
        }
        long long getBreadth()
        {
            return this->b;
        }
        long long getHeight()
        {
            return this->h;
        }
        long long CalculateVolume()
        {
            return (long long)l*b*h;
        }
        friend ostream& operator<<(ostream& os,const Box& B)
        {
            os<<B.l<<" "<<B.b<<" "<<B.h<<" ";
            return os;
        }
        friend bool operator<(Box&A,Box &B)
        {
            if(A.l!=B.l)
                return A.l<B.l;
            else if(A.b!=B.b)
                return A.b<B.b;
            else
                return A.h<B.h;
        }
};

// The class should have the following functions :

// Constructors:
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

