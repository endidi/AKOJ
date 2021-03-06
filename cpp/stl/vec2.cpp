//vec2.cpp -- methodes and iterators
//16.8
#include<bits/stdc++.h>
using namespace std;

struct Review//struct storage title and rating
{
    string title;
    int rating;
};

//declare FillReview function read data
//declare ShowReview function print data
bool FillReview(Review & rr);
void ShowReview(const Review & rr);
void ShowReviewAll(vector<Review> );

int main()
{
    vector<Review> books;//define a book struct vector
    Review temp;
    while(FillReview(temp))
        books.push_back(temp);
    int num = books.size();
    if (num > 0)
    {
        cout<<"Thank you. You entered the following:"<<endl;
        cout<<"Rating\tBook"<<endl;

        ShowReviewAll(books);
        cout<<"Reprising:\n"
            <<"Rating\tBook\n";
        vector<Review>::iterator pr;
        ShowReviewAll(books);
        vector<Review> oldlist(books); //copy constructor used
        if (num > 3)
        {
            //remove 2 items
            books.erase(books.begin()+1,books.begin()+3);
            cout<<"After erasure:"<<endl;
            ShowReviewAll(books);

            //insert 1 item
            books.insert(books.begin(),oldlist.begin()+1,oldlist.begin()+2);
            cout<<"After insertion:"<<endl;
            ShowReviewAll(books);
        }

        books.swap(oldlist);
        cout<<"Swapping oldlist with books:"<<endl;
        ShowReviewAll(books);

    }
    else
        cout<<"Nothing entered, nothing gained"<<endl;

    return 0;
}

bool FillReview(Review & rr)
{
    cout<<"Enter book tilte (quit to quit): ";
    getline(cin,rr.title);
    if (rr.title == "quit")
        return false;
    cout<<"Enter book rating: ";
    cin>>rr.rating;
    if (!cin)
        return false;
    //get rid of rest of input line
    while(cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review & rr)
{
    cout<<rr.rating<<"\t"<<rr.title<<endl;
}

void ShowReviewAll(vector<Review> books)
{
    vector<Review>::iterator pr;
    for (pr = books.begin();pr != books.end();pr++)
        ShowReview(*pr);
}
