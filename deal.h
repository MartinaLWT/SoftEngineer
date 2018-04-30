#ifndef DEAL_H_
#define DEAL_H_
#include<string>
using std::wstring;

class Deal
{
private:
    wstring item_name;
    wstring seller_name;
    wstring buyer_name;
    int item_ID;
    int state;//enum {Tobepaid,Tobedelivered,Tobecomfirmed,Complete}state;
public:
    //const static string kStateTable[4] = {"Tobepaid", "Tobedelivered", "Tobecomfirmed", "Complete"};
    Deal();
    Deal(wstring seller_name,wstring buyer_name,wstring item_name,int item_ID);
    void ChangeState();
    wstring GetItemName();
    wstring GetSeller();
    wstring GetBuyer();
    int GetItemID();
    int GetState();
};

#endif // DEAL_H_
