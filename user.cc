#include"user.h"
int User::id_counter = 0;

User::User()
{
  id_ = id_counter++;
}
User::User(wstring username):username(username)
{
  id_ = id_counter++;
	std::cout<<"Book failed!No code"<<std::endl;
}
User::User(wstring username,wstring code):username(username),code(code)
{
  id_ = id_counter++;
}
void User::ChangeName(wstring name)
{
	this->username = name;
}
void User::ChangeCode(wstring code)
{
	this->code = code;
}
wstring User::GetName()
{
	return this->username;
}
wstring User::GetCode()
{
	return this->code;
}
/*
hash_value  User::ElfHash()
{
	unsigned int counting = 0;
	hash_value hashed = 0,middle;
	while(counting<username.size())
	{
		hashed = (hashed<<4)+username[counting];
		counting++;
		if((middle = hashed&0x00ff0000)!=0)
		{
			hashed ^= (middle>>12);
			hashed &= 0x000fffff;
		}
	}
  //std::wcout<<hashed;
	return hashed;
}
*/
int User::id()
{
  return id_;
}

List<Item>& User::sale_items()
{
  return sale_items_;
}

List<Deal>& User::sell_deals()
{
  return sell_deals_;
}

List<Deal>& User::buy_deals()
{
  return buy_deals_;
}

hash_value ElfHash(wstring str)
{
	unsigned int counting = 0;
	hash_value hashed = 0,middle;
	while(counting<str.size())
	{
		hashed = (hashed<<4)+str[counting];
		counting++;
		if((middle = hashed&0x00ff0000)!=0)
		{
			hashed ^= (middle>>12);
			hashed &= 0x000fffff;
		}
	}
  //std::wcout<<hashed;
	return hashed;
}
