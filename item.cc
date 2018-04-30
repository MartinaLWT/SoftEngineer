#include"item.h"

int Item::id_count = 0;

bool Item::title_contain(wstring str)
{
  unsigned fail[kStringLength];
  fail[0]=fail[1]=0;
  for(unsigned long i=1;i<str.size();i++)
  {
    int j=fail[i];
    while(j!=0 && str[i]!=str[j])
      j=fail[j];
    if(str[i]==str[j])
      fail[i+1]=j+1;
    else
      fail[i+1]=0;
  }
  for(unsigned long i=0,j=0;i<title_.size();i++)
  {
    while(j!=0 && title_[i]!=str[j])
      j=fail[j];
    if(title_[i]==str[j])
      j++;
    if(j==str.size())
      return true;
  }
  return false;
}

bool Item::detail_contain(wstring str)
{
  unsigned fail[kStringLength];
  fail[0]=fail[1]=0;
  for(unsigned long i=1;i<str.size();i++)
  {
    int j=fail[i];
    while(j!=0 && str[i]!=str[j])
      j=fail[j];
    if(str[i]==str[j])
      fail[i+1]=j+1;
    else
      fail[i+1]=0;
  }
  for(unsigned long i=0,j=0;i<detail_.size();i++)
  {
    while(j!=0 && detail_[i]!=str[j])
      j=fail[j];
    if(detail_[i]==str[j])
      j++;
    if(j==str.size())
      return true;
  }
  return false;
}

Item::Item()
{
  id_ = id_count++;
}

Item::Item(double price,wstring title,wstring detail,bool on_shelf,wstring seller):price_(price),title_(title),detail_(detail),on_shelf_(on_shelf),seller_(seller)
{
  id_ = id_count++;
}

double Item::price()
{
  return price_;
}

wstring Item::title()
{
  return title_;
}

wstring Item::detail()
{
  return detail_;
}

bool Item::contain(wstring str)
{
  return title_contain(str) || detail_contain(str);
}

long Item::id()
{
  return id_;
}

bool Item::on_shelf()
{
  return on_shelf_;
}

void Item::put_on_shelf()
{
  on_shelf_=true;
}

void Item::put_off_shelf()
{
  on_shelf_=false;
}

wstring Item::seller()
{
  return seller_;
}
