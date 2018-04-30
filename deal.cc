#include"deal.h"

Deal::Deal(){}
Deal::Deal(wstring seller_name,wstring buyer_name,wstring item_name,int item_ID):seller_name(seller_name),buyer_name(buyer_name),item_name(item_name),item_ID(item_ID)
{
    state = 0;
}
void Deal::ChangeState()
{
    state++;
}
wstring Deal::GetSeller()
{
    return seller_name;
}
wstring Deal::GetBuyer()
{
    return buyer_name;
}
wstring Deal::GetItemName()
{
    return item_name;
}
int Deal::GetItemID()
{
    return item_ID;
}
int Deal::GetState()
{
    return state;
}
